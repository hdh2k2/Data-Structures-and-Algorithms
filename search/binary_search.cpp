#include<iostream>
#define deu 100

using namespace std;

int a[deu];

bool binary_search(int a[], int n, int x){
    int left, right, mid;

    left = 0; right = n - 1; // init 
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
    cout <<  (binary_search(a, n, x) == 1 ? "YES" : "NO");
    system("pause");

}