#include<iostream>
using namespace std;
class list
{
	private:
		int *ptr;
		int length;
		int size;
		int current;
	public:
		list(int);
		void add(int);
		void start();
		void tail();
		void print();
		void next();
		void back();
};
list::list(int l)
{
	if(l>0)
	{
		length =l+1;
		current =0;
		size=0;
		ptr= new int[length];
		for (int i=0; i<length;i++)
		{
			ptr[i]= -1;
		}
	}
}
void list::add(int value)
{
	if(current==length)
	{
		cout<<"List is full";
	}
	else
	ptr[++current]= value;
	size++;
}
void list::start()
{
	current =1;
}
void list::tail()
{
	current == size;
}
void list::next()
{
	if(current!= length)
	current = ++current;
}
void list::back()
{
	if(current!= length)
	current = --current;
}