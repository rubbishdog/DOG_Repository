//小型公司的工资管理程序
#include<iostream>
#include<string>
using namespace std;

//基类 
class Employee{
	public:
		Employee(){
			no=totalno++;				//输入的员工编号为目前最大编号＋1 
			cout<<"职工姓名：";
			cin>>name;
			salary=0.0; 				//薪水初值为0 
		}
		virtual void pay()=0;			// 计算月薪函数 
		virtual void display()=0;		//输出员工信息函数 
	protected:
		int no;							//编号 
		string name;					//姓名 
		float salary;					//薪水 
		static int totalno;				//目前最大编号 
}; 

//兼职类技术人员类
class Technician:public Employee{
	public:
		Technician(){
			hourlyrate=100;
			cout<<name<<"本月工作时间：";
			cin>>workhours;
		}
		void pay(){
			salary=hourlyrate*workhours;
		}
		void display(){
			cout<<"兼职技术人员："<<name<<",编号：";
			cout<<no<<",本月工资："<<salary<<endl;
		}
	private:
		float hourlyrate;
		int workhours;
}; 

//销售类
class Salesman:virtual public Employee{
	public:
		Salesman(){
			commrate=0.04f;
			cout<<name<<"本月销售额：";
			cin>>sales;
		}
		void pay(){
			salary=sales*commrate;
		}
		void display(){
			cout<<"销售员："<<name<<",编号,";
			cout<<no<<",本月工资:"<<salary<<endl;
		}
	protected:
		float commrate;
		float sales;
};

//经理类
class Manager:virtual public Employee{
	public:
		Manager(){
			monthlypay=8000;
		} 
		void pay(){
			salary=monthlypay;
		}
		void display(){
			cout<<"经理："<<name<<",编号:";
			cout<<no<<",本月工资:"<<salary<<endl;
		}
	protected:
		float monthlypay;
}; 

//销售经理类
class Salesmanager:public Manager,public Salesman{
	public:
		Salesmanager(){
			monthlypay=5000;
			commrate=0.05f;
			cout<<name<<"所管部门月销售量：";
			cin>>sales; 
		}
		void pay(){
			salary=monthlypay+commrate*sales;
		}
		void display(){
			cout<<"销售经理："<<name<<",编号："<<no<<",本月工资:"<<salary<<endl; 
		}
}; 

int Employee::totalno=10000;

int main(){
	Manager m1;
	Technician t1;
	Salesman s1;
	Salesmanager sm1;
	Employee *em[4]={&m1,&t1,&s1,&sm1};
	cout<<"上述人员的基本信息为："<<endl;
	for(int i=0;i<4;i++){
		em[i]->pay();
		em[i]->display();
	}
	return 0;
}









