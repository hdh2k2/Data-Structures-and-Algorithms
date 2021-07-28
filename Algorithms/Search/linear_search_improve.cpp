#include"library.h"

int arr[deu];

bool linear_search_improve(int a[], int n, int x){
    if (x== a[n-1])  // Reduces 1 comparison, but not increases memory space
        return true;
    
    else{
        for (int i = 0;i< n-1;  i ++)
            if (arr[i] == x)
                return true;
        return false;
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

int main(){
    cls;
    int n,x;
    arr[n];
    init_array(arr, n);
    cout << "Input a number to find in array: ";
    cin >> x;
    cout << x << " in array: ";
    cout <<  (linear_search_improve(arr, n, x) == true ? "YES" : "NO");
    pause;
}