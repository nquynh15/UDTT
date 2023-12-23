#include<bits/stdc++.h>
using namespace std;

//Cau truc du lieu
// + So dinh n = 5
int n = 9;
// + Ma hoa dinh A = 0, B = 1, ...., I = n-1(8)
// + Dinh xuat phat
int u = 0;
// + Dinh ket thuc
int v = 1;
// + Danh dau dinh da di qua
bool go[9] = {false, false, false, false, false, false, false, false, false};
// + Duong di ngan nhat
int p[9], m = 0;
// + Do thi:
int c[9][9]= {
	{-1, -1, 16, 10, 19, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, -3,  8,  12, 5},
	{16, -1, -1, 18, -1, -1, -1, 20, -1},
	{10, -1, 18, -1,  7,  7,  8, -1, -1},
	{19, -1, -1,  7, -1, -1, -1, -1,  9},
	{-1,  3, -1,  7, -1, -1,  2, 15, -1},
	{-1,  8, -1,  8, -1,  2, -1, -1,  4},
	{-1, 12, 20, -1, -1, 15, -1, -1, -1},
	{-1,  5, -1, -1,  9, -1,  4, -1, -1}
};
//Tong chi phi duong di ngan nhat tim duoc
int cost = 0;
bool greedy_travel_sales_man(){
	p[m] = u; // tap muc tieu chua dinh xuat phat
	go[u] = true; // // Dinhu da tham
	
	while(u != v){
		
		int w = 0;
		while(w<n && (go[w] == true || c[u][v] == -1))
			w++;
		
		if(w==n)
			return false;
		else{
			u = w;
			w++;
			while(w<n){
				if(go[w] == false && c[p[m]][w] != -1 && c[p[m]][w] < c[p[m]][u])
					u=w;
				w++;
			}
			cost += c[p[m]][u];
			m++;
			p[m] = u;
			go[u] = true;
		}
	}
	return true;
	
}
int main(){
	if(greedy_travel_sales_man()){
		cout<<"Tim duoc duong di: ";
		for(int i=0; i<=m; i++)
			cout<<(char)(p[i] + 65)<<" ";
		cout<<"\nVoi tong chi phi: "<<cost;
	}
	else
		cout<<"Khong tim duoc duong di!";
	
	return 0;
}
