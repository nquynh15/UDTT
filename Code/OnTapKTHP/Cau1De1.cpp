#include<bits/stdc++.h>
using namespace std;

int dem_ki_tu_in_hoa(string s, int n){
	if(n== 0)
		return 0;
	int dem = dem_ki_tu_in_hoa(s, n-1);
	if(s[n-1] >= 'A' && s[n-1] <= 'Z')
		dem++;
	return dem;
}
int chia_de_tri(string s, int l, int r){
	if(l == r){
		if(s[l] >= 'A' && s[l] <= 'Z')
			return 1;
		else	return 0;
	}
	int m = (l+r)/2;
	return chia_de_tri(s, l, m) + chia_de_tri(s, m+1, r);
}
int main(){
	string s = "Today is 1 greAte 7123 day!";
	int n = s.length();
	cout<<dem_ki_tu_in_hoa(s, n)<<endl;
	cout<<chia_de_tri(s, 0, n-1)<<endl;
	
	return 0;
}
