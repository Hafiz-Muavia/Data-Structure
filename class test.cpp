#include <iostream>
using namespace std;

class Node 
{
	private:
		int dataMember;
		Node* next;
		Node* back;
		public:
			Node();
			Node(int);
			void setdata(int);
			int getdata();
			void setnext(Node*);
			Node* getnext();
			void setback(Node*);
			Node* getback();
			void showdata();
};
Node::Node(){
	dataMember=0;
}
Node::Node(int d){
	setdata(d);
	next=nullptr;
	back=nullptr;
}

void Node::setdata(int d){
	dataMember=d;
}
void Node::setback(Node* ptr){
	back= ptr;
}
Node* Node::getback(){
	return back;
}
void Node::setnext(Node* ptr){
	next=ptr;
}
Node* Node::getnext(){
	return next;
}
void Node::showdata(){
	cout << "Data member is: " <<dataMember<<endl;
	cout<<"The address of next: " << next<<endl;
	cout<<"The address of back: "<< back<<endl;
	cout<<"The address of node itself is: "<< &dataMember<<endl;
	cout<<"..........."<<endl;
}
int Node::getdata(){
	return dataMember;}

class List 
{
	private:
		Node* head, *current;
		int size;	
		public:
			List();
			void showlist();
			void add(int);
			void get(int);
			void find(int);
			void deletepos(int);
			void addatlast(int);
			void mid();
			void tail();
};
List::List(){
	head=NULL;
	current=NULL;
	size=0;}
void List::showlist(){
	Node* pointer= head;
	for(int i =0; i<size; i++){
		pointer->showdata();
		pointer=pointer->getnext();
	}
}
	void List::add(int d){
		Node* newnode= new Node(d);
		if(head==NULL){
			head= newnode;
			current=newnode;
		}
		else
		{
			newnode->setnext(head);
			current->setnext(newnode);
			newnode->setback(current);
			current=newnode;
		}
		size++;
		
	}
	
	void List::find(int val){
		int position=0;
		bool found=false;
		Node* pointer=head;
		for(int i=0; i<size; i++){
		position++;
		if(pointer->getdata()==val){
			found=true;
			cout<<"Value found at position "<<position <<endl;
			break;
		}
		pointer=pointer->getnext();

	}
	if(found==false){
		cout<<"Value not found"<<endl;
	}
	}
	void List::addatlast(int d){
		Node* newnode= new Node(d);
		Node* pointer= head;
		for(int i =0; i<size-1; i++){
			pointer=pointer->getnext();
		}
		pointer->setnext(newnode);
		newnode->setnext(head);
		head->setback(newnode);
		newnode->setback(pointer);
		size++;
	}
	void List::get(int pos){
		Node* pointer= head;
		if(pos<0 ||pos>size){
			cout<<"Invalid position"<<endl;
			return;
		}
		for(int i =0; i< (size-pos); i++){
			pointer=pointer->getnext();
		}
		pointer->showdata();
	}
	void List::mid(){
		int position=size/2;
		Node* pointer = head;
		for(int i=0; i<position; i++){
			pointer=pointer->getnext();
			
		}
		cout<<"Value found in the mid is: "<<endl;
		pointer->showdata();
	}
	void List::deletepos(int pos){
		if(pos<0 ||pos>size){
			cout<<"Invalid position!"<<endl;
			return;
		}
		else if(pos==1){
			Node* pointer= head;
			pointer=pointer->getnext();
			tail();
			current->setnext(pointer);
			pointer->setback(current);
			delete[] head;
			head= pointer;
			size--;
		}
		else if( pos==size){
			Node* pointer= current;
			tail();
			pointer=pointer->getback();
			pointer->setnext(head);
			head->setback(pointer);
			delete[] current;
			current=pointer;
			size--;
			
		}
		else {
			Node* pointer= head;
			Node* pointer2 = head;
			for(int i=0; i<=(size-pos);i++){
				pointer= pointer->getnext();

			}
			current=pointer;
			pointer2= pointer;
			pointer2= pointer->getback();
			current = current->getnext();
			pointer2->setnext(current);
			current->setback(pointer2);
			delete[] pointer;
		size--;
			
		}
	}
	void List::tail(){
		Node* ptr= head;
		for(int i = 0; i<size-1;i++){
			ptr=ptr->getnext();
		}
		current=ptr;
	}
	int main(){
		int value, position, noofnodes;
		List first;
		cout<<"Enter the number of nodes you want to add: ";
		cin  >> noofnodes;
		for(int i = 0; i < noofnodes;i++){
			cout<<"Enter the value you want to add: ";
			cin>> value;
			first.add(value);
		}
		first.showlist();
		cout<<"Enter the value you want to find: ";
		cin>> value;
		first.find(value);
		cout<<"Enter the positon you want to get the value of: ";
		cin >> position;
		first.get(position);
cout<<"Enter the value you want to add at last node: ";
cin >>value;
first.addatlast(value);
		first.showlist();
first.mid();
	cout<<"Enter the position you want to delete at: ";
	cin>> position;
	first.deletepos(position);
	first.showlist();
	}