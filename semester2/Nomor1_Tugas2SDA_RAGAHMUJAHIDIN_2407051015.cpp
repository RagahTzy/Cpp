#include <iostream>
#define MAX 5

using namespace std;

struct stack {
    int arr[MAX];
    int Topindex;

    stack(){
        Topindex = -1;
    }

    void Push(int data){
        if(Topindex >= MAX-1){
            cout << "Stack penuh, gabisa lagi!" << endl;
            return;
        }
        arr[++Topindex] = data;
        cout << "Elemen " << data << " dimasukkan ke stack." << endl;
    }

    void Pop(){
        if(isEmpty()){
            cout << "Stack kosong. Tidak bisa menghapus." << endl;
            return;
        }
        cout << "Menghapus elemen " << arr[Topindex] << " dari stack." << endl;
        Topindex--;
    };
    
    int Top(){
        if(isEmpty()){
            cout << "Stack kosong!" << endl;
            return -1;
        }
        return arr[Topindex];
    }
    
    bool isEmpty(){
        return Topindex == -1;
    }

    int size(){
        return Topindex + 1;
    }
};

int main(){

    stack s;
    s.Push(10);
    s.Push(20);
    s.Push(30);
    cout << "Elemen teratas: " << s.Top() << endl;
    s.Pop();
    cout << "Elemen teratas: " << s.Top() << endl;
    
    return 0;
}