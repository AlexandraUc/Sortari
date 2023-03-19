extern int aux[];
void interclasare(int v[], int st, int mij, int dr){
    int n=-1;
    int i = st;
    int j = mij+1;

    while(i <= mij && j <= dr)
        if(v[i] <= v[j])
            aux[++n] = v[i++];
        else
            aux[++n] = v[j++];

    while(i <= mij)
        aux[++n] = v[i++];

    while(j <= dr)
        aux[++n] = v[j++];

    for(i = 0; i <= n; i++)
        v[st+i] = aux[i];
}

void mergeSort(int v[], int st, int dr){
    if(st < dr){
        int mij = (st+dr) / 2;
        mergeSort(v, st, mij);
        mergeSort(v, mij+1, dr);
        interclasare(v, st, mij, dr);
    }
}