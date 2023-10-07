#include <iostream>
using namespace std;

class List
{
	public:
		int x[7];
		int size = 7;
		int pos,n;
        void set(int a);
        void get();
        float gpa_cal();
        void insert (int m);
        void remove (int q);
        void update(int a);
        
	};
	
int main()
{
	List sem1,sem2,sem3;
	sem1.set(1);
	sem2.set(2);
	sem3.set(3);
	float c1,c2,c3;
	//sem1.get();
	c1=sem1.gpa_cal();
	cout << "Gpa in semester 1 is: "<<c1<<endl;
	c2=sem2.gpa_cal();
	cout << "Gpa in semester 2 is: "<<c2<<endl;
	c3=sem3.gpa_cal();
	cout << "Gpa in semester 3 is: "<<c3<<endl;
	
    float	cgpa;
	cgpa = (c1+c2+c3)/3.0;
	cout << " total CGPA is: "<<cgpa<<endl;
	int t,y,g,s,b;
	cout << "Enter value you want to insert ";
	cin >> t;  
	sem1.insert(t);
    cout  << endl << "Enter the index at which you want to delete value: ";
	 cin >> y;
	sem1.remove(y);
	 cout  << endl << "Enter the index at which you want to update value: ";
	 cin >> g;
    sem1.update(g);
	
	
	
	return 0;
}

 void List::set(int a){
		cout << " Enter Marks for semester: " << a<< endl;
	x[0] =0;
	for (int i=1;i<size; i++){
	 cout <<"x ["  << i << "] : " ;
	 cin >>  x[i];;
	 }
}
void List::get(){
	cout << " Marks in each subject are :" << endl;
	for (int i=1;i<size; i++){
	 cout <<"x ["  << i << "] : " <<  x[i] << endl;
	 }	
}
float List:: gpa_cal()	{
	    // for each semester 
	            float gp;
				float ch=0.0, sum=0.0;
				for(int i=1; i<7; i++){
					
				if(x[i]>=85)
				ch=4;
				else if(x[i]>=80)
				ch=3.7;
				else if(x[i]>=75)
				ch=3.3;
				else if(x[i]>=70)
				ch=3.0;
				else if(x[i]>=65)
				ch=2.7;
				else if(x[i]>=61)
				ch=2.3;
				else if(x[i]>=58)
				ch=2.0;
				else if(x[i]>=55)
				ch=1.70;
				else if(x[i]>=50)
				ch=1.0;
				else
				ch=0.0;
				
				sum=sum+ch*3.0;
				
				}
				gp=sum/18.0;
				return gp;
			}
			
void  List ::insert (int m){
	size  = 7;
	POS1:
	cout  << endl << "Enter the index at which you want to insert value: ";
	 cin >> pos;
	 
	 if (pos>size){
	 	cout << "Invalid position.Again enter: " << endl;
		 goto POS1;}
	 
	 n = size-pos;
     int k=6;
	 for ( int i = 1;i<=n;i++){
	 	
	 	x[k] = x[k-1];
	k--;
	 }
	 x[pos]=m;
	 
	 for (int i=1;i<size; i++){
	 cout <<"x ["  << i << "] : " <<  x[i] << endl;
	 }
}
void List ::remove (int q){

	 
	 if (q>size){
	 	cout << "Invalid position" << endl;}
	 
	 n = size-q;
     
	 for ( int i = 1;i<=n;i++){

	 	x[q]= x[q+1];
	q++;
	 }
	 
	size--;
	x [6] = 0;
	for (int i=1;i<=size; i++){
	 cout <<"x ["  << i << "] : " <<  x[i] << endl;
	 }
}

void List:: update(int a){
	int upd;
	if (a>size){
	 	cout << "Invalid position" << endl;
		}
	 cout << "Enter value you want to update ";
	 cin >> upd;
	 
	 x[a]=upd;
	 for (int i=1;i<size; i++){
	 cout <<"x ["  << i << "] : " <<  x[i] << endl;
	 }
}

