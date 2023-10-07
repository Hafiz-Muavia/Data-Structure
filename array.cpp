#include <iostream>
using namespace std;
class insert{
	private:
		int x[7]={0,1,2,3,4,5};
		int siz=5;
	public:
		void in();
		void out();
		void insert1(int,int);
		void remove(int);
		void get(int);
		void update(int,int);
		void find(int);
		int sizee();
};
void insert::in(){
	cout<<"Enter values: ";
	for(int i=1;i<=siz;i++){
		cin>>x[i];
	}
}
void insert::out(){
	cout<<"Values are: ";
	for(int i=1;i<=siz;i++){
		cout<<"x["<<i<<"]="<<x[i]<<endl;
	}
}
void insert::insert1(int b,int z){
	siz++;
	int j=siz-b;
	int k=6;
	for(int i=1;i<=j;i++){	
		x[k]=x[k-1];
		k--;
	}
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
void insert::get(int a){
	cout<<"Particular position is: x["<<a<<"]="<<x[a]<<endl;
}
void insert::update(int a, int b){
	x[a]=b;
	cout<<"Updated value is: x["<<a<<"]="<<x[a]<<endl;
}
void insert::find(int a){
	int l=-1;
	for(int i=1;i<=6;i++){
		if(x[i]==a){
			l++;
			cout<<a<<" is being found at index "<<i<<" as x["<<i<<"]="<<x[i]<<endl;
		}
	}
	if(l==-1){
		cout<<"Not found."<<endl;
	}
}
int insert::sizee(){
	return siz;
}
int main(){
	insert obj1;
	cout<<"Without insertion ";
	obj1.out();
	int y;
	cout<<"Enter position for insertion: ";
	Pos1:
	cin>>y;
	if(y>5||y<1){
		cout<<"Error. Again input the position: ";
		goto Pos1;
	}
	cout<<"Enter value you want to insert: ";
	int aa;
	cin>>aa;
	obj1.insert1(y,aa);
	cout<<"Updated array will be: "<<endl;
    obj1.out();
    cout<<"Enter the position you want to get: ";
    Pos3:
    cin>>y;
    if(y>6||y<1){
		cout<<"Error. Again input the position: ";
		goto Pos3;
	}
	obj1.get(y);
	cout<<"Length of array before deletion is: "<<obj1.sizee()<<endl;
    cout<<"Enter position to delete: ";
    Pos2:
    cin>>y;
    if(y>6||y<1){
		cout<<"Error. Again input the position: ";
		goto Pos2;
	}
    obj1.remove(y);
    cout<<"After removal ";
    obj1.out();
    cout<<"Length of array after deletion is: "<<obj1.sizee()<<endl;
    cout<<"Enter the position you want to update: ";
    Pos4:
    cin>>y;
    if(y>5||y<1){
		cout<<"Error. Again input the position: ";
		goto Pos4;
	}
	cout<<"Enter value of updation: ";
	cin>>aa;
	obj1.update(y,aa);
	obj1.out();
	cout<<"Enter value you want to find: ";
	cin>>aa;
	obj1.find(aa);
	return 0;
}