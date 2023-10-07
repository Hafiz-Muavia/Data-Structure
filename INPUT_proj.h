#include <iostream>
#include "DOB.h"
#include "merit_proj.h"
#include "Project1.h"
#include "date_check.h"
using namespace std;

void input(list& bba,list& IT,list& comm, list& law, list& eng, list quota){
	int i=1,j=1;
	int matric,inter,test,day,month,year,day1,month1,year1,age;
	string name,s_o,dept,email,province,city,inter_type;
	long long int ph,cnic,s_o_cnic;
	float merit;
	while(i==1){
		int x,y;
		cout<<"*********************Student: "<<j++<<"*********************"<<endl;
		cout<<"Enter Name: ";
		cin.ignore();
		getline(cin,name);
		cout<<"Enter Father's Name: ";
		getline(cin,s_o);
		cout<<"From which Province you belong?"<<endl;
		pro:
		cout<<"Press: \n1 for Punjab\n2 for Sindh\n3 for Balochistan\n4 for KPK\n5 for Gilgit"<<endl;
		cin>>x;
		switch(x){
			case 1:
				province="Punjab";
				break;
			case 2:
				province="Sindh";
				break;
			case 3:
				province="Balochistan";
				break;
			case 4:
				province="KPK";
				break;
			case 5:
				province="Gilgit";
				break;
			default:
				cout<<"Invalid choice. Enter again."<<endl;
				goto pro;
		}
		cout<<"Enter City: ";
		cin.ignore();
		getline(cin,city);
		cout<<"Enter Date of Birth."<<endl;
		cout<<"Enter Year: ";
		cin>>year;
		if(year<2000){
			cout<<"Your age limit has been reached. You cannot get admission in University of the Punjab, Gujranwala Campus."<<endl;
			j--;
			continue;
		}
		cout<<"Enter Month: ";
		m:
		cin>>month;
		if(month<1||month>12){
			cout<<"Invalid Month.Enter month again."<<endl;
			goto m;
		}
		day=date_check(year,month);		
		cout<<"Enter Current Date."<<endl;
	    cout<<"Enter Year: ";
	    yy:
		cin>>year1;
		if(year1<2023){
			cout<<"Invalid Year.Enter year again."<<endl;
			goto yy;
		}
		cout<<"Enter Month: ";
		mm:
		cin>>month1;
		if(month1<1||month1>12){
			cout<<"Invalid Month.Enter month again."<<endl;
			goto mm;
		}
		day1=date_check(year1,month1);
		DOB dob,cur_date,AGE;
		cur_date.set(day1,month1,year1);
		dob.set(day,month,year);
		AGE=cur_date-dob;
		age=AGE.getyear();
		cout<<"In which Department you want to study?"<<endl;
		dep:
		cout<<"Press 1 for IT \nPress 2 for Law\nPress 3 for BBA\nPress 4 for Commerce\nPress 5 for English "<<endl;
		cin>>y;
		switch(y){
			case 1:
				dept="IT";
				break;
			case 2:
				dept="Law";
				break;
			case 3:
				dept="BBA";
				break;
			case 4:
				dept="Commerce";
				break;
			case 5:
				dept="English";
				break;
			default:
				cout<<"Invalid choice. Enter again."<<endl;
				goto dep;
		}
		cout<<"Enter email: ";
		cin.ignore();
		getline(cin,email);
		cout<<"Enter CNIC: ";
		cin>>cnic;
		cout<<"Enter Father's CNIC: ";
		cin>>s_o_cnic;
		cout<<"Enter phone number: ";
		cin>>ph;
		cout<<"Enter Test Marks: ";
		cin>>test;
		cout<<"Enter Matric Marks: ";
		cin>>matric;
		cout<<"Enter Intermediate Marks: ";
		cin>>inter;
		cout<<"Which field you studied in Intermediate? Press: "<<endl;
		intr: 
		cout<<"1 for FSc Pre Medical\n2 for FSc Pre Engineering\n3 for ICS Physics\n4 for ICS Statistics\n5 for I.Com"<<endl;
		cin>>x;
		switch(x){
			case 1:
				inter_type="FSc Pre Medical";
				break;
			case 2:
				inter_type="FSc Pre Engineering";
				break;
			case 3:
				inter_type="ICS Physics";
				break;
			case 4:
				inter_type="ICS Statistics";
				break;
			case 5:
				inter_type="I.Com";
				break;
			default:
				cout<<"Invalid choice. Enter again."<<endl;
				goto intr;
		}
		merit=meritt(matric,inter,test);
	if(merit<60){
		cout<<"You are not eligible as your merit is too low. You cannot get admission in University of the Punjab, Gujranwala Campus."<<endl;j--;
		continue;
	}
	cout<<"In which category you are applying for? Press: "<<endl;
	mer:
	cout<<"1 for Open Merit\n2 for Reserved Quota\n3 for Sports Man\n4 for Out of Province"<<endl;
	cin>>x;
	if(x==1){
	int oo=-1;
		switch(y){
				case 1:
					if(IT.siz()==0){
						IT.addnode(name,s_o,province,city,age,day,month,year,dept,email,ph,cnic,s_o_cnic,matric,inter,test,merit,inter_type);
						oo++;
					}
					else{
						node* ptr=IT.start();
						for(int z=1;z<=IT.siz();z++){
							if(ptr->getmerit()<merit){
								IT.insert(z,name,s_o,province,city,age,day,month,year,dept,email,ph,cnic,s_o_cnic,matric,inter,test,merit,inter_type);
								oo++;
								break;
							}
							ptr=ptr->getnext();
						}
					}
					if(oo==-1){
						IT.addnode(name,s_o,province,city,age,day,month,year,dept,email,ph,cnic,s_o_cnic,matric,inter,test,merit,inter_type);
					}
					break;
				case 2:
					if(law.siz()==0){
						law.addnode(name,s_o,province,city,age,day,month,year,dept,email,ph,cnic,s_o_cnic,matric,inter,test,merit,inter_type);
						oo++;
					}
					else{
						node* ptr=law.start();
						for(int z=1;z<=law.siz();z++){
							if(ptr->getmerit()<merit){
								law.insert(z,name,s_o,province,city,age,day,month,year,dept,email,ph,cnic,s_o_cnic,matric,inter,test,merit,inter_type);
								oo++;
								break;
							}
							ptr=ptr->getnext();
						}
					}
					if(oo==-1){
						law.addnode(name,s_o,province,city,age,day,month,year,dept,email,ph,cnic,s_o_cnic,matric,inter,test,merit,inter_type);
					}
					break;
				case 3:
					if(bba.siz()==0){
						bba.addnode(name,s_o,province,city,age,day,month,year,dept,email,ph,cnic,s_o_cnic,matric,inter,test,merit,inter_type);
						oo++;
					}
					else{
						node* ptr=bba.start();
						for(int z=1;z<=bba.siz();z++){
							if(ptr->getmerit()<merit){
								bba.insert(z,name,s_o,province,city,age,day,month,year,dept,email,ph,cnic,s_o_cnic,matric,inter,test,merit,inter_type);
								oo++;
								break;
							}
							ptr=ptr->getnext();
						}
					}
					if(oo==-1){
						bba.addnode(name,s_o,province,city,age,day,month,year,dept,email,ph,cnic,s_o_cnic,matric,inter,test,merit,inter_type);
					}
					break;
				case 4:
					if(comm.siz()==0){
						comm.addnode(name,s_o,province,city,age,day,month,year,dept,email,ph,cnic,s_o_cnic,matric,inter,test,merit,inter_type);
						oo++;
					}
					else{
						node* ptr=comm.start();
						for(int z=1;z<=comm.siz();z++){
							if(ptr->getmerit()<merit){
								comm.insert(z,name,s_o,province,city,age,day,month,year,dept,email,ph,cnic,s_o_cnic,matric,inter,test,merit,inter_type);
								oo++;
								break;
							}
							ptr=ptr->getnext();
						}
					}
					if(oo==-1){
						comm.addnode(name,s_o,province,city,age,day,month,year,dept,email,ph,cnic,s_o_cnic,matric,inter,test,merit,inter_type);
					}
					break;
				case 5:
					if(eng.siz()==0){
						eng.addnode(name,s_o,province,city,age,day,month,year,dept,email,ph,cnic,s_o_cnic,matric,inter,test,merit,inter_type);
						oo++;
					}
					else{
						node* ptr=eng.start();
						for(int z=1;z<=eng.siz();z++){
							if(ptr->getmerit()<merit){
								eng.insert(z,name,s_o,province,city,age,day,month,year,dept,email,ph,cnic,s_o_cnic,matric,inter,test,merit,inter_type);
								oo++;
								break;
							}
							ptr=ptr->getnext();
						}
					}
					if(oo==-1){
						eng.addnode(name,s_o,province,city,age,day,month,year,dept,email,ph,cnic,s_o_cnic,matric,inter,test,merit,inter_type);
					}
					break;
			}
	}
	else if(x==2||x==3||x==4){
		quota.addnode(name,s_o,province,city,age,day,month,year,dept,email,ph,cnic,s_o_cnic,matric,inter,test,merit,inter_type);
	}
	else{
		cout<<"Invalid Choice. Again Press:"<<endl;
			goto mer;
	}
	cout<<"For another student, press 1: ";
	cin>>i;
	}
	IT.showlist();
	IT.delptr();
	bba.delptr();
	comm.delptr();
	eng.delptr();
	law.delptr();
	quota.delptr();
}

