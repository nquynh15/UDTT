#include <bits/stdc++.h>

using namespace std;

struct GoiHang{
	int khoiLuong;
	int giaTri;
};

void inGoiHang(GoiHang gh) {
	cout<<setw(20)<<left<<gh.khoiLuong<<setw(20)<<gh.giaTri<<endl;
}

int QHD(GoiHang *ghs, int n, int s) {
	int F[n+1][s+1];
	memset(F, 0, sizeof(F));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= s; j++) {
			F[i][j] = F[i-1][j];
			
			if(j >= ghs[i].khoiLuong) {
				F[i][j] = max(F[i][j], F[i-1][j - ghs[i].khoiLuong] + ghs[i].giaTri);
			}
		}
	}
	return F[n][s];
}

void inKetqua (GoiHang *ghs, int n, int s, int &dem) {
	cout<< "\n Max: "<<QHD(ghs, n, s)<<endl;
	
	int i = n, j = s;
	while(i != 0) {
		if(QHD(ghs, i, j) != QHD(ghs, i-1, j)){
			inGoiHang(ghs[i]);
			dem++;
			j -= ghs[i].khoiLuong;
		}
		i--;
	}
}

void inBang(GoiHang *ghs, int n, int s) {
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= s; j++) {
			cout<<setw(5)<<QHD(ghs, i, j);
		}
		cout<<endl;
	}
 }

int main(){
	int n = 8;
	
	GoiHang ghs[n+1] = {
		{0,0},
		{1, 12},
		{3, 23},
		{5, 27},
		{4, 46},
		{3, 2},
		{6, 36},
		{4, 22},
		{7, 55}
	};
	
	for(int i=1; i<=n; i++){
		cout<<ghs[i].khoiLuong<<"\t"<<ghs[i].giaTri<<endl;
	}
	
	int s = 10;
	int dem2 = 0;
	inKetqua(ghs, n, s, dem2);
	cout<<"=> Lay duoc "<<dem2<<" goi hang!"<<endl;
	
	cout<<"---------BANG------------"<<endl;
	inBang(ghs, n, s);
	
	return 0;
}
