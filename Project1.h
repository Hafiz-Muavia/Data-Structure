#include <iostream>
#include <iomanip>
using namespace std;
int A=0;
class node{
	private:
		int sr_no,matric,inter,test,day,month,year,age;
		string name,s_o,dept,enrol,email,province,city,inter_type;
		long long int ph,cnic,s_o_cnic;
		float merit;
		node* next;
		node* prev;
	public:
		node(string,string,string,string,int,int,int,int,string,string,long long,long long,long long,int,int,int,float,string);
		void setdata(string,string,string,string,int,int,int,int,string,string,long long,long long,long long,int,int,int,float,string);
		int getmerit();
		void setprev(node*);
		node* getprev();
		void setnext(node*);
		node* getnext();
		void showdata();
};

node::node(string name,string s_o ,string province,string city,int age,int day,int month,int year,string dept,string email,long long ph,long long cnic,long long s_o_cnic,int matric,int inter,int test,float merit,string inter_type){
	prev=NULL;
	setdata(name,s_o,province,city,age,day,month,year,dept,email,ph,cnic,s_o_cnic,matric,inter,test,merit,inter_type);
	next=NULL;
}
void node::setdata(string name,string s_o ,string province,string city,int age,int day,int month,int year,string dept,string email,long long ph,long long cnic,long long s_o_cnic,int matric,int inter,int test,float merit,string inter_type){
	sr_no=++A;
	this->name=name;
	this->s_o=s_o;
	this->province=province;
	this->city=city;
	this->day=day;
	this->month=month;
	this->year=year;
	this->age=age;
	this->dept=dept;
	this->email=email;
	this->ph=ph;
	this->cnic=cnic;
	this->s_o_cnic=s_o_cnic;
	this->matric=matric;
	this->inter=inter;
	this->test=test;
	this->merit=merit;
	this->inter_type=inter_type;
}
int node::getmerit(){
	return merit;
}
void node::setprev(node* ptr){
	prev=ptr;
}
node* node::getprev(){
	return prev;
}
void node::setnext(node* ptr){
	next=ptr;
}
node* node::getnext(){
	return next;
}
void node::showdata(){
	cout<<setw(6)<<sr_no<<setw(20)<<setfill(' ')<<name<<setw(20)<<setfill(' ')<<s_o<<setw(20)<<setfill(' ')<<city<<setw(20)<<setfill(' ')<<dept<<setw(10)<<setfill(' ')<<"Merit"<<endl;
}

class list{
	private:
		node* head;
		node* current;
		node* ptr90;
		node* ptr80;
		node* ptr70;
		int size;
	public:
		list();
		void addnode(string,string,string,string,int,int,int,int,string,string,long long,long long,long long,int,int,int,float,string);
		void showlist();
		node* start();
		void tail();
		void next();
		void back();
		int siz();
		void insert(int,string,string,string,string,int,int,int,int,string,string,long long,long long,long long,int,int,int,float,string);
		void delptr();
};
list::list(){
	head=NULL;
	current=NULL;
	size=0;
}
void list::addnode(string name,string s_o ,string province,string city,int age,int day,int month,int year,string dept,string email,long long ph,long long cnic,long long s_o_cnic,int matric,int inter,int test,float merit,string inter_type){
	node* ptr=new node(name,s_o,province,city,age,day,month,year,dept,email,ph,cnic,s_o_cnic,matric,inter,test,merit,inter_type);
	if(size==0){
		head=ptr;
		current=ptr;
	}
	else{
		tail();
		ptr->setnext(current->getnext());
		ptr->setprev(current);
		current->setnext(ptr);
		current=ptr;
	}
	size++;
}
void list::showlist(){
	cout<<setw(6)<<"Sr. no"<<setw(20)<<setfill(' ')<<"Name"<<setw(20)<<setfill(' ')<<"S/O"<<setw(20)<<setfill(' ')<<"City"<<setw(20)<<setfill(' ')<<"Department"<<setw(10)<<setfill(' ')<<"Merit"<<endl;
	node* ptr=head;
	for(int i=1;i<=size;i++){
		ptr->showdata();
		ptr=ptr->getnext();
	}
}
node* list::start(){
	current=head;
	return current;
}
void list::tail(){
	node* ptr=head;
	for(int i=1;i<size;i++)
	     ptr=ptr->getnext();
	current=ptr;
}
void list::next(){
	if(current->getnext()!=NULL){
		current=current->getnext();
	}
}
void list::back(){
	if(current!=head){
		current=current->getprev();
	}
}
int list::siz(){
	return size;
}

void list::insert(int a,string name,string s_o ,string province,string city,int age,int day,int month,int year,string dept,string email,long long ph,long long cnic,long long s_o_cnic,int matric,int inter,int test,float merit,string inter_type){
	node *ptr=new node(name,s_o,province,city,age,day,month,year,dept,email,ph,cnic,s_o_cnic,matric,inter,test,merit,inter_type);
	if(a==1){
		head->setprev(ptr);
		ptr->setnext(head);
		head=ptr;
		size++;
	}
	else if(a==size+1){
		addnode(name,s_o,province,city,age,day,month,year,dept,email,ph,cnic,s_o_cnic,matric,inter,test,merit,inter_type);
	}
	else{
		current=head;
		for(int i=1;i<a-1;i++){
			current=current->getnext();			
		}
		ptr->setnext(current->getnext());
		ptr->setprev(current);
		current->setnext(ptr);
		current=ptr;
		ptr=ptr->getnext();
		ptr->setprev(current);
		size++;
	}
}

void list::delptr(){
	delete ptr90;
	delete ptr80;
	delete ptr70;
}