#include <iostream>//preprocessor directive
using namespace std;//standard library

class DOB{//class definition
	private://access specifier
		int year,day,month;//declarations
		public://access specifier
		DOB();//constructor declaration
		//functions' declarations
		void set();
		void get();
		DOB operator -(DOB a);//operator overloading's declaration
};//class ends
DOB::DOB(){//constructor
	this->year=this->day=this->month=0;//initialization
}
void DOB::set(){//setter function for input
	cout<<" as date/month/year: ";
	Date:
	cin>>this->day>>this->month>>this->year;
	if(month<1||month>12){//condition for month
		cout<<"Wrong input. Enter date again: ";//error
		goto Date;//goto statement
	}
	switch(month){
		case 1:
			if(day<0||day>31){//condition for days
				cout<<"Wrong input. Enter date again: ";//error
	        	goto Date;  //goto statement
			} 
			break;
		case 2:
			if(year%4==0&&year%100!=0||year%400==0){//condition for leap year
				if(day<0||day>29){//condition for days
				cout<<"Wrong input. Enter date again: ";//error
	        	goto Date;  //goto statement
			} 
			break;
			}
			else{
				if(day<0||day>28){//condition for days
				cout<<"Wrong input. Enter date again: ";//error
	        	goto Date; //goto statement
			} 
			break;
			}
			
		case 3:
			if(day<0||day>31){//condition for days
				cout<<"Wrong input. Enter date again: ";//error
	        	goto Date;  //goto statement
			} 
			break;
		case 4:
			if(day<0||day>30){//condition for days
				cout<<"Wrong input. Enter date again: ";//error
	        	goto Date;  //goto statement
			} 
			break;
		case 5:
			if(day<0||day>31){//condition for days
				cout<<"Wrong input. Enter date again: ";//error
	        	goto Date;  //goto statement
			} 
			break;
		case 6:
			if(day<0||day>30){//condition for days
				cout<<"Wrong input. Enter date again: ";//error
	        	goto Date ; //goto statement
			} 
			break;
		case 7:
			if(day<0||day>31){//condition for days
				cout<<"Wrong input. Enter date again: ";//error
	        	goto Date  ;//goto statement
			} 
			break;
		case 8:
			if(day<0||day>31){//condition for days
				cout<<"Wrong input. Enter date again: ";//error
	        	goto Date  ;//goto statement
			} 
			break;
		case 9:
			if(day<0||day>30){//condition for days
				cout<<"Wrong input. Enter date again: ";//error
	        	goto Date  ;//goto statement
			} 
			break;
		case 10:
			if(day<0||day>31){//condition for days
				cout<<"Wrong input. Enter date again: ";//error
	        	goto Date  ;//goto statement
			} 
			break;
		case 11:
			if(day<0||day>30){//condition for days
				cout<<"Wrong input. Enter date again: ";//error
	        	goto Date  ;//goto statement
			} 
			break;
		case 12:
			if(day<0||day>31){//condition for days
				cout<<"Wrong input. Enter date again: ";//error
	        	goto Date  ;//goto statement
			} 
			break;
	}
}
void DOB::get(){//getter function for output
	cout<<this->year<<" Years "<<this->month<<" Months "<<this->day<<" Days."<<endl;
}
DOB DOB::operator -(DOB a){//overloaded - operator
	if(a.year>year||(a.year==year&&a.month>month)||(a.year==year&&a.month==month&&a.day>day)){//condition for years
		cout<<"Date of birth is greater than current date. Not possible..."<<endl;//error
		DOB temp;
		temp.year=0;
		temp.day=0;
		temp.month=0;
		return temp;
	}
	else{
		DOB temp;//temporary object
	temp.year=this->year-a.year;
	if(a.month>this->month||(a.month==this->month&&a.day>this->day)){//condition for months to assign years
		temp.year--;
	}
	temp.month=this->month-a.month;
	if(a.day>this->day){//condition for days to assign months
		temp.month--;
	}
	if(temp.month<0){//condition for negative months
		temp.month+=12;
	}
	//Assigning days
	int days=0;
	switch(a.month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			days=31-a.day;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			days=30-a.day;
			break;
		case 2:
			if(a.month%4==0&&a.month%100!=0||a.month%400==0)//leap year
			days=29-a.day;
			else days=28-a.day;
			break;
	}
	    days+=this->day;
	    temp.day=days;
	    if(a.day<this->day){//condition for exceeding days
	  		 	switch(a.month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			temp.day-=31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			temp.day-=30;
			break;
		case 2:
			if(a.month%4==0&&a.month%100!=0||a.month%400==0)//leap year
			temp.day-=29;
			else temp.day-=28;
			break;
	}
		}
	return temp;//returning temporary object
	}
} 
int main(){//function where execution starts
	DOB cur_date,dob,age;//object creation memory allocation and constructor calls
	cout<<"Enter your Date of birth";
	dob.set();//dob data
	cout<<"Enter current date";
	cur_date.set();//current data
	cout<<"Your age is: ";
	age=cur_date-dob;//overloading - operator
	age.get();//actual age
	return 0;//control returns
}//program ends
