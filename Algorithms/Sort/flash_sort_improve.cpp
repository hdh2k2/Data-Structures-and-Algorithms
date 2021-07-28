#include"library.h"

int a[deu];

void flash_sort(int a[],int n){ // Sort up ascending
    // phân lớp dữ liệu tốt nhât là m = 0.43n btw
	// m = 0.2 n btw
	// phân lớp
	int m = n / 5;
	int min = a[0];
	int Imax = 0;
	vector<int>L;
	L.resize(m);
	for (int i = 0; i < n; i++) {
		if (i < m)L[i] = 0;
		if (min > a[i])min = a[i];
		if (a[Imax] < a[i])Imax = i;
	}
	double constant = 1.0*(m - 1) / (a[Imax] - min);
	for (int i = 0; i < n; i++) {
		int temp = int(constant*(a[i] - a[min]));
		L[temp]++;
	}
	for (int i = 1; i < m; i++) {
		L[i] = L[i - 1] + L[i];
	}
	SWAP(a[Imax], a[0]);
	// hoan vi
	int dem = 0;
	int k1 = m - 1;
	int j = 0;
	while (dem < n - 1) {
		while (j > L[k1] - 1) {
			j++;
			k1 = int(constant*(a[j] - min));
		}
		int flash = a[j];
		while (j != L[k1]) {
			k1 = int(constant*(flash - min));
			int hold = a[L[k1] - 1];
			a[L[k1] - 1] = flash;
			flash = hold;
			L[k1] --;
			dem++;
		}
	}
	for (int i = 1; i < n; i++) {
		int j = i - 1;
		int x = a[i];
		while (j >= 0 && a[j] > x) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
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