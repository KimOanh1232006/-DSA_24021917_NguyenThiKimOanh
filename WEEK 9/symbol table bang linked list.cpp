#include <iostream>
using namespace std;

struct Node {
    char key;
    int val;
    Node* next;
};

// 1. Tìm kiếm (get): Trả về value nếu thấy, trả về -1 nếu không thấy
int get(Node* head, char key) {
    Node* p = head;
    while (p != NULL) {
        if (p->key == key) return p->val;
        p = p->next;
    }
    return -1;
}

// 2. Thêm mới / Cập nhật (put)
void put(Node* &head, char key, int val) {
    // Bước 1: Dò xem key đã có chưa, nếu có rồi thì cập nhật lại val
    Node* p = head;
    while (p != NULL) {
        if (p->key == key) {
            p->val = val;
            return;
        }
        p = p->next;
    }

    // Bước 2: Chưa có thì tạo Node mới và nối thẳng vào đầu danh sách
    Node* moi = new Node;
    moi->key = key;
    moi->val = val;
    moi->next = head;
    head = moi;
}

int main() {
    Node* head = NULL; // Ban đầu danh sách rỗng

    put(head, 'A', 10);
    put(head, 'P', 60);
    put(head, 'X', 90);

    cout << "Gia tri cua P: " << get(head, 'P') << endl; // In ra 60
    cout << "Gia tri cua Q: " << get(head, 'Q') << endl; // In ra -1 (khong thay)
    return 0;
}