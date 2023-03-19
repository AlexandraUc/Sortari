#include <iostream>
#include <fstream>
#include <chrono>
#include "mergeSort.h"
#include "quickSort.h"
#include "quickSort_random.h"
#include "shellSort.h"
#include "heapSort.h"
#include "radixSort_10.h"
#include "radixSort_2_10.h"
#include "radixSort_2^16.h"

using namespace std;
using namespace::chrono;

int v[100000000];
int cop[100000000];
int aux[100000000];

// Functie care verifica corectitudinea sortarii
bool verif(int v[], int cop[], int n){
    for(int i = 0; i < (n-1); i++)
        if(v[i] > v[i+1])
            return false;
    for(int i = 0; i < n; i++)
        if(v[i] != cop[i])
            return false;
    return true;
}

int main(){
    ifstream f("Test1.txt");
    int t, n, max;
    f >> t >> n >> max;

    for(int i = 0; i < n; i++){
        f >> v[i];
        cop[i] = v[i];
    }

    auto start = high_resolution_clock::now();
    
    //mergeSort(v, 0, n-1);
    //quickSort(v, n);
    //quickSort_random(v, n);
    //shellSort(v, n);
    //heapSort(v, n);
    //radixSort_10(v, n);
    //radixSort_2_10(v, n);
    //radixSort_2_16(v, n);
    //sort(v, v+n);
    
    auto stop = high_resolution_clock::now();
    auto medie_timp_ns = duration_cast<nanoseconds>(stop - start).count();
    auto medie_timp_ms = duration_cast<microseconds>(stop - start).count();
    auto medie_timp_s = duration_cast<seconds>(stop - start).count();

    sort(cop, cop+n);
    if(verif(v, cop, n) == true)
        cout << medie_timp_ns << " ns " << medie_timp_ms << " ms " << medie_timp_s << " s\n"; 
    else
        cout << "Esuat\n";

    f.close();
    return 0;
}