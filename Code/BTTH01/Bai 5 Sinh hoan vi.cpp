#include<bits/stdc++.h>

using namespace std;

void swap(int &a, int &b){
	int tg = a;
	a = b;
	b = tg;
}

void view_config(int x[], int n){
	for(int i=1; i<=n; i++)
		cout<<x[i];
	cout<<endl;
}
void next_config(int x[], int n, int i){
	//Tm x[k] be nhat torng doan cuoi lon nha
	int k=n;
	while(x[k] < x[i])
		k--;
	
	//Dao gia tri x[i] va x[k]
	swap(x[i], x[k]);
	
	//Dao nguoc doan cuoi
	int j=n; i++;
	while(i < j){
		swap(x[i], x[j]);
		i++;	j--;
	}
}
void listing_configs(int n){
	int i, x[n+1] = {0};
	for(int i=1; i<=n; i++){
		x[i] = i;
	}
	
	do{
		view_config(x, n);
		//tim phan tu lien truoc doan cuoi giam dan
		i = n-1;
		while(i>0 && x[i]> x[i+1])	i--;
		if(i>0)		next_config(x, n, i);
	}while(i>0);
}

main(){
	int n, s[n];
	cout<<"n = ";	cin>>n;
	listing_configs(n);
	
	return 0;
}
