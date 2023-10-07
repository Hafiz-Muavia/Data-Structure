#include <iostream>
using namespace std;
class node{
	private:
		int data;
		node* next;
		
	public:
		node(int);
		void setdata(int);
		void setnext(node*);
		node* getnext();
		int getdata();
		void showdata();
};
class list{
	private:
		int size;
		node* head;
		node* current;
	public:
		list();
		void addnode(int);
		void showlist();
		void insert(int);
};
node::node(int d){
	setdata(d);
	next=NULL;
}
void node::setdata(int d){
	data=d;
}
void node::setnext(node* ptr){
	next=ptr;
}
node* node:: getnext(){
	return next;
}
int node::getdata(){
	return data;
}
void node::showdata(){
	cout<<"Data is: "<<data<<endl;
}
list::list(){
	size=0;
	head=NULL;
	current=NULL;
}
void list::addnode(int d){
	node* ptr=new node(d);
	if(size==0){
		head=ptr;
		current=ptr;
	}
	else {
		ptr->setnext(current->getnext());
		current->setnext(ptr);
		current=current->getnext();
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
void list::insert(int d){
	node* ptr=new node(d);
	ptr->setnext(head);
	head=ptr;
	size++;
}
int main(){
	list l1;
	l1.addnode(7);
	l1.addnode(11);
	l1.addnode(9);
	l1.addnode(13);
	l1.showlist();
	int x;
	cout<<"Enter any value to be inserted on head: ";
	cin>>x;
	l1.insert(x);
	cout<<"After insertion: "<<endl;
	l1.showlist();
	return 0;
}