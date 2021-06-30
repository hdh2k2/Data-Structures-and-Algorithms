#include<iostream>
#define deu 100

using namespace std;

int arr[deu];

bool linear_search(int a[], int n, int x){
    int i = n - 1;
    if ( x == a[i])
        return true;

    if (n - 1 < 0)
            return false;
    else
        return linear_search(a, n - 1, x);
}

int main(){
    system("cls");
   
    int n,x;
    arr[n];
    cout << "Input a number of element: ";
    cin >> n;

    for (int i = 0; i< n; i++){
        cout << "Input element " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "Input a number to find in array: ";
    cin >> x;
    cout << x << " in array: ";
    cout <<  (linear_search(arr, n, x) == 1 ? "YES" : "NO");
    system("pause");
    
}