//���캯������������ʾ��
#include<iostream>
using namespace std;
//����Ľ��沿�� 
class Point{
	public:
		Point(); //Ĭ�Ϲ��캯�� 
		Point(int); //һ�������Ĺ��캯�� 
		Point(int,int); //���������Ĺ��캯�� 
		~Point(); //�������� 
		void displayxy(); 
	private:
		int X,Y;
}; 
//�����ʵ�ֲ��� 
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
	//��������p1ʱ���������������Ĺ��캯��
	//����p2Ϊ�������飬ÿ������Ԫ�ر�����ʱ��Ҫ���ù��캯��
	//��������p3ʱ����Ĭ�Ϲ��캯�� 
	return 0;
}


