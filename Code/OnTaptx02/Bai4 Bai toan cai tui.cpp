#include<bits/stdc++.h>
using namespace std;

/*
chiec tui co kich thuoc s
danh sach d co n chiec dien thoai
dien thoai: nhan hieu, kich thuoc, gia ban
->co the lay duoc  bao nhieu chiec dien thoai bo vao tui 
de duoc tong gia ban lon nhat ma khong vuot qua kich thuoc tui
*/

struct DienThoai{
	string nhanHieu;
	int kichThuoc;
	int giaBan;
};
void HienThi(DienThoai s){
	cout<<left<<setw(15)<<s.nhanHieu<<setw(15)<<s.giaBan<<endl;
}
int Algo(int n, int s, DienThoai *d){
	int F[n+1][s+1];
	for(int j=0; j<=s; j++)
		F[0][j] = 0;
	for(int i=1; i<=n; i++){
		for(int j=0; j<=s; j++){
			F[i][j] = F[i-1][j];
			if(d[i].kichThuoc <= j && F[i][j] < d[i].giaBan + F[i-1][j-d[i].kichThuoc])
				F[i][j]  = d[i].giaBan + F[i-1][j-d[i].kichThuoc];
		}
	}
	return F[n][s];
}

void Result(int n, int s, DienThoai *d){
	cout<<"Tong gia tri lay duoc: "<<Algo(n, s, d)<<endl;
	int i=n, j = s;
	cout<<"Cac dien thoai da lay: "<<endl;
	while(i != 0){
		if(Algo(i, j, d) != Algo(i-1, j, d)){
			HienThi(d[i]);
			j = j-d[i].kichThuoc;
		}
		i--;
	}
}

int main(){
	int n = 5;
	DienThoai d[n] = {
		{"IPhone", 5, 10},
		{"Oppo", 4, 11},
		{"Vivo", 5, 10},
		{"Xiaomi", 5, 9},
		{"Redmi", 6, 10},
	};
	int s = 15;
	Result(n, s, d);
	
	return 0;
}

