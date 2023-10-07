#include <iostream>
using namespace std;

class node{
	private:
		int sr;
		char ch;
		string name;
		node* next;
	public:
		node(int, char, string);
	    void setdata(int, char, string);
	    int getdata();
	    void setnext(node*);
	    node* getnext();
	    void showdata();
};
class list{
	private:
		node* head;
		node* current;
		int size;
	public:
		list();
	    void addnode(int, char, string);
		void j();
		void showlist();	
};
    node::node(int sr, char ch, string name){
    	setdata(sr, ch, name);
    	next=NULL;
	}
void node::setdata(int sr, char ch, string name){
	this->sr=sr;
	this->ch=ch;
	this->name=name;
}	
int node::getdata(){
	return sr;
}
void node::setnext(node* ptr){
	next=ptr;
}
node* node::getnext(){
	return next;
}  
void node::showdata(){
	cout<<"Sr no is: "<<sr<<endl;
	cout<<"Name is: "<<name<<endl;
}
list::list(){
	head=NULL;
    current=NULL;
    size=0;
}
void list::addnode(int sr, char ch, string name){
	node* ptr=new node(sr,ch,name);
	if(size==0){
		head=ptr;
		current=ptr;
		head->setnext(head);
	}
	else {
	ptr->setnext(current->getnext());
	current->setnext(ptr);
	current=ptr;
}
         size++;
}
void list::showlist()
    {
    	node* ptr=head;
    	for(int i=1; i<=size; i++){
    	ptr->showdata();
    	ptr=ptr->getnext();
	}
}
void list::j(){
	    node* ptr=head;
	    current=head;
	    while(size>1){
	    	ptr=ptr->getnext();
	    	current->setnext(ptr->getnext());
	    	delete ptr;
	    	size--;
	    	current=current->getnext();
	    	ptr=current;
		}
		head=current;
}
void input(list &l1, list &l2){
	string name;
	char ch;
	for(int i=1; i<=5; i++){
		out:
			cout<<"Enter name of student: "<<i<<endl;
			cin>>name;
			cout<<"Enter gender('M' for Male & 'F' for Female)"<<endl;
			cin>>ch;
			if(ch=='M' || ch=='m'){
				l1.addnode(i,ch,name);
			}
		    else if(ch=='F' || ch=='f'){
				l2.addnode(i,ch,name);
			}
			else{
			cout<<"Error. Enter again"<<endl;
			goto out;
	}
}
}
int main(){
	list l1,l2;
	input(l1,l2);
	l1.j();
	l2.j();
	cout<<"Cr is...."<<endl;
	l1.showlist();
	cout<<"Gr is...."<<endl;
	l2.showlist();
	return 0;
}
