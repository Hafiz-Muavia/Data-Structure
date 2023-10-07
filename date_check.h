#include <iostream>
using namespace std;

int date_check(int year,int month){
	int day;
	cout<<"Enter Date: ";
		d:
		cin>>day;
	switch(month){
		case 1:
			if(day<0||day>31){//condition for days
				cout<<"Wrong input. Enter date again: ";//error
	        	goto d;
			} 
			break;
		case 2:
			if(year%4==0&&year%100!=0||year%400==0){//condition for leap year
				if(day<0||day>29){//condition for days
				cout<<"Wrong input. Enter date again: ";//error
	        	goto d;
			} 
			break;
			}
			else{
				if(day<0||day>28){//condition for days
				cout<<"Wrong input. Enter date again: ";//error
	        	goto d;
			} 
			break;
			}
			
		case 3:
			if(day<0||day>31){//condition for days
				cout<<"Wrong input. Enter date again: ";//error
	        	
			} 
			break;
		case 4:
			if(day<0||day>30){//condition for days
				cout<<"Wrong input. Enter date again: ";//error
	        goto d;
			} 
			break;
		case 5:
			if(day<0||day>31){//condition for days
				cout<<"Wrong input. Enter date again: ";//error
	        goto d;
			} 
			break;
		case 6:
			if(day<0||day>30){//condition for days
				cout<<"Wrong input. Enter date again: ";//error
	        goto d;
			} 
			break;
		case 7:
			if(day<0||day>31){//condition for days
				cout<<"Wrong input. Enter date again: ";//error
	        goto d;
			} 
			break;
		case 8:
			if(day<0||day>31){//condition for days
				cout<<"Wrong input. Enter date again: ";//error
	        goto d;
			} 
			break;
		case 9:
			if(day<0||day>30){//condition for days
				cout<<"Wrong input. Enter date again: ";//error
	        goto d;	
			} 
			break;
		case 10:
			if(day<0||day>31){//condition for days
				cout<<"Wrong input. Enter date again: ";//error
	        goto d;
			} 
			break;
		case 11:
			if(day<0||day>30){//condition for days
				cout<<"Wrong input. Enter date again: ";//error
	        goto d;
			} 
			break;
		case 12:
			if(day<0||day>31){//condition for days
				cout<<"Wrong input. Enter date again: ";//error
	        	goto d;
			} 
			break;
		}
		return day;
}