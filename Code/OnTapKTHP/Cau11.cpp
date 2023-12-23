#include<bits/stdc++.h>
using namespace std;

float sum(float a[], int left, int right){
	if(left >= right)
		return a[left];
	int mid = (left + right)/2;
	float sumLeft = sum(a, left, mid);
	float sumRight = sum(a, mid+1, right);
	return sumLeft + sumRight;
}
int tham_lam(int n, float a[], float c, float &m){
	if(a[0] > c)
		return -1;
	int i = 0;
	m = 0;
	while (i < n && (m + a[i]) <= c) {
        m += a[i];
        i++;
    }
	
	return i;
}
int char_in_string(char c, char *p){
	for(int i=0; i<strlen(p); i++){
		if(c == p[i])
			return i;
	}
	return -1;
}
int boyer_moore_horspool(char *s, char *p){
	int dem = 0, v = strlen(p), i = v - 1;
    while (i < strlen(s)) {
        int x = v - 1;
    	int temp = i;
        while (x >= 0 && s[temp] == p[x]) {
            temp--;
            x--;
        }
        if (x < 0) {
            dem++;
            i = i + v;
        } else {
            int k = char_in_string(s[temp], p);
            if (k < 0) {
                i = i + v;
            } else {
                i = i + v - k - 1;
            }
        }
    }
    return dem;
}

int main(){
	int n = 8;
	float a[n] = {1.2, 2, 3, 4.2, 4.7, 5, 6.8, 7.2};
	float c = 8.5;

	float s = sum(a, 0, n-1);
	cout<<"Sum = "<<s<<endl;
	
	float m;
	int g = tham_lam(n, a, c, m);
	if(g < 0 ){
		cout<<"Khong co phan tu nao";
	}
	else{
		cout<<"Lay duoc "<<g<<" phan tu"<<endl;
		for(int i=0; i<g; i++){
			cout<<a[i]<<"\t";
		}
		cout<<"\n=>tong gia tri: "<<m<<endl;
	}	
	char P[] = "Hello today is the holiday, today's sunny!";
	char Q[] = "today";
	int check = boyer_moore_horspool(P, Q);
	if(check == 0)
		cout<<"Q khong la chuoi con cua P";
	else
		cout<<"Q la chuoi con cua P";
	
	return 0;
}
