#include <iostream>//preprocessor directive
#include <iomanip>//for manipulators
using namespace std;//standard library
class result{//class definition
	private://access specifier
	    //private Declarations of data members
	    
		int marks[11];
		string names[11];
		int subject_no;
		float gpa[11];
		float grade_points[11];
		float credit_hours[11];
		int TotalCreditHours;
		int TotalGradePoints;
		float total_gpa;
	public://access specifier
	    //public declaration for member functions
		result();
		void in(int);
		void out(int);
		void gpa1();
		void GradePoints();
		void GPA();
		result operator +(result);
		void operator /(int);
		void insert();
		void deleted();
		void update();
};//class ends
//Definitions of member functions
result::result(){//constructor
    //initializations to zero
	this->marks[0]=0;
	this->names[0]='\0';
	this->subject_no=0;
	this->gpa[0]=0;
	this->grade_points[0]=0;
	this->credit_hours[0]=0;
}
void result::in(int sem_no){//for input
	Subjects:
		
	cout<<"How many subjects are in semester "<<sem_no<<": ";
	cin>>this->subject_no;
	if(this->subject_no<1||this->subject_no>7){//condition for subject numbers(can't exceed 6)
		cout<<"Invalid. Try again."<<endl;
		goto Subjects;//goto statement
	}
	
	cout<<"Enter marks for semester: "<<sem_no<<endl;
	for(int i=1;i<=this->subject_no;i++){
		//Names of subjects
		cout<<"subject_name["<<i<<"]: ";
		cin.ignore();
		getline(cin,this->names[i]);
		Marks:
			//Marks
		cout<<"marks["<<i<<"]: ";
		cin>>this->marks[i];	
		if(this->marks[i]<0||this->marks[i]>100){//condition for marks
			cout<<"Invalid Marks. Enter again: "<<endl;
			goto Marks;//goto statement
		}
		CH:
			//credit hours
		cout<<"credit_hours["<<i<<"]: ";
		cin>>this->credit_hours[i];
		if(this->credit_hours[i]<0){//condition for credit hours
			cout<<"Invalid Input. Enter again: "<<endl;
			goto CH;//goto statement
		}
	}
}
void result::out(int sem_no){//for output
	cout<<"Marks for semester "<<sem_no<<" are: "<<endl;
	cout<<"Subjects"<<setw(20-8)<<setfill(' ')<<"Marks"<<setw(20)<<setfill(' ')<<"Credit Hours"<<endl;
	for(int i=1;i<=this->subject_no;i++){
		cout<<this->names[i]<<setw(20-(names[i].size()))<<setfill(' ')<<this->marks[i]<<setw(20-2)<<setfill(' ')<<this->credit_hours[i]<<endl;
	}
	cout<<"GPA for Semester "<<sem_no<<" is: "<<this->total_gpa<<endl;
}
void result::gpa1(){//for gpa of individual subjects
	for(int i=1;i<=this->subject_no;i++){
		if(this->marks[i]>=85&&this->marks[i]<=100)
		    this->gpa[i]=4.0;
		else if(this->marks[i]>=80&&this->marks[i]<85)
		    this->gpa[i]=3.7;
		else if(this->marks[i]>=75&&this->marks[i]<80)
		    this->gpa[i]=3.3;
		else if(this->marks[i]>=70&&this->marks[i]<75)
		    this->gpa[i]=3.0;
		else if(this->marks[i]>=65&&this->marks[i]<70)
		    this->gpa[i]=2.7;
		else if(this->marks[i]>=61&&this->marks[i]<65)
		    this->gpa[i]=2.3;
		else if(this->marks[i]>=58&&this->marks[i]<61)
		    this->gpa[i]=2.0;
		else if(this->marks[i]>=55&&this->marks[i]<58)
		    this->gpa[i]=1.7;
		else if(this->marks[i]>=50&&this->marks[i]<55)
		    this->gpa[i]=1.0;
		else if(this->marks[i]>=0&&this->marks[i]<50)
		    this->gpa[i]=0.0;	
	}
}
void result::GradePoints(){//for grade points of individual subject as well as per semester
	this->TotalCreditHours=0;
	this->TotalGradePoints=0;
	for(int i=1;i<=this->subject_no;i++){
		this->grade_points[i]=this->gpa[i]*this->credit_hours[i];
		this->TotalGradePoints+=this->grade_points[i];
		this->TotalCreditHours+=this->credit_hours[i];
	}
}
void result::GPA(){//GPA per semester
	this->total_gpa=this->TotalGradePoints/float(this->TotalCreditHours);
}
result result::operator +(result t){//overloading + operator for adding gpa
	result temp;//temporary object
	temp.total_gpa=0;
	temp.total_gpa=this->total_gpa+t.total_gpa;
	return temp;
}
void result:: operator /(int t){//overloading / operator for dividing gpa
	result temp;
	temp.total_gpa=0;
    temp.total_gpa=this->total_gpa/3.0;
    cout<<"CGPA of 3 semesters are: "<<temp.total_gpa;
}
void result::insert(){//for insertion
	int ins;
	Indexing1:
	cout<<"Enter the index at which you want to insert: ";
	cin>>ins;
	if(ins<1||ins>this->subject_no+1){//condition for index
		cout<<"Invalid input. Try again."<<endl;
		goto Indexing1;
	}
	this->subject_no++;
	int k=this->subject_no;
	int j=this->subject_no-ins;
	for(int i=1;i<=j;i++){//loop for insertion
		this->marks[k]=this->marks[k-1];
		this->names[k]=this->names[k-1];
		k--;
	}
	//Insertion process
	cout<<"subject_name["<<ins<<"]: ";
		cin>>this->names[ins];
		Marks1:
		cout<<"marks["<<ins<<"]: ";
		cin>>this->marks[ins];	
		if(this->marks[ins]<0||this->marks[ins]>100){
			cout<<"Invalid Marks. Enter again: "<<endl;
			goto Marks1;
		}
		CH1:
		cout<<"credit_hours["<<ins<<"]: ";
		cin>>this->credit_hours[ins];
		if(this->credit_hours[ins]<0){
			cout<<"Invalid Input. Enter again: "<<endl;
			goto CH1;
		}
}
void result::deleted(){//for deletion
	int del;
	Deletion1:
	cout<<"Enter index you want to delete: ";
	cin>>del;
	if(del<1||del>this->subject_no){//condition for index
		cout<<"Invalid input. Try again."<<endl;
		goto Deletion1;
	}
	int k=del;
	int j=this->subject_no-del;
	this->subject_no--;
	for(int i=1;i<=j;i++){//loop for deletion
		this->marks[k]=this->marks[k+1];
		this->names[k]=this->names[k+1];
		k++;
	}
}
void result::update(){//for updation
	int upd;
	Updation1:
		cout<<"Enter index you want to update: ";
	cin>>upd;
	if(upd<1||upd>this->subject_no){//condition for index
		cout<<"Invalid input. Try again."<<endl;
		goto Updation1;
	}
	//updation process
	cout<<"subject_name["<<upd<<"]: ";
		cin>>this->names[upd];
		Marks2:
		cout<<"marks["<<upd<<"]: ";
		cin>>this->marks[upd];	
		if(this->marks[upd]<0||this->marks[upd]>100){
			cout<<"Invalid Marks. Enter again: "<<endl;
			goto Marks2;
		}
		CH2:
		cout<<"credit_hours["<<upd<<"]: ";
		cin>>credit_hours[upd];
		if(credit_hours[upd]<0){
			cout<<"Invalid Input. Enter again: "<<endl;
			goto CH2;
		}
}
int main(){//function where execution starts
	result Mavi[4];//object creation, memory allocation and constructor calls
	for(int i=1;i<4;i++){//loop for input 3 semesters
		Mavi[i].in(i);
	}
	for(int i=1;i<4;i++){
		//Calling member functions
		Mavi[i].gpa1();
		Mavi[i].GradePoints();
		Mavi[i].GPA();
	}
	for(int i=1;i<4;i++){//loop for individual output per semester
		Mavi[i].out(i);
	}
	Mavi[0]=Mavi[1]+Mavi[2]+Mavi[3];// overloading to add 3 gpa
	Mavi[0]/3;//overloading to divide addition by 3
	int y;
	Insertion://insertion process
	cout<<"Enter the semester in which you want to insert. Input 0 for no insertion.";
	cin>>y;
	switch(y){//for semesters
		case 0:
			cout<<"No insertion."<<endl;
			break;
		case 1:
			Mavi[1].insert();
			Mavi[1].gpa1();
		    Mavi[1].GradePoints();
		    Mavi[1].GPA();
			break;
		case 2:
			Mavi[2].insert();
			Mavi[2].gpa1();
		    Mavi[2].GradePoints();
		    Mavi[2].GPA();
			break;
		case 3:
			Mavi[3].insert();
			Mavi[3].gpa1();
		    Mavi[3].GradePoints();
		    Mavi[3].GPA();
			break;
		default:
			cout<<"Invalid Input. Try again."<<endl;
			goto Insertion;
			break;
	}
	if(y!=0){//if any insertion occurs
		cout<<"If you want more insertion, Type 1.";//more insertion
	    cin>>y;
	    if(y==1){
		    goto Insertion;
	    }
	    cout<<"Output after Insertion"<<endl;
	    for(int i=1;i<4;i++){
		Mavi[i].out(i);
	    }
	    Mavi[0]=Mavi[1]+Mavi[2]+Mavi[3];
	    Mavi[0]/3;
	}
	Deletion://deletion process
	cout<<"Enter the semester in which you want to delete subject. Input 0 for no deletion.";
	cin>>y;
	switch(y){//for semesters
		case 0:
			cout<<"No deletion."<<endl;
			break;
		case 1:
			Mavi[1].deleted();
			Mavi[1].gpa1();
		    Mavi[1].GradePoints();
		    Mavi[1].GPA();
			break;
		case 2:
			Mavi[2].deleted();
			Mavi[2].gpa1();
		    Mavi[2].GradePoints();
		    Mavi[2].GPA();
			break;
		case 3:
			Mavi[3].deleted();
			Mavi[3].gpa1();
		    Mavi[3].GradePoints();
		    Mavi[3].GPA();
			break;
		default:
			cout<<"Invalid Input. Try again."<<endl;
			goto Deletion;
			break;
	}
	if(y!=0){//if any deletion occurs
		cout<<"If you want more deletion, Type 1.";
	    cin>>y;
	    if(y==1){
		    goto Deletion;
	    }
	    cout<<"Output after Deletion"<<endl;
	    for(int i=1;i<4;i++){
		Mavi[i].out(i);
	    }
	    Mavi[0]=Mavi[1]+Mavi[2]+Mavi[3];
	    Mavi[0]/3;
	}
	Updation://updation process
	cout<<"Enter the semester in which you want to update subject. Input 0 for no updation.";
	cin>>y;
	switch(y){//for semesters
		case 0:
			cout<<"No updation."<<endl;
			break;
		case 1:
			Mavi[1].update();
			Mavi[1].gpa1();
		    Mavi[1].GradePoints();
		    Mavi[1].GPA();
			break;
		case 2:
			Mavi[2].update();
			Mavi[2].gpa1();
		    Mavi[2].GradePoints();
		    Mavi[2].GPA();
			break;
		case 3:
			Mavi[3].update();
			Mavi[3].gpa1();
		    Mavi[3].GradePoints();
		    Mavi[3].GPA();
			break;
		default:
			cout<<"Invalid Input. Try again."<<endl;
			goto Updation;
			break;
	}
	if(y!=0){//if any updation occurs
		cout<<"If you want more updation, Type 1.";
	    cin>>y;
	    if(y==1){
		    goto Updation;
	    }
	    cout<<"Output after Updation"<<endl;
	    for(int i=1;i<4;i++){
		Mavi[i].out(i);
	    }
	    Mavi[0]=Mavi[1]+Mavi[2]+Mavi[3];
	    Mavi[0]/3;
	}
	return 0;//control returns
}//program ends