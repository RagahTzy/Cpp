#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* next;

public:
    LinkedList() : head(nullptr), next(nullptr) {}

    bool isEmpty() {
        return head == nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node{value, head};
        head = newNode;
    }

    bool findFirst() {
        if (isEmpty()) return false;
        next = head;
        return true;
    }

    bool findNext() {
        if (next == nullptr || next->next == nullptr) return false;
        next = next->next;
        return true;
    }

    int retrieve() {
        if (next == nullptr) {
            cout << "Kesalahan: Tidak ada elemen saat ini." << endl;
            return -1;
        }
        return next->data;
    }

    void update(int value) {
        if (next == nullptr) {
            cout << "Kesalahan: Tidak ada elemen saat ini." << endl;
            return;
        }
        next->data = value;
    }

    void deleteNow() {
        if (next == nullptr) {
            cout << "Kesalahan: Tidak ada elemen saat ini." << endl;
            return;
        }
        if (next == head) {
            deleteHead();
            return;
        }
        Node* prev = head;
        while (prev->next != next) {
            prev = prev->next;
        }
        prev->next = next->next;
        delete next;
        next = prev->next;
    }

    void deleteHead() {
        if (isEmpty()) {
            cout << "Kesalahan: Daftar kosong." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        next = head;
    }

    void clear() {
        while (!isEmpty()) {
            deleteHead();
        }
    }
};

int main() {
    LinkedList list;
    int pilihan, nilai;

    do {
        cout << "\nMenu Linked List:\n";
        cout << "1. Masukkan nilai\n";
        cout << "2. Hapus head\n";
        cout << "3. Update nilai elemen saat ini\n";
        cout << "4. Cari elemen pertama\n";
        cout << "5. Cari elemen berikutnya\n";
        cout << "6. Tampilkan elemen saat ini\n";
        cout << "7. Hapus elemen saat ini\n";
        cout << "8. Kosongkan daftar\n";
        cout << "0. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                if (!(cin >> nilai)) {
                    cout << "Kesalahan: Input harus berupa angka. Program dihentikan.\n";
                    return 1;
                }
                list.insert(nilai);
                cout << "Nilai berhasil dimasukkan.\n";
                break;

            case 2:
                list.deleteHead();
                cout << "Head berhasil dihapus.\n";
                break;

            case 3:
                cout << "Masukkan nilai baru: ";
                if (!(cin >> nilai)) {
                    cout << "Kesalahan: Input harus berupa angka. Program dihentikan.\n";
                    return 1;
                }
                list.update(nilai);
                cout << "Nilai elemen saat ini berhasil diperbarui.\n";
                break;

            case 4:
                if (list.findFirst()) {
                    cout << "Elemen pertama ditemukan.\n";
                } else {
                    cout << "Daftar kosong.\n";
                }
                break;

            case 5:
                if (list.findNext()) {
                    cout << "Elemen berikutnya ditemukan.\n";
                } else {
                    cout << "Tidak ada elemen berikutnya.\n";
                }
                break;

            case 6:
                nilai = list.retrieve();
                if (nilai != -1) {
                    cout << "Elemen saat ini: " << nilai << endl;
                }
                break;

            case 7:
                list.deleteNow();
                cout << "Elemen saat ini berhasil dihapus.\n";
                break;

            case 8:
                list.clear();
                cout << "Daftar berhasil dikosongkan.\n";
                break;

            case 0:
                cout << "Keluar dari program.\n";
                break;

            default:
                cout << "Kesalahan: Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);

    return 0;
}