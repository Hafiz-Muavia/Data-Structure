#include <iostream>
using namespace std;

class Node {

	public:
       int data;
       Node* link;
        Node(int);
};
Node :: Node (int n){
          this->data = n;
          this->link = NULL;
}
class Stack {
       Node* top;
   public:
       Stack();
       void push(int);
       bool isEmpty ();
       bool isFull();
       int topp();
       void pop ();
       void display ();
};

 Stack::Stack() {
	        top = NULL; }
	        
 void  Stack::push(int data){
	        Node* temp = new Node (data);
            temp->data = data;
             temp->link = top;
             top = temp;
}
bool Stack::isEmpty (){
            if(top==NULL)
		     return true;
		     else
		     return false;
}

int Stack::topp(){
    	     if (!isEmpty ())
             return top->data;
         else{
         	 cout << "Stack is Empty.";
         	 return 0;
		 }
            
}
void Stack::pop (){
           if (isEmpty()) {
              cout << "Stack is Empty";
}
           else {
              Node* ptr = top;
                top = top->link;
                delete ptr;
}}
 void Stack::display (){
	         Node* temp;
        if (top == NULL) {
       cout << " There is no data in Stack ";
	    exit (1);
  }
       else {
           temp = top;
        while (temp != NULL) {
             cout <<"Data is:" << temp->data << endl;
             temp = temp->link;
        
}}
       cout << endl;}
       
 int main(){
      Stack s;
       int  num,choice;
        while (true) {
        int value;


        cout << "Enter value to push in Stack: ";
        cin >> value;

      s.push (value);

        cout << "Do you want to push another value? (1 for yes, 0 for no): ";
        cin >> choice;

        if (choice == 0) {
            break;
        }
    }
      
       s.display();

      cout << "Top element is " << s.topp() << endl;

     cout <<endl<< "\tBy calling pop function.." << endl;
        s.pop ();

       s.display();
        cout << "Top element is " << s.topp() << endl;
  return 0;
}