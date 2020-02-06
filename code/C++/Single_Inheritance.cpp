//公有继承方式单继承示例 
#include<iostream>
using namespace std;
class Point{
	public:
		void setxy(int myx,int myy){
			X=myx;
			Y=myy;
		}
		void movexy(int x,int y){
			X+=x;
			Y+=y;
		}
	protected:
		int X,Y;
};

class Circle:public Point{
	public:
		void setr(int myx,int myy,int myr){
			setxy(myx,myy);
			R=myr;
		}
		void display();
	protected:
		int R;
};

void Circle::display(){
	cout<<"The postion of center is:("<<X<<","<<Y<<")"<<endl;
	cout<<"The radius of Circle is:"<<R<<endl;
}

int main(){
	Circle C;
	C.setr(4,5,6);
	cout<<"The start data of Circle:"<<endl;
	C.display();
	C.movexy(1,2);
	cout<<"The new data of circle:"<<endl;
	C.display();
	return 0;
}






