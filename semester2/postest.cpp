#include <iostream>
#define MAX 5

using namespace std;

struct stack {
    int arr[MAX];
    int topIndex;

    stack(){
        topIndex = -1;
    }

    void push(int data){
        if(topIndex >= MAX-1){
            cout << "Stack penuh, gabisa lagi" << endl;
            return;
        }
        arr[++topIndex] = data;
        cout << "Menambahkan data " << data << " ke dalam stack" << endl;
    }

    void pop(){
        if(isEmpty()){
            cout << endl << "Stack kosong. Tidak bisa menghapus" << endl;
            return;
        }
        cout << "Menghapus data " << arr[topIndex] << " dari stack" << endl;
        topIndex--;
    };
    
    int top(){
        if(isEmpty()){
            cout << "Stack kosong" << endl;
            return -1;
        }
        return arr[topIndex];
    }
    
    bool isEmpty(){
        return topIndex == -1;
    }

    int size(){
        return topIndex + 1;
    }
};


int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "elemen teratas: " << s.top() << endl << endl;
    
    s.pop();
    cout << "Elemen teratas setelah pop: " << s.top() << endl;
    cout << "Ukuran elemen dalam stack: " << s.size() << endl << endl;

    s.pop();
    s.pop();
    s.pop();

    return 0;
}