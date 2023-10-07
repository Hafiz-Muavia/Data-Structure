#include<iostream>
using namespace std;
class node
{
		
		public:
			int data;
		    node *next;
			node(int);
			
};
 node :: node(int n)
{
	data=n;
	next=NULL;
}
class stack
{
	private:
		node*top;
		public:
			stack();
			void push(int);
			void display();
			int peek();
			void pop();
};
stack::stack()
{
	top=0;
}
void stack::push(int x)
{
	node*ptr=new node(x);
	ptr->data=x;
	ptr->next=top;
	top=ptr;
}
void stack::display()
{
	node*temp;
	temp=top;
	if(top==0)
	{
		cout<<"stack is empty"<<endl;
	}
	else
	{
		while(temp!=0)
		{
			cout<<"data is: "<<temp->data<<endl;
			temp=temp->next;
			
		}
	}
}
int stack::peek()
{
	if(top==0)
	{
		cout<<"stack is empty"<<endl;
	}
	else
	{
		cout<<"top value is: "<<top->data<<endl;
	}
}
void stack::pop()
{
	node *temp;
	temp=top;
	if(top==0)
	{
		cout<<"stack is empty"<<endl;
	}
	else
	{
		cout<<"value that we want to remove is: "<<top->data<<endl;
		top=top->next;
		delete temp;
	}
}
int main()
{
	stack s;
	int a,b;
	cout<<"how many value that you want to push: ";
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		cout<<"value on node"<<i<< endl;
        cin>>b;
        s.push(b);
	}
	s.display();
	s.peek();
	s.pop();
	s.pop();
    s.display();
}