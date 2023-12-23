#include<bits/stdc++.h>
using namespace std;

void HienThi(int x[], int n){
	for(int i=0; i<n; i++)
		cout<<x[i]<<" ";
	cout<<endl;
}
void BubbleSort(int x[], int n){
	for(int i=0; i<n; i++){
		for(int j=n-1; j>i; j--){
			if(x[j]<x[j-1])
				swap(x[j], x[j-1]);
		}
	}
	
}
void SelectionSort(int x[], int n){
	for(int i=0; i<n-1; i++){
		int m=i;
		for(int j=i+1; j<n-1; j++){
			if(x[m] > x[j])
			m = j;
		}
		if(m!=i)
			swap(x[m], x[i]);
	}
}

void InsertionSort(int x[], int n){
	for(int i=1; i<n; i++){
		int tam = x[i];
		int j=i-1;
		while(j>-1 && x[j] >tam){
			x[j+1] = x[j];
			j--;
		}
		x[j+1] = tam;
	}
}
int main(){
	int n=5;
	int x[n] = {8, 2, 1, 5, 7};
	BubbleSort(x, n);
	HienThi(x, n);
	SelectionSort(x, n);
	HienThi(x, n);
	InsertionSort(x, n);
	HienThi(x, n);
	
	
	return 0;
}

