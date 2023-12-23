#include<bits/stdc++.h>
using namespace std;

void HienThi(int a[], int n){
	for(int i=0; i<n; i++)
		cout<<a[i]<<"\t";
	cout<<endl;
}
//cach 1
void intervalScheduling(int n, float s[], float f[], int *schedule){
	float last_finish = f[0];
	schedule[0] = 1;
	for(int i=1; i<n; i++){
		if(s[i] >= last_finish){
			schedule[i] = 1;
			last_finish = f[i];
		}
	}
}
//cach 2
int *Schedule(int n, float s[], float f[]){
	int *result = new int[n];
	for(int i=0; i<n; i++)
		result[i] = 0;
	float last_finish = f[0];
	result[0] = 1;
	for(int i=1; i<n; i++){
		if(s[i] >= last_finish){
			result[i] = 1;
			last_finish = f[i];
		}
	}
	return result;
}
int main(){
	int n = 5;
	float s[n] = {8, 9, 10, 11, 12};
	float f[n] = {8.5, 11, 11.5, 12.5, 13};
	
	int schedule[n] = {0};
	intervalScheduling(n, s, f, schedule);
	HienThi(schedule, n);
	
	int *so = Schedule(n, s, f);
	HienThi(so, n);
	
	return 0;
}
