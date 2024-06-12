#include <iostream>
using namespace std;

struct Mahasiswa_015
{
    string nama;
    int nim;
    Mahasiswa_015 *next;
    Mahasiswa_015 *prev;
};

Mahasiswa_015 *head, *tail, *curr, *hapus;

void init()
{
    head = NULL;
    tail = NULL;
}

bool isEmpty()
{
    return head == NULL;
}

void insertDepan(string nama, int nim)
{
    Mahasiswa_015 *newMahasiswa = new Mahasiswa_015;
    newMahasiswa->nama = nama;
    newMahasiswa->nim = nim;
    newMahasiswa->next = NULL;
    newMahasiswa->prev = NULL;

    if (isEmpty())
    {
        head = tail = newMahasiswa;
    }
    else
    {
        newMahasiswa->next = head;
        head->prev = newMahasiswa;
        head = newMahasiswa;
    }
}

void insertBelakang(string nama, int nim) {
    Mahasiswa_015 *newMahasiswa = new Mahasiswa_015;
    newMahasiswa->nama = nama;
    newMahasiswa->nim = nim;
    newMahasiswa->next = NULL;
    newMahasiswa->prev = NULL;

    if (isEmpty()) {
        head = tail = newMahasiswa;
        tail->next = NULL;
    } else {
        tail->next = newMahasiswa;
        tail = newMahasiswa;
    }
}

void hapusBelakang()
{
    if (!isEmpty())
    {
        hapus = tail;
        tail = tail->prev;
        if (tail != NULL)
        {
            tail->next = NULL;
        }
        else
        {
            head = NULL;
        }
        delete hapus;
    }
}

void hapusDepan() {
        if (isEmpty() == false){
        if (head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        } else{
            head = tail = NULL;
        }
    } else{
        cout << "List kosong!" << endl;
    }
}

void tampilList()
{
    curr = head;
    while (curr != NULL)
    {
        cout << curr->nama << "\t" << curr->nim << endl;
        curr = curr->next;
    }
    cout << "---Print done\n";
}

int main()
{
    init();
    insertDepan("Arin", 2149692);
    insertDepan("Putra", 2201943);
    insertBelakang("Kalvin", 2371648);
    tampilList();

    hapusDepan();
    tampilList();

    hapusBelakang();
    tampilList();
    return 0;
}