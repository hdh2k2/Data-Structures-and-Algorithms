#include"library.h"

int a[deu];

void binary_insertion_sort(int a[],int n){ // Sort up ascending
    int left, right, mid;
    int x; //save element 
    for (int i = 1; i < n ; i ++){
        x = a[i];
        left = 0;
        right = i - 1;
        while (left <= right){
            mid = (left + right) / 2;
            if (x< a[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }

        for (int j = i - 1; j >= left; j --)
            a[j + 1] = a[j];
        a[left] = x;
    }
}

int main(){
    cls;
    int n;
    init_array(a, n);
    cout << "Array before sorting: ";
    printf_array(a, n);
    cout << "\nArray after sorting: ";
    binary_insertion_sort(a, n);
    printf_array(a, n);
    pause;
}