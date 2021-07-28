#include"library.h"

int a[deu];

bool jump_search(int a[], int n, int x){
    int step = (int)sqrt(n);
    int prev = 0 ;
    int r = min(step, n) - 1;
    while(a[r]< x){
        prev= step;
        step += (int)sqrt(n);
        if (prev >= n)
            return false;
        r=min(step,n) - 1;

    }

    while(a[prev] < x){
        prev++;
        if (prev == min ( step, n ))
            return false;
    }

    if( a[prev] == x)
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
    cout <<  (jump_search(a, n, x) == true ? "YES" : "NO");
    pause;
}