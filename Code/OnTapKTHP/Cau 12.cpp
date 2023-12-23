#include<bits/stdc++.h>
using namespace std;

struct GoiHang{
	float khoiluong;
	float giatri;
};

float sum(int n, GoiHang h[], int index){
	if(index == n-1)
		return h[index].giatri;
	return h[index].giatri + sum(n, h, index+1);
}
void swap(GoiHang &d1, GoiHang &d2){
	GoiHang temp = d1;
	d1 = d2;
	d2 = temp;
}
void sort(int n, GoiHang d[]){
	for(int i=0; i<n; i++){
		for(int j=n-1; j>i; j--){
			if(d[j].giatri<d[j-1].giatri)
				swap(d[j], d[j-1]);
		}
	}
}

bool lay_goi_hang(int n, GoiHang *h, float c, int *r, int &g) {
    int i = 0;
    g = 0;
    float tong_giatri = 0;

    while (i < n) {
        if (tong_giatri + h[i].giatri <= c) {
            r[g] = i;
            tong_giatri += h[i].giatri;
            g++;
        }
        i++;
    }	
    
    return tong_giatri == c;
}
//int lay_goi_hang(int n, GoiHang *h, float c, int *r) {
//    int i = 0; 
//    int g = 0;
//    float tong_giatri = 0;
//
//    do{
//    	tong_giatri += h[i].giatri;
//    	r[g] = i;
//    	g++;
//    	i++;
//	}while(i<n && tong_giatri < c);
//
//    return g;
//}
void hien_thi(int n, GoiHang *d, int *r){
	for(int i=0; i<n; i++){
		cout<<d[r[i]].khoiluong<<"\t"<<d[r[i]].giatri<<endl;
	}
}
int main(){
	int n= 8;
	GoiHang h[n] = {
		{1, 1.2}, {3, 2.3}, {5, 2.7}, {4.6, 4.6}, {3, 2}, {6, 3.6}, {4, 2.2}, {3.3, 5.5}
	};
		
	sort(n, h);
	for(int i=0; i<n; i++){
		cout<<h[i].khoiluong<<"\t"<<h[i].giatri<<endl;
	}
	
	int index = 0;
	float s = sum(n, h, index);
	cout<<"Tong gia tri cac goi hang: "<<s<<endl;

	
	float c = 10;
	int r[10];
	int g;
	if(lay_goi_hang(n, h, c, r, g)){
		cout<<"Lay duoc "<<g<<" goi hang de tong gia tri bang "<<c<<": "<<endl;
		hien_thi(g, h, r);
	}
	else
		cout<<"Khong lay duoc goi hang nao de co tong gia tri bang "<<c<<endl;
		
	//Lay sao cho tong_giatri > c;
//	int g = lay_goi_hang(n, h, c, r);
//	if(g == 0)
//		cout<<"Khong lay duoc goi hang nao de co tong gia tri lon hon "<<c<<endl;
//	else{
//		cout<<"lay duoc "<<g<<" goi hang: "<<endl;
//		hien_thi(g, h, r);
//	}
	
	
	return 0;
}
