#include<bits/stdc++.h>
using namespace std;

struct TuLanh{
	string tenHang;
	int dienTich;
	int giaTri;
};
void swap(TuLanh &tu1, TuLanh &tu2){
	TuLanh temp = tu1;
	tu1 = tu2;
	tu2 = temp;
}

void HienThi(TuLanh tulanh){
	cout<<left<<setw(15)<<tulanh.tenHang<<setw(20)<<tulanh.dienTich<<setw(20)<<tulanh.giaTri<<endl;
}
void SapXep(int n, TuLanh *d){
	for(int i=1; i<n; i++){
		for(int j=i+1; j<=n; j++){
			if(d[i].giaTri< d[j].giaTri){
				swap(d[i], d[j]);
			}
		}
	}
}
bool A(int n, TuLanh *d, int m, int *r, int &g){
	int i=1; g = 0;
	int temp = m;
	while(i<=n && d[i].giaTri <= temp){
		r[g] = i;
		g++;
		temp -= d[i].giaTri;
		i++;
	}
	if(temp == m)	return false;
	else	return true;
}
void HienThi(int n, TuLanh *d, int *r){
	for(int i=0; i<n; i++){
		cout<<left<<setw(15)<<d[r[i]].tenHang<<setw(20)<<d[r[i]].giaTri<<endl;
	}
}

int B(int n, int m, TuLanh *d){
	int F[n+1][m+1];
	for(int j=0; j<=m; j++)
		F[0][j] = 0;
	for(int i=1; i<=n; i++){
		for(int j=0; j<=m; j++){
			F[i][j] = F[i-1][j];
			if(d[i].dienTich <= j && F[i][j] < d[i].giaTri+ F[i-1][j-d[i].dienTich]){
				F[i][j] = d[i].giaTri+ F[i-1][j-d[i].dienTich];
			}				
		}
	}
	
	return F[n][m];
}
void Result(int n, int m, TuLanh *d){
	int i=n, j = m;
	int count = 0;
	while(i!=0){
		if(B(i, j, d) != B(i-1, j, d)){
			count++;
			j = j -d[i].dienTich;
		}
		i--;
	}
	i=n, j = m;
	cout<<"Xep duoc "<<count<<" tu lanh la: "<<endl;
	while(i!=0){
		if(B(i, j, d) != B(i-1, j, d)){
			HienThi(d[i]);
			j = j -d[i].dienTich;
		}
		i--;
	}
}
int main(){
	
	//Cau 1
	int n = 6;
	TuLanh d[n+1] = {
		{"", 0, 0},
		{"Panasonic", 3, 12000000},
		{"Sharp", 2, 8000000},
		{"Samsung", 6, 11000000},
		{"LG", 5, 13000000},
		{"Funiki", 3, 10000000},
		{"Toshiba", 4, 12000000},
	};
	SapXep(n, d);
	for(int i=1; i<=n; i++){
		HienThi(d[i]);
	}
	int m = 30000000;
	int r[20], g;
	cout<<"\n---------------Cau1------------------"<<endl;
	if(A(n, d, m, r, g)){
		cout<<"Mua duoc "<<g<<" tu lanh la: "<<endl;
		HienThi(g, d, r);
	}
	else
		cout<<"Khong mua duoc tu lanh nao!"<<endl;
	
	//Cau 2
	cout<<"\n---------------Cau2------------------"<<endl;
	int s = 14;
	Result(n, s, d);
	
	return 0;
}
