#include <bits/stdc++.h>
using namespace std;

//Vet can
int Vet_Can(char *q, char *p){
	int dem = 0;
	int m = strlen(q);
	int n = strlen(p) - m;
	for(int i=0; i<=n; i++){
		int j = 0;
		while(j<m && p[i+j]==q[j]){
			j++;
		}
		if(j==m) dem++;
	}
	return dem;
}
int char_in_string(char k, char *q){
	for(int i=0; i<strlen(q); i++){
		if(k == q[i]){
			return i;
		}
	}
	return -1;
}
//Boyer Moore Horspool
int Boyer_Moore_Horspool(char *q, char *p, int *z){
	int dem = 0;
	int v = strlen(q);
	int i = v - 1;
	int length = strlen(p);
	//int *z = new int[length];
	for(int i=0; i<length; i++){
		z[i] = 0;
	}
	while(i < strlen(p)){
		int temp = i;
		int x = v - 1;
		while(p[temp] == q[x] && x>-1){
			temp--; x--;
		}
		if(x<0){
			dem++;
			i = i + v;
			z[temp+1] = 1;
		}
		else{
			int k = char_in_string(p[temp], q);
			if(k < 0) i = i + v;
			else i = i + v - k - 1;
		}
	}
	return dem;
}
int main(){
	char P[] = "Learning algorithms, data structure and algorithms application this semester";
	char Q[] = "algorithms";
	int *z = new int[strlen(P)];
	cout<<"Boyer Moore Horspool: "<<Boyer_Moore_Horspool(Q, P, z)<<endl;
	cout<<"cac vi tri xuat hien: ";
	for(int i=0; i<strlen(P); i++){
		if(z[i] == 1) cout<<i;
	}
	cout<<endl;
	cout<<"Thuat toan vet can: "<<Vet_Can(Q, P)<<endl;

	return 0;
}
