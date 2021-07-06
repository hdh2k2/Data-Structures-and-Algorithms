#include"library.h"

int a[deu];

bool interpolation_search(int a[], int n, int x){
    int low = 0, high = n - 1, mid;
    while(a[low] <= x && a[high] >= x){
        if (a[low] - a[high] == 0)
            return (low + high) / 2;
        mid = low + ((x - a[low]) * (high - low)) / (a[high] - a[low]);
        if ( a[mid] < x )
            low = mid + 1;
        else if ( a[mid] > x)
            high = mid - 1;
        else
            return true;
    }

    if( a[low] == x)
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
    int n, x;
    init_array(a, n);
    cout << "Input a number to find in array: ";
    cin >> x;
    cout << x << " in array: ";
    cout <<  (interpolation_search(a, n, x) == true ? "YES" : "NO");
    pause;
}