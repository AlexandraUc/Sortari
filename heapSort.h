#include <iostream>
using namespace std;

void heapify(int v[], int n, int i){
    int maxi = i;
    int st = 2*i+1;
    int dr = 2*i+2;

    if(st < n && v[st] > v[maxi])
        maxi = st;
    
    if(dr < n && v[dr] > v[maxi])
        maxi = dr;
    
    if(maxi != i){
        swap(v[maxi], v[i]);
        heapify(v, n, maxi);
    }
}

void heapSort(int v[], int n){
    for(int i = n/2-1; i >= 0; i--)
        heapify(v, n, i);
    
    for(int i = n-1; i >= 0; i--){
        swap(v[i], v[0]);
        heapify(v, i, 0);
    }
}