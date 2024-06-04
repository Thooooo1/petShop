#include <stdio.h>

// Hàm sắp xếp mảng k[] bằng giải thuật Selection Sort - kiểu lựa chọn
void selection_sort(int k[], int n) {
    int i, j, m, x;
    // for(i = 1; i < n; i++) // duyệt để chọn vị trí cho các ptu đã sxep
    for (i = 0; i < n - 1; i++) {
        m = i;
        for (j = i + 1; j < n; j++) {// duyệt tới ptu còn lại chưa sxep trong mảng
            if (k[j] < k[m]) {  
                m = j;
            }
        }
        if (m != i) {
            // Đổi chỗ k[i] và k[m]
            x = k[i];
            k[i] = k[m];
            k[m] = x;
        }
    }
}

// Hàm sắp xếp mảng k[] bằng giải thuật Insertion Sort - kiểu thêm dần
void insert_sort(int k[], int n) {
    int i, j, x;
    //'k[0] = vô cùng bé '
    for (i = 2; i < n; i++) {
        x = k[i];
        j = i - 1; // xét ptu trc vị trí đang xét
        //while(x < k[j])
        while (j >= 0 && x < k[j]) {// j >= 0 để ko truy cập ptu ngoài mảng-di chuyển x sang j + 1 
            k[j + 1] = k[j];
            j = j - 1;//j giảm đi 1 để di chuyển sang phần tử tiếp theo trong phần đã sắp xếp
        }
        k[j + 1] = x;
    }
}

// Hàm sắp xếp mảng k[] bằng giải thuật Bubble Sort
void bubble_sort(int k[], int n) {
    int i, j, x;
    //for(i=0;i<n-1;i++)
    for (i = 1; i < n; i++) {
        //for(j = 0; j < n - 1 - i; j++)
        for (j = n - 1; j >= i ; j--) {
            if (k[j] < k[j - 1]) {
                // Đổi chỗ k[j] và k[j - 1]
                x = k[j];
                k[j] = k[j - 1];
                k[j - 1] = x;
            }
        }
    }
}

int main() {
    int k[] = {18, 77, 34, 36, 44, 58, 99};
    int n = sizeof(k) / sizeof(k[0]);

    printf("Mang truoc khi sap xep:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", k[i]);
    }

    // Sắp xếp mảng k bằng các giải thuật
    //selection_sort(k, n);
     //insert_sort(k, n);
     bubble_sort(k, n);

    printf("\nMang sau khi sap xep:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", k[i]);
    }

    return 0;
}