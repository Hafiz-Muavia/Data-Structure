#include<iostream>
#include<string>
#include<stack>
#include<math.h>
using namespace std;

class Stack {
private:
    int top;
    char arr[50];
    int op_arr[20];
public:
    Stack() {
        top = -1;
    }

    void push(char);
     void push(int);
    void pop();
    char top_();
    int op_top_();
    int Empty();
    int prec(char c);
    string infix_to_postfix(string );
    int postfix_evaluation(string );
};

void Stack::push(char ch) {

    arr[++top] = ch;
}
void Stack::push(int operand) {

    op_arr[++top] = operand;
    
}
void Stack::pop() {
    if (top >= 0) {
        top--;
    }
}

char Stack::top_() {
    return arr[top];
}
int Stack::op_top_() {
    return op_arr[top];
}
int Stack::Empty() {
    if (top < 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int Stack::prec(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1; // Consider other characters as having the lowest precedence
}
string Stack::infix_to_postfix(string s) {
    Stack stk;
    string postfix;

    for (int i = 0; i < s.length(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            postfix += s[i];
        }
        else if (s[i] == '(') {
            stk.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!stk.Empty() && stk.top_() != '('  ) {
                postfix += stk.top_();
                stk.pop();
            }
            if (!stk.Empty() && stk.top_() == '(') {
                stk.pop();
            }
        }
        else {
            while (!stk.Empty() && (prec(stk.top_()) >= prec(s[i]) && stk.top_() != '(')) {

                postfix += stk.top_();
                stk.pop();
            }
            stk.push(s[i]);
        }
    }
    while (!stk.Empty()) {

        postfix += stk.top_();

        stk.pop();
    }
    return postfix;
}
int Stack::postfix_evaluation(string s){
	Stack st;
	
	
	for(int i=0;i<s.length();i++){
		
		if(s[i]>='0' && s[i]<='9' ){
			st.push(s[i]-'0'); //passing character as an integer
		}
		else{
			int operand2 = st.op_top_();
			st.pop();
			int operand1 = st.op_top_();
			st.pop();
			
			
			switch(s[i]){
				
				case '+':
					st.push(operand1+operand2);
					break;
				
				case '-':
					st.push(operand1-operand2);
					break;
				
				case '*':
					st.push(operand1*operand2);
					break;
				
				case '/':
					st.push(operand1/operand2);
					break;
				
				case '^':
					int temp=pow(operand1,operand2);
					
					st.push(temp);
					break;
			}
		}
	}
	
	return st.op_top_();
	
	
	
}

int main() {
    Stack s1;
    string infix;
    string postfix;
    cout <<"Infix Expression :((6-(2+3))*(3+8/2)^2+3) \nPostfix Expression : "<< s1.infix_to_postfix("((6-(2+3))*(3+8/2)^2+3)") << endl;
    	cout<<"Postfix Expression Evaluation : "<<s1.postfix_evaluation("623+-382/+2^*3+")<<endl;
   
   
    cout<<"\n------That was My Expression-----\n\nNow Enter your infix expression to convert it into Postfix : ";
    cin>>infix;
        cout <<"\nInfix Expression : "<<infix<<endl;
		postfix= s1.infix_to_postfix(infix) ;
		cout <<"\nPostfix Expression : "<<postfix<<endl;
		
		cout<<"Postfix Expression Evaluation : "<<s1.postfix_evaluation(postfix)<<endl;
    return 0;
}
