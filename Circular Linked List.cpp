#include <iostream>//preprocessor directive
using namespace std;//standard library

class Node{//node class
	private:
		Node* prev;
		int data;
	    Node *Next;
	public:
		Node(int);
		void setdata(int);
		int getdata();
		void setnext(Node*);
		void setprev(Node*);
		Node* getnext();
		Node* getprev();
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
		Node* tail();
		void next();
		Node* back();
		void mid();
		void insert(int,int);
		void remove(int);
		void del(int);
		void reverse(list);
};
Node::Node(int d){
	prev=NULL;
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
void Node::setprev(Node* ptr){
	prev=ptr;
}
Node* Node::getprev(){
	return prev;
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
		ptr->setnext(head);
		ptr->setprev(head);
	}
	else{
		current=tail();
		ptr->setprev(current);
		ptr->setnext(current->getnext());
		current->setnext(ptr);
		head->setprev(ptr);
		current=ptr;
		
	}
	    size++;
}
void list::showlist(){
	Node* ptr=head;
	for(int i=1;i<=size;i++){
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
Node* list::tail(){
	Node* ptr=head;
	for(int i=1;i<size;i++)
	     ptr=ptr->getnext();
	current=ptr;
	return current;
}
void list::next(){
		current=current->getnext();
}
Node* list::back(){
	current=current->getprev();
	return current;
}
void list::insert(int a,int b){
	Node *ptr=new Node(b);
	if(a==1){
		head->setprev(ptr);
		ptr->setnext(head);
		head=ptr;
		current=tail();
		ptr->setprev(current);
		current->setnext(ptr);
		size++;
	}
	else if(a==size+1){
		current=head;
		for(int i=1;i<size;i++){
			current=current->getnext();
		}
		current->setnext(ptr);
		ptr->setprev(current);
		current=ptr;
		current->setnext(head);
		head->setprev(current);
		size++;
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
void list::remove(int a){
	if(a==1){
		Node* ptr=head;
		ptr=ptr->getnext();
		ptr->setprev(tail());
		delete head;
		head=ptr;
		tail();
		current->setnext(head);
		size--;
	}
	else if(a==size){
		Node* ptr=current=head;
		for(int i=1;i<a-1;i++){
			ptr=ptr->getnext();
			current=current->getnext();
		}
		ptr=ptr->getnext();
		current->setnext(head);
		head->setprev(current);
		delete ptr;
		size--;
	}
	else{
		Node *ptr=current=head;
		Node *ptr2;
		for(int i=1;i<a-1;i++){
			current=current->getnext();
			ptr=ptr->getnext();
		}
		ptr2=ptr;
		ptr2=ptr2->getnext();
		current=current->getnext();
		ptr->setnext(current->getnext());
		current=current->getnext();
		
		current->setprev(ptr);
		delete ptr2;
		size--;
	}
}
void list::del(int b){
	int l=-1;
	Node* ptr=head;
	Node* ptr2=ptr;
	for(int i=1;i<=size;i++){
		ptr2=ptr2->getnext();
		if(b==ptr->getdata()){
			l++;
			remove(i);
			i--;
		}
		ptr=ptr2;
		
	}
	if(l==-1){
		cout<<"Value not found."<<endl;
	}
}
void list::mid(){
	int j;
	if(size%2==0){
		j=(size+2)/2;		
	}
	else {
		j=(size+1)/2;
	}
	Node* ptr=head;
	for(int i=1;i<j;i++){
			ptr=ptr->getnext();
		}
		cout<<"Middle element is: "<<ptr->getdata()<<endl;
}
void list::reverse(list l1){
	Node* p=l1.tail();
	addnode(p->getdata());
	
	while(p!=l1.head){
		p=l1.back();
		addnode(p->getdata());
	}
}
int main(){//main function
	list l1;
	int a,b;
	l1.addnode(5);
	l1.addnode(7);
	l1.addnode(8);
	l1.addnode(3);
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
	cout<<"Enter the index at which you want to insert: ";
	sizeee3:
	cin>>a;
	if(a>0 && a<=l1.siz()+1){
		cout<<"Enter the value you want to insert: ";
		cin>>b;
		l1.insert(a,b);
	}
	else{
		cout<<"Invalid index. Enter again."<<endl;
		goto sizeee3;	
	}
	cout<<"List after insertion:"<<endl;
	l1.showlist();
	cout<<"Enter the index you want to delete: ";
	sizeee4:
	cin>>a;
	if(a>0 && a<=l1.siz()){
		l1.remove(a);
	}
	else{
		cout<<"Invalid index. Enter again."<<endl;
		goto sizeee4;	
	}
	cout<<"List after deletion:"<<endl;
	l1.showlist();
	cout<<"Enter the value you want to delete: ";
	cin>>b;
	l1.del(b);
	cout<<"List after deletion: "<<endl;
	l1.showlist();
	l1.mid();
	list l2;
	l2.reverse(l1);
	cout<<"After reverse: "<<endl;
	l2.showlist();
	return 0;
}