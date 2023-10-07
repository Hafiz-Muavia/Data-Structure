#include <iostream>//preprocessor directive
using namespace std;//standard library

class Node{//node class
	private:
		int data;
	    Node *Next;
	public:
		Node(int);
		void setdata(int);
		int getdata();
		void setnext(Node*);
		Node* getnext();
		void showdata();
};
class list{//linked_list
	private:
		Node* head;
		Node* current;
		int size;
	public:
		//different functions for different operations
		list();
		void addnode(int);
		void showlist();
		void get(int);
		int siz();
		void update(int,int);
		void find(int);
		void start();
		void tail();
		void next();
		void back();
};
Node::Node(int d){
	setdata(d);
	Next=NULL;
}
void Node::setdata(int d){
	data=d;
}
int Node::getdata(){
	return data;
}
void Node::setnext(Node* ptr){
	Next=ptr;
}
Node* Node::getnext(){
	return Next;
}
void Node::showdata(){
	cout<<"Data is: "<<data<<endl;
}

list::list(){
	head=NULL;
	current=NULL;
	size=0;
}
void list::addnode(int d){
	Node* ptr=new Node(d);
	if(size==0){
		head=ptr;
		current=ptr;
	}
	else{
		ptr->setnext(current->getnext());
		current->setnext(ptr);
		current=ptr;
		
	}
	    size++;
}
void list::showlist(){
	Node* ptr=head;
	while(ptr!=NULL){
		ptr->showdata();
		ptr=ptr->getnext();
	}
}
void list::get(int a){
	Node* ptr;
	ptr=head;
	
	for(int i=1;i<a;i++){
		ptr=ptr->getnext();
	}
	current=ptr;
	cout<<"Particular index's value is: "<<current->getdata()<<endl;
}
int list::siz(){
	return size;
}
void list::update(int a,int b){
	Node* ptr=head;
	for(int i=1;i<a;i++){
		ptr=ptr->getnext();
	}
	ptr->setdata(b);
}
void list::find(int b){
	Node *ptr=head;
	int l=-1;
	for(int i=1;i<=size;i++){
		if(ptr->getdata()==b){
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
	Node* ptr=head;
	for(int i=1;i<size;i++)
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
		Node* ptr=head;
		while(ptr->getnext()!=current){
			ptr=ptr->getnext();
		}
		current=ptr;
	}
	else{
		Node* ptr=head;
		for(int i=1;i<size;i++)
	        ptr=ptr->getnext();
        current=ptr;
	}
}
int main(){//main function
	list l1;
	int a,b;
	l1.addnode(5);
	l1.addnode(7);
	l1.addnode(8);
	l1.showlist();
	//size of linked list
	cout<<"Length of list is: "<<l1.siz()<<endl;
	//particular index value
	cout<<"Enter the index you want to get: ";
	sizeee:
	cin>>a;
	if(a>0 && a<=l1.siz()){
		l1.get(a);
	}
	else{
		cout<<"Invalid index. Enter again."<<endl;
		goto sizeee;	
	}
	//updation
	cout<<"Enter the index you want to update: ";
	sizeee2:
	cin>>a;
	if(a>0 && a<=l1.siz()){
		cout<<"Enter the updated value: ";
		cin>>b;
		l1.update(a,b);
	}
	else{
		cout<<"Invalid index. Enter again."<<endl;
		goto sizeee2;	
	}
	cout<<"List after updation:"<<endl;
	l1.showlist();
	//searching
	cout<<"Enter the value you want to find: ";
	cin>>b;
	l1.find(b);
}