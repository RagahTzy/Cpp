#include <iostream>
using namespace std;

class Buku {
protected:
    string Judul;
    string Pengarang;
    int tahunTerbit;

public:
    Buku(string j, string p, int t) {
        Judul = j;
        Pengarang = p;
        tahunTerbit = t;
    }

    void tampilkanBuku() {
        cout << "Judul       : \"" << Judul << "\"" << endl;
        cout << "Pengarang   : \"" << Pengarang << "\"" << endl;
        cout << "Tahun Terbit: " << tahunTerbit << endl;
    }

    void setJudul(string judulbaru) {
        Judul = judulbaru;
    }

    void setPengarang(string pengarangbaru) {
        Pengarang = pengarangbaru;
    }

    void setTahunTerbit(int tahunbaru) {
        tahunTerbit = tahunbaru;
    }
};

class Ebook : public Buku {
private:
    float ukuranFile; // dalam MB
    string formatFile;

public:
    Ebook(string j, string p, int t, float u, string f) 
        : Buku(j, p, t), ukuranFile(u), formatFile(f) {}

    void tampilkanEbook() {
        tampilkanBuku();
        cout << "Ukuran File : " << ukuranFile << " MB" << endl;
        cout << "Format File : \"" << formatFile << "\"" << endl;
    }

    void setUkuranFile(float ukuranBaru) {
        ukuranFile = ukuranBaru;
    }

    void setFormatFile(string formatBaru) {
        formatFile = formatBaru;
    }
};

int main() {
    Buku buku("Nikmati Masa Muda", "Panca Satria", 2005);
    buku.tampilkanBuku();
    
    cout << endl << "Setelah mengubah nilai atribut:\n";
    buku.setJudul("Habiskan Duitmu Segera");
    buku.setPengarang("Bram Ahimsa");
    buku.setTahunTerbit(2023);
    buku.tampilkanBuku();
    cout << endl;
    Ebook ebook("Belajar C++ untuk Pemula", "Zane Programmer", 2021, 2.5, "PDF");
    ebook.tampilkanEbook();
    return 0;
}
