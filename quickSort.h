#include <iostream>
using namespace std;

int medianaDin3(int v[], int st, int dr){
    int mij = (st+dr)/2;
    if((v[st] >= v[dr] && v[st] <= v[mij]) || (v[st] <= v[dr] && v[st] >= v[mij]))
        return st;
    if((v[dr] >= v[st] && v[dr] <= v[mij]) || (v[dr] <= v[st] && v[dr] >= v[mij]))
        return dr;
    if((v[mij] >= v[st] && v[mij] <= v[dr]) || (v[mij] <= v[st] && v[mij] >= v[dr]))
        return mij;
}

void quickSort(int v[], int n){
    if(n < 2) 
        return;

    int st, dr, poz_pivot, pivot;
    st = 0;
    dr = n - 1;
                                       
    poz_pivot = medianaDin3(v, st, dr);  
    pivot = v[poz_pivot];                                                                                              

    while(st <= dr){           
        while(v[st] < pivot)
            st++;
        while(v[dr] > pivot)
            dr--; 
                                                      
        if (st <= dr){
            swap(v[st], v[dr]);
            st++;
            dr--;
        }
    }

    quickSort(v, dr+1);
    quickSort(v+st, n-st);
}