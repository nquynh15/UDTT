#include<bits/stdc++.h>

using namespace std;

void HienThi(int *x, int n){
	for(int i=0; i<n; i++)
		cout<<"\t"<<x[i];
	cout<<endl;
}
void BubbleSort(int a[], int n){
	
} 
/*
n: so tien bat ky
m: so dong tien
c[]: mang chua cac dong tien
s[]: mang chua so luong lay ra dong tien c[] tuong ung
*/

bool cashiers_algorithm(int *c, int m, long n, int *s){
	int i=0;
	s[i] = 0;
	while(n>0 && i<m){
		s[i] = n/c[i];
		n -= c[i]*s[i];
		i++;
	}
	if(n>0)	return false;
	else	return true;
}

int main(){
	long n = 10;
	int m = 5;
	int c[m] = {100, 25, 15, 34, 21};
	int s[m];
	if(cashiers_algorithm(c, m, n, s)){
		HienThi(s, m);
	}
	else
		cout<<"No solution!"<<endl;	
	
	return 0;	
}