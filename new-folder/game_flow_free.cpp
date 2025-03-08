#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Struktur untuk mewakili sel dalam papan permainan
struct Cell {
    int row;
    int col;
    bool is_empty;
    int color; // 0 untuk kosong, 1-5 untuk warna
};

// Struktur untuk mewakili jalur
struct Path {
    int color;
    vector<Cell> cells;
};

// Fungsi untuk mencetak papan permainan
void print_board(vector<vector<Cell>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j].is_empty) {
                cout << "  ";
            } else {
                cout << board[i][j].color << " ";
            }
        }
        cout << endl;
    }
}

// Fungsi untuk memeriksa apakah sel valid
bool is_valid_cell(vector<vector<Cell>>& board, int row, int col) {
    return row >= 0 && row < board.size() && col >= 0 && col < board[0].size();
}

// Fungsi untuk menemukan titik awal dan akhir untuk warna yang diberikan
pair<Cell, Cell> find_start_end(vector<vector<Cell>>& board, int color) {
    Cell start, end;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j].color == color) {
                if (start.is_empty) {
                    start.row = i;
                    start.col = j;
                } else {
                    end.row = i;
                    end.col = j;
                }
            }
        }
    }
    return make_pair(start, end);
}

// Fungsi untuk mencari jalur menggunakan algoritma Breadth-First Search (BFS)
Path find_path(vector<vector<Cell>>& board, int color) {
    Path path;
    path
