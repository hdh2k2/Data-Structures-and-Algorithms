#include<iostream>
#define deu 100
#define loop(n) for (int i = 0; i < n; i ++)
#define check(a,b, c) while (a>=0 && b < c)
#define cls system("cls")
#define pause system("pause")

using namespace std;

int a[deu];

void insertion_sort(int a[],int n){ // Sort up ascending
    int key,j;
    loop(n){
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
    loop(n){
        cout << "Input element " << i + 1 << ": ";
        cin >> a[i];
    }
}

void printf_array(int a[],int n){
    loop(n)
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