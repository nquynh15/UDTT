#include<bits/stdc++.h>
using namespace std;


struct Package{
	float kichthuoc;
	float khoiluong;
};
void SelectionSort(Package p[], int n){
	for(int i=0; i<n-1; i++){
		int m=i;
		for(int j=i; j<n-1; j++){
			if(p[m].khoiluong>p[j].khoiluong)
				m = j;
		}
		if(m != i){
			Package tmp = p[m];
			p[m] = p[i];
			p[i] = tmp;
		}
	}
}
void HienThi(Package p[], int x[], int n){
	for(int i=0; i<n; i++)
		cout<<p[x[i]].kichthuoc<<"\t";
	cout<<endl;
	for(int i=0; i<n; i++)
		cout<<p[x[i]].khoiluong<<"\t";
	cout<<endl;
}

/*
p: ds goi hang
n: so luong goi hang
k: kich thuoc balo
-> tong khoi luong cac goi hang nho nhat
*/
bool SelctPackage(Package *b, int n, float k, int *r, int &g){
	float p=k;
	int i=0;
	g=0;
	while(i<n){
		if(b[i].kichthuoc < p){
			r[g] = i;
			g++;
			p -= b[i].kichthuoc;
		}
		i++;
	}
	if(p == k) 	return false;
	else 		return true;
}

int main(){
	int n=5;
	float k = 8.5;
	Package p[n] = {{3, 2}, {3, 3}, {3, 4}, {2, 3}, {4, 3}};
	int r[n];
	int g;
	
	SelectionSort(p, n);
	if(SelctPackage(p, n, k, r, g)){
		cout<<"Chon duoc so goi hang la: "<<g<<endl;
		HienThi(p, r, g);
	}
	else
		cout<<"Khong chon duoc tui nao"<<endl;
	
	return 0;
}
