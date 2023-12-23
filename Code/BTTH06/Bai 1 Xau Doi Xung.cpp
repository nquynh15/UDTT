#include<bits/stdc++.h>
using namespace std;

bool check(char *s){
	for(int i=0; i<strlen(s)/2; i++){
		if(s[i] != s[strlen(s) - i -1])
			return false;
	}
	return true;
}


void XauConDoiXung(char *s, int k, char *r ){
	int start, end;

    if (s[k] != '\0') {
        start = end = k;
    } else {
        cout << "Chuoi het ki tu.\n";
        return;
    }

    while (start >= 0 && end < strlen(s)) {
        if (s[start] != s[end]) {
            break;
        }
        start--;
        end++;
    }

    int d = 0;
    for (int i = start + 1; i <= end - 1; i++) {
        r[d] = s[i];
        d++;
    }
    r[d] = '\0';
}

int main(){
	
	char str[] = "abbaduoeteoui";
	if(check(str))
		cout<<"Doi xung";
	else{
		cout<<"Khong doi xung";
		int k;
		cout<<"\nk = ";	cin>>k;
		if (k >= 0 && k < strlen(str)) {
            char r[100];
            XauConDoiXung(str, k, r);
            int i = 0;
            while (r[i] != '\0') {
                cout << r[i];
                i++;
            }
            cout << endl;
        } else {
            cout << "Gia tri k khong hop le.\n";
        }
		
	}	
	
	return 0;
}
