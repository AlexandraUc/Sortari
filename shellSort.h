void shellSort(int v[], int n){
    for(int h = n/2; h > 0; h /= 2){
        for(int i = h; i < n; i++){
            int aux = v[i];
            int j = i;
            while(j >= h && v[j-h] > aux){
                v[j] = v[j-h];
                j -= h;
            }
            v[j] = aux;
        }
    }
}