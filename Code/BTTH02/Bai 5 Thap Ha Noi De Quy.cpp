#include<bits/stdc++.h>

using namespace std;

void ThapHaNoi(int n, char a, char b, char c){
	if(n == 1)
		cout<<"Chuyen 1 dia tu "<<a<<" sang "<<c<<endl;
	else{
		ThapHaNoi(n-1, a, c, b);
		ThapHaNoi(1, a, b, c);
		ThapHaNoi(n-1, b, a, c);
	}
}

main(){
	char a = 'A', b = 'B', c = 'C';
	int n;
	cout<<"So dia can chuyen: ";	cin>>n;
	ThapHaNoi(n, a, b, c);
	
	return 0;
}