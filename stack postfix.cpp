#include <iostream>
#include <cmath>
using namespace std;
int check(int x,char c,int y){
	int z;
	switch(c){
				case '+':
					z=x+y;
					break;
				case '-':
					z=x-y;
					break;
				case '*':
					z=x*y;
					break;
				case '/':
					z=x/y;
					break;
				case '%':
					z=x%y;
					break;
				case '^':
					z=pow(x,y);
					break;
			}
			return z;
}

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
void postfix(stack &s){
	string hui;
	cout<<"Enter a string in postfix expression: ";
	cin>>hui;
	int i=hui.length();
	for(int j=0;j<i;j++){
		if(hui[j]>='0'&&hui[j]<='9'){
			int k=int(hui[j]-'0');
			cout<<k<<endl;
			s.push(k);
		}
		else{
			int x,y,z;
			x=s.pop();
			y=s.pop();
			z=check(y,hui[j],x);
			s.push(z);
			cout<<"push"<<z<<endl;
		}
	}
	cout<<"Value is: "<<s.pop()<<endl;
}
void prefix(stack &s){
	string hui;
	cout<<"Enter a string in prefix expression: ";
	cin>>hui;
	int i=hui.length();
	for(int j=i-1;j>=0;j--){
		if(hui[j]>='0'&&hui[j]<='9'){
			int k=int(hui[j]-'0');
			cout<<k<<endl;
			s.push(k);
		}
		else{
			int x,y,z;
			x=s.pop();
			y=s.pop();
			z=check(x,hui[j],y);
			s.push(z);
			cout<<"push"<<z<<endl;
		}
	}
	cout<<"Value is: "<<s.pop()<<endl;
}
void infix(stack &s){
	string hui;
	cout<<"Enter a string in infix expression: ";
	cin>>hui;
	int i=hui.length();
	for(int j=0;j<i;j++){
		if(hui[j]=='('){
			int k=j;
			char ch=hui[j];
			for(int m=k;ch!=')';k++){
				if(ch=='('){
					
				}
			}
		}
		if(hui[j]>='0'&&hui[j]<='9'){
			int k=int(hui[j]-'0');
			cout<<k<<endl;
			s.push(k);
		}
		else{
			int x,y,z;
			x=s.pop();
			y=s.pop();
			
			s.push(z);
			cout<<"push"<<z<<endl;
		}
	}
	cout<<"Value is: "<<s.pop()<<endl;
}

int main(){
	stack s;
	postfix(s);
	prefix(s);
	infix(s);
}
