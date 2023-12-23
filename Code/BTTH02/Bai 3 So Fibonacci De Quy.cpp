#include<bits/stdc++.h>

using namespace std;

int Fibonaci(int n){
	if(n==0)
		return 0;
	if(n == 1)
		return 1;
	return Fibonaci(n-1) + Fibonaci(n-2);
}

main(){
	int n;
	cout<<"Tim so Fibonaci thu n : ";		cin>>n;
	cout<<"So Fibonaci thu "<<n<<" la: "<<Fibonaci(n)<<endl;
	
	return 0;
}
