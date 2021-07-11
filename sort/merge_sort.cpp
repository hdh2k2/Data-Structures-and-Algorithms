#include"library.h"

int a[deu];

void merge(int a[], int left, int mid, int right){
    int *temp = new int[right - left + 1];
    int m;
    int i = left;
    int j = mid + 1;
    m = 0;
    while (!(i > mid && j > right )){
        if ((i <= mid && j <= right && a[i] < a[j]) || j>right){
            temp[m++] = a[i++];
        }

        else {
            temp[m++] = a[j++];
        }
    }

    for (int i = 0; i<m ; i ++){
        a[left + i] = temp[i];
    }

    delete[] temp;
}

void merge_sort(int a[],int left, int right){ // Sort up ascending
    if (left < right){
        int mid = (left + right) / 2;
        merge_sort(a, left, mid);
        merge_sort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

int main(){
    cls;
    int n;
    init_array(a, n);

    cout << "Array before sorting: ";
    printf_array(a, n);
    cout << "\nArray after sorting: ";
    merge_sort(a, 0, n - 1);
    printf_array(a, n);
    pause;
}