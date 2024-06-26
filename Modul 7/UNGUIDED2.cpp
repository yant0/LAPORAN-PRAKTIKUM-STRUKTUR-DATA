#include <iostream>
#include <iomanip>
using namespace std;

const int maksimalQueue = 5;
int front = 0;
int back = 0;

struct Node {
    string name;
    string nim;
    Node *next;
    Node *prev;
};

bool isFull() {
    if (back == maksimalQueue) return true;
    else return false;
}

bool isEmpty() {
    if (back == 0) return true;
    else return false;
}

void enqueueAntrian(Node *&head, string data, string nim) {
    Node *add = new Node;
    add->name = data;
    add->nim = nim;
    if (isFull()) cout << "Antrian penuh" << endl;
    else {
        if (isEmpty()) {
            head = add;
            head->next = nullptr;
            head->prev = nullptr;
            front++;
            back++;
        } else {
            Node *current = head;
            for (int i = 0; i < back-1; i++) {
                current = current->next; 
            }
            current->next = add;
            add->prev = current;
            add->next = nullptr;
            back++;
        }
    }
}

void dequeueAntrian(Node *&head) {
    if (isEmpty()) cout << "Antrian kosong" << endl;
    else {
        Node *current = head->next;
        // for (int i = 0; i < back; i++) {
        //     queueTeller[i] = queueTeller[i + 1];   
        // }
        head = current;
        head->prev = nullptr;
        back--;
    }
}

int countQueue() {return back;}

void clearQueue(Node *&head) {
    if (isEmpty()) {cout << "Antrian Kosong" << endl;}
    else {
        // for (int i = 0; i < back; i++) {
        //     queueTeller[i] = "";
        // }
        head = nullptr;
        back = 0;
        front = 0;
    }
}

void viewQueue(Node *&head) {
    cout << "Data Mahasiswa:" << endl;
    Node *current = head;
    for (int i = 0; i < maksimalQueue; i++) {
        // cout << i + 1 << ". " << queueTeller[i] << endl;
        if (current != nullptr) {
            cout << i + 1 << ". " << left << setw(30) << current->name << setw(12) << current->nim << endl ;
            current  = current->next;
        } else {
        cout << i + 1 << ". (Kosong)" << endl;
        }
    }
}

int main() {
    Node *mahasiswa = new Node;

    enqueueAntrian(mahasiswa,"Andi", "2311102042");
    enqueueAntrian(mahasiswa, "Maya", "2311102022");
    viewQueue(mahasiswa);
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian(mahasiswa);
    enqueueAntrian(mahasiswa, "Muhammad Agha Zulfadhli", "2311102015");
    viewQueue(mahasiswa);
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue(mahasiswa);
    viewQueue(mahasiswa);
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}