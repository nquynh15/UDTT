#include<bits/stdc++.h>

using namespace std;

int Fibonacci(int n){
	if(n == 1 || n == 2)
		return 1;
	else
		return Fibonacci(n-1) + Fibonacci(n-2);
}

main(){
	int n;
	cout<<"n = ";	cin>>n;
	cout<<"So Fibnacci thu "<<n<<" la: "<<Fibonacci(n);
	
	return 0;		
}
