#include<bits/stdc++.h>
using namespace std;

void BubbleSort(int a[], int n){
	
} 
/*
bottle: danh sach chai nuoc voi gia tri la dung tich cua chai;
jug: luong nuoc can do vao
m: so luong chai cac loai
s: so chai lay duoc
*/

bool pouring(long jug, int *b, int m, int &s){
	int i=m-1;
	while(jug >= b[i] && i>=0 && b[i]!=0){
		jug -= b[i];
		b[i] = 0;
		i--;
		s++;
	}
	if(i<m-1)	return true;
	else 		return false;
}

int main(){
	int jug = 10, m = 5;
	int b[m] = {8, 5, 4, 3, 2};
	int s = 0;
	if(pouring(jug, b, m, s))
		cout<<s<<endl;
	else
		cout<<"Khong co phuong an"<<endl;
	
	return 0;
}