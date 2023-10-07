#include<iostream>
#include<conio.h>
using namespace std;
class list{
	private:
		int *ptr;
		int length;
		int size;
		int current;
	public:
		list(){
		}
		list(int);
		void add(int);
		void start();
		void tail();
		void next();
		void back();
		void print();	
		void copylist(list);
		int len();
		void pos(int);
		void insert(int,int);
		void search(int);
		void clear();
		void del(int);
		void update(int,int);
};
list::list(int i){
	if(i>0){
		length=i+1;
		current=0;
		size=0;
		ptr=new int[length];
		for(int j=0;j<length;j++){
			ptr[j]=-1;//shows block is still empty
		}
	}
}
void list::add(int value){
	if(current==length){
	cout<<"List is Full."<<endl;
	}
	else {
		ptr[++current]=value;
		size++;
	}
}
void list::start(){
	current=1;
}
void list::tail(){
	if(current==length){
		cout<<"Current is already at the end."<<endl;
	}
}
void list::next(){
	if(current==length){
		cout<<"Current is already at the end.Now it will be at start."<<endl;
		current=1;
	}
	else current++;
}
void list::back(){
	if(current==1){
		cout<<"Current is already at the start.Now it will be at tail."<<endl;
		current=length;
	}
	else current--;
}
void list::print(){
	cout<<"Output is: "<<endl;
	for(int i=1;i<=length;i++){
		cout<<"ptr["<<i<<"]="<<ptr[i]<<endl;
	}
}
void list::copylist(list l){
	length=l.length;
	size=l.size;
	current=l.current;
	for(int i=1;i<=length;i++){
		ptr[i]=l.ptr[i];
	}
}
int list::len(){
	return length;
}
void list::pos(int u){
	cout<<"Particular position is: ptr["<<u<<"]="<<ptr[u]<<endl;
}
void list::search(int u){
	int loc=-1;
	for(int i=1;i<=length;i++){
		if(ptr[i]==u){
			cout<<u<<" is present at index: "<<i<<endl;
			loc++;
		}
		
	}
	if(loc==-1){
			cout<<"Not in array."<<endl;
		}
}
void list::clear() {
        current = 0;
    size = 0;

    for (int j = 0; j <= length; j++) {
        ptr[j] = -1;
    }
    
    cout << "Cleared" << endl;
}
void list::del(int l){
	int j=length-l;
	int k=l;
    for(int i=1;i<=j;i++){
    	ptr[k]=ptr[k+1];
    	k++;
	}
	length--;
}
void list::update(int x,int y){
	ptr[x]=y;
}
void list::insert(int x,int y){
	int j,k,l;
	j=length+1-x;
	k=length;
	for(int i=1;i<=j;i++){
		ptr[k+1]=ptr[k];
		k--;
	}
	ptr[x]=y;
	length++;
}
int main()
{   int d;
	list a(3);
	a.print();
	a.add(55);
	a.start();
	a.back();
	a.add(20);
	a.add(20);
	a.next();
	a.add(45);
	a.next();
	a.add(40);
	a.next();
	a.next();
	a.add(69);
	
	a.print();
	list b(1);
	b.copylist(a);
	cout<<"B list"<<endl;
	b.print();
	cout<<"Length of a is: "<<a.len()<<endl;
	JKL:
	cout<<"Enter position you want to get: ";
	int v;
	cin>>v;
	if(v<1||v>a.len()){
		cout<<"Invalid. "<<endl;
		goto JKL;
	}
	a.pos(v);
	cout<<"Enter value you want to search: ";
	cin>>v;
	a.search(v);
	KKK:
	cout<<"Enter index at which you want to insert: ";
	cin>>v;
	if(v<1||v>a.len()){
		cout<<"Invalid. "<<endl;
		goto KKK;
	}
	cout<<"Enter value you want to insert: ";
	cin>>d;
	a.insert(v,d);
	cout<<"After inserting"<<endl;
	a.print();
    Jk:
	cout<<"Enter the index you want to delete: ";
	cin>>v;
	if(v<1||v>a.len()){
		cout<<"Invalid. "<<endl;
		goto Jk;
	}
	a.del(v);
	cout<<"After deleting"<<endl;
	a.print();
	JL:
	cout<<"At which index you want to update: ";
	cin>>v;
	if(v<1||v>a.len()){
		cout<<"Invalid. "<<endl;
		goto JL;
	}
	cout<<"Enter updated value: ";
	cin>>d;
	a.update(v,d);
	cout<<"After updating"<<endl;
	a.print();
	a.clear();
	cout<<"After clearing"<<endl;
	a.print();
	return 0;
}