#include<iostream>
using namespace std;

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}
void view_config(int x[], int n){
	for(int i=0; i<n; i++)
		cout<<x[i];
	cout<<endl;
}
void LietKeQuayLui(int x[], int n, int k){
	if(k == n)
		view_config(x, n);
	else{
		for(int i=k; i<n; i++){
			swap(x[k], x[i]);
			LietKeQuayLui(x, n, k+1);
			swap(x[k], x[i]);
		}
	}
}

int main(){
	int x[] = {1, 2, 3};
	LietKeQuayLui(x, 3, 0);
	
	return 0;
}
