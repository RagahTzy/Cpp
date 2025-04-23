#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

void tambahNama(Node*& head, const string& namaBaru) {
    Node* newNode = new Node{namaBaru, nullptr};
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

void tampilkanNama(Node* head) {
    for (Node* temp = head; temp; temp = temp->next)
        cout << "- " << temp->nama << endl;
    if (!head) cout << "Daftar nama kosong.\n";
}

int main() {
    Node* head = nullptr;
    int pilihan;
    string nama;

    do {
        cout << "\n1. Tambah Nama\n2. Tampilkan Nama\n3. Keluar\nPilih: ";
        cin >> pilihan;
        cin.ignore();
        if (pilihan == 1) {
            cout << "Masukkan nama: ";
            getline(cin, nama);
            tambahNama(head, nama);
        } else if (pilihan == 2) tampilkanNama(head);
    } while (pilihan != 3);

    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
