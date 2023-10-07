#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int sizee=0,count=0;
int total_crhr=0;
float total_grpt=0,cgp1,cgp231=0;
class node{
	private:
		int marks,cred_hrs;
		string cname,ccode;
		float gpa,cgpa=0,grade_points;
		node* next;
	public:
		node(int,int,string,string,float,float);
		void setdata(int,int,string,string,float,float);
		int getmarks();
		void setnext(node*);
		node* getnext();
		void showdata();
};
node::node(int marks,int cred_hrs,string cname,string ccode,float gpa,float grade_points){
	setdata(marks,cred_hrs,cname,ccode,gpa,grade_points);
	next=NULL;
}
void node::setdata(int marks,int cred_hrs,string cname,string ccode,float gpa,float grade_points){
	this->marks=marks;
	this->cname=cname;
	this->ccode=ccode;
	this->cred_hrs=cred_hrs;
	this->grade_points=grade_points;
	this->gpa=gpa;
}
void node::setnext(node* ptr){
	next=ptr;
}
node* node:: getnext(){
	return next;
}
void node::showdata(){
	cout<<endl;
	cout<<cname<<setw(20)<<setfill(' ')<<ccode<<setw(20-(ccode.size()))<<setfill(' ')<<marks<<setw(20)<<setfill(' ')<<cred_hrs<<setw(20)<<setfill(' ')<<grade_points<<setw(20)<<setfill(' ')<<gpa<<endl;
}
int node::getmarks(){
	return marks;
}
class list{
	private:
		node* head;
		node* current;	
		int size;
	public:
		list();
		void addnode(int,int,string,string,float,float);
		float cgpa123(float, int);
		void showlist();
		void get(int);
		void in();
		float calc_gpa(int);
		float calc_GP(float,int);
		float gpapersem();
		void cgpa(float);
		int siz();
		void newsem();
		void update(int,int,int,string,string,float,float);
		void find(int);
		void start();
		void tail();
		void next();
		void back();
		void insert(int,int,int,string,string,float,float);
		void remove(int);
		void del(int);
		void notepad(list,list);
};
list::list(){
	head=NULL;
	current=NULL;
	size=0;
}
void list::addnode(int marks,int cred_hrs,string cname,string ccode,float gpa,float grade_points){
	node* ptr=new node(marks,cred_hrs,cname,ccode,gpa,grade_points);
	if(sizee==0){
		head=ptr;
		current=ptr;
	}
	else{
		ptr->setnext(current->getnext());
		current->setnext(ptr);
		current=ptr;
	}
	size++;
	   	sizee++;
}
void list::showlist(){
	cout<<"Name"<<setw(20)<<setfill(' ')<<"Course Code"<<setw(20)<<setfill(' ')<<"Marks"<<setw(20)<<setfill(' ')<<"Credit Hours"<<setw(20)<<setfill(' ')<<"Grade Points"<<setw(20)<<setfill(' ')<<"GPA"<<endl;
	node* ptr=head;
	while(ptr!=NULL){
		ptr->showdata();
		ptr=ptr->getnext();
	}
}

void list::in(){
	int marks,cred_hrs;
	string cname,ccode;
	float gpa,grade_points;
	cout<<"Enter marks for subject "<<sizee+1<<": ";
	cin>>marks;
	cout<<"Enter subject name: ";
	cin.ignore();
	getline(cin,cname);
	cout<<"Enter credit hours: ";
	cin>>cred_hrs;
	cout<<"Enter course code: ";
	cin>>ccode;
	gpa=calc_gpa(marks);
	grade_points=calc_GP(gpa,cred_hrs);
	addnode(marks,cred_hrs,cname,ccode,gpa,grade_points);
}
float list::calc_gpa(int marks){
	float gpa;
	if(marks<=100&&marks>=85){
		gpa=4.0;
	}
	else if(marks<85&&marks>=80){
		gpa=3.7;
	}
	else if(marks<80&&marks>=75){
		gpa=3.3;
	}
	else if(marks<75&&marks>=70){
		gpa=3.0;
	}
	else if(marks<70&&marks>=65){
		gpa=2.7;
	}
	else if(marks<65&&marks>=61){
		gpa=2.3;
	}
	else if(marks<61&&marks>=58){
		gpa=2.0;
	}
	else if(marks<58&&marks>=55){
		gpa=1.7;
	}
	else if(marks<55&&marks>=50){
		gpa=1.0;
	}
	else{
		gpa=0.0;
	}
	return gpa;
}
float list::calc_GP(float gpa,int cred_hrs){
	float grade_points=gpa*cred_hrs;
	total_grpt+=grade_points;
	total_crhr+=cred_hrs;
	return grade_points;
}
float list::gpapersem(){
	float cgpa=total_grpt/total_crhr;
	return cgpa;
}
void list::newsem(){
	sizee=0;
    total_crhr=0;
    total_grpt=0;
}
void list::cgpa(float cgpa){
	cgp1+=cgpa;
	count++;
	if(count==3){
		cout<<"CGPA of 3 semesters is: "<<cgp1/3.0<<endl;
	}
}
void list::get(int a){
	node* ptr;
	ptr=head;
	
	for(int i=1;i<a;i++){
		ptr=ptr->getnext();
	}
	current=ptr;
	cout<<"Particular index's value is: "<<endl;
	current->showdata();
}
int list::siz(){
	return size;
}
void list::update(int a,int marks,int cred_hrs,string cname,string ccode,float gpa,float grade_points){
	node* ptr=head;
	for(int i=1;i<a;i++){
		ptr=ptr->getnext();
	}
	ptr->setdata(marks,cred_hrs,cname,ccode,gpa,grade_points);
}
void list::find(int b){
	node *ptr=head;
	int l=-1;
	for(int i=1;i<=size;i++){
		if(ptr->getmarks()==b){
			cout<<b<<" is found at index: "<<i<<endl;
			l++;
		}
		ptr=ptr->getnext();
	}
	if(l==-1){
		cout<<"Value not found!!!"<<endl;
	}
}
void list::start(){
	current=head;
}
void list::tail(){
	node* ptr=head;
	for(int i=1;i<sizee;i++)
	     ptr=ptr->getnext();
	current=ptr;
}
void list::next(){
	if(current->getnext()!=NULL){
		current=current->getnext();
	}
	else{
		current=head;
	}
}
void list::back(){
	if(current!=head){
		node* ptr=head;
		while(ptr->getnext()!=current){
			ptr=ptr->getnext();
		}
		current=ptr;
	}
	else{
		node* ptr=head;
		for(int i=1;i<size;i++)
	        ptr=ptr->getnext();
        current=ptr;
	}
}
void list::insert(int a,int marks,int cred_hrs,string cname,string ccode,float gpa,float grade_points){
	node* ptr=new node(marks,cred_hrs,cname,ccode,gpa,grade_points);
	if(a==1){
		ptr->setnext(head);
		head=ptr;
		size++;
	}
	else{
		current=head;
		for(int i=1;i<a-1;i++){
			current=current->getnext();
			
		}
		ptr->setnext(current->getnext());
		current->setnext(ptr);
		current=ptr;
		size++;
	}
}
void list::remove(int a){
	if(a==1){
		current=head;
		current=current->getnext();
		delete head;
		head=current;
	}
	else if(a==size){
		node* ptr=head;
		for(int i=1;i<a-1;i++){
			ptr=ptr->getnext();
			
		}
		ptr->setnext(NULL);
		ptr=ptr->getnext();
		delete ptr;
		size--;
	}
	else{
		node* ptr=current=head;
		for(int i=1;i<a-1;i++){
			current=current->getnext();
			ptr=ptr->getnext();
		}
		ptr=ptr->getnext();
		current->setnext(ptr->getnext());
		delete ptr;
		size--;
	}
}
float list::cgpa123(float cgpa , int a){
	cgp231+=cgpa;
	if(a==3){
		return cgp231/3.0;
	}
	else {
		return cgp231;
	}
}
		
void list::notepad(list l2,list l3){
	system("start notepad.exe Student.txt");
	ofstream file("Student.txt");
    if(file.is_open()){
    	float y=gpapersem();
	
	file<<"GPA of semester "<<1<<" is: "<<y<<endl;
	cgpa123(y,1);
	
	
	y=l2.gpapersem();
	file<<"GPA of semester "<<2<<" is: "<<y<<endl;
	l2.cgpa123(y,2);
	
	y=l3.gpapersem();
	
	file<<"GPA of semester "<<3<<" is: "<<y<<endl;
	file<<"CGPA of 3 Semesters is "<<l3.cgpa123(y,3);
	}
	file.close();
}