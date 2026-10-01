#include <iostream>
#include <vector>

using namespace std;


void inDanhSach(const vector<int>& danhSach) {
    cout << "[ ";
    for (int phanTu : danhSach) {
        cout << phanTu << " ";
    }
    cout << "]\n";
}

int main() {
   
    vector<int> danhSach = {10, 20, 30, 40};
    cout << "Danh sach ban dau: ";
    inDanhSach(danhSach);
    cout << "-------------------------------------\n";

    
    int viTriCanLay = 2;
    cout << "1. Gia tri tai vi tri " << viTriCanLay << " la: " << danhSach[viTriCanLay] << "\n";

    // 2. CHÈN PHẦN TỬ VÀO ĐẦU 
    int giaTriChenDau = 5;
    danhSach.push_back(0); 
    for (int i = danhSach.size() - 1; i > 0; i--) {
        danhSach[i] = danhSach[i - 1]; 
    }
    danhSach[0] = giaTriChenDau; 
    cout << "2. Sau khi chen " << giaTriChenDau << " vao DAU: ";
    inDanhSach(danhSach);

    // 3. CHÈN PHẦN TỬ VÀO CUỐI 
    int giaTriChenCuoi = 50;
    danhSach.push_back(giaTriChenCuoi);
    cout << "3. Sau khi chen " << giaTriChenCuoi << " vao CUOI: ";
    inDanhSach(danhSach);

    // 4. CHÈN VÀO VỊ TRÍ i -> O(n) 
    int viTriChen = 3;
    int giaTriChenGiua = 25;
    danhSach.push_back(0); 
    for (int i = danhSach.size() - 1; i > viTriChen; i--) {
        danhSach[i] = danhSach[i - 1]; 
    }
    danhSach[viTriChen] = giaTriChenGiua; 
    cout << "4. Sau khi chen " << giaTriChenGiua << " vao vi tri " << viTriChen << ": ";
    inDanhSach(danhSach);

    // 5. XÓA PHẦN TỬ ĐẦU -> O(n) 
    for (int i = 0; i < danhSach.size() - 1; i++) {
        danhSach[i] = danhSach[i + 1]; 
    }
    danhSach.pop_back(); 
    cout << "5. Sau khi XOA phan tu DAU: ";
    inDanhSach(danhSach);

    // 6. XÓA PHẦN TỬ CUỐI -> O(1)
    danhSach.pop_back();
    cout << "6. Sau khi XOA phan tu CUOI: ";
    inDanhSach(danhSach);

    // 7. XÓA Ở VỊ TRÍ i -> O(n) 
    int viTriXoa = 2;
    for (int i = viTriXoa; i < danhSach.size() - 1; i++) {
        danhSach[i] = danhSach[i + 1]; 
    }
    danhSach.pop_back(); 
    cout << "7. Sau khi XOA o vi tri " << viTriXoa << ": ";
    inDanhSach(danhSach);

    // 8. DUYỆT XUÔI -> O(n)
    cout << "8. Duyet XUOI: ";
    for (int i = 0; i < danhSach.size(); i++) {
        cout << danhSach[i] << " ";
    }
    cout << "\n";

    // 9. DUYỆT NGƯỢC -> O(n)
    cout << "9. Duyet NGUOC: ";
    for (int i = danhSach.size() - 1; i >= 0; i--) {
        cout << danhSach[i] << " ";
    }
    cout << "\n";

    return 0;
}
