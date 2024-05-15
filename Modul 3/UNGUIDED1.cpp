#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
    string nama_anda;
    int usia_anda;
    Node *next;
};

void addNode(Node *&list, string name = "", int age = -1, int placement = 0) {
    Node *newNode = new Node;
    newNode->next = NULL;
    int iterator = 0;

    if (placement < 0) {
        // Jika placement ngawur
        cout << "Urutan invalid !";
        return;
    }

    if (name != "" && age != -1) {
        // jika variabel di fungsi ada
        newNode->nama_anda = name;
        newNode->usia_anda = age;
    } else {
        // jika variabel kosong
        cout << "Input nama : ";
        cin >> newNode->nama_anda;
        cout << "Input usia : ";
        cin >> newNode->usia_anda;
    }

    // Jika list kosong
    if (list == NULL || list->nama_anda == "") {
        list = newNode;
        return;
    }
    
    // Perulangan hingga terakhir
    Node *current = list;
    while (current->next != nullptr) {
        if (placement != 0) {
            if (/*wkwk*/ iterator+2 == placement) {break;}
            if (/*kocak*/ 1 == placement) {
                newNode->next = current;
                list = newNode; // fak it bruh
                // current->nama_anda = newNode->nama_anda;
                // current->usia_anda = newNode->usia_anda;
                return;
            }
            iterator++;
        }
        current = current->next;    
    }
    newNode->next = current->next;
    current->next = newNode;
}

void initList(Node *&list) {
    cout << "----- INIT\n";
    addNode(list, "Muhammad Agha Zulfadhli", 18);
    addNode(list, "John", 19);
    addNode(list, "Jane", 20);
    addNode(list, "Michael", 18);
    addNode(list, "Yusuke", 19);
    addNode(list, "Akechi", 20);
    addNode(list, "Hoshino", 18);
    addNode(list, "Karin", 18);
}

void printNodes(Node *&list) {

    cout << "----- PRINT OUT\n";
    // Jika list kosong
    if (list->nama_anda == "") {
        cout << "kosong :[\n";
        return;
    }

    Node *counter = list;
        cout << left << setw(30) << "Nama";
        cout << left << setw(4) << "Usia" << endl;
    while (counter != NULL) {
        cout << left << setw(30) << counter->nama_anda;
        cout << left << setw(4) << counter->usia_anda << endl;
        counter = counter->next;
    }
}

void deleteNode(Node *&list) {

    string deleteThis;
    Node *current = list;
    Node *previous = NULL;

    printNodes(list);

    // jika list kosong
    if (list == NULL) {
        cout << "LIST KOSONG CURUT";
        return;
    }
    cout << "---- DELETE\n";
    // deleteThis->nama_anda = "Akechi"; (buat tugas 1b)
    cout << "Hapus nama : ";
    cin >> deleteThis;

    while (deleteThis != current->nama_anda) {
        previous = current;
        current = current->next;
    }

    // If the note to delete is the first node
    if (previous == NULL) {
        list = list->next;
    } else {
        previous->next = current->next;
    }
    delete current;
    
}

void changeNode(Node *&list) {

    int newAge;
    string oldName, newName;

    printNodes(list);
    cout << "----- CHANGE\n";
    cout << "Nama siapa yang ingin diganti : ";
    cin >> oldName;
    cout << "Nama baru : ";
    cin >> newName;
    cout << "Berapa umur dia : ";
    cin >> newAge;

    Node *current = list;
    while (oldName != current->nama_anda) {current = current->next;}
    current->nama_anda = newName;
    current->usia_anda = newAge;
}

void addNodeSpecified(Node *&list) {

    string newName;
    int age,placement;

    printNodes(list);
    cout << "----- ADD\n";
    cout << "Nama : ";
    cin >> newName;
    cout << "Usia : ";
    cin >> age;
    cout << "Placement : ";
    cin >> placement;

    addNode(list, newName, age, placement);
}

int main() {
    Node* list = new Node;
    //compeler 
    list->nama_anda =  "";
    list->usia_anda =  -1;
    list->next = NULL;

    int choice = 0;

    do {
        cout << "----- MENU\nMenu orang program yeah\n\n1. Tampilkan list\n2. Tambah orang\n3. Tambah orang di urutan \n4. Ganti orang\n5. Inisialisasi list orang (template)\n6. Hapus orang\n7. Exit";
        cout << "\n\nPilih [1-7] : ";
        cin >> choice;

        switch (choice) {
        case 1:
            printNodes(list);
            break;

        case 2:
            cout << "----- ADD\n";
            addNode(list);
            break;

        case 3:
            addNodeSpecified(list);
            break;

        case 4:
            changeNode(list);
            break;

        case 5:
            initList(list);
            cout << "DONE\n";
            break;
        
        case 6:
            deleteNode(list);
            break;
        
        default:
            break;
        }
    } while (choice != 7);
}