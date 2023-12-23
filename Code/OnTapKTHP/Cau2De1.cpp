#include<bits/stdc++.h>
using namespace std;

struct Toy{
	int size;
	int value;
};
void swap(Toy &t1, Toy &t2){
	Toy temp = t1;
	t1 = t2;
	t2 = temp;
}
void sort(int n, Toy d[]){
	for(int i=0; i<n-1; i++){
		for(int j=n-1; j>i; j--){
			if(d[j].value<d[j-1].value)
				swap(d[j], d[j-1]);
		}
	}
}
bool tham_lam(int n, int m, Toy d[], int r[], int &g){
	int p = m;
	int i = 0;
	g = 0;
	while(i<n && d[i].value <= p){
		r[g] = i;
		g++;
		p -= d[i].value;
		i++;
	}
	if(p == m)	return false;
	else		return true;
}
int qhd(int n, int s, Toy d[]){
	int F[n+1][s+1];
	for(int j=0; j<=s; j++){
		F[0][j] = 0;
	}
	for(int i=1; i<=n; i++){
		for(int j=0; j<=s; j++){
			F[i][j] = F[i-1][j];
			if(d[i].size <= j){
				int temp = d[i-1].value + F[i-1][j-d[i-1].size];
				if(F[i][j] < temp)
					F[i][j] = temp;
			}
		}
	}
	return F[n][s];
}
void result(int n, int s, Toy d[]){
	cout<<"Gia tri lon nhat: "<<qhd(n, s, d)<<endl;
	int i=n, j= s;
	while(i != 0){
		if(qhd(i, j, d) != qhd(i-1, j, d)){
			cout<<d[i-1].size<<"\t"<<d[i-1].value<<endl;
			j = j - d[i-1].size;
		}
		i--;	
	}
	cout<<endl;
}
int main(){
	int n = 6;
	Toy d[n] = {{2, 3}, {4, 4,}, {5, 3}, {6, 7}, {2, 1}, {4, 7} };
	sort(n, d);
	for(int i = 0; i<n; i++){
		cout<<d[i].size<<"\t"<<d[i].value<<endl;
	}
	int m = 11;
	int g, r[10];
	
	if(tham_lam(n, m, d, r, g)){
		cout<<"\nLay duoc: "<<g<<endl;
		for(int i=0; i<g; i++){
			cout<<d[i].size<<"\t"<<d[i].value<<endl;
		}
		cout<<endl;
	}
	else
		cout<<"Khong lay duoc do choi nao ca"<<endl;
	
	int s = 10;
	for(int i=0; i<=n; i++){
		for(int j=0; j<= m; j++){
			cout<<setw(5)<<qhd(i, j, d);
		}
		cout<<endl;
	}
	result(n, s, d);
	
	return 0;
}
