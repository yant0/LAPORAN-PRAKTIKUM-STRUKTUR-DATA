#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    int arr[10], min, max, choice;
    double sum = 0;

    cout << "Input nilai untuk array hingga 10\n";
    for (int i = 0; i < 10; i++) {
        cout << "Data ke-" << i+1 << " : ";
        cin >> arr[i];
    }

    cout << "\nData Array : ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    for (int i = 0; i < 10; i++) {
        sum += arr[i];
    }
    
    max = arr[0];
    min = arr[0];
    for (int i = 0; i < 10; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
        if (min > arr[i]) {
            min = arr[i];
        }
    }

    cout << "\n\n1. Rata-rata\n2. Minimum\n3. Maksimum\n\nPilih Menu : ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "\nRata rata : " << fixed << sum/10 << endl;
        break;
    case 2:
        cout << "Nilai Minimum : " << min << endl;
        break;
    case 3:
        cout << "Nilai Maksimum : " << max << endl;
        break;
    
    default:
        break;
    }
}