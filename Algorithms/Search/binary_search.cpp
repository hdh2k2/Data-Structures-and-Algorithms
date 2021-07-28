#include"library.h"

int a[deu];

bool binary_search(int a[], int n, int x){
    int left, right, mid;
    left = 0; right = n; // init index of element
    while (left <=right){
        mid = (left + right) / 2;
        if ( a[mid] > x )
            right = mid - 1;
        else if ( a[mid] < x)
            left = mid + 1;
        else if ( a[mid] == x)
            return true;
    }
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
    int n, x;
    init_array(a, n);
    cout << "Input a number to find in array: ";
    cin >> x;
    cout << x << " in array: ";
    cout <<  (binary_search(a, n, x) == true ? "YES" : "NO");
    pause;
}