#include<bits/stdc++.h>
using namespace std;

void next_config(char x[], int n, int i){
	x[i] = 'b';
	i++;
	while(i<=n){
		x[i] = 'a';
		i++;
	}
}
void view_config(char x[], int n){
	for(int i=1; i<= n; i++)
		cout<<x[i];
	cout<<endl;	
}
void listing_configs(int n){
	char x[n+1];
	for(int i=1; i<=n; i++){
		x[i] = 'a';
	}
	int i;
	do{
		view_config(x, n);
		i=n;
		while(i>0 && x[i] == 'b')
			i--;
		if(i>0) next_config(x, n, i);
	}while(i>0);
}
main(){
	int n;
	cout<<"Do dai chuoi n = ";
	cin>>n;
	listing_configs(n);
}