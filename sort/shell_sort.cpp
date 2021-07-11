#include"library.h"

int a[deu];

void shell_sort(int a[],int n){ // Sort up ascending
    for (int gap = n / 2; gap > 0; gap/=2){
        for (int i = gap; i < n; i ++){
            int temp = a[i];
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -=gap)
                a[j] = a[j - gap];
            a[j] = temp;
        }
    }
}

int main(){
    cls;
    int n;
    init_array(a, n);
    cout << "Array before sorting: ";
    printf_array(a, n);
    cout << "\nArray after sorting: ";
    shell_sort(a, n);
    printf_array(a, n);
    pause;
}