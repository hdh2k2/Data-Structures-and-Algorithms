#include"library.h"

int a[deu];

bool linear_search_recursive(int a[], int n, int x){
    int i = n - 1;
    if ( x == a[i])
        return true;

    if (n - 1 < 0)
            return false;
    else
        return linear_search_recursive(a, n - 1, x);
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
    a[n];
    init_array(a, n);
    cout << "Input a number to find in array: ";
    cin >> x;
    cout << x << " in array: ";
    cout <<  (linear_search_recursive(a, n, x) == true ? "YES" : "NO");
    pause;
}