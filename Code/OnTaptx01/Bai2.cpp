#include<bits/stdc++.h>
using namespace std;

/*: Cho tap S gom 7 ký tu S = {‘A’, ‘B’, ‘C’, ‘D’, ‘E’, ‘F’, ‘G’}. Hãy liet kê các cách 
lay 6 ký tu khác nhau tu tap S nói trên, cho biet so cách lay. Su dung phuong pháp sinh, 
sau dó su dung thuat toán quay lui.
*/

void next_config(int x[], int k, int i){
	x[i] +=1;
	i++;
	while(i<=k){
		x[i] = x[i-1]+1;
		i++;
	}
}
void view_config(int x[], int k){
	for(int i=1; i<=k; i++){
		if(x[i] == 1) cout<<"A\t";
		if(x[i] == 2) cout<<"B\t";
		if(x[i] == 3) cout<<"C\t";
		if(x[i] == 4) cout<<"D\t";
		if(x[i] == 5) cout<<"E\t";
		if(x[i] == 6) cout<<"F\t";
		if(x[i] == 7) cout<<"G\t";
	}
	cout<<endl;
}
void listing_configs(int k, int n, int &c){
	int i, x[k+1] = {0};
	for(i=1; i<=k; i++)
		x[i] = i;
	do{
		view_config(x, k);
		i = k;
		while(i>0 && x[i] == n-k+i)
			i--;
		if(i>0)
			next_config(x, k, i);
		c++;
	}while(i > 0);
} 
//PP SINH
void view_config(char c[], int k){
	for(int i=0; i<k; i++)
		cout<<c[i];
	cout<<endl;
}
void LayPhanTuBangQuayLui(char S[], int k, int index, char current[], int i) {
    if (i == k) {
        view_config(current, k);
        return;
    }

    if (index >= 7) {
        return;
    }
    // Bo qua phan tu hien tai
    LayPhanTuBangQuayLui(S, k, index + 1, current, i);
    // Chon phan tu hien tai
    current[i] = S[index];
    LayPhanTuBangQuayLui(S, k, index + 1, current, i + 1);
}

int main() {
	//PP Sinh
	int c = 0;
	listing_configs(6, 7, c);
	cout<<"So cach lay: "<<c<<endl;
	
	//PP Quay lui
    char S[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int k = 6;
    char current[6] = {};

    LayPhanTuBangQuayLui(S, k, 0, current, 0);

    return 0;
}

