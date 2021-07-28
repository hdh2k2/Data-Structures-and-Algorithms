#include"library.h"

int a[deu];

void counting_sort(int *a , int n){
	int max = 0;
	for (int i = 0; i < n; i++) { if (max < a[i])max = a[i]; }
	int * C = new int[max + 1];
	for (int i = 0; i <= max; i++)C[i] = 0;
	int * b = new int[n];
	for (int i = 0; i < n; i++)
	{
		C[a[i]] = C[a[i]] + 1;
	}
	for (int i = 1; i <= max; i++)
	{
		
		C[i] = C[i] + C[i - 1];
	}
	//for (int i = 0; i <= max; i++)cout << C[i] << '\t';
	//cout << endl;
	for (int i = n - 1; i >= 0; i--) {
		b[C[a[i]]-1] = a[i];
		C[a[i]] = C[a[i]] -1;
	}
	for (int i = 0; i < n; i++)a[i] = b[i];
	delete[]b;
	delete[]C;
}

int main(){
    cls;
    int n;
    init_array(a, n);
    cout << "Array before sorting: ";
    printf_array(a, n);
    cout << "\nArray after sorting: ";
    counting_sort(a, n);
    printf_array(a, n);
    pause;
}