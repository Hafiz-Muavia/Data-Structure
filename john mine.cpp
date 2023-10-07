#include <iostream>
using namespace std;

class node{
	private:
		int sr;
		char ch;
		string name;
	    node *next;
	public:
		node(int,char,string);
		void setdata(int,char,string);
		int getdata();
		void setnext(node*);
		node* getnext();
		void showdata();
};
class list{
	private:
		node* head;
		node* current;
		int size;
	public:
		//different functions for different operations
		list();
		void addnode(int,char,string);
		void showlist();
		void josephus();
};
node::node(int sr,char ch,string name){
	setdata(sr,ch,name);
	next=NULL;
}
void node::setdata(int sr,char ch,string name){
	this->sr=sr;
	this->name=name;
	this->ch=ch;
}
int node::getdata(){
	return sr;
}
void node::setnext(node* ptr){
	next=ptr;
}
node* node::getnext(){
	return next;
}
void node::showdata(){
	cout<<"Sr. no. is: "<<sr<<endl;
	cout<<"Name is: "<<name<<endl;
}
list::list(){
	head=NULL;
	current=NULL;
	size=0;
}
void list::addnode(int sr,char ch,string name){
	node* ptr=new node(sr,ch,name);
	if(size==0){
		head=ptr;
		current=ptr;
		head->setnext(head);
	}
	else{
		ptr->setnext(current->getnext());
		current->setnext(ptr);
		current=ptr;
		
	}
	    size++;
}
void list::showlist(){
	node* ptr=head;
	for(int i=1;i<=size;i++){
		ptr->showdata();
		ptr=ptr->getnext();
	}
}

void list::josephus(){
	node* ptr=head;
	current=head;
	while(size>1){
		ptr=ptr->getnext();
		current->setnext(ptr->getnext());
		delete ptr;
		size--;
		current=current->getnext();
		ptr=current;
	}
	head=current;
}
void input(list &l1, list &l2){
	char ch;
	string name;
	for(int i=1;i<=60;i++){
		in:
		cout<<"Enter name for student "<<i<<": ";
		cin>>name;
		cout<<"Enter Gender('M' or 'm' for male and 'F' or 'f' for female): ";
		cin>>ch;
		if(ch=='M'||ch=='m'){
			l1.addnode(i,ch,name);
		}
		else if(ch=='F'||ch=='f'){
			l2.addnode(i,ch,name);
		}
		else{
			cout<<"Invalid Gender. Again input."<<endl;
			goto in;
		}
	}
}
int main(){
	list l1,l2;
	input(l1,l2);
	l1.josephus();
	l2.josephus();
	cout<<"CR is here."<<endl;
	l1.showlist();
	cout<<"GR is here."<<endl;
	l2.showlist();
	return 0;
}