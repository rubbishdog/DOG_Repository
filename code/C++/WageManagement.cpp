//С�͹�˾�Ĺ��ʹ������
#include<iostream>
#include<string>
using namespace std;

//���� 
class Employee{
	public:
		Employee(){
			no=totalno++;				//�����Ա�����ΪĿǰ����ţ�1 
			cout<<"ְ��������";
			cin>>name;
			salary=0.0; 				//нˮ��ֵΪ0 
		}
		virtual void pay()=0;			// ������н���� 
		virtual void display()=0;		//���Ա����Ϣ���� 
	protected:
		int no;							//��� 
		string name;					//���� 
		float salary;					//нˮ 
		static int totalno;				//Ŀǰ����� 
}; 

//��ְ�༼����Ա��
class Technician:public Employee{
	public:
		Technician(){
			hourlyrate=100;
			cout<<name<<"���¹���ʱ�䣺";
			cin>>workhours;
		}
		void pay(){
			salary=hourlyrate*workhours;
		}
		void display(){
			cout<<"��ְ������Ա��"<<name<<",��ţ�";
			cout<<no<<",���¹��ʣ�"<<salary<<endl;
		}
	private:
		float hourlyrate;
		int workhours;
}; 

//������
class Salesman:virtual public Employee{
	public:
		Salesman(){
			commrate=0.04f;
			cout<<name<<"�������۶";
			cin>>sales;
		}
		void pay(){
			salary=sales*commrate;
		}
		void display(){
			cout<<"����Ա��"<<name<<",���,";
			cout<<no<<",���¹���:"<<salary<<endl;
		}
	protected:
		float commrate;
		float sales;
};

//������
class Manager:virtual public Employee{
	public:
		Manager(){
			monthlypay=8000;
		} 
		void pay(){
			salary=monthlypay;
		}
		void display(){
			cout<<"����"<<name<<",���:";
			cout<<no<<",���¹���:"<<salary<<endl;
		}
	protected:
		float monthlypay;
}; 

//���۾�����
class Salesmanager:public Manager,public Salesman{
	public:
		Salesmanager(){
			monthlypay=5000;
			commrate=0.05f;
			cout<<name<<"���ܲ�������������";
			cin>>sales; 
		}
		void pay(){
			salary=monthlypay+commrate*sales;
		}
		void display(){
			cout<<"���۾���"<<name<<",��ţ�"<<no<<",���¹���:"<<salary<<endl; 
		}
}; 

int Employee::totalno=10000;

int main(){
	Manager m1;
	Technician t1;
	Salesman s1;
	Salesmanager sm1;
	Employee *em[4]={&m1,&t1,&s1,&sm1};
	cout<<"������Ա�Ļ�����ϢΪ��"<<endl;
	for(int i=0;i<4;i++){
		em[i]->pay();
		em[i]->display();
	}
	return 0;
}









