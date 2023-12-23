#include<bits/stdc++.h>
using namespace std;

struct LapTop{
	char tenHang[10];
	char cauHinh[60];
	int giaBan;
};

void HienThi(LapTop laptop){
	cout<<left<<setw(10)<<laptop.tenHang<<setw(40)<<laptop.cauHinh<<setw(15)<<laptop.giaBan<<endl;
}

void swap(LapTop &t1, LapTop &t2){
	LapTop temp = t1;
	t1 = t2;
	t2 = temp;
}

void SapXep(int n, LapTop *d){
	for(int i=0; i<n-1; i++){
		for(int j=n-1; j>i; j--){
			if(d[j].giaBan>d[j-1].giaBan)
				swap(d[j], d[j-1]);
		}
	}
}
bool MuaBan(int n, int p, LapTop *d, int &count, int *r){
	count = 0;
	int i=0;
	while(i<n && p>0){
		if((p-d[i].giaBan) >=0){
			r[count] = i;
			p -= d[i].giaBan;
			count++;
		}
		i++;		
	}
	if(p == 0)	return true;
	else		return false;
}
void HienThiMuaBan(int n, int *r, LapTop *d){
	for(int i=0; i<n; i++){
		cout<<left<<setw(10)<<d[r[i]].tenHang<<setw(15)<<d[r[i]].giaBan<<endl;
	}
		
}
int char_in_string(char c, char *p){
	for(int i=0; i<strlen(p); i++){
		if(c == p[i])	return i;
	}
	return -1;
}
int Boyer_Moore_Horspool(char *p, char *t){
	int v = strlen(p);
	int i = v - 1;
	while(i < strlen(t)){
		int x = v-1;
		int temp = i;
		while(p[x] == t[temp] && x>-1){
			temp--;
			x--;
		}
		if(x<0)	return i - v + 1;
		else {
			int k = char_in_string(t[temp], p);
			if(k>-1)	i = i+v - k - 1;
			else		i = i+v;
		}
	}
	return -1;
}
int OCungT(int n, LapTop *d, char *t, int *result){
	int count = 0;
	for(int i = 0; i<n; i++){
		result[i] = 0;
	}
	for(int i=0; i<n; i++){
		if(Boyer_Moore_Horspool(t, d[i].cauHinh) > -1){
			result[i] = 1;
			count++;
		}
	}
	return count;
}
int main(){
	int n = 6;
	LapTop d[n]={
		{"HP", "CPU 2.5GHz - RAM 16GB - SSD 256GB", 13000000},
		{"ACER", "CPU 2.5GHz - RAM 16GB - HDD 256GB", 15000000},
		{"Lenovo", "CPU 2.5GHz - RAM 16GB - SSD 256GB", 33000000},
		{"Dell", "CPU 2.5GHz - RAM 16GB - HDD 256GB", 19000000},
		{"Mac", "CPU 2.5GHz - RAM 16GB - SSD 256GB", 30000000},
		{"Asus", "CPU 2.5GHz - RAM 16GB - HDD 256GB", 16000000},
	};
	SapXep(n, d);

	//Cau 1
	cout<<"\n-------------------Cau 1-----------------------"<<endl;
	int p = 45000000;
	int r[20], count;
	if(MuaBan(n, p, d, count, r)){
		cout<<"Mua duoc "<<count<<" chiec laptop voi tong so tien dung bang "<<p<<" la: "<<endl;
		HienThiMuaBan(count, r, d);
	}
	else
		cout<<"Khong duoc nhung chiec lap top de tong gia tri dung bang "<<p<<endl;
	
	//Cau2
	cout<<"\n-------------------Cau 2-----------------------"<<endl;
	char t[] = "HDD 256";
	int result[20];
	int quantity = OCungT(n, d, t, result);
	if(quantity == 0)
		cout<<"Khong co laptop nao co o cung HDD 256"<<endl;
	else{
		cout<<"Co "<<quantity<<" laptop co o cung HDD256 la: "<<endl;
		for(int i = 0; i<n; i++){
			if(result[i] == 1)
				HienThi(d[i]);
		}
	}
	
	
	return 0;
}
