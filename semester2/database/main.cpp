
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

class Mahasiswa {
private:
    long long nim;
    string nama;
    string jurusan;
public:
    void setNim(long long n) { nim = n; }
    void setNama(string nm) { nama = nm; }
    void setJurusan(string jur) { jurusan = jur; }
    long long getNim() const { return nim; }
    string getNama() const { return nama; }
    string getJurusan() const { return jurusan; }
};

void simpanKeFile(Mahasiswa data[], int jumlah, const string& filename) {
    ofstream outFile(filename);
    for (int i = 0; i < jumlah; ++i) {
        outFile << data[i].getNim() << ';' << data[i].getNama() << ';' << data[i].getJurusan() << '\n';
    }
    outFile.close();
}

int loadDariFile(Mahasiswa data[], const string& filename) {
    ifstream inFile(filename);
    if (!inFile) return 0;
    int i = 0;
    string line;
    while (getline(inFile, line) && i < 100) {
        size_t pos1 = line.find(';');
        size_t pos2 = line.find(';', pos1 + 1);
        if (pos1 == string::npos || pos2 == string::npos) continue;
        long long nim = stoll(line.substr(0, pos1));
        string nama = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string jurusan = line.substr(pos2 + 1);
        data[i].setNim(nim);
        data[i].setNama(nama);
        data[i].setJurusan(jurusan);
        i++;
    }
    inFile.close();
    return i;
}

void tampilkanData(Mahasiswa data[], int jumlah) {
    if (jumlah == 0) {
        cout << "Tidak ada data untuk ditampilkan.\n";
        return;
    }
    for (int i = 0; i < jumlah; ++i) {
        cout << "Mahasiswa ke-" << i+1 << ":\n";
        cout << "NIM     : " << data[i].getNim() << endl;
        cout << "Nama    : " << data[i].getNama() << endl;
        cout << "Jurusan : " << data[i].getJurusan() << endl << endl;
    }
}

void hapusData(Mahasiswa data[], int& jumlah) {
    if (jumlah == 0) {
        cout << "Tidak ada data yang bisa dihapus.\n";
        return;
    }
    int index;
    cout << "Masukkan nomor data yang ingin dihapus (1 - " << jumlah << "): ";
    cin >> index;
    if (index < 1 || index > jumlah) {
        cout << "Nomor tidak valid.\n";
        return;
    }
    for (int i = index - 1; i < jumlah - 1; ++i) {
        data[i] = data[i + 1];
    }
    jumlah--;
    cout << "Data berhasil dihapus.\n";
}

void updateData(Mahasiswa data[], int jumlah) {
    if (jumlah == 0) {
        cout << "Tidak ada data untuk diperbarui.\n";
        return;
    }
    int index;
    cout << "Masukkan nomor data yang ingin diperbarui (1 - " << jumlah << "): ";
    cin >> index;
    if (index < 1 || index > jumlah) {
        cout << "Nomor tidak valid.\n";
        return;
    }
    long long nim;
    string nama, jurusan;
    cin.ignore();
    cout << "Masukkan NIM baru: ";
    cin >> nim;
    cin.ignore();
    cout << "Masukkan Nama baru: ";
    getline(cin, nama);
    cout << "Masukkan Jurusan baru: ";
    getline(cin, jurusan);
    data[index - 1].setNim(nim);
    data[index - 1].setNama(nama);
    data[index - 1].setJurusan(jurusan);
    cout << "Data berhasil diperbarui.\n";
}

int main() {
    Mahasiswa database[100];
    int jumlah = 0;
    int pilihan;

    do {
        system("cls"); // clear screen di awal setiap tampilan menu
        cout << "\n--- MENU UTAMA ---\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Tampilkan Data Mahasiswa\n";
        cout << "3. Hapus Data Mahasiswa\n";
        cout << "4. Update Data Mahasiswa\n";
        cout << "5. Simpan ke File\n";
        cout << "6. Muat dari File\n";
        cout << "7. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();
        system("cls");

        switch (pilihan) {
            case 1: {
                Mahasiswa mhs;
                long long nim;
                string nama, jurusan;
                cout << "Masukkan NIM: ";
                cin >> nim;
                cin.ignore();
                cout << "Masukkan Nama: ";
                getline(cin, nama);
                cout << "Masukkan Jurusan: ";
                getline(cin, jurusan);
                mhs.setNim(nim);
                mhs.setNama(nama);
                mhs.setJurusan(jurusan);
                if (jumlah < 100) {
                    database[jumlah++] = mhs;
                    cout << "Data berhasil ditambahkan.\n";
                } else {
                    cout << "Database penuh!\n";
                }
                break;
            }
            case 2:
                tampilkanData(database, jumlah);
                break;
            case 3:
                hapusData(database, jumlah);
                break;
            case 4:
                updateData(database, jumlah);
                break;
            case 5: {
                string filename;
                cout << "Masukkan nama file untuk disimpan: ";
                getline(cin, filename);
                simpanKeFile(database, jumlah, filename);
                cout << "Data berhasil disimpan ke file.\n";
                break;
            }
            case 6: {
                string filename;
                cout << "Masukkan nama file untuk dimuat: ";
                getline(cin, filename);
                jumlah = loadDariFile(database, filename);
                cout << jumlah << " data berhasil dimuat dari file.\n";
                break;
            }
            case 7: {
                char yakin;
                cout << "Apakah anda yakin ingin keluar dari aplikasi? (y/n): ";
                cin >> yakin;
                if (yakin == 'y' || yakin == 'Y') {
                    cout << "Keluar dari program.\n";
                    return 0;
                }
                break;
            }
            default:
                cout << "Pilihan tidak valid!\n";
        }
        cout << "\nTekan Enter untuk melanjutkan...";
        cin.get();
    } while (true);

    return 0;
}
