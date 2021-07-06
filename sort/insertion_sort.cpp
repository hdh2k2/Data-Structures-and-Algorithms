#include"library.h"

int a[deu];

void insertion_sort(int a[],int n){ // Sort up ascending
    int key,j;
    loop_Ascending(0,n){
        key = a[i];
        j = i - 1;
        check(j,key,a[j]){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key; 
    }
}

void init_array(int a[], int &n){
    cout << "Input a number of element: ";
    cin >> n;
    loop_Ascending(0,n){
        cout << "Input element " << i + 1 << ": ";
        cin >> a[i];
    }
}

void printf_array(int a[],int n){
    loop_Ascending(0,n)
        cout << a[i] << " ";
}

int main(){
    cls;
    int n;        
    init_array(a, n);
    cout << "Array before sort: ";
    printf_array(a, n);
    cout << "\nArray after sort: ";
    insertion_sort(a, n);
    printf_array(a, n);
    pause;
}