#include<iostream>
#define deu 100

using namespace std;

int a[deu];

#if 0
    
    void swap (int &element1, int &element2){
        int temp;
        temp = element1;
        element1= element2;
        element2= temp;
    }

#endif //command for swap function

int partition(int a[], int left, int right){
    int pivot = a[right ];
    int index = left - 1;
    for (int i = left; i <=right - 1 ; i ++){
        if ( a[i] < pivot){
            index++;
            swap(a[index], a[i]);
        }
    }
    index++;
    swap(a[index], a[right]);
    return index;
}


void quick_sort(int a[],int left, int right){ // Sort up ascending
    if ( left < right ){
        int iPiVot = partition(a, left, right);
        quick_sort(a, left, iPiVot - 1);
        quick_sort(a, iPiVot + 1, right);

    }

}

void init_array(int a[], int &n){
    cout << "Input a number of element: ";
    cin >> n;
    for (int i = 0; i < n; i ++){
        cout << "Input element " << i + 1 << ": ";
        cin >> a[i];
    }
}

void printf_array(int a[],int n){
    for (int i = 0; i < n; i ++)
        cout << a[i] << " ";
}

int main(){
    system("cls");
    
    int n;
    init_array(a, n);

    cout << "Array before sort: ";
    printf_array(a, n);
    cout << "\nArray after sort: ";
    quick_sort(a, 0, n - 1);
    printf_array(a, n);
    system("pause");
}