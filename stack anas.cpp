#include<iostream>
using namespace std;
const int max_size=3;
class Stack{
	private:
		int top;
		int arr[max_size];
	public:
		Stack();
		void push(int);
		void pop();
		void topValue();
		bool isEmpty();
		void showlist();
	
};

Stack ::Stack(){
	top=-1;
}

void Stack:: push(int val){
	if(top>=max_size-1){
		cout<<"\tStack OverFlow ! "<<endl;
	}
else{

arr[++top]=val;
cout<<arr[top]<<"^ pushed onto Stack "<<endl;
}
}
void Stack ::pop(){
	if(top<0){
		cout<<"\tStack UnderFlow ! "<<endl;
	}
	else
	{
	
	
	cout<<arr[top--]<<"^ popped from Stack "<<endl;}
}
void Stack::topValue(){
	if(top<0)
	cout<<"Can't get Top Value 'UnderFlow issue ! "<<endl;
else
{

cout<<"Top Value : "<<arr[top]<<endl;
}}
 bool  Stack::isEmpty(){
 
 	return (top<0);/*agr stack empty hui ,means top me -1 hi hua to hmari condition true hojaegi or udr yes hojaega|| otherwise no hojaega*/
 //	return 1;/*Ans yes hoga ku ke 1 represent krta true(beshk -1 ho) ko or 0 false ko*/
 }
 void Stack::showlist(){
 	cout<<"--------------------Showing Stack Values--------------------------"<<endl;
 	for(int i=0;i<max_size;i++){
 		cout<<i<<"-index value : "<<arr[i]<<endl;
	 }
 }
 int main(){
 	Stack obj1;
 	
 	
 	obj1.push(5);
 	obj1.push(10);
 	obj1.push(15);
 	obj1.push(20);
 	
 	obj1.pop();
 	obj1.topValue();/*Latest value from last*/
 
 	
 	obj1.showlist();
 	cout<<"Is Stack Empty ? "<<(obj1.isEmpty()? "Yes" : "No")<<endl;/*agr udr se  -1 aya to condition true (means yes display hoga) otherwise else statment(No display hoga)*/
 	
 }