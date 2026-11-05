#include <iostream>
#include <algorithm>
using namespace std;

// Hàm vun đống (Heapify) tại vị trí nút gốc i
void heapify(int a[], int n, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    // Kiểm tra nếu nút con bên trái lớn hơn nút gốc
    if (left < n && a[left] > a[largest]) {
        largest = left;
    }

    // Kiểm tra nếu nút con bên phải lớn hơn phần tử lớn nhất hiện tại
    if (right < n && a[right] > a[largest]) {
        largest = right;
    }

    // Nếu phần tử lớn nhất không phải là nút cha i
    if (largest != i) {
        swap(a[i], a[largest]);
        // Đệ quy heapify lại cây con bị ảnh hưởng
        heapify(a, n, largest);
    }
}

// Thuật toán Heap Sort
void heapSort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }

  
    for (int i = n - 1; i >= 0; i--) {
        
        swap(a[0], a[i]);
       
        heapify(a, i, 0);
    }
}

int main() {
    int n;
    cin >> n;
    int a[1000];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    heapSort(a, n);

    for (int i = 0; i < n; i++) {
        cout << a[i]<< " ";
    } return 0;
}