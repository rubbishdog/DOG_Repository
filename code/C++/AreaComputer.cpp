#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class RectangleArea //类的声明 
{
	public: //行为抽象   //公有行为 
		void setData(float L,float W); //输入数据 
		float ComputerArea(); //计算面积 
		void OutputArea(); //输出面积 
	private: //数据抽象  //私有成员 
		float length,width,area; //定义长、宽、面积 
 } ;
 
 void RectangleArea::setData(float L,float W)
 {
 	length=L;
 	width=W;
 }
 
 float RectangleArea::ComputerArea()
 {
 	area=length*width;
 	return area;
 }
 
 void RectangleArea::OutputArea()
 {
 	cout<<"Area="<<area<<endl;
 }
 
 int main()
 {
 	float width,length;
 	cout<<"Please enter data:"<<endl;
 	cin>>width>>length;
 	RectangleArea Rectangle;  //声明对象 
 	Rectangle.setData(width,length); //通过对象调用setData()函数 
	Rectangle.ComputerArea();
	Rectangle.OutputArea();
	return 0;
 }
 

 
 
 
 
 
 
