#include <iostream>
using namespace std;

void Show(int x[], int k) {
    for (int i = 1; i <= k; i++) 
        cout << x[i] << " ";
    cout << endl;
}
//start: chi dinh phan tu bat dau de lua chon moi lan de quy
void Try(int k, int x[], int n, int d[], int currentIndex, int start) {
	if (currentIndex == k) {
        Show(x, k);
    }
    for (int i = start; i <= n; i++) {
        if (!d[i]) {
            x[currentIndex + 1] = i;
            d[i] = 1;
		    Try(k, x, n, d, currentIndex + 1, i+1);
            d[i] = 0;
        }
    }
}

int main() {
    int n, k;
    cout << "Nhap n: ";    cin >> n;
    cout << "Nhap k: ";    cin >> k;

    int x[k + 1], d[n + 1] = {0};
    Try(k, x, n, d, 0, 1);

    return 0;
}

