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

void interchange_sort(int a[],int n){ // Sort up ascending
    for (int i = 0; i < n - 1 ;i ++)
        for ( int j = i + 1; j < n; j ++)
            if (a[i] > a[j])
                swap(a[i], a[j]);
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
    interchange_sort(a, n);
    printf_array(a, n);
    system("pause");
}