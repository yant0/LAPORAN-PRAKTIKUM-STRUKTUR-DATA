#include <iostream>
using namespace std;

int chartoint(char a) { return a;}
int doubletoint(double a) { return static_cast<int>(a); }
int floattoint(float a) { return static_cast<int>(a); }
char inttochar(int a) {return static_cast<char>(a); }
double inttodouble(int a) { return static_cast<double>(a); }
float inttofloat(int a) { return static_cast<float>(a); }

int main() {
    int choice, input;
    char input_char;

    cout << "Program converter _________\n1. Char -> Int\n2. Double -> Int\n3. Float -> Int\n4. Int -> Char\n5. Int ->Double\n6. Int -> Float\nPilih intruksi : ";
    cin >> choice;

    if (choice == 1) {
        cout << "Input karakter : ";
        cin >> input_char;
        cout << "Hasil konversi :" << chartoint(input_char);
    } else if (choice == 2) {
        cout << "Input double : ";
        cin >> input;
        static_cast<double>(input);
        cout << "Hasil konversi :" << doubletoint(input);
    } else if (choice == 3) {
        cout << "Input float : ";
        cin >> input;
        static_cast<float>(input);
        cout << "Hasil konversi :" << floattoint(input);
    } else if (choice == 4) {
        cout << "Input int : ";
        cin >> input;
        cout << "Hasil konversi :" << inttochar(input);
    } else if (choice == 5) {
        cout << "Input int : ";
        cin >> input;
        cout << "Hasil konversi :" << inttodouble(input);
    } else if (choice == 6) {
        cout << "Input int : ";
        cin >> input;
        cout << "Hasil konversi :" << inttofloat(input);
    }
    return 0;
}
