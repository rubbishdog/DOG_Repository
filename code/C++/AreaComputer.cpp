#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class RectangleArea //������� 
{
	public: //��Ϊ����   //������Ϊ 
		void setData(float L,float W); //�������� 
		float ComputerArea(); //������� 
		void OutputArea(); //������ 
	private: //���ݳ���  //˽�г�Ա 
		float length,width,area; //���峤������� 
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
 	RectangleArea Rectangle;  //�������� 
 	Rectangle.setData(width,length); //ͨ���������setData()���� 
	Rectangle.ComputerArea();
	Rectangle.OutputArea();
	return 0;
 }
 

 
 
 
 
 
 
