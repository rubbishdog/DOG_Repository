#include<iostream>
#include<string>
using namespace std;
class Student{
	public:
		Student();                                  //���캯�� 
		Student* find(int i_no);				    //����ָ��ѧ�ŵ�ѧ�� 
		void edit(string i_newname,float score);    //�޸�ѧ������Ϣ 
		void erase();								//ɾ��ָ��ѧ�ŵ�ѧ�� 
		int add(Student* i_newStudent);				//����ѧ�� 
		int getno();								//���ѧ����ѧ�� 
		string getname();							//���ѧ�������� 
		float getscore();							//���ѧ���ĳɼ� 
		static int maxno;							//��ǰ���ѧ�� 
	private:
		int no;										//ѧ��ѧ�� 
		string name;								//ѧ������ 
		float score;								//ѧ���ɼ� 
		Student* per;								//��ǰ���ָ�� 
		Student* next;								//��һ�����ָ�� 
}; 

Student::Student(){
	score=0.0;
	per=NULL;
	next=NULL;
}

Student* Student::find(int i_no){
	if(i_no==no)
		return this;
	if(next!=NULL)
		return next->find(i_no);
	return NULL;  
}

void Student::edit(string i_name,float i_score){
	if(i_name=="")
		return;
	name=i_name;
	score=i_score;
}

void  Student::erase(){
	if(no<0)
		return;
	if(per!=NULL)
		per->next=next;
	if(next!=NULL)
		next->per=per;
	next=NULL;
	per=NULL;
}

int Student::add(Student* i_newStudent){
	int no=maxno+1;
	while(true){
		if(NULL==find(no)){
			break;
		}
		no=no+1;
	}
	Student* tmp=this;
	while(true){
		if(tmp->next==NULL){
			break;
		}
		tmp=tmp->next;
	}
	tmp->next=i_newStudent;
	i_newStudent->next=NULL;
	i_newStudent->per=tmp;
	i_newStudent->no=no;
	return no; 
}

int Student::getno(){
	return no;
}

string Student::getname(){
	return name;
}

float Student::getscore(){
	return score;
}

int Student::maxno=1000;
int main(){
	Student* studentroot=new Student();
	string input;
	Student* tmp=NULL;
	while(true){
		cout<<"����ָ��:����(F),����(A),�༭(E),ɾ��(D),�˳�(Q)"<<endl;
		cin>>input;
		if((input=="F")||(input=="f")){
			cout<<"����ѧ�ţ�";
			int id=-1;
			cin>>id;
			tmp=studentroot->find(id);
			if(tmp==NULL){
				cout<<"û�ҵ���"<<endl;
				continue; 
			} 
			cout<<"ѧ��:"<<tmp->getno();
			cout<<"����:";
			string name;
			if((name=tmp->getname())!=""){
				cout<<name<<endl;
			}
			else{
				cout<<"δ����"<<endl; 
			}
		}	
		else if((input=="A")||(input=="a")){
			cout<<"����������:";
			cin>>input;
			tmp=new Student();
			tmp->edit(input,tmp->getscore());
			cout<<"ѧ��:"<<studentroot->add(tmp)<<endl; 
		}
		else if((input=="E")||(input=="e")){
			cout<<"����ѧ�ţ�";
			int id=0;
			cin>>id;
			tmp=studentroot->find(id);
			if(tmp==NULL){
				cout<<"�պţ�"<<endl;
				continue;
			} 
			cout<<"�����֣�";
			cin>>input;
			tmp->edit(input,tmp->getscore());
			cout<<"���ĳɹ���"<<endl;
		}
		else if((input=="D")||(input=="d")){
			cout<<"����ѧ�ţ�";
			int id=0;
			cin>>id;
			tmp=studentroot->find(id);
			tmp->erase();
			cout<<"�Ѿ�ɾ����" <<endl; 
			delete tmp;
		}
		else if((input=="Q")||(input=="q")){
			break;
		}
		else{
			cout<<"��������"<<endl; 
		}
	}
	delete studentroot;
	return 0;
} 







