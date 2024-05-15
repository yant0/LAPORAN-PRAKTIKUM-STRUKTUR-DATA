#include <iostream>
#include <iomanip>
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

int main()
{
    const int MAX_SIZE = 100;

    char stack[MAX_SIZE];
    cout << left << setw(18) << "Masukkan Kalimat " << ": ";
    cin.getline(stack, MAX_SIZE);
    // inputnnya satu aja yah 😭

    int size = strlen(stack);

    char stack_ori[MAX_SIZE + 1];
    strcpy(stack_ori, stack);

    swapStack(stack, size);
    cout << left << setw(18) << "Data " << ": " <<  stack;

    return 0;
}