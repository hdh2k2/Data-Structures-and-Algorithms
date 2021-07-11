#include"library.h"

int a[deu];

void heapify(int a[], int n, int i){
    int largest = i;
    int _left_node = 2 * i + 1;
    int _right_node = 2 * i + 2;
    if ( _left_node< n && a[_left_node] > a[largest])
        largest = _left_node;
    if (_right_node < n && a[_right_node] > a[largest])
        largest = _right_node;

    if ( largest != i){ // if largest is not root
        SWAP(a[i], a[largest]);
        heapify(a, n, largest); // Recursively heapify the affected sub-tree
    }

}

void heap_sort(int a[],int n){ // Sort up ascending
    for (int i = n / 2 - 1; i >= 0;i --){
        heapify(a, n, i);
    }

    for ( int i =  n -1; i > 0 ; i --){
        SWAP(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main(){
    cls;
    int n;
    init_array(a, n);
    cout << "Array before sorting: ";
    printf_array(a, n);
    cout << "\nArray after sorting: ";
    heap_sort(a, n);
    printf_array(a, n);
    pause;
}