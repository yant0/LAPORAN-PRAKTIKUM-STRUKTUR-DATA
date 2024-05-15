// Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari
// array dengan map.

#include <iostream>
#include <map>
using namespace std;

int main() {

    int array_siswa_kelas[4]= {42, 39, 40, 41};
    map<char, int> map_siswa_kelas;
    map_siswa_kelas['A'] = 42;
    map_siswa_kelas['B'] = 39;
    map_siswa_kelas['C'] = 40;
    map_siswa_kelas['D'] = 41;

    cout << "Print jumlah siswa menggunakan array________\n";
    for (int i = 0; i < 4; i++) {
        cout << "Kelas " << static_cast<char>(65+i) << " = "<< array_siswa_kelas[i] << endl;
    }
    cout << "Print jumlah siswa menggunakan map________\n";
    for (auto i : map_siswa_kelas){
        cout << "Kelas " << i.first << " = " << i.second << endl;
    }
    return 0;
}
