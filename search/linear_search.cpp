#include<iostream>
#define deu 100

using namespace std;

int arr[deu];

bool linear_search(int a[], int n, int x){
    for (int i = 0;i< n;  i ++)
        if (arr[i] == x)
            return true;
    return false;
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