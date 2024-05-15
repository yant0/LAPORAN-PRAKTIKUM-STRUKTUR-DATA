#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
    string name;
    string nim;
    Node *next;
};

void addMhs(Node *&head, string name, string nim, int pos) {
    Node *add = new Node;
    add->name = name;
    add->nim = nim;

    if (pos < 0) {
        cout << "\n\nPosisi tidak falid";
        return;
    }
    

    // jika kosong
    if (head == nullptr) {
        head = add;
        head->next = nullptr;
        return;
    }

    // tambah di kepala
    if (pos == 0 || pos == 1) {
        add->next = head;
        head = add;
        return;
    }

    // tambah di tempat spesifik / diakhir
    if (pos > 0) {
        Node *current = head;
        Node *previous = current;
        for (int i = 0; i < pos-1 && current != nullptr ; i++) {
            previous = current;
            current = current->next;
        }
        previous->next = add;
        add->next = (current == head) ? nullptr : current;  
        /*
        gtw atas apaan, mungkin nangkep kalo list 
        cuma 1 terus nyambungin ke head lagi 
        */
    } // ok 😀👍
}

void addFront(Node *&head) {
    string name,nim;

    cout << "\n-Tambah Depan-\n\nMasukkan Nama : ";
    cin >> name;
    cout <<"Masukkan NIM : ";
    cin >> nim;
    addMhs(head,name,nim,0);
    cout <<"\nData telah ditambahkan";
}
void addBack(Node *&head) {
    string name,nim;

    cout << "\n-Tambah Belakang-\n\nMasukkan Nama : ";
    cin >> name;
    cout <<"Masukkan NIM : ";
    cin >> nim;
    addMhs(head,name,nim,99999);
    cout <<"\nData telah ditambahkan";
}
void AddSpecific(Node *&head) {
    string name,nim;
    int pos;

    cout << "\n-Tambah Tengah-\n\nMasukkan Nama : ";
    cin >> name;
    cout <<"Masukkan NIM : ";
    cin >> nim;
    cout <<"Masukkan Posisi : ";
    cin >> pos;
    addMhs(head,name,nim,pos);
    cout <<"\nData telah ditambahkan";
}

void changeMhs(Node *&head, string oldNim, string newName, string newNim) {
    // teorinya bila ada nama yg sama, jd kita pake nim aja
    Node *change = new Node;
    change->name = newName;
    change->nim = newNim;

    // ganti di kepala
    if (head->nim == oldNim || oldNim == "First") {
        change->next = head->next;
        head = change;
        return;
    }
    
    // iterasi
    Node *current = head;
    Node *previous = current;
    if (oldNim == "Last") { // DI AKHIR
        while (current->next != nullptr) {
        previous = current;
        current = current->next;
        }
        previous->next = change;
        change->next = nullptr;
        return;
    }
    while (current != nullptr && current->nim != oldNim) { // SPESIFIk
        previous = current;
        current = current->next;
    }
    if (current == nullptr) {
        cout << "\nNIM tidak ditemukan !";
        return;
    }
    previous->next = change;
    change->next = (current == head) ? nullptr : current->next;
}

void changeFront(Node *&head) {
    string name,nim;
    cout << "\n-Ubah Depan-\n\nMasukkan nama : ";
    cin >> name;
    cout << "Masukkan NIM : ";
    cin >> nim;
    changeMhs(head,"First",name,nim);
}
void changeSpecific(Node *&head) {
    string name,nim,oldNim;
    cout << "\n-Ubah Tengah-";
    cout << "\n\nMasukkan NIM yang ingin diganti : ";
    cin >> oldNim;
    cout << "\nMasukkan nama : ";
    cin >> name;
    cout << "Masukkan NIM : ";
    cin >> nim;
    changeMhs(head,oldNim,name,nim);
}
void changeBack(Node *&head) {
    string name,nim;
    cout << "\n-Ubah Belakang-\n\nMasukkan nama : ";
    cin >> name;
    cout << "Masukkan NIM : ";
    cin >> nim;
    changeMhs(head,"Last",name,nim);
}

void deleteMhs(Node *&head, string nim) {
    
    // Jika ngehapus kepala
    if (head->nim == nim || nim == "First") {
        Node *temp = head;
        head = temp->next;
        delete temp;
        return;
    }

    Node *current = head;
    Node *previous = current;
    if (nim == "Last") { // DI AKHIR
        while (current->next != nullptr) {
        previous = current;
        current = current->next;
        }
        previous->next = current->next;
        delete current;
        return;
    }
    while (current != nullptr && current->nim != nim) { // SPESIFIk
        previous = current;
        current = current->next;
    }
    
    previous->next = current->next;
    delete current;
}

void deleteBack(Node *&head) {
    deleteMhs(head,"Last");
    cout << "\n-Hapus Belakang-\nData (nama mahasiswa yang dihapus) berhasil dihapus";
}
void deleteSpecific(Node *&head) {
    string nim;
    cout << "\n-Hapus Tengah-\n\nMasukkan NIM : "; // ganti nim sory :p
    cin >> nim;
    deleteMhs(head,nim);
    cout << "\nData (nama mahasiswa yang dihapus) berhasil dihapus";
}
void deleteFront(Node *&head) {
    deleteMhs(head,"First");
    cout << "\n-Hapus Depan-\nData (nama mahasiswa yang dihapus) berhasil dihapus";
}

void deleteAll(Node *&head) {
    // iterasi
    Node *current = head;
    while (current != nullptr) { // SPESIFIk
        Node *previous = current;
        current = current->next;
        delete previous;
    }
    if (current == nullptr) {
        head = nullptr;
    }
}

void viewNodes(Node *head) {
    cout << "\n\nDATA MAHASISWA\n\n";
    if (head == nullptr) {
        cout << "\nDATA KOSOMG";
        return;
    }
    
    cout << left << setw (30) << "Nama" << setw(18) << "NIM" << endl; 
    for (Node *current = head; current != nullptr; current = current->next) {
        cout << left << setw (30) << current->name << setw(18) << current->nim << endl; 
    }
}

int main() {
    Node *mhs = new Node;
    mhs = nullptr;
    int choice;

    addMhs(mhs,"Jawad","23300001",1);
    addMhs(mhs,"Muhammad Agha Zulfadhli","2311102015",2);
    addMhs(mhs,"Farrel","23300003",3);
    addMhs(mhs,"Denis","23300005",4);
    addMhs(mhs,"Anis","23300008",5);
    addMhs(mhs,"Bowo","23300015",6);
    addMhs(mhs,"Gahar","23300040",7);
    addMhs(mhs,"Udin","23300048",8);
    addMhs(mhs,"Ucok","23300050",9);
    addMhs(mhs,"Budi","23300099",10);

    do {    
        cout << "\n\nPROGRAM SINGLE LINKED LIST NON-CIRCULAR\n"
        "1. Tambah Depan\n"
        "2. Tambah Belakang\n"
        "3. Tambah Tengah\n"
        "4. Ubah Depan\n"
        "5. Ubah Belakang\n"
        "6. Ubah Tengah\n"
        "7. Hapus Depan\n"
        "8. Hapus Belakang\n"
        "9. Hapus Tengah\n"
        "10. Hapus List\n"
        "11. TAMPILKAN\n"
        "0. KELUAR\n\n"
        "Pilih Operasi : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addFront(mhs);
            break;
        
        case 2:
            addBack(mhs);
            break;
        
        case 3:
            AddSpecific(mhs);
            break;
        
        case 4:
            changeFront(mhs);
            break;
        
        case 5:
            changeBack(mhs);
            break;
        
        case 6:
            changeSpecific(mhs);
            break;
        
        case 7:
            deleteFront(mhs);
            break;
        
        case 8:
            deleteBack(mhs);
            break;
        
        case 9:
            deleteSpecific(mhs);
            break;
        
        case 10:
            deleteAll(mhs);
            break;
        
        case 11:
            viewNodes(mhs);
            break;
        
        default:
            break;
        }
    } while (choice != 0);
}