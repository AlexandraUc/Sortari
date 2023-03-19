#include <iostream>
using namespace std;

void quickSort_random(int v[], int n){
    if(n < 2) 
        return;

    int st, dr, poz_pivot, pivot;
    st = 0;
    dr = n - 1;
                                       
    srand(time(NULL));
    poz_pivot = st + rand() % (dr - st);
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

    quickSort_random(v, dr+1);
    quickSort_random(v+st, n-st);
}
