#include <iostream>
using namespace std;

float meritt(int matric,int inter,int test){
	float a,b,merit;
	a=(((0.25*matric)+inter)*75)/((0.25*1100)+1100);
	b=(test*25)/100;
	merit=a+b;
	return merit;
}


