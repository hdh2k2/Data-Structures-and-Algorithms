#include"library.h"

int a[deu];

bool binary_search_recursive(int a[], int x, int left, int right){
    int mid;
    if (left > right)
        return false;      
    else{
        mid = (left + right) / 2;
        if ( a[mid] > x )
            return binary_search_recursive(a, x, left, mid - 1);
        if ( a[mid] < x)
            return binary_search_recursive(a, x, mid + 1, right);
        if ( a[mid] == x)
            return true;
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
    int n, x;
    init_array(a, n);
    cout << "Input a number to find in array: ";
    cin >> x;
    cout << x << " in array: ";
    cout <<  (binary_search_recursive(a, x, 0, n-1) == true ? "YES" : "NO");
    system("pause");

}