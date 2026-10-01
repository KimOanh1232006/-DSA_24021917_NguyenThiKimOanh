#include <iostream>
using namespace std;
struct Nut {
    int giaTri;      
    Nut* tiepTheo;   


    Nut(int val) {
        giaTri = val;
        tiepTheo = nullptr;
    }
};


class DanhSachLienKet {
public:
    Nut* dau; 

    DanhSachLienKet() {
        dau = nullptr; 
    }
    int truyCap(int viTri) {
        Nut* hienTai = dau;
        int chiSo = 0;
        
        while (hienTai != nullptr) {
            if (chiSo == viTri) {
                return hienTai->giaTri;
            }
            chiSo++;
            hienTai = hienTai->tiepTheo;
        }
        
        cout << "\n[Loi] Vi tri khong hop le! ";
        return -1;
    }

    //  CHÈN VÀO ĐẦU -> O(1)
    void chenDau(int giaTri) {
        Nut* nutMoi = new Nut(giaTri);
        nutMoi->tiepTheo = dau; 
        dau = nutMoi;           
    }

    //  CHÈN VÀO CUỐI -> O(n)
    void chenCuoi(int giaTri) {
        Nut* nutMoi = new Nut(giaTri);
        
        
        if (dau == nullptr) {
            dau = nutMoi;
            return;
        }

     
        Nut* hienTai = dau;
        while (hienTai->tiepTheo != nullptr) {
            hienTai = hienTai->tiepTheo;
        }
        
       
        hienTai->tiepTheo = nutMoi;
    }

    //  CHÈN VÀO VỊ TRÍ i -> O(n)
    void chenViTri(int viTri, int giaTri) {
        if (viTri == 0) {
            chenDau(giaTri);
            return;
        }

        Nut* hienTai = dau;
        
        for (int i = 0; i < viTri - 1 && hienTai != nullptr; i++) {
            hienTai = hienTai->tiepTheo;
        }

        if (hienTai == nullptr) {
            cout << "Vi tri chen vuot qua do dai danh sach!\n";
            return;
        }

        Nut* nutMoi = new Nut(giaTri);
        nutMoi->tiepTheo = hienTai->tiepTheo;
        hienTai->tiepTheo = nutMoi;
    }

    //  XÓA PHẦN TỬ ĐẦU -> O(1)
    void xoaDau() {
        if (dau == nullptr) return;

        Nut* nutTam = dau;      
        dau = dau->tiepTheo;    
        delete nutTam;          
    }

    // XÓA PHẦN TỬ CUỐI -> O(n)
    void xoaCuoi() {
        if (dau == nullptr) return;

        
        if (dau->tiepTheo == nullptr) {
            delete dau;
            dau = nullptr;
            return;
        }

        //  nut ke cuoi 
        Nut* hienTai = dau;
        while (hienTai->tiepTheo->tiepTheo != nullptr) {
            hienTai = hienTai->tiepTheo;
        }

        delete hienTai->tiepTheo;  
        hienTai->tiepTheo = nullptr; 
    }

    //  XÓA Ở VỊ TRÍ i -> O(n)
    void xoaViTri(int viTri) {
        if (dau == nullptr) return;

        if (viTri == 0) {
            xoaDau();
            return;
        }

        Nut* hienTai = dau;
       
        for (int i = 0; i < viTri - 1 && hienTai->tiepTheo != nullptr; i++) {
            hienTai = hienTai->tiepTheo;
        }

        if (hienTai->tiepTheo == nullptr) return;

        Nut* nutXoa = hienTai->tiepTheo;
        hienTai->tiepTheo = nutXoa->tiepTheo; 
        delete nutXoa;                        
    }

    //  DUYỆT XUÔI  -> O(n)
    void duyetXuoi() {
        Nut* hienTai = dau;
        cout << "[ ";
        while (hienTai != nullptr) {
            cout << hienTai->giaTri << " -> ";
            hienTai = hienTai->tiepTheo;
        }
        cout << "NULL ]\n";
    }

    
    void duyetNguocDeQuy(Nut* p) {
        if (p == nullptr) return;
        duyetNguocDeQuy(p->tiepTheo); 
        cout << p->giaTri << " ";     
    }

    //  DUYỆT NGƯỢC  -> O(n)
    void duyetNguoc() {
        cout << "[ ";
        duyetNguocDeQuy(dau);
        cout << "]\n";
    }
};

int main() {
    DanhSachLienKet ds;

    // Khoi tao danh sach
    ds.chenCuoi(10);
    ds.chenCuoi(20);
    ds.chenCuoi(30);
    ds.chenCuoi(40);

    cout << "Danh sach ban dau: ";
    ds.duyetXuoi();


    cout << " Gia tri tai vi tri index 2: " << ds.truyCap(2) << "\n";
    ds.chenDau(5);
    cout << " Sau khi chen 5 vao DAU: ";
    ds.duyetXuoi();
    ds.chenCuoi(50);
    cout << " Sau khi chen 50 vao CUOI: ";
    ds.duyetXuoi();
    ds.chenViTri(3, 25);
    cout << " Sau khi chen 25 vao vi tri index 3: ";
    ds.duyetXuoi();
    ds.xoaDau();
    cout << " Sau khi XOA phan tu DAU: ";
    ds.duyetXuoi();
    ds.xoaCuoi();
    cout << " Sau khi XOA phan tu CUOI: ";
    ds.duyetXuoi();
    ds.xoaViTri(2);
    cout << " Sau khi XOA o vi tri index 2: ";
    ds.duyetXuoi();
    cout << " Duyet XUOI: ";
    ds.duyetXuoi();


    cout << " Duyet NGUOC: ";
    ds.duyetNguoc();

    return 0;
}
