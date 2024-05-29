#include <iostream>
using namespace std;

int main() {
    int dataNum[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int num4 = 0 ;
    for (int i = 0; i < 10; i++) if (dataNum[i] == 4) num4++;
    cout << "Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4\n"
    "Jumlah Nomor 4 di data : " << num4; 
}