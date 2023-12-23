#include<bits/stdc++.h>
using namespace std;

struct Flight{
	string soHieu;
	float giaVe;
	int soGhe;
};
//khoi tao danh sach
Flight f[7] = {
	{"VN001", 1250000, 158},
	{"VN002", 1050000, 162},
	{"VN003", 850000, 156},
	{"VN004", 650000, 160},
	{"VN005", 550000, 164},
	{"VN006", 1250000, 152},
	{"VN007", 1450000, 156}	
};

void HienThi(Flight a){
	cout<<left<<setw(10)<<a.soHieu<<setw(10)<<setprecision(10)<<a.giaVe<<setw(10)<<a.soGhe<<endl;
}
void HienThiTheoGiaVe(Flight a[], int index, int n){	
	if(index < n){
		if(a[index].giaVe > 700000)
			HienThi(a[index]);
		HienThiTheoGiaVe(a, index + 1, n);
	}
		
}
float GiaVeThapNhat(Flight a[], int l, int r){
	if(l==r)
		return l;
	int m = (l+r)/2;
	float min1 = GiaVeThapNhat(a, l, m);
	float min2 = GiaVeThapNhat(a, m+1, r);
	if(min1 <= min2)
		return min1;
	else
		return min2;		
}
void Show(string soHieuChon[], int k){
	for(int i=0; i<k; i++)
		cout<<soHieuChon[i]<< " ";
	cout<<endl<<endl;
}
void Try(Flight b[], int n, string soHieuChon[], int k, int d[],int currIndex, int &count){

	if (k == 0) {
		count++;
        Show(soHieuChon, 4);
        return;
    }

    for (int i = currIndex; i < n; i++) {
        if (!d[i]) {
            soHieuChon[4 - k] = b[i].soHieu;
            d[i] = 1;
            Try(b, n, soHieuChon, k - 1, d, i+1, count); // Giam giá tri k de chon chuyen bay tiep theo
            d[i] = 0; // Ðat lai trang thái cua chuy?n bay sau khi ch?n xong
        }
    }
}
main(){
	
	cout<<"Cac chuyen bay co gia ve tren 70000: "<<endl;
	HienThiTheoGiaVe(f, 0, 7);  
	cout<<"Chuyen bay co gia ve thap nhat: "<<endl;
	int indexMin = GiaVeThapNhat(f, 0, 6);
	HienThi(f[indexMin]);
	
	int count = 0, d[10] = {0};
	string soHieuChon[4];
	Try(f, 7, soHieuChon, 4, d, 0, count);
	cout<<endl<<count<<endl;
	return 0;
}
