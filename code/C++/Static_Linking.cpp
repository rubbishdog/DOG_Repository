#include<iostream>
using namespace std;
const double PI=3.14;
//定义基类
class Figure{  
	public:
		Figure(){ } ;
		double area() const {
			return 0.0;}
}; 
//定义公有继承派生类 
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
//定义派生类，公有继承方式
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
	Figure fig; //基类Figure对象 
	double area; 
	area=fig.area();
	cout<<"Area of figure is:"<<area<<endl;
	Circle c=Circle(3.0); //派生类Circle对象 
	area=c.area();
	cout<<"Area of circle is:"<<area<<endl;
	Rectangle rec=Rectangle(4.0,5.0); //派生类Rectangle对象 
	area=rec.area();
	cout<<"Area of rectangle is:"<<area<<endl;
	return 0; 
}









