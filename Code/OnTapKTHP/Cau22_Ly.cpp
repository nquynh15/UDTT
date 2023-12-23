#include<bits/stdc++.h>
using namespace std;
struct GoiHang{
	int khoiluong;
	int giatri;
};

int algo(int n, GoiHang *a, int m){
	int  F[n+1][m+1];
	for(int j=0; j<=m; j++)
		F[0][j] = 0;
	for(int i=1; i<=n; i++){
		for(int j=0; j<=m; j++){
			F[i][j] = F[i-1][j];
			int temp = a[i-1].giatri + F[i-1][j-a[i-1].khoiluong];
			if(a[i-1].khoiluong <= j && F[i][j] < temp)
				F[i][j] = temp;
		}
	}
	return F[n][m];
}
void result(int n, GoiHang *a, int m){
	cout<<"P = "<<algo(n, a, m)<<endl;
	int i=n, j = m;
	while(i != 0){
		if(algo(i, a, j) != algo(i-1, a, j)){
			cout<<a[i-1].khoiluong<<"\t"<<a[i-1].giatri<<endl;
			j = j - a[i-1].khoiluong;
		}
		i--;
	}
}
int main(){
	int n= 8;
	GoiHang a[n] = {
		{1, 12}, {3, 23}, {5, 27}, {4, 46}, {3, 2}, {6, 36}, {4, 22}, {7, 55}
	};
	
	for(int i=0; i<n; i++){
		cout<<a[i].khoiluong<<"\t"<<a[i].giatri<<endl;
	}
	
	int m = 10;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++) {
			cout<<setw(5)<<algo(i, a, j);
		}
		cout<<endl;
	}
	result(n, a, m);
	
	return 0;
}
