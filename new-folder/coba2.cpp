#include <iostream>
#include <string>
#include <stdexcept>  // Tambahkan header ini untuk invalid_argument
using namespace std;

char getGrade(float nilai) {
    if (nilai >= 78) {
        return 'A';
    } else if (nilai >= 65) {
        return 'B';
    } else if (nilai >= 45) {
        return 'C';
    } else if (nilai >= 35) {
        return 'D';
    } else {
        return 'E';
    }
}

float extractNumber(const string& input) {
    size_t pos = input.find("="); // Cari posisi '='
    if (pos != string::npos) {
        string angkaStr = input.substr(pos + 1); // Ambil substring setelah '='
        angkaStr.erase(0, angkaStr.find_first_not_of(" ")); // Hapus spasi di depan
        try {
            return stof(angkaStr); // Coba konversi string ke float
        } catch (const invalid_argument& e) {
            cerr << "Error: Invalid number in input: " << angkaStr << endl;
            return 0.0f; // Return 0 jika terjadi kesalahan dalam konversi
        }
    }
    return 0.0f; // Return 0 jika tidak ada angka
}

int main() {
    int jumlahMahasiswa;
    string input;

    // Input jumlah mahasiswa
    cout << "Masukkan jumlah mahasiswa: ";
    getline(cin, input);
    try {
        jumlahMahasiswa = stoi(input); // Coba konversi jumlah mahasiswa ke integer
    } catch (const invalid_argument& e) {
        cerr << "Error: Invalid number for jumlah mahasiswa!" << endl;
        return 1; // Keluar jika terjadi kesalahan dalam konversi jumlah mahasiswa
    }

    // Validasi jumlahMahasiswa
    if (jumlahMahasiswa <= 0) {
        cerr << "Jumlah mahasiswa tidak valid" << endl;
        return 1; // Keluar dari program jika jumlah mahasiswa tidak valid
    }

    float totalNilai = 0;

    for (int i = 0; i < jumlahMahasiswa; ++i) {
        // Input data mahasiswa
        cout << "Mahasiswa " << i + 1 << endl;
        float tugasIndividu1, tugasIndividu2, tugasIndividu3;
        float tugasKelompok1, tugasKelompok2;
        float kuis, uts, projectBasedLearning;

        // Memproses Tugas Individu
        cout << "Tugas Individu 1 = ";
        getline(cin, input);
        tugasIndividu1 = extractNumber(input);
        
        cout << "Tugas Individu 2 = ";
        getline(cin, input);
        tugasIndividu2 = extractNumber(input);
        
        cout << "Tugas Individu 3 = ";
        getline(cin, input);
        tugasIndividu3 = extractNumber(input);

        // Memproses Tugas Kelompok
        cout << "Tugas Kelompok 1 = ";
        getline(cin, input);
        tugasKelompok1 = extractNumber(input);
        
        cout << "Tugas Kelompok 2 = ";
        getline(cin, input);
        tugasKelompok2 = extractNumber(input);

        // Memproses Kuis, UTS, Project Based Learning
        cout << "Kuis = ";
        getline(cin, input);
        kuis = extractNumber(input);
        
        cout << "UTS = ";
        getline(cin, input);
        uts = extractNumber(input);
        
        cout << "Project Based Learning = ";
        getline(cin, input);
        projectBasedLearning = extractNumber(input);

        // Menghitung nilai akhir mahasiswa
        float rataTugasIndividu = (tugasIndividu1 + tugasIndividu2 + tugasIndividu3) / 3;
        float rataTugasKelompok = (tugasKelompok1 + tugasKelompok2) / 2;

        float nilaiAkhir = (rataTugasIndividu * 0.1) + (rataTugasKelompok * 0.15) + (kuis * 0.1) + (uts * 0.2) + (projectBasedLearning * 0.45);

        // Menampilkan hasil
        cout << "Nilai Akhir Mahasiswa " << i + 1 << " = " << nilaiAkhir << endl;
        cout << "Huruf Mutu Mahasiswa " << i + 1 << " = " << getGrade(nilaiAkhir) << endl;

        totalNilai += nilaiAkhir;
    }

    // Menghindari pembagian dengan 0
    if (jumlahMahasiswa > 0) {
        float rataRataKelas = totalNilai / jumlahMahasiswa;
        cout << "Nilai Rata-Rata Kelas = " << rataRataKelas << endl;
    } else {
        cerr << "Tidak ada mahasiswa, tidak dapat menghitung rata-rata kelas." << endl;
    }

    return 0;
}

