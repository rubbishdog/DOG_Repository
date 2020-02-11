#include<iostream>
using namespace std;
class Base{
	public:
		virtual int func(int x){
			cout<<"This is Base class ";
			return x;
		}
		void func2(){
			func(5);
		}
}; 

class Subclass:public Base{
	public:
		virtual int func(int x){
			cout<<"This is Sub class ";
			return x;
		}
};

void test(Base& x){
	cout<<"x="<<x.func(5)<<endl;
}

int main(){
	Base bc;
	Subclass sc;
	test(bc);
	test(sc);
	sc.func2();
	return 0;
}
