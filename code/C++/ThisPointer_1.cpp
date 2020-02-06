//implicitly use of this pointer  
#include<iostream>
using namespace std;
class Point{
	public:
		Point(int=0,int=0);
		void displayxy();
	private:
		int X,Y;
};

Point::Point(int x,int y)
{
	X=x;
	Y=y;
}

void Point::displayxy()
{
	cout<<X<<endl; //�൱�ڣ�cout<<this->X<<endl; 
	cout<<Y<<endl; //�൱�ڣ�cout<<this->Y<<endl; 
}

int main()
{
	Point obj_1(10,20),obj_2(8,9),*p;
	p=&obj_1; //pָ�����obj_1 
	p->displayxy();
	p=&obj_2; //pָ�����obj_2 
	p->displayxy();
	return 0;
}
