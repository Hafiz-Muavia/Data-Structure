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
		void insert(int,int);
		void remove(int);
		void del(int);
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
void list::insert(int a,int b){
	Node *ptr=new Node(b);
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
		Node* ptr=head;
		for(int i=1;i<a-1;i++){
			ptr=ptr->getnext();
			
		}
		ptr->setnext(NULL);
		ptr=ptr->getnext();
		delete ptr;
		size--;
	}
	else{
		Node* ptr=current=head;
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
void list::del(int b){
	Node* ptr=head;
	for(int i=1;i<=size;i++){
		if(i==1&&b==ptr->getdata()){
			ptr=ptr->getnext();
			delete head;
			head=ptr;
			size--;
		}
		else if(i==size&&b==ptr->getdata()){
			Node* p=head;
			for(int j=1;j<size-1;j++){
				p=p->getnext();
			}
			p->setnext(NULL);
			p=p->getnext();
			delete p;
			size--;
		}
		else if(i!=1&&i!=size&&b==ptr->getdata()){
			Node* p=current=head;
			for(int j=1;j<i-1;j++){
			    p=p->getnext();
				current=current->getnext();	
			}
			p=p->getnext();
			current->setnext(p->getnext());
			delete p;
			size--;
		}
		else {
			cout<<"Value not find."<<endl;
		}
		ptr=ptr->getnext();
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
	return 0;
}