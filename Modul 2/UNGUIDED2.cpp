#include <iostream>
using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI
int main() {
    int d1,d2,d3;

    cout << "Inputkan ukuran dimensi pertama : ";
    cin >> d1;
    cout << "Inputkan ukuran dimensi kedua : ";
    cin >> d2;
    cout << "Inputkan ukuran dimensi ketiga : ";
    cin >> d3;


    // Deklarasi array
    int arr[d1][d2][d3];
    // Input elemen
    for (int x = 0; x < d1; x++) {
        for (int y = 0; y < d2; y++) {
            for (int z = 0; z < d3; z++) {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
    // Output Array
    for (int x = 0; x < d1; x++) {
        for (int y = 0; y < d2; y++) {
            for (int z = 0; z < d3; z++) {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // Tampilan array
    for (int x = 0; x < d1; x++) {
        for (int y = 0; y < d2; y++) {
            for (int z = 0; z < d3; z++) {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}