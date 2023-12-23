#include<bits/stdc++.h>
using namespace std;

void Dem(char *s, char *c, int &count){
	int n = strlen(s);
	int m = strlen(c);
	for(int i = 0; i<n; i++){
		int j= 0;
		while(j<m && s[i+j] == c[j])
			j++;
		if(j == m)
			count++;
	}
}

void ThayThe(char *s, char *c, char *r, char *f){
	int n = strlen(s);
	int m = strlen(c);
	int t = strlen(r);
	int k= 0;
	
    for (int i = 0; i < n; i++) {
        int match = 1;
        for (int j = 0; j < m; j++) {
            if (s[i + j] != c[j]) {
                match = 0;
                break;
            }
        }

        if (match) {
        	//thay the tu tu vi tri i den vi tri i+m-1
            for (int z = 0; z < t; z++) {
                f[k] = r[z];
                k++;
            }
            i += m - 1;
        } else {
            f[k] = s[i];
        }

        k++;
    }
    f[k] = '\0';
}

int main(){
	
	char s[] = "That family has a child, The child is a pretty girl.";
	char c[] = "child";
	char r[] = "children";
	int count = 0;
	Dem(s, c, count);
	if(count == 0)
		cout<<"Khong co tu 'child' trong doan van"<<endl;
	else{
		cout<<count<<endl;
		char final[100];
		ThayThe(s, c, r, final);
		int i=0;
		while(final[i] != '\0'){
			cout<<final[i];
			i++;
		}
		cout<<endl;
	}
	
	return 0;
}
