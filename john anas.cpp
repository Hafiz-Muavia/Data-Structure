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
	public:
		list();
		void add_node(int );
		void showlist();
		void josophus();
	};
int main(){
	list l1;
	int no_of_boys;
	cout<<"Enter num of boys : ";
	cin>>no_of_boys;
	for(int i=1;i<=no_of_boys;i++){
	l1.add_node(i);}

	l1.showlist();
	l1.josophus();
	cout<<"------------------ OUR CR -------------------"<<endl;
	l1.showlist();

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
	cout<<"Boy No : "<<data<<endl;
	cout<<"His ID : "<<&data<<endl;
	cout<<"Next Boy ID : "<<next<<endl<<endl;
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
void list::josophus(){
    int t_size=size;
node* ptr=head;
node* temp=NULL;
current=head;
for(int i=1;i<t_size;i++){
    current=current->getnext();
    temp=current;

    current=current->getnext();

    ptr->setnext(current);

     ptr=current;
    delete[] temp;

    size--;
}
head=ptr;

}
