#include <iostream>
using namespace std;

struct queue {
    int data[5];
    int front, rear, count;

    queue() {
        front = rear = count = 0;
    }

    void enqueue(int value){
        if (count < 5){
            data[rear] = value;
            rear = (rear + 1) % 5;
            count ++;
            cout << "Enqueued: " << value << endl;
        }else{
            cout << "Queue penuh!" << endl;
        }
    }

    void dequeue(){
        if (count > 0){
            cout << "Dequeued: " << data[front] << endl;
            front = (front + 1) % 5;
            count --;
        }else{
            cout << "Queue kosong!" << endl;
        }
    }

    int peek(){
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
    q.enqueue(10);
    q.enqueue(20);
    cout << "Front element: " << q.peek() << endl;
    q.dequeue();
    cout << "Front setelah dequeue: " << q.peek() << endl;
    cout << "Queue size: " << q.size() << endl;
    return 0;
}