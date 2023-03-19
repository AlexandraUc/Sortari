#include <algorithm>
using namespace std;

extern int aux[];
void countingSort_2_16(int v[], int n, int exp){
    int x = 1 << 16;
    int frecv[1 << 16];
    for(int i = 0; i < x; i++)
        frecv[i] = 0;
        
    for(int i = 0; i < n; i++){
        int j = v[i] / exp;
        frecv[j % x]++;
    }

    for(int i = 1; i < x; i++)
        frecv[i] += frecv[i-1];

    int i = n-1;
    while(i >= 0){
        int j = v[i] / exp;
        aux[frecv[j % x] - 1] = v[i];
        frecv[j % x]--;
        i--;
    }

    for(i = 0; i < n; i++)
        v[i] = aux[i];
}

void radixSort_2_16(int v[], int n){
    int maxi = *max_element(v, v+n);
    long long exp = 1;
    while(maxi / exp >= 1){
        countingSort_2_16(v, n, exp);
        exp = exp << 16;
    }
}