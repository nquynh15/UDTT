#include<bits/stdc++.h>
using namespace std;

struct XeMay{
	string hoTen;
	string noiDangKy;
	string hangSX;
};

void HienThi(XeMay a){
	cout<<left<<setw(18)<<a.hoTen<<setw(10)<<a.noiDangKy<<setw(10)<<a.hangSX<<endl;
}
void HienThiDanhSach(XeMay a[], int n, int i){
	if(i == n)
		return ;
	else{
		HienThi(a[i]);
		HienThiDanhSach(a, n, i+1);
	}
}
int DemXeMay(XeMay a[], int l, int r, int &count){
	if(l == r){
		if(a[l].noiDangKy == "Ha Tay"){
			HienThi(a[l]);
			return count++;
		}
	}
	else{
		int m = (l+r)/2;
		return DemXeMay(a, l, m, count) + DemXeMay(a, m+1, r, count);
	}
}
void Show(XeMay a[], int b[], int n){
	for(int i=0; i<n; i++)
		cout<<setw(18)<<a[i].hoTen<<": "<<b[i]<<"\t";
	cout<<endl;
}
void Try(XeMay a[], int b[], int n, int k, int d[], int &c){
	for(int i=0; i<n; i++){
		if(d[i] == 0){
			b[k] = i;
			if(k == n){
				c++;
				Show(a, b, n);
			}
			else{
				d[i] = 1;
				Try(a, b, n, k+1, d, c);
				d[i] = 0;				
			}
			
		}
	}
}
int main(){
	int n= 7;
	XeMay x[n] = {
		{"Nguyen Manh", "Ha Tay", "Honda"},
		{"Nguyen Anh", "Ha Noi", "Honda"},
		{"Nguyen Linh", "Hai Duong", "Yamada"},
		{"Nguyen Long", "Ha Nam", "Suzuki"},
		{"Nguyen Nam", "Ha Tay", "Honda"},
		{"Nguyen Minh", "Hai Phong", "Yamaha"},
		{"Nguyen Quynh", "Bac Ninh", "Honda"}
	};
	
	/*	
	HienThiDanhSach(x, n, 0);
	
	int c = 0;
	DemXeMay(x, 0, n-1, c);
	if(c == 0)
		cout<<"Khong co ai dang ky xe o Ha Tay";
	else
		cout<<c<<endl;
	*/
	int b[n], d[n] = {0};
	for(int i=0; i<n; i++)
		b[i] = i;
	
	int count = 0;
	Try(x, b, n, 0, d, count);
	cout<<count<<endl;
	
	return 0;
	
}
