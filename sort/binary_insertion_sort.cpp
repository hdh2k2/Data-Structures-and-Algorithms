#include"library.h"

int a[deu];

#if 0
    
    void swap (int &element1, int &element2){
        int temp;
        temp = element1;
        element1= element2;
        element2= temp;
    }

#endif //command for swap function

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
    binary_insertion_sort(a, n);
    printf_array(a, n);
    pause;
}