#include<bits/stdc++.h>

using namespace std;

struct ThungHang{
	float kichthuoc;
	float khoiluong;
};

void BubbleSort(ThungHang s[], int n){
	for(int i=0; i<n; i++){
		for(int j =n-1; j>i; j--){
			if(s[j].khoiluong > s[j-1].khoiluong){
				ThungHang tmp = s[j];
				s[j] = s[j-1];
				s[j-1] = tmp;
			}
		}
	}
}
void HienThi(ThungHang s[], int x[], int n){
	for(int i=0; i<n; i++)
		cout<<s[x[i]].kichthuoc<<"\t";
	cout<<endl;
	for(int i=0; i<n; i++)
		cout<<s[x[i]].khoiluong<<"\t";
	cout<<endl;
}

/*
s: ds chua xe tai
n: so luong kien hang
k: kich thuoc thung xe cua John
r: mang chua ket qua;
g: so luog thung hang xep duoc len xe
->sao cho tong khoi luong xep len xe dat duoc la lon nhat
*/

bool XepHang(ThungHang *s, int n, float k, int *r,int &g){
	float p=k; 
	int i=0; 
	g=0;
	while(i<n){
		if(s[i].kichthuoc <= p){
			r[g] = i;
			g++;
			p -= s[i].kichthuoc;
		}
		i++;
	}
	if(p==k)	return false;
	else 		return true;
}
int main(){
	int n=5;
	ThungHang s[5] = {{3, 2}, {3, 3}, {3, 4}, {2, 3}, {4, 3}};
	float k = 20;
	int r[n];
	int g=0;
	
	BubbleSort(s, n);
	if(XepHang(s, n, k, r, g)){
		cout<<"So xe tai chon duoc: "<<g<<endl;
		HienThi(s, r, g);
		
	}
	else
		cout<<"Khong chon duoc xe nao!";
		
	return 0;
}
