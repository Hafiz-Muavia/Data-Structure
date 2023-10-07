#include<iostream>
#include<string.h>
using namespace std;
int stack_no=0;
class node{
	
	string name;
	node* next;
	

	 public:
	 	node(string);
	 
	 	void set_name( string );
	 	string get_name();
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
int num=3;

	public:
		list();
		void push(string );
		void showlist();
		void pop();
void top_();
void input();
void concatenate(list&,list&);
void reversee();

	};
int main(){
	list stack1,stack2,stack3;
	stack1.input();

stack2.input();

stack3.concatenate(stack1,stack2);
stack3.showlist();
stack3.reversee();
stack3.showlist();
 

	return 0;

}

node::node(string n){
	
	set_name(n);
	next= NULL;

}


void node::set_name(string n){
	name=n;
}
string node::get_name(){
	return name;
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
	cout<<"STUDENT NAME : "<<name<<endl;

}
 list::list(){
 	size=0;
 	current= NULL;
 	head= NULL;

 }
 void list::push(string n){
 	node* ptr= new node(n);
 	if(size==0){


 		current=ptr;
 		current->setnext(NULL);
 		//cout<<ptr->get_name()<<" has pushed into stack "<<endl;
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
 	//	cout<<ptr->get_name()<<" has pushed into stack "<<endl;
 		}
 		size++;
 }
 void list::showlist() {
 	node* ptr=head;
 	for(int i=1;i<=size;i++){
 		ptr->showdata();
	ptr=ptr->getnext();
	 }

 }
void list ::pop(){
node* ptr=top;
if(ptr!=NULL)
{cout<<ptr->get_name()<<" has poped from stack "<<endl;  
     current=ptr;
ptr=ptr->getnext();
top=head=ptr;
size--;
delete current;
}

else
    cout<<"STACK UNDERFLOW ! "<<endl;

}
void list:: top_(){
if(top!=NULL){
   cout<<"\n\tTOP : "<<top->get_name()<<" is on top of stack "<<endl<<endl;
}
else
    cout<<"STACK LIMIT ENDED "<<endl;
}
void list::input(){
	

	
	++stack_no;
	if(stack_no==1){
		
	for(int i=1;i<=num;i++){
	
		string nam;
		cout<<"Enter Name of "<<i<<" student : ";
		cin>>nam;
		push(nam);
	}
}
else if(stack_no==2){
		for(int i=1;i<=num;i++){
		string namee;
		cout<<"Enter Father Name of "<<i<<" student : ";
		cin>>namee;
		push(namee);
	}
}
}
void list::concatenate(list &student,list &father){
	
	string full_name;
	node*ptr=student.top;
	node*ptr2=father.top;

	
 
	for(int i=1;i<=num;i++){
	
	full_name=ptr->get_name()+" "+ ptr2->get_name(); /*isme stack1 or stack2 ki first value store hogi then 2nd then 3rd.....*/
	
push(full_name);
ptr=ptr->getnext();
ptr2=ptr2->getnext();}
}
void list::reversee(){
cout<<"---------------------AFTER REVERSING-------------"<<endl;
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

