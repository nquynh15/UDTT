#include<bits/stdc++.h>

using namespace std;

struct Laptop{
	string hangSX;
	string cauHinh;
	float giaBan;
};

void HienThi(Laptop l){
	cout<<left<<setw(10)<<l.hangSX<<setw(50)<<l.cauHinh<<setprecision(5)<<l.giaBan<<endl;
}

int main(){
	int n = 6;
	Laptop d[n] = {
		{"HP", "CPU 2.5GHz upto 3.5GHz-RAM 16GB-SSD 512GB", 17.7},
		{"ACER", "CPU 2.5GHz upto 3.5GHz-RAM 8GB-HDD 2TB", 21.8},
		{"DELL", "CPU 2.5GHz upto 3.5GHz-RAM 4GB-SSD 512GB", 25.6},
		{"SAMSUNG", "CPU 2.5GHz upto 3.5GHz-RAM 8GB-SSD 512GB", 34.8},
		{"LENOVO", "CPU 2.5GHz upto 3.5GHz-RAM 16GB-HDD 512GB", 31.6},
		{"LG", "CPU 2.5GHz upto 3.5GHz-RAM 16GB-HDD 512GB", 42.6}
	};
	for(int i=0; i<n; i++){
		HienThi(d[i]);
	}
	
	return 0;
}
