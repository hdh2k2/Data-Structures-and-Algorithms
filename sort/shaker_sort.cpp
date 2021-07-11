#include"library.h"

int a[deu];

void shaker_sort(int a[],int n){ // Sort up ascending
    int left = 0;
    int right = n - 1;
    int k = n - 1;
    while ( left < right){
        for (int j = right; j >left; j --){
            if (a[j] < a[j-1]){
                SWAP(a[j], a[j - 1]);
                k = j;
            }
        }

        left = k;
        for (int j = left; j < right; j ++){
            if (a[j] > a[j+1]){
                SWAP(a[j], a[j + 1]);
                k = j;
            }
        }
        right = k;
    }
}

int main(){
    cls;
    int n;
    init_array(a, n);
    cout << "Array before sorting: ";
    printf_array(a, n);
    cout << "\nArray after sorting: ";
    shaker_sort(a, n);
    printf_array(a, n);
    pause;
}