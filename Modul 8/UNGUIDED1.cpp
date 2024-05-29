#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool binarySearch(string kalimat, char key) {
    // searching
    sort(kalimat.begin(), kalimat.end());
    int awal = 0, akhir = kalimat.size() , tengah;
    bool found;
    while (!found && awal <= akhir) {
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
    cout << "Masukkan huruf untuk dicari : ";
    cin >> inputKata;

    cout << "Huruf " << inputKata << " dalam kalimat : " << (binarySearch(kalimat, inputKata) ? "Ada" : "Tidak ada");
}