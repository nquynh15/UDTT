#include<bits/stdc++.h>
using namespace std;

struct TuLanh{
	string tenHang;
	int dienTich;
	int giaTri;
};
void HienThiTuLanh(TuLanh tulanh){
	cout<<left<<setw(10)<<tulanh.tenHang<<setw(5)<<tulanh.dienTich<<setw(15)<<tulanh.giaTri<<endl;
}
void swap(TuLanh &tu1, TuLanh &tu2){
	TuLanh temp = tu1;
	tu1 =tu2;
	tu2 = temp;
}
void SapXep(int n, TuLanh *d){
	for(int i=1; i<=n-1; i++){
		for(int j = n-1; j>i; j--){
			if(d[j].giaTri<d[j-1].giaTri)
				swap(d[j], d[j-1]);
		}
	}
}
bool MuaTuLanh(int n, int m, TuLanh *d, int &g, int *r){
	int p = m;
	int i = 1; g = 0;
	while(i<=n && d[i].giaTri<=p){
		r[g] = i;
		g++;
		p -= d[i].giaTri;
		i++;
	}
	if(p == m)		return false;
	else			return true;
}

int XepTuLanh(int n, int m, TuLanh *d){
	int F[n+1][m+1];
	memset(F, 0, sizeof(F));
	for(int i=1; i<=n; i++){
		for(int j=0; j<=m; j++){
			F[i][j] = F[i-1][j];
			int temp = d[i].giaTri +F[i-1][j-d[i].dienTich];
			if(d[i].dienTich <= j && F[i][j] < temp)
				F[i][j] = temp;
		}
	}
	return F[n][m];
}
void inBangPA(int n, int m, TuLanh *d){
	for(int i=0; i<=n; i++){
		for(int j=1; j<=m; j++){
			cout<<setw(12)<<XepTuLanh(i, j, d);
		}
		cout<<endl;
	}
}
void Result(int n, int m, TuLanh *d, int &dem){
	int i=n,j = m;
	//cout<<"Tong gia tri lon nhat: "<<XepTuLanh(n, m,d)<<endl;
	cout<<"Cac tu lanh xep duoc: "<<endl;
	while(i!=0){
		if(XepTuLanh(i, j, d) != XepTuLanh(i-1, j, d)){
			HienThiTuLanh(d[i]);
			j = j-d[i].dienTich;
			dem++;
		}
		i--;
	}
}
int main(){
	int n=5;
	TuLanh d[n+1] = {
		{"", 0, 0},
		{"Panasonic", 3, 12000000},
		{"Sharp", 2, 11000000},
		{"LG", 4, 16000000},
		{"Funiki", 2, 14000000},
		{"Samsung", 5, 18000000},
	};
	SapXep(n, d);

	//Cau 1
	int m = 34000000;
	int g, r[20];
	MuaTuLanh(n, m, d, g, r);
	if(g>0){
		cout<<"Voi "<<m<<" mua duoc nhieu nhat "<<g<<" tu lanh la: "<<endl;
		for(int i = 1; i<=g; i++){
			cout<<left<<setw(10)<<d[i].tenHang<<setw(15)<<d[i].giaTri<<endl;
		}
	}
	else
		cout<<"Voi "<<m<<" khong duoc chiec tu lanh nao!"<<endl;
		
	//Cau 2
	int s = 12;
	int dem = 0;
	inBangPA(n, s, d);
	Result(n, s, d, dem);
	cout<<"=> Xep duoc "<<dem<< " tu lanh vao kho"<<endl;
	
	return 0;
}
