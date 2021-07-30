#include"library.h"

int a[deu];

void quick_sort(int a[], int left, int right){
	int i = left, j = right;
	int pivot = a[(left + right)/2];

	while (i <= j){
		while (a[i] < pivot) ++i;
		while (pivot < a[j]) --j;

		if (i <= j){
			swap(a[i], a[j]);
			++i;
			--j;
		}
	}
	if (i < right) quick_sort(a, i, right);
	if (left < j) quick_sort(a, left, j);
}

int main(){
    cls;
    int n;
    init_array(a, n);
    cout << "Array before sorting: ";
    printf_array(a, n);
    cout << "\nArray after sorting: ";
    quick_sort(a, 0, n - 1);
    printf_array(a, n);
    pause;
}