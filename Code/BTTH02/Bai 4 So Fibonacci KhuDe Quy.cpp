#include<bits/stdc++.h>

using namespace std;

int Fibonaci(int n){
	if(n == 1 || n==2){
		return 1;
	}
	int f1 = 1, f2 = 1, f;
	int i=3;
	while(i<=n){
		f = f1 + f2;
		f1 = f2;
		f2 = f;
		i++;
	}
	return f;
}

main(){
	int n;
	cout<<"Tim so Fibonaci thu n : ";		cin>>n;
	cout<<"So Fibonaci thu "<<n<<" la: "<<Fibonaci(n)<<endl;
	
	return 0;
}