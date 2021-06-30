#include<iostream>
#define deu 100

using namespace std;

int a[deu];

bool binary_search_recursive(int a[], int n, int x){
    int left, right, mid;
   
    left = 0; right = n - 1; // init index of element

    if (left > right)
        return false;

    else{
        mid = (left + right) / 2;
        if ( a[mid] > x )
            return binary_search_recursive(a, mid - 1, x);
        if ( a[mid] < x)
            return binary_search_recursive(a, mid + 1, x);
        if ( a[mid] == x)
            return true;
    }



}

int main(){
    system("cls");
    int n, x;
    cout << "Input a number of element: ";
    cin >> n;
    for (int i = 0; i < n; i ++){
        cout << "Input element " << i + 1 << ": ";
        cin >> a[i];
    }

    cout << "Input a number to find in array: ";
    cin >> x;
    cout << x << " in array: ";
    cout <<  (binary_search_recursive(a, n, x) == 1 ? "YES" : "NO");
    system("pause");

}