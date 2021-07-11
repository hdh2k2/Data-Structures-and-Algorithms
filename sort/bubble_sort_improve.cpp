#include"library.h"

int a[deu];

void bubble_sort_improve(int a[],int n){ // Sort up ascending
    for (int i = 0;i < n  - 1; i ++)
        for (int j = n - 1; j > i;j --)
            if (a[j] < a[j-1])
                SWAP(a[j], a[j - 1]);
}

int main(){
    cls;
    int n;
    init_array(a, n);
    cout << "Array before sorting: ";
    printf_array(a, n);
    cout << "\nArray after sorting: ";
    bubble_sort_improve(a, n);
    printf_array(a, n);
    pause;
}