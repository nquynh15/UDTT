#include<bits/stdc++.h>
using namespace std;

// Hàm cong hai chuoi so nguyên lon
string addBigIntegers(string a, string b) {
    int carry = 0;
    string result = "";

    // Ðao chuoi de bat dau cong tu phan don vi
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    // Ðam bao cùng do dai
    while (a.length() < b.length()) a += '0';
    while (b.length() < a.length()) b += '0';

    for (int i = 0; i < a.length(); i++) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result += (sum % 10) + '0';
        carry = sum / 10;
    }

    // Neu còn du, thêm vào ket qua
    if (carry) {
        result += carry + '0';
    }

    // Ðao ket qua de có ket qua dúng
    reverse(result.begin(), result.end());

    return result;
}

int main() {
    string m, n;

    // Nhap 2 so nguyên duong m và n
    cout << "Nhap so nguyen duong m: ";
    cin >> m;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;

    // Tính tong và hien thi
    string sum = addBigIntegers(m, n);
    cout << "Tong cua " << m << " va " << n << " la: " << sum << endl;

    return 0;
}

