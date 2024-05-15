#include <iostream>
#include <algorithm>
using namespace std;

string checkPolindrom(string str) {
    string reversed = str;
    reverse(reversed.begin(), reversed.end());
    if (str != reversed) {
        return "Kalimat Tersebut adalah : Bukan Polindrom\n";
    }
    return "Kalimat Tersebut adalah : Polindrom\n";
}

void inputKalimat(string &str) {
    cout << "Masukkan Kalimat : ";
    getline(cin, str);
}

int main() {

    string str;
    
    while (true) {
    inputKalimat(str);
    if (str == "0") break; 
    cout << checkPolindrom(str);
    }

    return 0;
}

// GAJADI KARENA PAKE STRING SEHARUSYA BOLE TAPI YAH TERSERAH