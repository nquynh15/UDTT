#include<bits/stdc++.h>
using namespace std;

int analys01(int m,int n){
	int f[m+1][n+1];
	for(int i=0;i<=m;i++){
		f[i][0]=1;
	}

	for(int j=1;j<=n;j++){
		f[0][j]=0;
	}

	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i>j){
				f[i][j]=f[i-1][j];
			}else{
				f[i][j]=f[i-1][j]+f[i][j-i];
		 }
		}
	}
	return f[m][n];
}
int main(){

	cout<<analys01(3,5);
}
