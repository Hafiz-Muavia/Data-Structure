#include <iostream>
#include "LIST.h"
using namespace std;
int main(){
	list l1(3);
	l1.print();
	l1.add(55);
	l1.start();
	l1.back();
	l1.add(20);
	l1.add(20);
	l1.next();
	l1.add(45);
	l1.next();
	l1.add(40);
	l1.next();
	l1.next();
	l1.add(69);
	l1.print();
	list l2(1);
	l1.copylist(l1);
		cout<<"List l2:-"<<endl;
	l2.print();
	list l3(l1);
	cout<<"List l3:-"<<endl;
	l3.print();
}