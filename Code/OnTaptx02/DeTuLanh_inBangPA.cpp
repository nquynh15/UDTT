#include <bits/stdc++.h>

using namespace std;

struct TuLanh{
	string tenHang;
	int dienTich;
	int giaTri;
};

void inTuLanh(TuLanh tl) {
	cout<<setw(20)<<left<<tl.tenHang<<setw(20)<<tl.dienTich<<setw(20)<<tl.giaTri<<endl;
}

int QHD(TuLanh *hs, int n, int s) {
	int F[n+1][s+1];
	memset(F, 0, sizeof(F));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= s; j++) {
			F[i][j] = F[i-1][j];
			
			if(j >= hs[i].dienTich) {
				F[i][j] = max(F[i][j], F[i-1][j - hs[i].dienTich] + hs[i].giaTri);
			}
		}
	}
	
	return F[n][s];
}

void sapXep(TuLanh *x, int n) {
	for(int i = 1; i<= n-1; i++){
		for(int j=i+1; j<=n; j++) {
			if(x[i].giaTri < x[j].giaTri){
				swap(x[i] , x[j]);
			}
		}
	}
}

void A(TuLanh *x, int n, int m, int &s) {
	int i = 1;
	while(i <= n && x[i].giaTri < m){
		m -= x[i].giaTri;
		i++;
		s++;
	}
}

void inKetqua (TuLanh *hs, int n, int s, int &dem) {
	cout<< "\n Max: "<<QHD(hs, n, s)<<endl;
	
	int i = n, j = s;
	while(i != 0) {
		if(QHD(hs, i, j) != QHD(hs, i-1, j)){
			inTuLanh(hs[i]);
			dem++;
			j -= hs[i].dienTich;
		}
		i--;
	}
}

void inBang(TuLanh *hs, int n, int s) {
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= s; j++) {
			cout<<setw(10)<<QHD(hs, i, j);
		}
		cout<<endl;
	}
 }

int main(){
	int n = 6;
	
	TuLanh hs[n+1] = {
		{"",0,0},
		{"Panasonic", 3, 12000000},
		{"Sharp", 2, 8000000},
		{"Samsung", 6, 11000000},
		{"LG", 5, 13000000},
		{"Funiki", 3, 10000000},
		{"Toshiba", 4, 12000000},
	};
	
	sapXep(hs, n);
	for(int i = 1; i<=n; i++) {
		inTuLanh(hs[i]);
	}
	
	//Cau 1
	int dem = 0;
	int m = 10000000;
	A(hs, n, m, dem);
	if(dem>0){
		cout<<"\nVoi "<<m<<" mua duoc it nhat "<<dem<<" tu lanh:\n";
		for(int i = 1; i<= dem; i++) {
			inTuLanh(hs[i]);
		}
	}
	else
		cout<<"\nVoi "<<m<<" khong mua duoc chiec laptop nao"<<endl;
	
	
	// Cau 2
	int s = 14;
	int dem2 = 0;
	
	cout<<"\n---------BANG PHUONG AN------------"<<endl;
	inBang(hs, n, s);
	inKetqua(hs, n, s, dem2);
	cout<<"=> Xep duoc "<<dem2<<" tu lanh vao kho dien tich "<<s<<endl;
	
	
	return 0;
}
