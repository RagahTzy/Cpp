#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node* prev;
};

class doublelinkedlist {
private:
    node* head;

public:
    doublelinkedlist(){
        head = nullptr;
    }

    void insertfront(int value){
        node* newnode = new node{value, nullptr, head};
        if(head != nullptr){
            head->prev = newnode;
        }
        head = newnode;
    }

    void insertback(int value){
        node* newnode = new node{value, nullptr, nullptr};
        if(head == nullptr){
            head = newnode;
            return;
        }
        node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }

    void displayfront(){
        node* temp = head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    doublelinkedlist dll;

    dll.insertfront(10);
    dll.insertfront(20);
    dll.insertback(5);
    dll.insertback(1);

    cout << "List Maju: ";
    dll.displayfront();

    return 0;
}