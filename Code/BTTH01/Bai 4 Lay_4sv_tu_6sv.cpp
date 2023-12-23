#include<bits/stdc++.h>
using namespace std;

void combination(map<int, string> mp, int n, int r, int index, map<int, string> data, int i){
	if (index == r){
		for (int j = 0; j < r; j++){
			cout << data[j] << ' ';
		}
		cout << "\n";
		return;
	}
	if (i >= n)	return;
	data[index] = mp[i];
	combination(mp, n, r, index + 1, data, i + 1);
	combination(mp, n, r, index, data, i + 1);
}
void print(map<int, string> mp, int n, int r) {
	map<int, string> data;
	combination(mp, n, r, 0, data, 0);
}

void view_config(string str[], int x[], int k){
	for(int i=0; i<= k; i++)
		cout<<str[x[i]]<<"\t";
	cout<<endl;
}

void LietKeCacPhanTu(string sinhvien[], int n, int k){
	int x[k];

	//Khoi tao ban dau
	for (int i = 0; i < k; i++) {
        x[i] = i;
    }
//	int i = k;
//	while( i>0 && x[i] == n-k+i){
//		i--;
//	}
//	if(i>0){
//		x[i]++;
//		for(int j=i+1; j<k; j++){
//			x[j]= x[i] + j-i;
//		}
//	}

}

main(){
	string s[] =  {"Trang", "Cong", "Trung", "Binh", "Hoan", "Mai"};
	int n=6, k= 4;
	//LietKeCacPhanTu(s, n, k);
	map<int, string> mp;
	for (int i = 0; i < 6; i++) mp[i] = s[i];
	print(mp, n, k);
	
	return 0;
}



