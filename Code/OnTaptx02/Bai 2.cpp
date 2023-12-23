#include<bits/stdc++.h>
using namespace std;

struct Quat{
	string tenHang;
	string mauSac;
	int giaBan;
};
void HienThi(int n, Quat d[], int r[]){
	for(int i=0; i<n; i++){
		cout<<left<<setw(15)<<d[r[i]].tenHang<<setprecision(10)<<d[r[i]].giaBan<<endl;
	}
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

bool MuaQuat(int n, Quat *d, int total, int *r, int &count){	
	int i = 0;
	count = 0;
	while(total > 0 && i<n){
		if(total-d[i].giaBan >= 0){
			r[count]= i;
			total -=d[i].giaBan;
			count++;
		}
		i++;
	}
	if(total == 0)	return true;
	else return false;
}

int main(){
	int n= 6;
	Quat d[n] = {
		{"VietNhat", "Do",    280000},
		{"Fujiki",   "Xanh",  300000},
		{"HoaPhuong","Trang", 370000},
		{"MHD",      "Xanh",  240000},
		{"HoaPhuong","Do",    320000},
		{"VietNhat", "Den",   350000},
	};
	
	SapXep(n, d);
	for(int i=0; i<n; i++){
		cout<<left<<setw(15)<<d[i].tenHang<<setw(15)<<d[i].mauSac<<setprecision(10)<<d[i].giaBan<<endl;
	}
	int r[20], count;
	int p = 720000;
	if(!MuaQuat(n, d, p, r, count))
		cout<<"Khong mua duoc nhung chiec quat de duoc tong gia ban bang "<<p<<endl;
	else{
		cout<<"Mua duoc "<<count<<" quat co tong gia dung bang "<<p<<" la: "<<endl;
		HienThi(count, d, r);
	}
		
	
	
	return 0;
}
