#include<bits/stdc++.h>
using namespace std;

void Show(int x[], int n){
	for(int i=1; i<=n; i++){
		cout<<x[i];
	}
	cout<<endl;
}
void Try(int k, int x[], int n, int d[]){
	for(int i=1; i<=n; i++){
		if(d[i] == 0){
			x[k] = i;
			d[i] = 1;
			if(k == n)		
				Show(x, n);
			else
				Try(k+1, x, n, d);
			d[i] = 0;			
		}
		
	}
}
main(){
	int n;
	cout<<"n = ";	cin>>n;
	int x[n], d[n+1]={0};
	for(int i=1; i<=n; i++){
		x[i] = i;
	}
	Try(1, x, n, d);
	
	return 0;
}
