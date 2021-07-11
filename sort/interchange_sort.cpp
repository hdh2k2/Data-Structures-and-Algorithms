#include"library.h"

int a[deu];

void interchange_sort(int a[],int n){ // Sort up ascending
    for (int i = 0; i < n - 1 ;i ++)
        for ( int j = i + 1; j < n; j ++)
            if (a[i] > a[j])
                SWAP(a[i], a[j]);
}

int main(){
    cls;
    int n;
    init_array(a, n);
    cout << "Array before sorting: ";
    printf_array(a, n);
    cout << "\nArray after sorting: ";
    interchange_sort(a, n);
    printf_array(a, n);
    pause;
}