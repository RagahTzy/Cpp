#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> myList = {10, 20, 30, 40};  // Membuat list dengan elemen awal

    myList.push_front(5);   // Menambahkan elemen di depan
    myList.push_back(50);   // Menambahkan elemen di belakang

    cout << "Isi list: ";
    for (int num : myList) {
        cout << num << " ";
    }

    return 0;
}
