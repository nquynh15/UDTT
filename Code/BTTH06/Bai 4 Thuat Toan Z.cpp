#include<bits/stdc++.h>

using namespace std;

int thuat_toan_z(char *p, char *t){
	int n = strlen(p);
	int m = strlen(t);
	char new_t[n + 1 + m];
	memcpy(new_t, p, n);
	memcpy(&new_t[n], "$", 1);
	memcpy(&new_t[n+1], t, m);
	
	int l = strlen(new_t)-1;
	int *z = new int[l];
	int left = 0, right = 0;
	for(int i=1; i<l; i++){
		if(i > right){
			left = right = i;
			while(right < l && new_t[right-left] == new_t[right]){
				right++;
			}
			z[i] = right - left; right--;
		}else if(z[i-left] < right - i + 1){
			z[i] = z[i-left];
		}else{
			left = i;
			while(right < l && new_t[right-left] == new_t[right]){
				right++;
			}
			z[i] = right - left; right--;
		}
	}
	int dem = 0;
	for(int i=0; i<l; i++){
		if(z[i] == strlen(p)){
			dem++;
		}
	}
	return dem;
}
int main(){
	char p[] = "Viet";
	char s[] = "Ban Viet o Viet Nam";
	cout<<thuat_toan_z(p, s);
	return 0;
}

