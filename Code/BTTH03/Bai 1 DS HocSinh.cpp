#include<bits/stdc++.h>

using namespace std;

struct HocSinh{
	char ten[7];
	char hoDem[20];
	int namSinh;
	char diaChi[20];
};
HocSinh hs[6] = {
	{"Anh", "Pham Van", 2001, "Ha Noi"},
	{"Son", "Tran Xuan", 2000, "Hai Phong"},
	{"Quang", "Dang Ngoc", 1999, "Hai Duong"},
	{"Lam", "Ma Van", 2002, "Thai Binh"},
	{"Huong", "Nguyen Mai", 2000, "Nam Dinh"},
	{"Anh", "Hoang Ngoc", 2002, "Ha Nam"},
};

void HienThi(int n, HocSinh s[]){
	for(int i=0; i<n; i++){
		cout<<left<<setw(10)<<s[i].ten<<setw(20)<<s[i].hoDem<<setw(10)<<s[i].namSinh<<setw(30)<<s[i].diaChi<<endl;
	}
}

void TronMang(HocSinh s[], int l, int r, int m){
	int n1 = m - l + 1;
	int n2 = r - m;
	HocSinh lhs[n1];
	HocSinh rhs[n2];
	for(int i=0; i<n1; i++){
		lhs[i] = s[i];
	}
	for(int i=0; i<n2; i++){
		rhs[i] = s[m+i];
	}
	int i=0, j=0, k = l;
	while(i<n1 && j < n2){
		if(lhs[i].ten <= rhs[j].ten){
			s[k] = lhs[i];
			i++;
		}
		else{
			s[k] = rhs[j];
			j++;
		}
		k++;
	}
	while(i < n1){
		s[k] = lhs[i];
		i++;	k++;
	}
	while(j < n2){
		s[k] = rhs[j];
		j++;	k++;
	}
}

void SapXep(HocSinh s[], int l, int r){
	if(l < r){
		int m = l + (r-l)/2;
		SapXep(s, l, m);
		SapXep(s, m+1, r);
		TronMang(s, l, r, m);
	}
}
void TimKiem(HocSinh s[], char tenTim[7]){
	
}
main(){
	
	HienThi(6, hs);
	cout<<"=============================="<<endl;
	SapXep(hs, 0, 5);
	HienThi(6, hs);
	
	return 0;
}
