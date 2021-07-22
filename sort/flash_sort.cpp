#include"library.h"

int a[deu];

void flash_sort(int a[],int n){ // Sort up ascending
    double scaleFactor = 0.1;
    int *l, nmin, nmax, i, j, k, nmove;
    // m is usually chosen to be 0.1 * n
    const size_t m = int(scaleFactor * n);

        l = (int *)calloc(m, sizeof(int));
    nmin = 0;
    nmax = 0;
    for (i = 0; i < n; i++){
        if (a[i] < a[nmin]) {
            nmin = i;
        }
        if (a[i] > a[nmax]) {
            nmax = i;
        }
    }
    if (a[nmax] == a[nmin]) {
        // array is sorted (max = min)
        return; 
    }

    int c1 = double(m - 1.0) / double(a[nmax] - a[nmin]);
    int min = a[nmin];

    for (i = 0; i < n; ++i){
        k = int(c1 * (a[i] - min));
        ++l[k];
    }

    for (k = 1; k < m; ++k){
        l[k] += l[k - 1];
    }

    int hold = a[nmax];
    a[nmax] = a[0];
    a[0] = hold;

    int flash;
    nmove = 0;
    j = 0;
    k = m - 1;

    while (nmove < n - 1){
        while (j > l[k] - 1){
            j++;
            k = int(c1 * (a[j] - min));
        }

        flash = a[j];
        while (j != l[k]){
            k = int(c1 * (flash - min));
            l[k]--;
            hold = a[l[k]];
            a[l[k]] = flash;
            flash = hold;
            nmove++;
        }
    }

    for (i = 1; i < n; ++i){
        hold = a[i];
        j = i - 1;
        while (j >= 0 && hold < a[j]){
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = hold;
    }

    free(l);
}

int main(){
    system("cls");
    int n;
    init_array(a, n);
    cout << "Array before sorting: ";
    printf_array(a, n);
    cout << "\nArray after sorting: ";
    flash_sort(a, n);
    printf_array(a, n);
    system("pause");
}