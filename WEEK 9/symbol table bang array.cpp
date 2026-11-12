#include <iostream>
using namespace std;

// Hàm tìm kiếm nhị phân (mô phỏng đúng 3 biến lo, hi, m trong slide)
int rankKey(char keys[], int n, char key) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int m = (lo + hi) / 2;
        if      (key < keys[m]) hi = m - 1; // Tìm nửa trái
        else if (key > keys[m]) lo = m + 1; // Tìm nửa phải
        else                    return m;   // Tìm thấy tại vị trí m
    }
    return lo; // Không thấy -> trả về vị trí cần chèn
}

// 1. Tìm kiếm (get)
int get(char keys[], int vals[], int n, char key) {
    int i = rankKey(keys, n, key);
    if (i < n && keys[i] == key) {
        return vals[i]; // Tìm thấy
    }
    return -1; // Không tìm thấy
}

// 2. Thêm mới / Cập nhật (put)
void put(char keys[], int vals[], int &n, char key, int val) {
    int i = rankKey(keys, n, key);

    // Trường hợp 1: Key đã có -> ghi đè value mới
    if (i < n && keys[i] == key) {
        vals[i] = val;
        return;
    }

    // Trường hợp 2: Key chưa có -> dời các phần tử từ vị trí i sang phải 1 ô
    for (int j = n; j > i; j--) {
        keys[j] = keys[j - 1];
        vals[j] = vals[j - 1];
    }

    // Chèn cặp key - val mới vào ô i và tăng số lượng n
    keys[i] = key;
    vals[i] = val;
    n++;
}

int main() {
    char keys[100];
    int vals[100];
    int n = 0; // Số phần tử hiện tại

    // Nhập thử dãy chữ cái trong slide (cố tình nhập lộn xộn để thấy mảng tự xếp)
    char mau[] = {'P', 'A', 'X', 'E', 'M', 'C', 'R', 'H', 'S', 'L'};
    for (int i = 0; i < 10; i++) {
        put(keys, vals, n, mau[i], i * 10);
    }

    // In thử mảng keys sau khi thêm (sẽ tự động xếp thành A C E H L M P R S X)
    cout << "Mang keys da sap xep: ";
    for (int i = 0; i < n; i++) cout << keys[i] << " ";
    cout << endl;

    // Kiểm tra tìm P và Q giống ví dụ trong slide
    cout << "Tim P: " << get(keys, vals, n, 'P') << endl; // Trả về value của P
    cout << "Tim Q: " << get(keys, vals, n, 'Q') << endl; // Trả về -1
    cout << "Vi tri nen chen Q: " << rankKey(keys, n, 'Q') << endl; // Trả về 7

    return 0;
}