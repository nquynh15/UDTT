#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cout << "Nhap so luong xau ky tu (5 <= n <= 10): ";
    cin >> n;

    char **d = new char*[n];

    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "Xau " << i + 1 << ": ";

        d[i] = new char[100]; 
        cin.getline(d[i], 100);
    }

    cout << "Danh sach xau ky tu:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Xau " << i + 1 << ": " << d[i] << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] d[i];
    }
    delete[] d;

    return 0;
}

