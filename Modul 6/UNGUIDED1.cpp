#include <iostream>
#include <cstring>
using namespace std;

void printStack(char *stack, const int &size) {
    for (int i = 0; i < size; i++) cout << stack[i];
    cout << endl;
}

void swapStack(char *stack, const int &size) {
    for (int i = 0, j = size - 1; i < j; i++, j--) {
        swap(stack[i], stack[j]);
    }
}

bool checkPolindrom(const char *stack_ori, const char *stack_swapped, const int &size) {
    for (int i = 0; i < size; i++) {
        if (stack_ori[i] != stack_swapped[i]) return false;
    }
    return true;
}
int main()
{
    const int MAX_SIZE = 100;

    char stack[MAX_SIZE];
    cout << "Masukkan Kalimat : ";
    cin.getline(stack, MAX_SIZE);
    // inputnnya satu aja yah 😭

    int size = strlen(stack);
    char stack_ori[MAX_SIZE + 1];
    strcpy(stack_ori, stack);
    swapStack(stack, size);

    if (checkPolindrom(stack_ori, stack, size)) cout << "Kalimat tersebut Polindrom" << endl;
    else cout << "Kalimat tersebut bukan Polindrom" << endl;

    return 0;
}