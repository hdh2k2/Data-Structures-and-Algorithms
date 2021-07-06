#include"library.h"

int arr[deu];

bool linear_search(int a[], int n, int x){
    for (int i = 0;i< n;  i ++)
        if (arr[i] == x)
            return true;
    return false;
}

void init_array(int a[], int &n){
    cout << "Input a number of element: ";
    cin >> n;
    loop_Ascending(0,n){
        cout << "Input element " << i + 1 << ": ";
        cin >> a[i];
    }
}

int main(){
    cls;
    int n,x;
    arr[n];
    init_array(arr, n);
    cout << "Input a number to find in array: ";
    cin >> x;
    cout << x << " in array: ";
    cout <<  (linear_search(arr, n, x) == true ? "YES" : "NO");
    pause;
}