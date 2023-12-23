#include<bits/stdc++.h>

using namespace std;

//----PHUONG PHAP SINH----
//Sinh cau hinh moi
void next_config(int x[], int n, int i){
	x[i] = 1;
	i++;
	while(i<=n){
		x[i] = 0;
		i++;
	}
}
//Hien thi cau hinh
void view_config(int x[], int n){
	for(int i=1; i<=n; i++)
		cout<<x[i];
	cout<<endl;
}
//Liet ke cac cau hinh
void listing_configs(int n){
	int i;
	int x[n+1] = {0};
	do{
		view_config(x, n);
		i=n;
		while(i>0 && x[i] == 1){
			i--;
		}
		if(i>0){
			next_config(x, n, i);
		}
	}while(i>0);
}

//--DUNG DE QUY---
void SinhDayNhiPhan(int n, string s){
	if(n==0){
		cout<<s<<endl;
		return;
	}
	SinhDayNhiPhan(n-1, s+"0");
	SinhDayNhiPhan(n-1, s+"1");
}
main(){
	int n;
	cout<<"Sinh day nhi phan cua so n = ";
	cin>>n;
	cout<<"Ket qua: "<<endl;
	listing_configs(n);
	cout<<"C2: "<<endl;
	SinhDayNhiPhan(n, "");
	
	return 0;
}