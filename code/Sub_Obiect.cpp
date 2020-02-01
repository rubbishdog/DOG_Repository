//sub objectÊ¾Àı 
#include<iostream>
using namespace std;
class Part{
	public:
		Part();
		Part(int);
		~Part();
	private:
		int val;
}; 

Part::Part()
{
	val=0;
	cout<<"Default constructor of Part"<<endl;
}

Part::Part(int x)
{
	val=x;
	cout<<"Constructor of Part, "<<val<<endl;
}

Part::~Part()
{
	cout<<"Destructor of Part,"<<val<<endl;	
}

class Whole{
	public:
		Whole(int);
		Whole(){};
		~Whole();
	private:
		Part p1;
		Part p2;
};

Whole::Whole(int i):p1(),p2(i)
{
	cout<<"Constructor of Whole"<<endl;
}

Whole::~Whole()
{
	cout<<"Destructor of Whole"<<endl;
}

int main()
{
	Whole w=Whole(3); 
	return 0;
}







