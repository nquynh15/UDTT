#include <bits/stdc++.h>
using namespace std;

void quyHoachDong(int *w, int *v, int **f, int n, int m){
	for(int j=0; j<=m; j++){
		f[0][j] = 0;
	}
	for(int i=1; i<=n; i++){
		for(int j=0; j<=m; j++){
			f[i][j] = f[i-1][j];
			int temp = v[i-1] + f[i-1][j-w[i-1]];
			if(w[i-1] <= j && temp>f[i][j]){
				f[i][j] = temp;
			}
		}
	}
}

void truyVet(int *w, int *v, int **f, int n, int m){
	cout<<"Bang phuong an: "<<endl;
	for(int i=0; i<=n; i++){
		for(int j=0; j<=m; j++){
			cout<<left<<setw(10)<<f[i][j];
		}
		cout<<endl;
	}
	cout<<"Gia tri lon nhat co the lay: "<<f[n][m]<<endl;
	int i = n, j = m;
	while(i != 0){
		if(f[i][j] != f[i-1][j]){
			cout<<i<<" ";
			j = j - w[i-1];
		}
		i--;
	}
}
int main(){
	int n = 6;
	int w[n] = {3, 6, 2, 7, 1, 5};
	int v[n] = {4, 3, 2, 5, 1, 6};
	int m = 12;
	int **f = new int*[n+1];
	for(int i=0; i<=n; i++){
		f[i] = new int[m+1];
	}
	quyHoachDong(w, v, f, n, m);
	truyVet(w, v, f, n, m);
	
	return 0;
}
