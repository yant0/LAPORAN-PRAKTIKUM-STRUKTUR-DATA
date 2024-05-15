#include <iostream>
#include <iomanip>
using namespace std;

class Node {
    public:
    double data;
    string kata;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(double data, string kata) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->kata = kata;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }
    
    void pop() {
        if (head == nullptr) {
                return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    bool update(int oldData, int newData, string oldKata, string newKata) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData && current->kata == oldKata) {
                current->data = newData;
                current->kata = newKata;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void deleteSpecific(string name) {
        Node* current = head;

        // cek list sampe ambis 🔥🔥
        while (current != nullptr) {
            if (current->kata == name){break;}
            current = current->next;
        } if (current == nullptr) {
            return;
        }

        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            // Jika yg dihapus kepala
            head = current->next;
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else {
            // Jika yg dihapus buntut
            tail = current->prev;
        }
        delete current;
    }

    void display() {
        Node* current = head;
        cout << left << setw(20) << "Nama Produk" << "Harga" << endl;
        while (current != nullptr) {
            cout << left << setw(20)<< current->kata;
            cout << fixed << setprecision(3) << current->data << endl;
            current = current->next;
        }
    }

    void pushSpecific(double data, string kata, string cari) {
        Node *newNode = new Node;
        Node *current = head;
        newNode->data = data;
        newNode->kata = kata;

        while (cari != current->kata) {
            current = current->next;
        }
        newNode->next = current->next;
        current->prev = current->prev;
        current->next = newNode;
    }

};

int main() {
    DoublyLinkedList list;

    list.push(30.000, "Hanasui");
    list.push(50.000, "Wardah");
    list.push(100.000, "Skintific");
    list.push(150.000, "Somethinc");
    list.push(60.000, "Originote");

    while (true) {
        cout << "\n1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        
        switch (choice) {
            case 1: {
                double data;
                string kata;
                cout << "Enter data to add (double): ";
                cin >> data;
                cin.ignore();
                cout << "Enter kata to add: ";
                getline(cin, kata);
                list.push(data,kata);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                list.display();

                double oldData, newData;
                string oldKata, newKata;
                cout << "\nEnter old data (double): ";
                cin >> oldData;
                cout << "Enter new data (double): ";
                cin >> newData;
                cin.ignore();
                cout << "Enter old kata: ";
                getline(cin, oldKata);
                cout << "Enter new kata: ";
                getline(cin, newKata);
                bool updated = list.update(oldData, newData, oldKata ,newKata);
                if (!updated) { cout << "Data not found" << endl; }
                break;
            }
            case 4: {
                list.display();

                double data;
                string kata;
                cout << "\nEnter data to add (double): ";
                cin >> data;
                cin.ignore();
                cout << "Enter kata to add: ";
                getline(cin, kata);

                string cekThis;
                cout << "Add after what? : ";
                getline(cin, cekThis);
                list.pushSpecific(data, kata, cekThis);
                break;
            }
            case 5: {
                list.display();

                string delThis;
                cin.ignore();
                cout << "\nDelete what? : ";
                getline(cin, delThis);
                list.deleteSpecific(delThis);
            break;
            }
            case 6: {
                list.deleteAll();
            break;
            }
            case 7: {
                list.display();
            break;
            }
            case 8: {
            return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
            break;
            }
        }
    }
    return 0;
}