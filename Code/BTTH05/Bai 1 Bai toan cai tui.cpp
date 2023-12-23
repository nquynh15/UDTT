#include<bits/stdc++.h>
using namespace std;

/*
n: so goi hang
m: khoi luong toi da
w: khoi luong cua tui
v: gia tri cua tui
*/

int Algorithm(int n, int m, int w[], int v[]){
	int F[n+1][m+1];
	for(int j=0; j<=m; j++)
		F[0][j] = 0;
	for(int i=1; i<=n; i++){
		for(int j=0; j<= m; j++){
			F[i][j] = F[i-1][j];
			
			if(w[i] <= j && F[i][j] < v[i] + F[i-1][j-w[i]])
				F[i][j] = v[i] + F[i-1][j-w[i]];
		}
	}
	return F[n][m];
}

void Result(int n, int m, int w[], int v[]){
	cout<<"Tong gia tri: "<<Algorithm(n, m, w, v)<<endl;
	int i=n, j = m;
	cout<<"Cac goi duoc chon: "<<endl;
	while(i != 0){
		if(Algorithm(i, j, w, v) != Algorithm(i-1, j, w, v)){
			cout<<i<<" ";
			j = j-w[i];
		}
		i--;
	}
}
int main(){
	int n = 5;
	int m = 10;
	int w[n] = {3, 6, 2, 4, 5};
	int v[n] = {3, 4, 6, 5, 2};
	Result(n, m, w, v);
	
	return 0;
}

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
