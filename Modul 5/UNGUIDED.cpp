#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

const int TABLE_SIZE = 12;

struct HashNode {
    string nim;
    double grade;
};

int hashFunc(const string &nim) {
    int hash_result = 0;
    for (char it : nim) {
        hash_result += it;
    }
    return hash_result % TABLE_SIZE;
}

void addMahasiswa(vector<HashNode> &list, const string &nim, double grade) {
    HashNode add;
    add.nim = nim;
    add.grade = grade;
    list.push_back(add);
}

string searchByNIM(const vector<HashNode> &list, const string &nim) {
    for (const auto &node : list) {
        if (node.nim == nim) {
            return "NIM: " + node.nim + "\nGrade: " + to_string(node.grade);
        }
    }
    return "NIM: " + nim + " not found";
}

void searchByGrade(const vector<HashNode> mahasiswa[], double grade) {
    bool found = false;
    cout << left << setw(20) << "NIM" << "NILAI" << endl;
    for (int i = 0; i < TABLE_SIZE; i++) {
        for (const auto &node : mahasiswa[i]) {
            if (node.grade == grade) {
                cout << left << setw(20) << node.nim << fixed << setprecision(2) << node.grade << endl;
                found = true;
            }
        }
    }
    if (!found) {
        cout << "KOSONG" << endl;
    }
}

void deleteMahasiswa(vector<HashNode> &list, const string &nim) {
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (it->nim == nim) {
            list.erase(it);
            return;
        }
    }
}

string inputNIM() {
    string NIM;
    cout << "Masukkan NIM : ";
    cin >> NIM;
    return NIM;
}

double inputGrade() {
    double grade;
    cout << "Masukkan Nilai : ";
    cin >> grade;
    return grade;
}

int main() {
    int choice;
    string nim;
    double grade;

    vector<HashNode> mahasiswa[TABLE_SIZE];
    
    addMahasiswa(mahasiswa[hashFunc("2311102033")], "2311102033", 99.99);
    addMahasiswa(mahasiswa[hashFunc("2311102034")], "2311102034", 70.90);
    
    do {
        cout << "1. Tambah Mahasiswa\n2. Hapus\n3. Cari dengan NIM\n4. Cari dengan Nilai\n0. Exit\n\nINPUT : ";
        cin >> choice;

        switch (choice) {
            case 1:
                nim = inputNIM();
                grade = inputGrade();
                addMahasiswa(mahasiswa[hashFunc(nim)], nim, grade);
                cout << "\nDONE\n\n";
                break;
            case 2:
                nim = inputNIM();
                deleteMahasiswa(mahasiswa[hashFunc(nim)], nim);
                cout << "\nDONE\n\n";
                break;
            case 3:
                nim = inputNIM();
                cout << searchByNIM(mahasiswa[hashFunc(nim)], nim) << endl << endl;
                break;
            case 4:
                grade = inputGrade();
                searchByGrade(mahasiswa, grade);
                cout << "\n\n";
                break;
            default:
                break;
        }
    } while (choice > 0 && choice < 5);
    return 0;
}
