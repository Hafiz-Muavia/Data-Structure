#include<iostream>
#include<string.h>
using namespace std;
const int max_size=5;
int stack_no=0;
class node{
	
	int val;
	node* next;
	

	 public:
	 	node(int);
	 
	 	void set_value( int );
	 	int get_value();
	 	void setnext(node* );
	 	node* getnext();
	 	void showdata();

	};

class list{
	node* head;
	node* current;
	node* tail;
	node* top;
	int size;


	public:
		list();
		void push(int );
		void showlist();
		void pop();
void top_();
void input();
void mul(list&,list&);
void reversee();

	};
int main(){
	list stack1,stack2,stack3;
	stack1.input();
stack1.showlist();
stack2.input();
stack2.showlist();
stack3.mul(stack1,stack2);
stack3.showlist();
stack3.reversee();
stack3.showlist();
 

	return 0;

}

node::node(int v){
	
	set_value(v);
	next= NULL;

}


void node::set_value(int v){
	val=v;
}
int node::get_value(){
	return val;
}
void node::setnext(node* ptr){

	next=ptr;
}
node* node::getnext()
{
	return next;
}
void node::showdata()
{
	cout<<"Value : "<<val<<endl;

}
 list::list(){
 	size=0;
 	current= NULL;
 	head= NULL;

 }
 void list::push(int v){
 	node* ptr= new node(v);
 	if(size==0){


 		current=ptr;
 		current->setnext(NULL);
 		top=ptr;
 		tail=ptr;
 		head=ptr;
	 }
 	else
 	{
 		ptr->setnext(current); /*bracket me current ka next pass krwaya jo ke null he, or ese hmari latest value ke next wale address pr null set hogya*/

 		current=ptr;/*latest value ko current value bnaya */
 		head=ptr;
 		top=ptr;
 		}
 		size++;
 }
 void list::showlist() {
 cout<<"----------------------Showlist----------------------"<<endl;
 	node* ptr=head;
 	for(int i=1;i<=size;i++){
 		ptr->showdata();
	ptr=ptr->getnext();
	 }

 }
void list ::pop(){
node* ptr=top;
if(ptr!=NULL)
{cout<<ptr->get_value()<<" has poped from stack "<<endl;  
     current=ptr;
ptr=ptr->getnext();
top=head=ptr;
size--;
delete current;
//current=ptr;
}

else
    cout<<"STACK UNDERFLOW ! "<<endl;

}
void list:: top_(){
if(top!=NULL){
   cout<<"\n\tTOP : "<<top->get_value()<<" is on top of stack "<<endl<<endl;
}
else
    cout<<"STACK LIMIT ENDED "<<endl;
}
void list::input(){
	
	
	
	++stack_no;
cout<<"\n\nEnter Values for "<<stack_no<<" stack : "<<endl;
	
	

	for(int i=1;i<=max_size;i++){
	
		int v;
		cout<<"Enter "<<i<<" value : ";
		cin>>v;
		push(v);
	}


}
void list::mul(list &s1,list &s2){
	cout<<"--------------------Multiplication Process------------------"<<endl;
	int mul_ans;
	node*ptr=s1.top;
	node*ptr2=s2.top;

	for(int i=1;i<=max_size;i++){
	
	mul_ans=(ptr->get_value() )*( ptr2->get_value()); /*isme stack1 or stack2 ki last value ke multiply ka ans as first value store hogi then same .....*/
	cout<<ptr->get_value()<<" * "<<ptr2->get_value()<<" = "<<mul_ans<<endl;
push(mul_ans);
ptr=ptr->getnext();
ptr2=ptr2->getnext();}
cout<<"--------------------AFTER Multiplication ------------------"<<endl;
}
void list::reversee(){
cout<<"---------------------AFTER REVERSING------------------"<<endl;
node* temp;


 node* ptr=head;
 current=ptr->getnext();
 ptr->setnext(NULL);


for(int i=1;i<size;i++){

        temp=current->getnext();
 current->setnext(ptr);
 ptr=current;
current=temp;
}
head=ptr;
top=head;
}

