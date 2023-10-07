#include <iostream>
using namespace std;

class node{
	private:
		int data;
		node* next;
	public:
		node(int);
		void setdata(int);
		int getdata();
		void setnext(node*);
		node* getnext();
		void showdata();
};
class stack{
	private:
		node* top;
	public:
		stack();
		void push(int);
		int pop();
		int topp();
		bool isempty();
		bool isfull();
		void display();
		void reverse(stack);
		node* toppp();
};
node::node(int d){
	setdata(d);
	next=NULL;
}
void node::setdata(int d){
	data=d;
}
int node::getdata(){
	return data;
}
void node::setnext(node* ptr){
	next=ptr;
}
node* node::getnext(){
	return next;
}
void node::showdata(){
	cout<<"Data is: "<<data<<endl;
}

stack::stack(){
	top=NULL;
}
void stack::push(int d){
	node* ptr=new node(d);
	if (isfull())
    {
        cout << "Stack Overflow Occurs";
        exit(1);
    }
	if(isempty()){
		top=ptr;
	}
	else{
		ptr->setnext(top);
		top=ptr;
	}
}
int stack::pop(){
	if(isempty()){
		cout<<"Stack is empty."<<endl;
		exit(1);
	}
	else {
	int val=top->getdata();
	node* ptr=top;
	top=top->getnext();
	delete ptr;
	return val;	
	}
}
int stack::topp(){
	if(isempty()){
		cout<<"Stack is empty."<<endl;
		exit(1);
	}
	else return top->getdata();
}
bool stack::isempty(){
	return top==NULL;
}
bool stack::isfull(){
	node* ptr=new node(1);
	if(ptr->getdata()==1){
	return 0;
	}
	else return 1;
}
void stack::display(){
	node* ptr=top;
	if(top==NULL){
		cout<<"Stack is empty."<<endl;
		exit(1);
	}
	else{
			
	while(ptr!=NULL){
		ptr->showdata();
		ptr=ptr->getnext();
	}
	}

}
void stack::reverse(stack s1){
	node* ptr=s1.toppp();
	while(ptr!=NULL){
		push(ptr->getdata());
		ptr=ptr->getnext();
	}
}
node* stack:: toppp(){
	return top;
}
int main(){
	stack s1,s2;
	int x;
    for(int i=1;i<=5;i++){
    	cout<<"Enter value: ";
    	cin>>x;
    	s1.push(x);
	}
	cout<<"Values in Stack 1 are:"<<endl;
	s1.display();
	s2.reverse(s1);
	cout<<"Values in Reversed Stack aka Stack 2 are:"<<endl;
	s2.display();
}
