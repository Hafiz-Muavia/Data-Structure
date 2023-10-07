#include<iostream>
using namespace std;
class node{
	int id;
	char Gen;
	node* next;
	 
	 public:
	 	node(int,char);
	 	void set_id(int );
	 	int get_id();
	 	void set_gender( char );
	 	char get_gender();
	 	void setnext(node* );
	 	node* getnext();
	 	void showdata();
	};
	
class list{
	node* head;
	node* current;
	int size;
	int tot_students;
	
	public:
		list();
		void add_node(int,char );
		void showlist();
		node* josophus();
		void find_CR_or_GR();
	};
int main(){
	list l1;
		
	cout<<"------------------------------------------------------"<<endl;
	l1.find_CR_or_GR();
	return 0;

}

node::node(int d,char gen){
	set_id(d);
	set_gender(gen);
	next= NULL;
	
}
void node::set_id(int d){
	id=d;
}
int node::get_id(){
	return id;
}
void node::set_gender(char gen){
	Gen=gen;
}
char node::get_gender(){
	return Gen;
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
	cout<<"STUDENT ID : "<<id<<" \t Gender : "<<Gen<<endl;
	
}
 list::list(){
 	size=0;
 	current= NULL;
 	head= NULL;
 	
 }
 void list::add_node(int d,char gen){
 	node* ptr= new node(d,gen);
 	if(size==0){
 		
 		head=ptr;
 		current=ptr;
 		current->setnext(head);
	 }
 	else
 	{
 		ptr->setnext(current->getnext()); /*bracket me current ka next pass krwaya jo ke null he, or ese hmari latest value ke next wale address pr null set hogya*/
 		current->setnext(ptr); /*or isme current value ke next address pr latest valueka address set kiya*/
 		current=ptr; /*latest value ko current value bnaya */
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
 node* list::josophus(){
 	int temp_size=size;
 	
node * ptr=head;
current=head;

for(int i=1;i<temp_size;i++){
	current=current->getnext();
	ptr->setnext(current->getnext());
	delete current;
	ptr=ptr->getnext();
	current=ptr;
	size--;
}
head=ptr;
return ptr;

 } 
 
 void list::find_CR_or_GR(){
 	node* ptr;
 	cout<<"Enter No of Students : ";
 	cin>>tot_students;

 	
 	for(int i=1;i<=tot_students;i++){
 		char gen;
 		cout<<"Enter Gender of "<<i<<" Student || M for Male & F for Female :";
 		cin>>gen;
 		add_node(i,gen);
	 }
	 showlist();
	 
 	ptr=josophus();
 	if(ptr->get_gender()=='m'|| ptr->get_gender()=='M')
 	cout<<"We've got a new CR.\n\t----Details----"<<endl;
 		else if(ptr->get_gender()=='f'|| ptr->get_gender()=='F')
 	cout<<"We've got a new GR.\n\t----Details----"<<endl;
 	else
 	cout<<"\tGENDER NOT SPECIFIED ! "<<endl;
 	showlist();
 }