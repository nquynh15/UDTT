#include<bits/stdc++.h>
using namespace std;

int tong(int n, int a[], int k, int index){
	if(index == n)
		return 0;
	else{
		if(a[index]%k == 0)
			return a[index] + tong(n, a, k, index+1);
		else
			return tong(n, a, k, index+1);
	}
}

int main(){
	int n = 8;
	int a[n] = {12, 13, 4, 5, 12, 64, 78, 75};
	int k = 4;
	
	cout<<(tong(n, a, k, 0))<<endl;
	
	return 0;
}
