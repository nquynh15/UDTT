#include<bits/stdc++.h>
using namespace std;

// H�m cong hai chuoi so nguy�n lon
string addBigIntegers(string a, string b) {
    int carry = 0;
    string result = "";

    // �ao chuoi de bat dau cong tu phan don vi
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    // �am bao c�ng do dai
    while (a.length() < b.length()) a += '0';
    while (b.length() < a.length()) b += '0';

    for (int i = 0; i < a.length(); i++) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result += (sum % 10) + '0';
        carry = sum / 10;
    }

    // Neu c�n du, th�m v�o ket qua
    if (carry) {
        result += carry + '0';
    }

    // �ao ket qua de c� ket qua d�ng
    reverse(result.begin(), result.end());

    return result;
}

int main() {
    string m, n;

    // Nhap 2 so nguy�n duong m v� n
    cout << "Nhap so nguyen duong m: ";
    cin >> m;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;

    // T�nh tong v� hien thi
    string sum = addBigIntegers(m, n);
    cout << "Tong cua " << m << " va " << n << " la: " << sum << endl;

    return 0;
}

