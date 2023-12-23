#include<bits/stdc++.h>
using namespace std;

struct Quat{
	string tenHang;
	string mauSac;
	float giaBan;
};

void swap(Quat &q1, Quat &q2){
	Quat tmp = q1;
	q1 = q2;
	q2 = tmp;
}
void SapXep(Quat *d, int l, int r){
	int i=l, j = r;
	float pivot = d[(l+r)/2].giaBan;
	while(i<= j){
		while(d[i].giaBan < pivot)
			i++;
		while(d[j].giaBan > pivot)
			j--;
		if(i<=j){
			swap(d[i], d[j]);
			i++;
			j--;
		}
	}
	if(l < j)
		SapXep(d, l, j);
	if(r > i)
		SapXep(d, i, r);
}
void HienThi(int n, Quat d[], int r[]){
	for(int i=0; i<n; i++){
		cout<<left<<setw(15)<<d[r[i]].tenHang<<setprecision(10)<<d[r[i]].giaBan<<endl;
	}
}
bool MuaQuat(float p, Quat *d, int n, int &g, int *r){
	float m = p;
	g = 0;
	int i = 0;
	while(i<n){
		if(d[i].giaBan < m){
			r[g] = i;
			g++;
			m -= d[i].giaBan;
		}
		i++;
	}
	if(m == p)	return false;
	return true;
}

int main(){
	int n= 6;
	Quat d[n] = {
		{"VietNhat", "Do", 260000},
		{"Fujiki", "Xanh", 300000},
		{"HoaPhuong", "Trang", 370000},
		{"MHD", "Xanh", 240000},
		{"HoaPhuong", "Do", 320000},
		{"VietNhat", "Den", 350000},
	};
	SapXep(d, 0, n-1);
//	for(int i=0; i<n; i++){
//		cout<<left<<setw(15)<<d[i].tenHang<<setw(15)<<d[i].mauSac<<setprecision(10)<<d[i].giaBan<<endl;
//	}
	float p = 1000000;
	int g, r[100];
	if(MuaQuat(p, d, n, g, r)){
		cout<<"Mua duoc "<<g<<" quat la: "<<endl;
		HienThi(g, d, r);
	}
	else
		cout<<"Khong mua duoc chiec quat nao!";	
	
	return 0;
}