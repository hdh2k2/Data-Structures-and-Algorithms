#include"library.h"

int a[deu];

void selection_sort(int a[],int n){ // Sort up ascending
    int index_min_of_element;
    for (int i =0; i < n - 1; i++){
        index_min_of_element = i;
        for (int j = i + 1; j < n; j ++){
             if (a[j] < a[index_min_of_element]){
                  index_min_of_element = j;
             }
        }

        SWAP(a[i], a[index_min_of_element]);
    }
}

int main(){
    cls;
    int n;
    init_array(a, n);

    cout << "Array before sorting: ";
    printf_array(a, n);
    cout << "\nArray after sorting: ";
    selection_sort(a, n);
    printf_array(a, n);
    pause;
}