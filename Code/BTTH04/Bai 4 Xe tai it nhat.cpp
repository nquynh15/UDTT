#include<bits/stdc++.h>
using namespace std;

void SelectionSort(float a[], int n){
	int index;
	for(int i=0; i<n-1; i++){
		index=i;
		for(int j=i+1; j<n; j++){
			if(a[index]< a[j])
				index = j;
		}
		if(index != i){
			float temp = a[i];
			a[i]=a[index];
			a[index] = temp;
		}
	}
}
void HienThi(float a[], int n){
	for(int i=0; i<n; i++)
		cout<<a[i]<<"\t";
	cout<<endl;
}

/*
k: mang chua khoi luong xe tai
n: so xe tai
m: khoi luong can van chuyen
s: mang chua ket qua
g: so xe tai can 
*/
bool VanChuyen(float *k, int n, float m, float *s, int &g){
	int i=0; g=0;
	while(i<n && m>0 &&k[i] !=0){
		m -= k[i];
		s[g] = k[i];
		g++;
		i++;
	}
	if( m <= 0)		return true;
	else	return false;
}

int main(){
	int n=5;
	float m = 30;
	float k[n] = {10, 5, 7.5, 8, 4};
	float s[n];	int g;
	SelectionSort(k, n);
	if(VanChuyen(k, n, m, s, g)){
		cout<<"So xe tai: "<<g<<endl;
		HienThi(s, g);
	}
		
	else
		cout<<"No solution!"<<endl;
	
	
	return 0;
}
