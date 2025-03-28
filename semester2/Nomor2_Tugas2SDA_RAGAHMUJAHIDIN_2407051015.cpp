#include <iostream>
using namespace std;

struct queue {
    int data[5];
    int front, rear, count;

    queue() {
        front = rear = count = 0;
    }

    void Enqueue(int value){
        if (count < 5){
            data[rear] = value;
            rear = (rear + 1) % 5;
            count ++;
            cout << "Elemen " << value << " Dimasukkan ke queue." << endl;
        }else{
            cout << "Queue penuh!" << endl;
        }
    }

    void Dequeue(){
        if (count > 0){
            cout << "Menghapus elemen " << data[front] << " dari queue." << endl;
            front = (front + 1) % 5;
            count --;
        }else{
            cout << "Queue kosong!" << endl;
        }
    }

    int Front(){
        if (count > 0){
            return data[front];
        }else{
            cout << "Queue kosong!" << endl;
            return -1;
        }
    }

    bool isEmpty(){
        return count == 0;
    }
    bool isFull(){
        return count == 5;
    }
    int size(){
        return count;
    }
};

int main(){
    queue q;
    q.Enqueue(5);
    q.Enqueue(15);
    q.Enqueue(25);
    cout << "Elemen paling depan: " << q.Front() << endl;
    q.Dequeue();
    cout << "Elemen paling depan: " << q.Front() << endl;
    return 0;
}