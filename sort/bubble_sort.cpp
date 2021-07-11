#include"library.h"

int a[deu];

void bubble_sort(int a[],int n){ // Sort up ascending
    bool check = false;
    for (int i = 0; i < n- 1; i ++){
        for (  int j =0 ; j < n - i - 1 ; j ++){
            if ( a[j]> a[j + 1]){
                SWAP(a[j], a[j + 1]);
                check = true;
            }
        }

        if (check == false)
            break;
    }
}

int main(){
    cls;
    int n;
    init_array(a, n);
    cout << "Array before sorting: ";
    printf_array(a, n);
    cout << "\nArray after sorting: ";
    bubble_sort(a, n);
    printf_array(a, n);
    pause;
}