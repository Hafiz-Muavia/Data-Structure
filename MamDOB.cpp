#include<iostream>
using namespace std;
int limit[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *m[13]={"null","January","February","March","April","May","June","July","August","September","October","November", "December"};
class date
{
	private:
			int day;
			int month;
			int year;
	public:
			date(int,int,int);
			void setDate(int,int,int);
			void setDay(int);
			void setMonth(int);
			void setYear(int);
			int getDay();
			int getMonth();
			int getYear();
			void printDate();
};
date::date(int d,int m,int y)
{
		
		setMonth(m);
		setYear(y);
		setDay(d);
}
void date::setDay(int d)
{
		day = ((d>=1&&d<=limit[this->getMonth()])?d:1);
		if(this->getYear()%4==0&&this->getMonth()==2)
			day=((d>=1&&d<=29)?d:1);
}
void date::setMonth(int m)
{
		month =((m>=1&&m<=12)?m:1);
}
void date::setYear(int y)
{
		year = ((y>=1900&&y<=2023)?y:1900);
}
int date::getDay()
{
		return day;
}
int date::getYear()
{
		return year;
}
int date::getMonth()
{
		return month;
}
void date::printDate()
{
		cout<<this->getDay()<<":"<<m[this->getMonth()]<<":"<<this->getYear()<<endl;
}
int main()
{
		cout<<"hello world"<<endl;
		date d(15,4,1983);
		d.printDate();
}
