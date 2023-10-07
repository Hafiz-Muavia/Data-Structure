#include<iostream>
#include"age header.h"
#include"cgpa1.h"
#include<iomanip>
using namespace std;
class EXAM{
int bir_d,bir_m,bir_y;
		int c_day=17,c_mon=6,c_year=2023;
		
public:
	
	void age(){
		
		cout<<"ENTER BIRTH DAY : ";
		cin>>bir_d;
			cout<<"ENTER BIRTH MONTH : ";
		cin>>bir_m;
			cout<<"ENTER BIRTH YEAR : ";
		cin>>bir_y;
		
		
		
			setbirth_data(bir_d,bir_m,bir_y);
	setcur_data(c_day,c_mon,c_year);
	check_birthdata();
	check_curdata();
	display();
		
	}
	
	void cgpa_(){
		
		for(int sem=1;sem<=3;sem++){
	
		total_sub();
subject_set();

		display_marks();
		
		cout<<"\n\n---------------GPA OF "<<sem<<" SEMESTER = "<<fixed<<setprecision(2)<<GPA()<<endl;
		
	}
	show_CGPA();

		
	}
	
	
};



int main(){
	EXAM student[3];
	
	for(int i=1;i<3;i++){
	
	cout<<"---------------STUDENT <"<<i<<">--------------"<<endl;
	student[i].age();
	student[i].cgpa_();
}
	

	
	return 0;
}