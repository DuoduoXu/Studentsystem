#include<iostream>
using namespace std;
int studentCount=0;
struct Student{
	char name[22];
	long number;
	float score;
}students[100];

int find(char* name){
	int i;
	for(i=0;i<studentCount;i++){
		if(strcmp(students[i].name,name)==0){
			break;
	}
}
	return i;
}
void selectClass(){
	struct Student student;
	cout<<"name:";
	cin>>student.name;
	cout<<"number:";
	cin>>student.number;

	int i=find(student.name);
	if(i==studentCount){
		strcpy_s(students[i].name,student.name);
		students[i].number=student.number;
		studentCount++;
	}else{
		students[i].number+=student.number;
	}
}
void leaveClass(){
	struct Student student;
	cout<<"name:";
	cin>>student.name;
	cout<<"number:";
	cin>>student.number;

	int i=find(student.name);
	if(i==studentCount){
		cout<<"Error!"<<endl;
	}else{students[i].number-=student.number;
	}
}
void enterSystem()
{
	int a;
	int b,d;
	float c,e;
	cout<<"Input number";
	cin>>a;
	for(int i=0;i<studentCount;i++){
		if(students[i].number==a){
			b=i;
		}
	}
	cout<<"Input grade";
	cin>>c;
	students[b].score=c;
	for(int i=b+1;i<=studentCount;i++){
		cout<<"Go on?"<<endl;
		cout<<"6.contiune"<<endl;
		cout<<"7.Not"<<endl;
		cin>>d;
		if(d==6){
			cout<<"Input number"<<endl;
			cin>>e;
			students[i].score=e;
		}
		else{
			break;
		}
	}
}
void list()
{
	cout<<"name\t"<<"number\t"<<"score"<<endl;
	for(int i=0;i<studentCount;i++){
		cout<<students[i].name<<"\t";
			cout<<students[i].number<<"\t";
			cout<<students[i].score<<endl;
	}
}
int main()
{
	cout<<"1.Check"<<endl;
	cout<<"2.Add"<<endl;
	cout<<"3.Delete"<<endl;
	cout<<"4.Enter"<<endl;
	cout<<"5.Leave"<<endl;
	int action;
	do{
	cin>>action;
	switch(action){
	case 1:
			list ();
			break;
	case 2:
		selectClass();
		break;
	case 3:
		leaveClass();
		break;
	case 4:
		enterSystem();
		break;
	case 5:
		return 0;
	default:
		cout<<"error!";
	}
	
	}while(1);
}
