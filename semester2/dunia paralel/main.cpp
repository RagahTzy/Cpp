#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <limits>

using namespace std;

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void clearScreen() {
    system(CLEAR);
}

struct Karakter {
    string nama;
    char dunia; // 'A' atau 'B'
    unsigned long long level;
    unsigned long long power;
};

// Maks level dan power yang diijinkan
const unsigned long long MAX_LEVEL = 1000;
const unsigned long long MAX_POWER = 1000000000ULL; // 1 milyar

vector<Karakter> semuaKarakter;

// Fungsi simpan data ke file
void saveData(const string& filename = "data.txt") {
    ofstream file(filename);
    if(!file) {
        cout << "Gagal menyimpan data.\n";
        return;
    }
    for(const auto& k : semuaKarakter) {
        file << k.nama << '\n' << k.dunia << '\n' << k.level << '\n' << k.power << '\n';
    }
    file.close();
    cout << "Data berhasil disimpan ke " << filename << ".\n";
}

// Fungsi load data dari file
void loadData(const string& filename = "data.txt") {
    ifstream file(filename);
    if(!file) {
        cout << "File data tidak ditemukan.\n";
        return;
    }
    semuaKarakter.clear();
    string line;
    while(getline(file, line)) {
        Karakter k;
        k.nama = line;
        if(!getline(file, line)) break;
        k.dunia = line[0];
        if(!getline(file, line)) break;
        k.level = stoull(line);
        if(!getline(file, line)) break;
        k.power = stoull(line);
        semuaKarakter.push_back(k);
    }
    file.close();
    cout << "Data berhasil dimuat dari " << filename << ".\n";
}

// Tampilkan semua karakter detail
void readAll() {
    if(semuaKarakter.empty()) {
        cout << "Belum ada karakter.\n";
        return;
    }
    cout << "Daftar karakter:\n";
    for(const auto& k : semuaKarakter) {
        cout << "Nama: " << k.nama << "\nDunia: " << k.dunia
             << "\nLevel: " << k.level << "\nPower: " << k.power << "\n-----------------\n";
    }
}

// Tampilkan daftar nama + dunia saja (untuk update & delete)
void listNamaDunia() {
    if(semuaKarakter.empty()) {
        cout << "Belum ada karakter.\n";
        return;
    }
    cout << "Daftar karakter:\n";
    int no = 1;
    for(const auto& k : semuaKarakter) {
        cout << no++ << ". " << k.nama << " (Dunia " << k.dunia << ")\n";
    }
}

// Membuat karakter baru
void createCharacter() {
    Karakter k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Masukkan nama karakter: ";
    getline(cin, k.nama);
    do {
        cout << "Masukkan dunia karakter (A/B): ";
        cin >> k.dunia;
        k.dunia = toupper(k.dunia);
    } while(k.dunia != 'A' && k.dunia != 'B');
    
    do {
        cout << "Masukkan level karakter (max " << MAX_LEVEL << "): ";
        cin >> k.level;
    } while(k.level < 1 || k.level > MAX_LEVEL);
    
    do {
        cout << "Masukkan power karakter (max " << MAX_POWER << "): ";
        cin >> k.power;
    } while(k.power < 1 || k.power > MAX_POWER);
    
    semuaKarakter.push_back(k);
    cout << "Karakter berhasil dibuat.\n";
}

// Update karakter berdasarkan nama
void updateCharacter() {
    if(semuaKarakter.empty()) {
        cout << "Belum ada karakter untuk diupdate.\n";
        return;
    }
    listNamaDunia();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Masukkan nama karakter yang akan diupdate: ";
    string namaCari;
    getline(cin, namaCari);
    
    bool found = false;
    for(auto& k : semuaKarakter) {
        if(k.nama == namaCari) {
            found = true;
            cout << "Update karakter '" << k.nama << "':\n";
            cout << "Masukkan nama baru (enter untuk tetap): ";
            string input;
            getline(cin, input);
            if(!input.empty()) k.nama = input;
            
            char d;
            do {
                cout << "Masukkan dunia baru (A/B, enter untuk tetap): ";
                getline(cin, input);
                if(input.empty()) break;
                d = toupper(input[0]);
            } while(d != 'A' && d != 'B');
            if(!input.empty()) k.dunia = d;
            
            cout << "Masukkan level baru (1-" << MAX_LEVEL << ", enter untuk tetap): ";
            getline(cin, input);
            if(!input.empty()) {
                unsigned long long lv = stoull(input);
                if(lv >= 1 && lv <= MAX_LEVEL) k.level = lv;
                else cout << "Level tidak valid, tetap menggunakan level lama.\n";
            }
            
            cout << "Masukkan power baru (1-" << MAX_POWER << ", enter untuk tetap): ";
            getline(cin, input);
            if(!input.empty()) {
                unsigned long long pw = stoull(input);
                if(pw >= 1 && pw <= MAX_POWER) k.power = pw;
                else cout << "Power tidak valid, tetap menggunakan power lama.\n";
            }
            
            cout << "Update selesai.\n";
            break;
        }
    }
    if(!found) cout << "Karakter dengan nama '" << namaCari << "' tidak ditemukan.\n";
}

// Hapus karakter berdasarkan nama
void deleteCharacter() {
    if(semuaKarakter.empty()) {
        cout << "Belum ada karakter untuk dihapus.\n";
        return;
    }
    listNamaDunia();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Masukkan nama karakter yang akan dihapus: ";
    string namaCari;
    getline(cin, namaCari);
    
    auto it = remove_if(semuaKarakter.begin(), semuaKarakter.end(),
                        [&namaCari](const Karakter& k){ return k.nama == namaCari; });
    if(it != semuaKarakter.end()) {
        semuaKarakter.erase(it, semuaKarakter.end());
        cout << "Karakter berhasil dihapus.\n";
    } else {
        cout << "Karakter dengan nama '" << namaCari << "' tidak ditemukan.\n";
    }
}

// Sorting berdasarkan nama (ascending)
void sortByName() {
    if(semuaKarakter.empty()) {
        cout << "Belum ada karakter untuk diurutkan.\n";
        return;
    }
    sort(semuaKarakter.begin(), semuaKarakter.end(), [](const Karakter& a, const Karakter& b) {
        return a.nama < b.nama;
    });
    cout << "Berhasil diurutkan berdasarkan nama (A-Z).\n";
}

// Sorting berdasarkan dunia (dengan pilihan arah)
void sortByWorld() {
    if(semuaKarakter.empty()) {
        cout << "Belum ada karakter untuk diurutkan.\n";
        return;
    }
    int pilihan;
    cout << "Urutkan berdasarkan dunia:\n";
    cout << "1. Dunia A ke B (A duluan)\n";
    cout << "2. Dunia B ke A (B duluan)\n";
    cout << "Pilih: ";
    cin >> pilihan;
    if(pilihan == 1) {
        sort(semuaKarakter.begin(), semuaKarakter.end(), [](const Karakter& a, const Karakter& b) {
            return a.dunia < b.dunia;
        });
        cout << "Berhasil diurutkan dari Dunia A ke B.\n";
    } else if(pilihan == 2) {
        sort(semuaKarakter.begin(), semuaKarakter.end(), [](const Karakter& a, const Karakter& b) {
            return a.dunia > b.dunia;
        });
        cout << "Berhasil diurutkan dari Dunia B ke A.\n";
    } else {
        cout << "Pilihan tidak valid.\n";
    }
}

// Simulasi perang dunia A vs B
void simulasiPerang() {
    if(semuaKarakter.empty()) {
        cout << "Belum ada karakter untuk simulasi perang.\n";
        return;
    }
    
    // Pisahkan karakter berdasarkan dunia
    vector<Karakter> duniaA, duniaB;
    for(auto& k : semuaKarakter) {
        if(k.dunia == 'A') duniaA.push_back(k);
        else if(k.dunia == 'B') duniaB.push_back(k);
    }
    if(duniaA.empty() || duniaB.empty()) {
        cout << "Simulasi perang membutuhkan karakter di kedua dunia.\n";
        return;
    }
    
    cout << "Simulasi perang dimulai...\n";
    
    // Pertarungan satu-satu dari kedua dunia
    // Prosedur simpel: karakter bertarung sesuai indeks, power dikurangi power lawan
    // Jika power <=0, karakter dianggap mati (hapus)
    
    size_t maxPertarungan = min(duniaA.size(), duniaB.size());
    
    for(size_t i = 0; i < maxPertarungan; i++) {
        Karakter &a = duniaA[i];
        Karakter &b = duniaB[i];
        
        // Kurangi power lawan dengan power sendiri (saling serang)
        if(a.power > b.power) {
            a.power -= b.power;
            b.power = 0;
        } else if(b.power > a.power) {
            b.power -= a.power;
            a.power = 0;
        } else {
            // Sama-sama power = 0 (mati berdua)
            a.power = 0;
            b.power = 0;
        }
    }
    
    // Hapus karakter yang mati (power 0) dari duniaA dan duniaB
    duniaA.erase(remove_if(duniaA.begin(), duniaA.end(),
                          [](const Karakter& k){ return k.power == 0; }), duniaA.end());
    duniaB.erase(remove_if(duniaB.begin(), duniaB.end(),
                          [](const Karakter& k){ return k.power == 0; }), duniaB.end());
    
    // Akumulasi dan tampilkan hasil
    cout << "\nHasil Perang:\n";
    cout << "Dunia A (Tersisa " << duniaA.size() << " karakter):\n";
    for(auto& k : duniaA) {
        cout << "- " << k.nama << ", Level: " << k.level << ", Power: " << k.power << '\n';
    }
    cout << "Dunia B (Tersisa " << duniaB.size() << " karakter):\n";
    for(auto& k : duniaB) {
        cout << "- " << k.nama << ", Level: " << k.level << ", Power: " << k.power << '\n';
    }
    
    // Naikkan level +5 power untuk yang bertahan, pastikan tidak melebihi MAX
    for(auto& k : duniaA) {
        if(k.level < MAX_LEVEL) {
            k.level = min(k.level + 1, MAX_LEVEL);
        }
        if(k.power + 5 > MAX_POWER) {
            k.power = MAX_POWER;
        } else {
            k.power += 5;
        }
    }
    for(auto& k : duniaB) {
        if(k.level < MAX_LEVEL) {
            k.level = min(k.level + 1, MAX_LEVEL);
        }
        if(k.power + 5 > MAX_POWER) {
            k.power = MAX_POWER;
        } else {
            k.power += 5;
        }
    }
    
    // Gabungkan kembali ke semuaKarakter
    semuaKarakter.clear();
    semuaKarakter.insert(semuaKarakter.end(), duniaA.begin(), duniaA.end());
    semuaKarakter.insert(semuaKarakter.end(), duniaB.begin(), duniaB.end());
    
    cout << "\nLevel dan power karakter yang bertahan telah ditingkatkan.\n";
}

int main() {
    int pilihan;
    bool running = true;
    
    while(running) {
        cout << "\n=== Program Simulasi Dunia Paralel ===\n";
        cout << "1. Load Data dari File\n";
        cout << "2. Simpan Data ke File\n";
        cout << "3. Tambah Karakter\n";
        cout << "4. Tampilkan Semua Karakter\n";
        cout << "5. Urutkan Karakter\n";
        cout << "6. Update Karakter\n";
        cout << "7. Hapus Karakter\n";
        cout << "8. Simulasi Perang Dunia\n";
        cout << "9. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        clearScreen();
        switch(pilihan) {
            case 1:
                loadData();
                break;
            case 2:
                saveData();
                break;
            case 3:
                createCharacter();
                break;
            case 4:
                readAll();
                break;
            case 5: {
                cout << "Pilihan Urutkan:\n";
                cout << "1. Berdasarkan Nama\n";
                cout << "2. Berdasarkan Dunia\n";
                cout << "Pilih: ";
                int urutPilihan;
                cin >> urutPilihan;
                clearScreen();
                if(urutPilihan == 1) {
                    sortByName();
                } else if(urutPilihan == 2) {
                    sortByWorld();
                } else {
                    cout << "Pilihan urutkan tidak valid.\n";
                }
                break;
            }
            case 6:
                updateCharacter();
                break;
            case 7:
                deleteCharacter();
                break;
            case 8:
                simulasiPerang();
                break;
            case 9:
                running = false;
                cout << "Keluar program...\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
        cout << "\nTekan enter untuk lanjut...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        clearScreen();
    }
    
    return 0;
}