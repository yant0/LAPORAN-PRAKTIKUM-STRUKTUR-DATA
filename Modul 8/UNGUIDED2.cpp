#include <iostream>
using namespace std;
int main() {
    string kalimat;
    int vocal[5] = {0,0,0,0,0};
    cout << "-------- banyaknya huruf vocal dalam sebuah kalimat Perogram --------\n";
    cout << "Masukkan kalimat : ";
    getline(cin, kalimat);

    for (int i = 0; i < kalimat.size() ; i++) {
        if (kalimat[i] == 'a') {vocal[0]++;}
        if (kalimat[i] == 'i') {vocal[1]++;}
        if (kalimat[i] == 'u') {vocal[2]++;}
        if (kalimat[i] == 'e') {vocal[3]++;}
        if (kalimat[i] == 'o') {vocal[4]++;}
    }

    cout << "\nJumlah huruf vocal dalam kalimat : \n"
    "1. Huruf a : " << vocal[0] << endl <<
    "2. Huruf i : " << vocal[1] << endl <<
    "3. Huruf u : " << vocal[2] << endl <<
    "4. Huruf e : " << vocal[3] << endl << 
    "5. Huruf o : " << vocal[4] << endl;    
}