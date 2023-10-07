#include<iostream>
using namespace std;
class node{
	int data;
	node* next;
	 
	 public:
	 	node(int);
	 	void setdata(int );
	 	int getdata();
	 	void setnext(node* );
	 	node* getnext();
	 	void showdata();
	};
	
class list{
	node* head;
	node* current;
	int size;
	int no_of_boys;
	int no_of_girls;
	public:
		list();
		void add_node(int );
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

node::node(int d){
	setdata(d);
	next= NULL;
	
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
node* node::getnext()
{
	return next;
}
void node::showdata() 
{
	cout<<"STUDENT NO      : "<<data<<endl;
	cout<<"STUDENT ID      : "<<&data<<endl;
	cout<<"NEXT STUDENT ID : "<<next<<endl<<endl;
}
 list::list(){
 	size=0;
 	current= NULL;
 	head= NULL;
 	
 }
 void list::add_node(int d){
 	node* ptr= new node(d);
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
 	cout<<"Enter No of Boys : ";
 	cin>>no_of_boys;
	 cout<<"Enter No of Girls : ";
 	cin>>no_of_girls;
 	
 	for(int i=1;i<=(no_of_boys + no_of_girls);i++){
 		add_node(i);
	 }
	 showlist();
	 
 	ptr=josophus();
 	if(ptr->getdata()<=no_of_boys)
 	cout<<"AND The AWARD GOES TO ONE & ONLY CR \n --Student no : "<<ptr->getdata()<<"\t ID : "<<ptr<<endl;
 	if(ptr->getdata()>no_of_boys )
 	cout<<"AND The AWARD GOES TO ONE & ONLY GR \n --Student no : "<<ptr->getdata()<<"\t ID : "<<ptr<<endl;
 }