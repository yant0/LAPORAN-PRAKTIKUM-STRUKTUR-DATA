#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int jumlah_simpul;

    cout << "Silakan masukan jumlah simpul : ";
    cin >> jumlah_simpul;
    string nama_simpul[jumlah_simpul];

    cout << "Silakan masukan nama simpul\n";

    cin.ignore();
    for (int i = 0; i < jumlah_simpul; i++) {
        cout << "Simpul " << i+1 << " : ";
        getline(cin, nama_simpul[i]);
    }

    int simpul[jumlah_simpul][jumlah_simpul];

    cout << "Silakan masukkan bobot antar simpul\n";

    for (int i = 0; i < jumlah_simpul; i++) {
        for (int k = 0; k < jumlah_simpul; k++) {
            cout <<  nama_simpul[i] << " --> " << nama_simpul[k] << " = ";
            cin >> simpul[i][k];
        }
    }

    // CHECKS LONGEST LINE IN THE ARRAY OF CITIES
    // FOR SETW()
    int formatting;

    for (int i = 0; i < jumlah_simpul-1; i++) {
        if (nama_simpul[i].length() < nama_simpul[i+1].length())  {
            formatting = nama_simpul[i+1].length();
        }
    }

    // JUDUL TABEL
    cout << left << setw(formatting) << " ";
    for (int i = 0; i < jumlah_simpul; i++) {
        cout << left << setw(nama_simpul[i].length()) << nama_simpul[i]<< "   ";
    }
    cout << endl;

    // TOTAL KOTA FOR FORMATTING
    int MuhammadAghaZulfadhli_2311102015 = sizeof(nama_simpul) / sizeof(*nama_simpul);

    // PRINT ISI TABEL
    for (int i = 0; i < jumlah_simpul; i++) {
        cout << left << setw(formatting) << nama_simpul[i];
        for (int k = 0; k < MuhammadAghaZulfadhli_2311102015; k++) {
            cout << right << setw(nama_simpul[k].length()) << simpul[i][k] << "   ";
        }
        cout << endl;
    }
}