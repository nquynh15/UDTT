#include<bits/stdc++.h>
using namespace std;

int char_in_string(char c, string p){
	for(int i=0; i<p.length(); i++){
		if(c == p[i])
			return i;
	}
	return -1;
}
int boyer_moore_horspool(string q, string p){
	int dem = 0;
	//int v = strlen(q);
	int v = q.length();
	int i = v-1;
	while(i<p.length()){
		int x = v-1;
		int temp = i;
		while(x>=0 && p[temp] == q[x]){
			temp--;
			x--;
		}
		if(x<0){
			dem++;
			i = i+v;
		}
		else{
			int k = char_in_string(p[i], q);
			if(k<0)
				i = i + v;
			else
				i = i+v - k-1;
		}
	}
	return dem;
}
int dem(int n, string d[], string p){
	int count = 0;
	for(int i=0; i<n; i++){
		if(boyer_moore_horspool(p, d[i])>0)
			count++;
	}
	return count;
}
int main(){
	int n = 5;
	string d[n] = {"hello", "today", "is", "the", "holiday"};
	string P = "day";
	int count = dem(n, d, P);
	cout<<count<<endl;
	
	return 0;
}
