#include"library.h"

int a[deu];

void insertion_sort(int a[],int n){ // Sort up ascending
    int key,j;
    for (int i = 0; i < n; i ++){ 
        key = a[i];
        j = i - 1;
        while(j>=0 && key <=a[j]){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void flash_sort(int a[],int n){ // Sort up ascending
    if (n == 0) return;
	int m = (int)((0.2 * n) + 2);
	int min, max, maxIndex;
	min = max = a[0];
	maxIndex = 0;
    for (int i = 1; i < n - 1; i += 2){
		int small;
		int big;
		int bigIndex;
		if (a[i] < a[i + 1])
		{
			small = a[i];
			big = a[i + 1];
			bigIndex = i + 1;
		}
		else
		{
			big = a[i];
			bigIndex = i;
			small = a[i + 1];
		}

		if (big > max)
		{
			max = big;
			maxIndex = bigIndex;
		}

		if (small < min)
		{
			min = small;
		}
	}

	if (a[n - 1] < min){
		min = a[n - 1];
	}

	else if (a[n - 1] > max){
		max = a[n - 1];
		maxIndex = n - 1;
	}

	if (max == min){
		return;
	}
	int* L = new int[m + 1];
	for (int t = 1; t <= m; t++){
		L[t] = 0;
	}

	double c = (m - 1.0) / (max - min);
	int K;
	for (int h = 0; h < n; h++){
		K = ((int)((a[h] - min) * c)) + 1;
		L[K] += 1;
	}
	for (K = 2; K <= m; K++){
		L[K] = L[K] + L[K - 1];
	}

	int temp = a[maxIndex];
	a[maxIndex] = a[0];
	a[0] = temp;
	int j = 0;
	K = m;
	int numMoves = 0;
	while (numMoves < n){
		while (j >= L[K]){
			j++;
			K = ((int)((a[j] - min) * c)) + 1;
		}
		int evicted = a[j];
		while (j < L[K]){
			K = ((int)((evicted - min) * c)) + 1;
			int location = L[K] - 1;
			int temp = a[location];
			a[location] = evicted;
			evicted = temp;
			L[K] -= 1;
			numMoves++;
		}
	}

	int threshold = (int)(1.25 * ((n / m) + 1));
	const int minElements = 30;
	for (K = m - 1; K >= 1; K--){
		int classSize = L[K + 1] - L[K];
		if (classSize > threshold && classSize > minElements){
			flash_sort(&a[L[K]], classSize);
		}

		else {
			if (classSize > 1){
				insertion_sort(&a[L[K]], classSize);
			}
		}
	}

	delete[] L;
}

int main(){
    system("cls");
    int n;
    init_array(a, n);
    cout << "Array before sorting: ";
    printf_array(a, n);
    cout << "\nArray after sorting: ";
    flash_sort(a, n);
    printf_array(a, n);
    system("pause");
}