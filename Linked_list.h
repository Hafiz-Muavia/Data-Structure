#include <iostream>//preprocessor directive
using namespace std;//standard library

class Node{//node class
	private:
		int data;
	    Node *Next;
	public:
		Node(int);
		void setdata1(int);
		int getdata1();
		void setnext1(Node*);
		Node* getnext1();
		void showdata1();
};
class list1{//linked_list
	private:
		Node* head1;
		Node* current1;
		int size1;
	public:
		//different functions for different operations
		list1();
		void addnode1(int);
		void showlist1();
		void get1(int);
		int siz1();
		void update1(int,int);
		void find1(int);
		void start1();
		void tail1();
		void next1();
		void back1();
};
Node::Node(int d){
	setdata1(d);
	Next=NULL;
}
void Node::setdata1(int d){
	data=d;
}
int Node::getdata1(){
	return data;
}
void Node::setnext1(Node* ptr){
	Next=ptr;
}
Node* Node::getnext1(){
	return Next;
}
void Node::showdata1(){
	cout<<"Data is: "<<data<<endl;
}

list1::list1(){
	head1=NULL;
	current1=NULL;
	size1=0;
}
void list1::addnode1(int d){
	Node* ptr=new Node(d);
	if(size1==0){
		head1=ptr;
		current1=ptr;
	}
	else{
		ptr->setnext1(current1->getnext1());
		current1->setnext1(ptr);
		current1=ptr;
		
	}
	    size1++;
}
void list1::showlist1(){
	Node* ptr=head1;
	while(ptr!=NULL){
		ptr->showdata1();
		ptr=ptr->getnext1();
	}
}
void list1::get1(int a){
	Node* ptr;
	ptr=head1;
	
	for(int i=1;i<a;i++){
		ptr=ptr->getnext1();
	}
	current1=ptr;
	cout<<"Particular index's value is: "<<current1->getdata1()<<endl;
}
int list1::siz1(){
	return size1;
}
void list1::update1(int a,int b){
	Node* ptr=head1;
	for(int i=1;i<a;i++){
		ptr=ptr->getnext1();
	}
	ptr->setdata1(b);
}
void list1::find1(int b){
	Node *ptr=head1;
	int l=-1;
	for(int i=1;i<=size1;i++){
		if(ptr->getdata1()==b){
			cout<<b<<" is found at index: "<<i<<endl;
			l++;
		}
		ptr=ptr->getnext1();
	}
	if(l==-1){
		cout<<"Value not found!!!"<<endl;
	}
}
void list1::start1(){
	current1=head1;
}
void list1::tail1(){
	Node* ptr=head1;
	for(int i=1;i<size1;i++)
	     ptr=ptr->getnext1();
	current1=ptr;
}
void list1::next1(){
	if(current1->getnext1()!=NULL){
		current1=current1->getnext1();
	}
	else{
		current1=head1;
	}
}
void list1::back1(){
	if(current1!=head1){
		Node* ptr=head1;
		while(ptr->getnext1()!=current1){
			ptr=ptr->getnext1();
		}
		current1=ptr;
	}
	else{
		Node* ptr=head1;
		for(int i=1;i<size1;i++)
	        ptr=ptr->getnext1();
        current1=ptr;
	}
}