#include<bits/stdc++.h>
using namespace std;
struct ViTri{
		int nguoiThu;
		char  tenGhe;
};
void Swap(int &a,int &b){
	int tg=b;
	b=a;
	a=tg;

}
void view_config(ViTri a[],int n){
	for(int i=0;i<n;i++){
		if(a[i].nguoiThu==1){
			cout<<"Tung ngoi vi tri "<<a[i].tenGhe<<endl;
		}
		else if(a[i].nguoiThu==2){
			cout<<"Cuc ngoi vi tri "<<a[i].tenGhe<<endl;
		}
		else if(a[i].nguoiThu==3){
			cout<<"Truc ngoi vi tri "<<a[i].tenGhe<<endl;
		}
		else if(a[i].nguoiThu==4){
			cout<<"Mai ngoi vi tri "<<a[i].tenGhe<<endl;
		}
	}
	cout<<"---------------------"<<endl;
}
void view_config2(ViTri a[],int n){
	for(int i=0;i<n;i++){
		if(a[i].nguoiThu==0){
			cout<<"Tung ngoi vi tri "<<a[i].tenGhe<<endl;
		}
		else if(a[i].nguoiThu==1){
			cout<<"Cuc ngoi vi tri "<<a[i].tenGhe<<endl;
		}
		else if(a[i].nguoiThu==2){
			cout<<"Truc ngoi vi tri "<<a[i].tenGhe<<endl;
		}
		else if(a[i].nguoiThu==3){
			cout<<"Mai ngoi vi tri "<<a[i].tenGhe<<endl;
		}
	}
	cout<<"---------------------"<<endl;
}
void next_config(ViTri a[],int n,int i){
	int j=n-1;
	//tim vi tri vua du lon hon a[i]
	while(a[i].nguoiThu>=a[j].nguoiThu){
		j--;
	}
	//dao vi tri cua a[i] voi vi tri vua du lon hon a[i]
	Swap(a[i].nguoiThu,a[j].nguoiThu);
	//dao nguoc day
	j=n-1;
	int k=i+1;
	while(k<j){
		Swap(a[k].nguoiThu,a[j].nguoiThu);
		k++;
		j--;
	}
	
}
void list_config(int n){
	
	ViTri a[4]={
		{1,'A'},
		{2,'B'},
		{3,'C'},
		{4,'D'}
	};
	
	int i;
	do{
		view_config(a,n);
		i=n-2;
		while(i>-1&&a[i].nguoiThu>=a[i+1].nguoiThu){
			i--;
		}
		if(i>-1){
			next_config(a,n,i);
		}
	}while(i>-1);
}
void tryDoiViTri(ViTri a[],int k,int dd[], int &count){
	for(int i=0;i<4;i++){
		if(dd[i]==0){
			a[k].nguoiThu=i;
		if(k==3){//tim duoc phan tu cuoi
			count++;
			view_config2(a,4);
		}else{
			dd[i]=1;
			tryDoiViTri(a,k+1,dd, count);
			dd[i]=0;
		}
		}
	}
	
}

int main(){
	list_config(4);
	int dd[4]={0};
	ViTri a[4];
	a[0].tenGhe='A';
	a[1].tenGhe='B';
	a[2].tenGhe='C';
	a[3].tenGhe='D';
	int count=0;
	tryDoiViTri(a,0,dd, count);
	cout<<count<<endl;
	
	return 0;
	
}
