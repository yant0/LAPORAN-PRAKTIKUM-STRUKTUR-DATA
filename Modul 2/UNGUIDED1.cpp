#include <iostream>
using namespace std;

int main() {
    
    int arr[10];

    cout << "Input nilai untuk array hingga 10\n";
    for (int i = 0; i < 10; i++) {
        cout << "Data ke-" << i+1 << " : ";
        cin >> arr[i];
    }

    cout << "\nData Array : ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nNomor Ganjil : ";
    for (int i = 0; i < 10; i++) {
        if (arr[i] % 2 != 0) {
            cout << arr[i] << ", ";
        }
    }

    cout << "\nNomor Genap : ";
    for (int i = 0; i < 10; i++) {
        if (arr[i] % 2 == 0) {
            cout << arr[i] << ", ";
        }
    }
}