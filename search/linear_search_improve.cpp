#include<iostream>
#define deu 100

using namespace std;

int arr[deu];

bool linear_search(int a[], int n, int x){
    if (x== a[n-1])  // Reduces 1 comparison, but not increases memory space
        return true;
    
    else{
        for (int i = 0;i< n-1;  i ++)
            if (arr[i] == x)
                return true;
        return false;
    }
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