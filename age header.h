#include<iostream>
using namespace std;

		int b_day,b_mon,b_year;
		int cur_day,cur_mon,cur_year;
		int p_mon;
	int days_per_mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
		
	
//	void setbirth_data(int b_day, int b_mon,int b_year);
//	void setcur_data(int cur_day,int cur_mon,int cur_year);
//	void check_birthdata();
//	void check_curdata();
//	int calc_year();
//	int calc_mon();
//	int calc_day();
//	void display();
//};

void setbirth_data(int day, int mon,int year){
	 b_day= day;
 b_mon= mon;
	 b_year= year;
	if(b_year % 4 ==0)
	days_per_mon[2]=29;
	

}

void setcur_data(int day, int mon,int year){
	 cur_day= day;
	 cur_mon= mon;
	 cur_year= year;
	if(cur_year % 4 ==0)
	days_per_mon[2]=29;
	

}

void check_birthdata(){
	
	if(b_year<1)
{
		cout<<"Error ! in birth year "<<endl;
exit(1);
}

	if (b_mon <1 || b_mon >12)
{
		cout<<"Error ! in birth month "<<endl;
exit(1);
}	

if( b_day> days_per_mon[b_mon])
{
		cout<<"Error ! in birth day "<<endl;
exit(1);
}	

	
}

check_curdata(){
	
	if(cur_year< b_year)
{
		cout<<"Error ! in current year "<<endl;
exit(1);
}

	if (cur_year==b_year && cur_mon <b_mon)
{
		cout<<"Error ! in current month "<<endl;
exit(1);
}	

if((cur_year==b_year && cur_mon == b_mon && cur_day<b_day)||( cur_day> days_per_mon[cur_mon]))
{
		cout<<"Error ! in current day "<<endl;
exit(1);
}	

	
}
int calc_year(){
	int years=0;
	years=cur_year-b_year;
	if(cur_mon<b_mon || (cur_mon==b_mon && cur_day<b_day))
	years--;
	
return years;
	}
	








int calc_mon(){
	int months=0;

months=cur_mon-b_mon;
if( cur_day<b_day)
months--;

if(months<0)
months+=12;

	return months;
}	
	

int calc_day(){
    
    int days=0;
days=cur_day-b_day;

if(days<0)
{
p_mon=b_mon-1;
if(p_mon==0)
{ p_mon=12;
days=days_per_mon[p_mon]+cur_day-b_day;}
else
days=days_per_mon[p_mon]+cur_day-b_day;
}

    return days;
}





void display(){
	
	int years,mon,days;
	
	years=calc_year();
	mon=calc_mon();
	days = calc_day();
	

	cout<<"YEARS : "<<years<<endl;
	cout<<"MONTHS : "<<mon<<endl;
	cout<<"DAYS : "<<days<<endl;
	
}


