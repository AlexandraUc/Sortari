#include <algorithm>
using namespace std;

extern int aux[];
void countingSort_10(int v[], int n, int exp){
    int frecv[10];
    for(int i = 0; i < 10; i++)
        frecv[i] = 0;

    for(int i = 0; i < n; i++){
        int j = v[i] / exp;
        frecv[j % 10]++;
    }

    for(int i = 1; i < 10; i++)
        frecv[i] += frecv[i-1];

    int i = n-1;
    while(i >= 0){
        int j = v[i] / exp;
        aux[frecv[j % 10] - 1] = v[i];
        frecv[j % 10]--;
        i--;
    }

    for(i = 0; i < n; i++)
        v[i] = aux[i];
}

void radixSort_10(int v[], int n){
    int maxi = *max_element(v, v+n);
    int exp = 1;
    while(maxi / exp >= 1){
        countingSort_10(v, n, exp);
        exp *= 10;
    }
}