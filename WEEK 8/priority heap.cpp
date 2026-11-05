#include <iostream>
#include <algorithm>
using namespace std;


void swim(int *a, int k) {
    while (k > 1 && a[k / 2] < a[k]) { 
        swap(a[k], a[k / 2]); 
        k = k / 2; 
    }
}


void insert(int *a, int &n, int x) { 
    a[++n] = x; 
    swim(a, n); 
}


void sink(int *a, int n, int k) { 
    while (2 * k <= n) { //[cite: 4]
        int j = 2 * k; //[cite: 4]
        if (j < n && a[j] < a[j + 1]) { 
            j++; //[cite: 4]
        }
        if (a[k] >= a[j]) { 
            break;
        }
        swap(a[k], a[j]);
        k = j; 
    }
}

int delMax(int *a, int &n) { 
    int max = a[1]; 
    swap(a[1], a[n]); 
    n--; //[cite: 5]
    sink(a, n, 1); 
    return max; 
}

int main() {
    int a[1000];
    int n = 0; 

   
    int m;
    cout << "Nhap so phan tu can chen: ";
    cin >> m;

    cout << "Nhap cac gia tri: ";
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        insert(a, n, x);
    }

    cout << "Trang thai Max-Heap sau khi chen: ";
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

   
    if (n > 0) {
        int maxVal = delMax(a, n);
        cout << "Phan tu lon nhat vua lay ra (delMax): " << maxVal << endl;

        cout << "Trang thai Max-Heap con lai: ";
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}