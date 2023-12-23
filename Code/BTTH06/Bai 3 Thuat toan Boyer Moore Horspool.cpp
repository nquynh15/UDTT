#include <bits/stdc++.h>

using namespace std;

int char_in_string(char c, char *p) {
    for (int i = 0; i < strlen(p); i++) {
        if (c == p[i]) {
            return i;
        }
    }
    return -1;
}

int Boyer_Moore_Horspool(char *s, char *p) {
    int dem = 0, v = strlen(p), i = v - 1;
    while (i < strlen(s)) {
        int x = v - 1;
    	int temp = i;
        while (x >= 0 && s[temp] == p[x]) {
            temp--;
            x--;
        }
        if (x < 0) {
            dem++;
            i = i + v;
        } else {
            int k = char_in_string(s[i], p);
            if (k < 0) {
                i = i + v;
            } else {
                i = i + v - k - 1;
            }
        }
    }
    return dem;
}

int main() {
    char s[] = "toi co 1000, Nam có 21000, Dong co 1000 va 500";
    char pattern[] = "1000";
    cout << Boyer_Moore_Horspool(s, pattern) << endl;

    return 0;
}

