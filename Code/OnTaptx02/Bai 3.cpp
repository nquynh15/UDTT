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

void SapXep(int n, Quat d[]){
	for(int i=0; i<n-1; i++){
		int index = i;
		for(int j=i+1; j<n; j++){
			if(d[j].giaBan > d[index].giaBan)
				index = j;
		}
		if(index != i){
			swap(d[index], d[i]);
		}
	}
}

void HienThi(int n, Quat d[], int r[]){
	for(int i=0; i<n; i++){
		cout<<left<<setw(15)<<d[r[i]].tenHang<<setprecision(10)<<d[r[i]].giaBan<<endl;
	}
}
int MuaQuat(float p, Quat *d, int n, int &g, int *r){
	float sum = 0;
	g = 0;
	int i = 0;
	do{
		sum += d[i].giaBan;
		r[g] = i;
		g++;
		i++;
	}while(i<n && sum <p);
	return g;
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
	SapXep(n, d);
	for(int i=0; i<n; i++){
		cout<<left<<setw(15)<<d[i].tenHang<<setw(15)<<d[i].mauSac<<setprecision(10)<<d[i].giaBan<<endl;
	}
	float p = 1000000;
	int g, r[100];
	if(MuaQuat(p, d, n, g, r) == 0)
		cout<<"Khong mua duoc chiec quat nao!";		
	else{		
		cout<<"Mua duoc "<<g<<" quat la: "<<endl;
		HienThi(g, d, r);
	}
		
	
	return 0;
}