#include"library.h"

int a[deu];

int partition(int a[], int left, int right){
    int pivot = a[right];
    int index = left - 1;
    for (int i = left; i <=right - 1 ; i ++){
        if ( a[i] < pivot){
            index++;
            SWAP(a[index], a[i]);
        }                                      
    } 
    index++;
    SWAP(a[index], a[right]);
    return index;
}


void quick_sort(int a[],int left, int right){ // Sort up ascending
    if ( left < right ){
        int iPiVot = partition(a, left, right);
        quick_sort(a, left, iPiVot - 1);
        quick_sort(a, iPiVot + 1, right);

    }

}

int main(){
    cls;
    int n;
    init_array(a, n);
    cout << "Array before sorting: ";
    printf_array(a, n);
    cout << "\nArray after sorting: ";
    quick_sort(a, 0, n - 1);
    printf_array(a, n);
    pause;
}