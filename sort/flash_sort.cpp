#include"library.h"

int a[deu];

void flash_sort(int a[],int n){ // Sort up ascending
    int m = int (0.45 * n);
    int *temp = new int[n];
    int max = 0;
    int min = a[0];
    for (int i = 1; i < n; i++){
        if ( a[i] < min){
            min = a[i]; 
        }

        if ( a[i] > max){ 
            max = a[i]; 
        }
    }

    for (int i = 0; i < n ; i++)
        temp[i] = 0;


    for (int i = 0; i < n; i++){
        int k = int((m - 1) * (a[i] - min) / (max - min));
        temp[k]++;
    }

    for (int i = 0; i < m;i ++){
        temp[i] = temp[i] + temp[i - 1];
    }

    
    int hold = 0;
    int move = 0;
    int flash = 0;
    int k = 0;
    int t = 0;
    int j = 0;
    while (move < n - 1){
        while(j > (temp[k] - 1)){
            j++;
            k = int((m - 1) * (a[j] - min) / (max - min));
        }
        flash = a[j];
        if (k < 0 ) break;
        while(j!=  temp[k]){
            k = int((m - 1) * (a[j] - min) / (max - min));
            hold = a[t = --temp[j]];
            a[t] = hold;
            flash = hold;
        }
    }


    for (int j = 1; j < n; j ++ ){
        hold = a[j];
        int i = j - 1;
        while(i>=0&&a[i]>hold){
            a[i + 1] = a[i - 1];
            i--;
        }
        a[i + 1] = hold;
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