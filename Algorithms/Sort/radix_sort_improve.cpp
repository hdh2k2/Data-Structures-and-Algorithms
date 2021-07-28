#include"library.h"

int a[deu];
 
void radix_sort(int arr[], int n) {
    int max = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > max)max = a[i];
	}
	int d = 0;
	int temp = max;
	int pow = 1;
	while (temp) {
		temp = temp / 10;
		d++;
	}
	int i = 0;
	int *C = new int[10];
	int * B = new int[n];
	while (i < d) {
		for (int i = 0; i < 10; i++)C[i] = 0;
		for (int i = 0; i < n; i++)C[(a[i]/pow) % 10]++;
		for (int i = 1; i < 10; i++)C[i] = C[i] + C[i - 1];
		for (int i = n-1; i >=0; i--) {
			B[C[(a[i] / pow) % 10] - 1] = a[i];
			C[(a[i] / pow) % 10]--;
		}
		for (int i = 0; i < n; i++)a[i] = B[i];
		pow = pow * 10;
		i = i + 1;
	}
	delete[]C;
	delete[]B;
}

int main(){
    cls;
    int n;
    init_array(a, n);
    cout << "Array before sorting: ";
    printf_array(a, n);
    cout << "\nArray after sorting: ";
    radix_sort(a, n);
    printf_array(a, n);
    pause;
}