#include<iostream>
#define deu 100

using namespace std;

int a[deu];

#if 0
    
    void swap (int &element1, int &element2){
        int temp;
        temp = element1;
        element1= element2;
        element2= temp;
    }

#endif //command for swap function

void merge(int a[], int left, int mid, int right){
    int *temp = new int[right - left + 1];
    int m;
    int i = left;
    int j = mid + 1;
    m = 0;
    while (!(i > mid && j > right )){
        if ((i <= mid && j <= right && a[i] < a[j]) || j>right){
            temp[m++] = a[i++];
        }

        else {
            temp[m++] = a[j++];
        }
    }

    for (int i = 0; i<m ; i ++){
        a[left + i] = temp[i];
    }

    delete[] temp;
}

void merge_sort(int a[],int left, int right){ // Sort up ascending
    if (left < right){
        int mid = (left + right) / 2;
        merge_sort(a, left, mid);
        merge_sort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

void init_array(int a[], int &n){
    cout << "Input a number of element: ";
    cin >> n;
    for (int i = 0; i < n; i ++){
        cout << "Input element " << i + 1 << ": ";
        cin >> a[i];
    }
}

void printf_array(int a[],int n){
    for (int i = 0; i < n; i ++)
        cout << a[i] << " ";
}

int main(){
    system("cls");
    
    int n;
    init_array(a, n);

    cout << "Array before sort: ";
    printf_array(a, n);
    cout << "\nArray after sort: ";
    merge_sort(a, 0, n - 1);
    printf_array(a, n);
    system("pause");
}