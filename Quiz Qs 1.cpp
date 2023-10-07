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
		void reverse(list);
		node* tail();
		node* back();
		int siz();
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
node* list::tail(){
	node* ptr=head;
	while(ptr->getnext()!=NULL){
		ptr=ptr->getnext();
	}
	current=ptr;
	return current;
}
node* list::back(){
	if(current!=head){
			node* ptr=head;
	while(ptr->getnext()!=current){
		ptr=ptr->getnext();
	}
	current=ptr;
	}
    return current;
}
int list::siz(){
	return size;
}
void list::reverse(list l1){
	node* p=l1.tail();
	node* ptr=head;
	addnode(p->getdata());
	
	do{
		p=l1.back();
		addnode(p->getdata());
	}
	while(p!=l1.head);
}
int main(){
	list l1,l2;
	l1.addnode(7);
	l1.addnode(11);
	l1.addnode(9);
	l1.addnode(13);
	l1.showlist();
	cout<<"After reverse:"<<endl;
	l2.reverse(l1);
	
	l2.showlist();
	return 0;
}