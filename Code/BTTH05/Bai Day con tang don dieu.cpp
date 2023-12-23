#include<bits/stdc++.h>
using namespace std;

void alg(int a[], int n, ){
	int L[n+1] = {0};
	L[n+1] = 1;
	int T[n+1] = {0};
	int i,j;
	for(i=n;i>=0;i--){
		int jmax=n+1;
		for(j=i+1;j<=n+1;j++){
			if(a[j]>a[i]&&L[j]>L[jmax])
				jmax=j;
		}
		L[i]=L[jmax]+1;
		T[i]=jmax;
	}

	int k=T[0];
	//cout<<k;
	while(k!=n+1){
		cout<<a[k]<<" ";
		k=T[k];
	}
	cout<<endl;
}
int main(){
	int a[17]={INT_MIN,17,5,6,4,2,9,11,22,33,15,16,23,21,34,27,INT_MAX};
	int b[12]={INT_MIN, 5, 2, 3, 4, 9, 10, 5, 6, 7, 8,INT_MAX};
	alg(b, 10);
	alg(a,15);
}
