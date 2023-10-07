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
		void insertL(int,int);
		void search(int);
		void clear();
		void del(int);
		void updateL(int,int);
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
		this->ptr[i]=l.ptr[i];
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
void list::updateL(int x,int y){
	ptr[x]=y;
}
void list::insertL(int x,int y){
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