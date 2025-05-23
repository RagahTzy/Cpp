#include <windows.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <commdlg.h>
#include <algorithm>

using namespace std;

struct Mahasiswa {
    long long nim;
    string nama;
    string jurusan;
};

vector<Mahasiswa> database;

// Komponen UI
HWND hNim, hNama, hJurusan, hListBox, hOutput;

void updateListBox(HWND listbox) {
    SendMessage(listbox, LB_RESETCONTENT, 0, 0);
    for (size_t i = 0; i < database.size(); ++i) {
        stringstream ss;
        ss << i + 1 << ". " << database[i].nama;
        SendMessage(listbox, LB_ADDSTRING, 0, (LPARAM)ss.str().c_str());
    }
}

string getDataAsString() {
    ostringstream oss;
    for (size_t i = 0; i < database.size(); ++i) {
        oss << "Mahasiswa ke-" << i + 1 << ":\r\n";
        oss << "NIM     : " << database[i].nim << "\r\n";
        oss << "Nama    : " << database[i].nama << "\r\n";
        oss << "Jurusan : " << database[i].jurusan << "\r\n\r\n";
    }
    return oss.str();
}

void tampilkanData() {
    string dataStr = getDataAsString();
    SetWindowText(hOutput, dataStr.c_str());
}

void simpanKeFile(HWND hwnd) {
    OPENFILENAME ofn = { sizeof(ofn) };
    char szFile[MAX_PATH] = "";
    ofn.hwndOwner = hwnd;
    ofn.lpstrFilter = "Data Mahasiswa (*.txt)\0*.txt\0";
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile);
    ofn.Flags = OFN_OVERWRITEPROMPT;

    if (GetSaveFileName(&ofn)) {
        ofstream out(ofn.lpstrFile);
        for (const auto& mhs : database) {
            out << mhs.nim << ';' << mhs.nama << ';' << mhs.jurusan << '\n';
        }
    }
}

void loadDariFile(HWND hwnd) {
    OPENFILENAME ofn = { sizeof(ofn) };
    char szFile[MAX_PATH] = "";
    ofn.hwndOwner = hwnd;
    ofn.lpstrFilter = "Data Mahasiswa (*.txt)\0*.txt\0";
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile);
    ofn.Flags = OFN_FILEMUSTEXIST;

    if (GetOpenFileName(&ofn)) {
        ifstream in(ofn.lpstrFile);
        string line;
        database.clear();
        while (getline(in, line)) {
            size_t pos1 = line.find(';');
            size_t pos2 = line.find(';', pos1 + 1);
            if (pos1 == string::npos || pos2 == string::npos) continue;
            Mahasiswa mhs;
            mhs.nim = stoll(line.substr(0, pos1));
            mhs.nama = line.substr(pos1 + 1, pos2 - pos1 - 1);
            mhs.jurusan = line.substr(pos2 + 1);
            database.push_back(mhs);
        }
        updateListBox(hListBox);
    }
}

void tambahData(HWND hwnd) {
    char bufNim[32], bufNama[128], bufJurusan[128];
    GetWindowText(hNim, bufNim, 32);
    GetWindowText(hNama, bufNama, 128);
    GetWindowText(hJurusan, bufJurusan, 128);

    if (strlen(bufNim) == 0 || strlen(bufNama) == 0 || strlen(bufJurusan) == 0) {
        MessageBox(hwnd, "Semua field harus diisi!", "Error", MB_ICONERROR);
        return;
    }

    Mahasiswa mhs;
    mhs.nim = atoll(bufNim);
    mhs.nama = bufNama;
    mhs.jurusan = bufJurusan;

    database.push_back(mhs);
    updateListBox(hListBox);
    SetWindowText(hNim, ""); SetWindowText(hNama, ""); SetWindowText(hJurusan, "");
}

void hapusData(HWND hwnd) {
    int index = (int)SendMessage(hListBox, LB_GETCURSEL, 0, 0);
    if (index >= 0 && index < (int)database.size()) {
        database.erase(database.begin() + index);
        updateListBox(hListBox);
    }
}

void updateData(HWND hwnd) {
    int index = (int)SendMessage(hListBox, LB_GETCURSEL, 0, 0);
    if (index >= 0 && index < (int)database.size()) {
        char bufNim[32], bufNama[128], bufJurusan[128];
        GetWindowText(hNim, bufNim, 32);
        GetWindowText(hNama, bufNama, 128);
        GetWindowText(hJurusan, bufJurusan, 128);

        if (strlen(bufNim) == 0 || strlen(bufNama) == 0 || strlen(bufJurusan) == 0) {
            MessageBox(hwnd, "Semua field harus diisi!", "Error", MB_ICONERROR);
            return;
        }

        database[index].nim = atoll(bufNim);
        database[index].nama = bufNama;
        database[index].jurusan = bufJurusan;
        updateListBox(hListBox);
    }
}

void sortByNim() {
    sort(database.begin(), database.end(), [](const Mahasiswa& a, const Mahasiswa& b) {
        return a.nim < b.nim;
    });
    updateListBox(hListBox);
}

void sortByNama() {
    sort(database.begin(), database.end(), [](const Mahasiswa& a, const Mahasiswa& b) {
        return a.nama < b.nama;
    });
    updateListBox(hListBox);
}

void sortByJurusan() {
    sort(database.begin(), database.end(), [](const Mahasiswa& a, const Mahasiswa& b) {
        return a.jurusan < b.jurusan;
    });
    updateListBox(hListBox);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE:
            CreateWindow("STATIC", "NIM:", WS_VISIBLE | WS_CHILD, 20, 20, 60, 20, hwnd, NULL, NULL, NULL);
            hNim = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 90, 20, 200, 20, hwnd, NULL, NULL, NULL);

            CreateWindow("STATIC", "Nama:", WS_VISIBLE | WS_CHILD, 20, 50, 60, 20, hwnd, NULL, NULL, NULL);
            hNama = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 90, 50, 200, 20, hwnd, NULL, NULL, NULL);

            CreateWindow("STATIC", "Jurusan:", WS_VISIBLE | WS_CHILD, 20, 80, 60, 20, hwnd, NULL, NULL, NULL);
            hJurusan = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 90, 80, 200, 20, hwnd, NULL, NULL, NULL);

            CreateWindow("BUTTON", "Tambah",  WS_VISIBLE | WS_CHILD, 310, 20, 80, 20, hwnd, (HMENU)1, NULL, NULL);
            CreateWindow("BUTTON", "Update",  WS_VISIBLE | WS_CHILD, 310, 50, 80, 20, hwnd, (HMENU)2, NULL, NULL);
            CreateWindow("BUTTON", "Hapus",   WS_VISIBLE | WS_CHILD, 310, 80, 80, 20, hwnd, (HMENU)3, NULL, NULL);

            hListBox = CreateWindow("LISTBOX", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | LBS_NOTIFY | WS_VSCROLL, 20, 120, 350, 100, hwnd, NULL, NULL, NULL);

            CreateWindow("BUTTON", "Tampilkan Data", WS_VISIBLE | WS_CHILD, 20, 230, 120, 30, hwnd, (HMENU)7, NULL, NULL);
            CreateWindow("BUTTON", "Simpan ke File", WS_VISIBLE | WS_CHILD, 150, 230, 120, 30, hwnd, (HMENU)4, NULL, NULL);
            CreateWindow("BUTTON", "Muat dari File", WS_VISIBLE | WS_CHILD, 280, 230, 120, 30, hwnd, (HMENU)5, NULL, NULL);
            CreateWindow("BUTTON", "Keluar", WS_VISIBLE | WS_CHILD, 150, 270, 120, 30, hwnd, (HMENU)6, NULL, NULL);

            hOutput = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | WS_VSCROLL | ES_READONLY, 20, 310, 380, 150, hwnd, NULL, NULL, NULL);

            CreateWindow("BUTTON", "Sort NIM", WS_VISIBLE | WS_CHILD, 20, 470, 100, 30, hwnd, (HMENU)8, NULL, NULL);
            CreateWindow("BUTTON", "Sort Nama", WS_VISIBLE | WS_CHILD, 130, 470, 100, 30, hwnd, (HMENU)9, NULL, NULL);
            CreateWindow("BUTTON", "Sort Jurusan", WS_VISIBLE | WS_CHILD, 240, 470, 100, 30, hwnd, (HMENU)10, NULL, NULL);

            break;

        case WM_COMMAND:
            switch (LOWORD(wParam)) {
                case 1: tambahData(hwnd); break;
                case 2: updateData(hwnd); break;
                case 3: hapusData(hwnd); break;
                case 4: simpanKeFile(hwnd); break;
                case 5: loadDariFile(hwnd); break;
                case 6: PostQuitMessage(0); break;
                case 7: tampilkanData(); break;
                case 8: sortByNim(); break;
                case 9: sortByNama(); break;
                case 10: sortByJurusan(); break;
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow) {
    const char CLASS_NAME[] = "MahasiswaUIWin32";
    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInst;
    wc.lpszClassName = CLASS_NAME;
    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(0, CLASS_NAME, "Aplikasi Pencatatan Data Mahasiswa - Win32", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 440, 550, NULL, NULL, hInst, NULL);
    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}