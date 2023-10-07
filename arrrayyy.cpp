#include <iostream>
using namespace std;
class insert{
	private:
		int x[6]={1,2,3,4,44};
		int siz=5;
	public:
		void in();
		void out();
		void insert1(int,int);
		void remove(int);
};
void insert::in(){
	cout<<"Enter values: ";
	for(int i=0;i<siz;i++){
		cin>>x[i];
	}
}
void insert::out(){
	cout<<"Values are: ";
	for(int i=0;i<siz;i++){
		cout<<x[i]<<endl;
	}
}
void insert::insert1(int b,int z){
	
	//As location is b our loop will be like n-b
	int j=5-b;
	int k=5;
	for(int i=1;i<=j;i++){
		
		x[k]=x[k-1];
		k--;
	}
	siz++;
	x[b]=z;
}
void insert::remove(int q){
	int k=q;
	int lp=6-q;
	for(int i=1;i<=lp;i++){
		x[k]=x[k+1];
		k++;
		
	}
	siz--;
	
}
int main(){
	insert obj1;
	cout<<"Without insertion ";
	obj1.out();
	int y;
	cout<<"Enter position for insertion: ";
	cin>>y;
	
	cout<<"Enter value you want to insert: ";
	int aa;
	cin>>aa;
	obj1.insert1(y,aa);
	cout<<"Updated array will be: "<<endl;
    obj1.out();
    cout<<"Emter position to delete: ";
    cin>>y;
    obj1.remove(y);
    cout<<"After removal ";
    obj1.out();
}