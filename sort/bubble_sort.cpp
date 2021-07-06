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

void bubble_sort(int a[],int n){ // Sort up ascending
    bool check = false;
    for (int i = 0; i < n- 1; i ++){
        for (  int j =0 ; j < n - i - 1 ; j ++){
            if ( a[j]> a[j + 1]){
                swap(a[j], a[j + 1]);
                check = true;
            }
        }

        if (check == false)
            break;
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
    bubble_sort(a, n);
    printf_array(a, n);
    pause;
}