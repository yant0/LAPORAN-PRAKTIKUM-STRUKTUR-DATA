#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

void searchName(string nama, char huruf) {
    for (int i = 0; i < nama.length(); i++) {
        if (huruf == nama[i]) {
            cout << "Data ditemukan pada index ke-" << i+1;
            return;
        }
    }
    cout << "Data tidak ditemukan";
    return;
}

int main() {
    int choice_015, num2 = 0;
    char kata;
    string nama = "Agha";
    string nim = "2311102015";

    cout << "---MENU PENCARIAN---\n"
    "1. Cari huruf dalam nama Agha\n"
    "2. Hitung banyaknya angka dalam NIM 2311102015\n"
    "Pilihan: ";
    cin >> choice_015;

    switch (choice_015) {
    case 1:
        cout << left << setw(36) << "Nama " << nama << endl;
        cout << left << setw(36) << "Masukkan huruf yang ingin dicari : ";
        cin >> kata;
        sort(nama.begin(), nama.end());
        cout << left << setw(36) << "Nama setelah urut " << nama << endl;
        searchName(nama, kata);
        break;
    case 2:
        for (int i = 0; i < nim.length(); i++) if (nim[i] == '2') num2++;
        cout << "Banyak angka 2 dalam NIM : " << num2;
        break;
    default:
        break;
    }
    return 0;
}