#include<iostream>
using namespace std;
const double PI=3.14;
//�������
class Figure{  
	public:
		Figure(){ } ;
		double area() const {
			return 0.0;}
}; 
//���幫�м̳������� 
class Circle:public Figure{
	public:
		Circle(double myr){
			R=myr;
		}
		double area() const {
			return PI*R*R;
		}
	protected:
		double R;
};
//���������࣬���м̳з�ʽ
class Rectangle:public Figure{
	public:
		Rectangle(double myl,double myw){
			L=myl;
			W=myw;
		}
		double area() const{
			return L*W;
		}
	private:
		double L,W;
}; 

int main(){
	Figure fig; //����Figure���� 
	double area; 
	area=fig.area();
	cout<<"Area of figure is:"<<area<<endl;
	Circle c=Circle(3.0); //������Circle���� 
	area=c.area();
	cout<<"Area of circle is:"<<area<<endl;
	Rectangle rec=Rectangle(4.0,5.0); //������Rectangle���� 
	area=rec.area();
	cout<<"Area of rectangle is:"<<area<<endl;
	return 0; 
}









