#include<bits/stdc++.h>

using namespace std;

void Show(int x[], int n){
	for(int i=1; i<=n; i++){
		cout<<x[i];
	}
	cout<<endl;
}
void Try(int k, int x[], int n){
	for(int i=0; i<=1; i++){
		x[k] = i;
		if(k == n){
			Show(x, n);
		}
		else
			Try(k+1, x, n);
	}
}

main(){
	int n;
	cout<<"n = ";	cin>>n;
	int x[n];

	Try(1, x, n);
	
	return 0;
}
