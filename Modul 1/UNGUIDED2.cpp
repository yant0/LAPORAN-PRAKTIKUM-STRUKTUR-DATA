#include <iostream>
using namespace std;

struct StructManusia {
    string nama;
    int umur;
    int tanggal_lahir;
    char tipe_kelamin;
};
class ClassManusia {
    string nama;
    int umur;
    int tanggal_lahir;
    char tipe_kelamin;
    
    public:
    string getNama(){ return nama; }
    int getUmur(){ return umur; }
    int getLahir(){ return tanggal_lahir; }
    char getKelamin(){ return tipe_kelamin; }

    void addNama(string addNama){ nama = addNama; }
    void addUmur(int addUmur){ umur = addUmur; }
    void addLahir(int addLahir){ tanggal_lahir = addLahir; }
    void addKelamin(char addKelamin){ tipe_kelamin = addKelamin; }
};

int main() {

    StructManusia struct_manusia;   //Secara default PUblic (dapat diakses dari luar)
    struct_manusia.nama = "Yanto";
    struct_manusia.umur = 69;
    struct_manusia.tanggal_lahir = 010203;
    struct_manusia.tipe_kelamin = 'F';
    ClassManusia class_manusia;     //Secara default Private (tidak dapat diakses dari luar)
    // class_manusia.nama = "Yanto";
    // class_manusia.umur = 69;
    // class_manusia.tanggal_lahir = 110203;
    // class_manusia.tipe_kelamin = 'f';
    // ------- kode di atas akan error karena class secara default private -----
    class_manusia.addNama("Udin");
    class_manusia.addUmur(12);
    class_manusia.addLahir(990101);
    class_manusia.addKelamin('L');

    cout << "Struct > Manusia _________\n";
    cout << struct_manusia.nama << endl;
    cout << struct_manusia.umur << endl;
    cout << struct_manusia.tanggal_lahir << endl;
    cout << struct_manusia.tipe_kelamin << endl;
    cout << "Class > Manusia _________\n";
    cout << class_manusia.getNama() << endl;
    cout << class_manusia.getUmur() << endl;
    cout << class_manusia.getLahir() << endl;
    cout << class_manusia.getKelamin() << endl;

    return 0;
}
