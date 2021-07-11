#include"library.h"

int a[deu];

void insertion_sort(int a[],int n){ // Sort up ascending
    int key,j;
    for (int i = 0; i < n; i ++){ 
        key = a[i];
        j = i - 1;
        while(j>=0 && key <=a[j]){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main(){
    cls;
    int n;        
    init_array(a, n);
    cout << "Array before sorting: ";
    printf_array(a, n);
    cout << "\nArray after sorting: ";
    insertion_sort(a, n);
    printf_array(a, n);
    pause;
}