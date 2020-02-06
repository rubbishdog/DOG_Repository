#include<iostream>
using namespace std;
class Point{
	public:
		int getresource();
		void freeresource()
		{
			resource=0;
		}
	private:
		static int resource; //声明静态数据成员 
}; 

int Point::resource=0; //给静态成员赋初值0，表示点不可以被访问 

int Point::getresource(){
	if(resource)
		return 0;
	else{
		resource=1;
		return 1;
	}
}

int main(){
	Point obj1,obj2;
	if(obj1.getresource())
		cout<<"obj1在访问点类资源"<<endl;
	if(!obj2.getresource())
		cout<<"obj2不在访问点类资源" <<endl;
	obj1.freeresource();  //obj1完成访问点类资源，resource赋值为0 
	if(obj2.getresource())
		cout<<"obj2在访问点类资源"<<endl; 
	return 0; 
}
