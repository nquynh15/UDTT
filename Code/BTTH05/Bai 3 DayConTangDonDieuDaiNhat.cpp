#include<bits/stdc++.h>
using namespace std;

void Algorithm(int a[], int n, int *&T, int *&L){
    L = new int[n+2];
    T = new int[n+2];

    L[n+1] = 0;
    T[n+1] = 0;

    for(int i = n; i >= 0; i--){
        int jmax = n+1;
        for(int j = i+1; j <= n; j++){
            if(a[j] > a[i] && L[j] > L[jmax])
                jmax = j;
        }
        L[i] = L[jmax] + 1;
        T[i] = jmax;
    }
    
    
}

void Result(int a[], int n, int T[]){
    int k = T[0];
    cout << "Dãy con: ";
    while(k != n+1){
        cout << "a[" << k << "]: " << a[k] << " ";
        k = T[k];
    }
    cout << endl;
}

int main(){
    int n = 9;
    int a[n+2] = {INT_MIN, 1, 8, 3, 4, 9, 10, 5, 11, 7, INT_MAX};

    int *T, *L;    
    Algorithm(a, n, T, L);
    Result(a, n, T);

    delete L;
    delete T; 
    
    return 0;
}

