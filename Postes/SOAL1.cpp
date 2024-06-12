#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int mA_015[3][4] = {{2,1,6,2},{1,2,3,4},{4,3,5,1}};
    int mB_015[3][4] = {{1,2,3,4},{7,1,2,1},{1,3,1,1}};

    cout << "Matriks A_015\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << mA_015[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Matriks B_015\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << mB_015[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Hasil Penjumlahan A+B\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << mA_015[i][j]+mB_015[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Hasil Penjumlahan A-B\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << right << setw(4) << mA_015[i][j]-mB_015[i][j];
        }
        cout << endl;
    }
    return 0;
}