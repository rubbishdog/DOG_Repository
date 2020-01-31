//构造函数和析构函数示例
#include<iostream>
using namespace std;
//点类的界面部分 
class Point{
	public:
		Point(); //默认构造函数 
		Point(int); //一个参数的构造函数 
		Point(int,int); //两个参数的构造函数 
		~Point(); //析构函数 
		void displayxy(); 
	private:
		int X,Y;
}; 
//点类的实现部分 
Point::Point() 
{
	X=7;
	Y=8;
	cout<<"Default constructor is called!";
	displayxy();
}

Point::Point(int x)
{
	X=x;
	Y=8;
	cout<<"Constructor is called!";
	displayxy(); 
}
Point::Point(int x,int y)
{
	X=x;
	Y=y;
	cout<<"Constructor is called!";
	displayxy();
}

Point::~Point()
{
	cout<<"Destructor is called!";
	displayxy(); 
}

void Point::displayxy()
{
	cout<<"("<<X<<","<<Y<<")"<<endl;
}

int main()
{
	Point p1(3,4),p2[2]={5,6},p3;
	cout<<endl;
	//创建对象p1时调用有两个参数的构造函数
	//对象p2为对象数组，每个数组元素被创建时都要调用构造函数
	//创建对象p3时调用默认构造函数 
	return 0;
}


