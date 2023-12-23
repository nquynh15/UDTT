#include<bits/stdc++.h>

using namespace std;
int Ucln(int a, int b)
{
	if(a*b == 0){
		return a;
	}
	while(a!= b){
		if(a>b)			a -= b;
		else		b -= a;
	}
	return a;
}
int UclnC2(int a, int b){
	while(a*b != 0){
		if(a>b)		a %= b;
		else	b %= a;
	}
	return a+b;
}
main(){
	int m, n;
	cout<<"m = ";		cin>>m;
	cout<<"n = "; 		cin>>n;
	cout<<"UCLN = "<<Ucln(m,n)<<endl;
	cout<<"UCLN = "<<UclnC2(m,n)<<endl;
	
	return 0;
}