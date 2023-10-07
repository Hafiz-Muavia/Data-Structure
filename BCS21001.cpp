#include <iostream>//preprocessor directive
using namespace std;//standard library

class time{//class definition
	private://access specifier
		int hours,minutes,seconds;//declarations
	public://access specifier
		time();//constructor declaration
		//functions' declarations
		void get();
		void set();
		//operator overloading's declarations
		time operator +(time a);
		time operator -(time a);
};//class ends
time::time(){//constructor
	this->hours=this->minutes=this->seconds=0;//initialization
}
void time::set(){//setter function for input
	Hours:
	cout<<"Enter hours: ";
	cin>>hours;
	if(hours<0||hours>23){//condition for hours
		cout<<"Wrong input."<<endl;//error
		goto Hours;//gotostatement
	}
	Minutes:
	cout<<"Enter minutes: ";
	cin>>minutes;
	if(minutes<0||minutes>59){//condition for minutes
		cout<<"Wrong input."<<endl;//error
		goto Minutes;//goto statement
	}
	Seconds:
	cout<<"Enter seconds: ";
	cin>>seconds;
	if(seconds<0||seconds>59){//condition for second
		cout<<"Wrong input."<<endl;//error
		goto Seconds;//goto statement
	}
}
void time::get(){//getter function for output
	cout<<"Time is: "<<this->hours<<":"<<this->minutes<<":"<<this->seconds<<endl;
}
time time:: operator +(time a){//overloaded + operator
	time temp;
	temp.hours=this->hours+a.hours;
	if(temp.hours>23){//condition for exceeding
		temp.hours-=24;
	}
	temp.minutes=this->minutes+a.minutes;
	if(temp.minutes>59){//condition for exceeding
		temp.minutes-=60;
		temp.hours++;
	}
	temp.seconds=this->seconds+a.seconds;
	if(temp.seconds>59){//condition for exceeding
		temp.seconds-=60;
		temp.minutes++;
	}
	return temp;
}
time time:: operator -(time a){//overloaded - operator
	time temp;

	temp.seconds=this->seconds-a.seconds;
	if(temp.seconds<0){//condition for negative time
		temp.seconds+=60;
		temp.minutes--;
	}
		
	temp.minutes=this->minutes-a.minutes;
	if(temp.minutes<0){//condition for negative time
		temp.minutes+=60;
		temp.hours--;
	}
	temp.hours=this->hours-a.hours;
	if(temp.hours<0){//condition for negative time
		temp.hours+=24;
	}
	return temp;
}
int main(){//function where execution starts
	time a,b,c,d;//object creation memory allocation and constructor calls
	//calling setter functions
	a.set();
	b.set();
	//overloading operators
	c=a+b;
	d=a-b;
	//output
	cout<<"For A:- "<<endl;
	a.get();
	cout<<"For B:- "<<endl;
	b.get();
	cout<<"For C as C=A+B(Operator Overloading)"<<endl;
	c.get();
	cout<<"For D as D=A-B(Operator Overloading)"<<endl;
	d.get();
	return 0;//control returns
}//program ends