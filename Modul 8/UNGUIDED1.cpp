#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool binarySearch(string kalimat, char key) {
    sort(kalimat.begin(), kalimat.end());
    // searching
    int awal, akhir, tengah;
    bool found;
    awal = 0;
    akhir = 7;
    while (!found && awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        if (kalimat[tengah] == key) {
            found = true;
            break;
        }
        else if (kalimat[tengah] < key) awal = tengah + 1;
        else akhir = tengah - 1;
    }
    return found;
}

int main() {
    string kalimat;
    char inputKata;
    cout << "-------- mencari sebuah huruf pada sebuah kalimat Perogram --------\n";
    cout << "Masukkan kalimat : ";
    getline(cin, kalimat);
    cout << "Masukkan kata untuk dicari : ";
    cin >> inputKata;

    cout << "Kata " << inputKata << " dalam kalimat : " << (binarySearch(kalimat, inputKata) ? "Ada" : "Tidak ada");
}