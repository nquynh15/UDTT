#include<bits/stdc++.h>
using namespace std;

int Ucln(int a, int b){	
	if(b == 0)	return a;
	else	return Ucln(b, a%b);
}

main(){
	int m, n;
	cout<<"m = ";		cin>>m;
	cout<<"n = ";		cin>>n;
	cout<<"UCLN = "<<Ucln(m,n)<<endl;
	
	return 0;
}