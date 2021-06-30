#include<iostream>
#define deu 100

using namespace std;

int a[deu];

void insertion_sort(int a[],int n){ // Sort up ascending
    int key,j;
    for (int i = 1; i < n; i++){
        key = a[i];
        j = i - 1;
        while(j >= 0 && key <a[j]){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key; 
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
    insertion_sort(a, n);
    printf_array(a, n);
    system("pause");
}