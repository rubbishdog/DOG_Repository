#include<iostream>
#include<string>
using namespace std;
class Student{
	public:
		Student();                                  //构造函数 
		Student* find(int i_no);				    //查找指定学号的学生 
		void edit(string i_newname,float score);    //修改学生的信息 
		void erase();								//删除指定学号的学生 
		int add(Student* i_newStudent);				//增加学生 
		int getno();								//获得学生的学号 
		string getname();							//获得学生的名字 
		float getscore();							//获得学生的成绩 
		static int maxno;							//当前最大学号 
	private:
		int no;										//学生学号 
		string name;								//学生姓名 
		float score;								//学生成绩 
		Student* per;								//当前结点指针 
		Student* next;								//下一个结点指针 
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
		cout<<"输入指令:查找(F),增加(A),编辑(E),删除(D),退出(Q)"<<endl;
		cin>>input;
		if((input=="F")||(input=="f")){
			cout<<"输入学号：";
			int id=-1;
			cin>>id;
			tmp=studentroot->find(id);
			if(tmp==NULL){
				cout<<"没找到！"<<endl;
				continue; 
			} 
			cout<<"学号:"<<tmp->getno();
			cout<<"姓名:";
			string name;
			if((name=tmp->getname())!=""){
				cout<<name<<endl;
			}
			else{
				cout<<"未输入"<<endl; 
			}
		}	
		else if((input=="A")||(input=="a")){
			cout<<"请输入姓名:";
			cin>>input;
			tmp=new Student();
			tmp->edit(input,tmp->getscore());
			cout<<"学号:"<<studentroot->add(tmp)<<endl; 
		}
		else if((input=="E")||(input=="e")){
			cout<<"输入学号：";
			int id=0;
			cin>>id;
			tmp=studentroot->find(id);
			if(tmp==NULL){
				cout<<"空号！"<<endl;
				continue;
			} 
			cout<<"新名字：";
			cin>>input;
			tmp->edit(input,tmp->getscore());
			cout<<"更改成功。"<<endl;
		}
		else if((input=="D")||(input=="d")){
			cout<<"输入学号：";
			int id=0;
			cin>>id;
			tmp=studentroot->find(id);
			tmp->erase();
			cout<<"已经删除。" <<endl; 
			delete tmp;
		}
		else if((input=="Q")||(input=="q")){
			break;
		}
		else{
			cout<<"输入有误！"<<endl; 
		}
	}
	delete studentroot;
	return 0;
} 







