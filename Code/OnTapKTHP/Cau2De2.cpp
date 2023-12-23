#include<bits/stdc++.h>
using namespace std;

struct Phone{
	char moTa[20];
	float gia;
};

void sort(int n,Phone d[]){
	for(int i=0; i<n-1; i++){
		for(int j=n-1; j>i; j--){
			if(d[j].gia<d[j-1].gia)
				swap(d[j], d[j-1]);
		}
	}
}
bool tham_lam(int n, float m, Phone d[], int &g){
	float p = m;
	int i=0; g = 0;
	while(i <n && d[i].gia <= p){
		if(p >= 0){
			g = i;
			g++;
			p -= d[i].gia;
		}
		i++;		
	}
	if(p == m)	return false;
	else		return true;
}
int char_in_string(char c, char p[]){
	for(int i=0; i<strlen(p); i++){
		if(c == p[i])
			return i;
	}
	return -1;
}
int boyer_moore_horspool(char s[], char t[]){
	int v = strlen(t);
	int i  = v-1;
	while(i<strlen(s)){
		int x = v-1;
		int temp = i;
		while(s[temp] == t[x] && x>-1){
			temp--;
			x--;
		}
		if(x<0)		return i-v+1;
		else{
			int k = char_in_string(s[temp], t);
			if(k>-1)	return i = i+v-k-1;
			else		return i = i-v;
		}
	}
	return -1;
}
int demDT(int n, Phone d[], char t[], int r[]){
	int count = 0;
	for(int i=0; i<n; i++){
		r[i] = 0;
	}
	for(int i=0; i<n; i++){
		if(boyer_moore_horspool(d[i].moTa, t) >-1){
			count++;
			r[i]=1;
		}
	}
	return count;
}
int main(){
	int n = 7;
	Phone d[n] = {
		{"Iphone 13 RAM 16GB", 1200},
		{"Oppo ZFlip RAM 8GB", 1150},
		{"Vivo 23S RAM 8GB", 1280},
		{"Iphone 14 RAM 16GB", 1370},
		{"Iphone 14 RAM 16GB", 1410},
		{"Iphone 10X RAM 8GB", 9500},
		{"Iphone XS RAM 16GB", 1460},
	};
	sort(n, d);
	for(int i=0; i<n; i++){
		cout<<d[i].moTa<<"\t"<<d[i].gia<<endl;
	}
	
	float m = 3000;
	int g;
	if(tham_lam(n, m, d, g)){
		cout<<"\nLay duoc "<<g<<" dien thoai: "<<endl;
		for(int i=0; i<g; i++){
			cout<<d[i].moTa<<"\t"<<d[i].gia<<endl;
		}
	}
	else
		cout<<"Khong lay duoc dt nao!"<<endl;
		
	char t[] = "RAM 16GB";
	int r[n];
	int count = demDT(n, d, t, r);
	if(count>0){
		cout<<"\nCo "<<count<<" dien thoai co RAM 16GB"<<endl;
		for(int i=0; i<n; i++){
			if(r[i] == 1)
				cout<<d[i].moTa<<"\t"<<d[i].gia<<endl;
		}
	}
	else
		cout<<"Khong co dien thoai nao co RAM 16GB"<<endl;
		
	return 0;
}
