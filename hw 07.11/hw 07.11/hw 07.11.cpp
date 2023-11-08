#include "settings.h"

void AddRow(int** arr, int* rows, int columns, int input_index) {
    *rows += 1;
    int** time_array = new int*[*rows];
    for (int y = 0; y < input_index; y++) {
        time_array[y] = new int[columns];
        for (int x = 0; x < columns; x++) {
            time_array[y][x] = arr[y][x];
            cout << time_array[y][x] << " ";
        }
        cout << "\n";
    }
    int index = 0;
    time_array[input_index] = new int[columns];
    for (int y = 0; y < columns; y++) {
        time_array[input_index][index] = 0;
        cout << time_array[input_index][index] << " ";
        index++;
    }
    cout << "\n";
    for (int y = input_index; y < columns; y++) {
        time_array[y] = new int[columns];
        for (int x = 0; x < columns; x++) {
            time_array[y][x] = arr[y][x];
            cout << time_array[y][x] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    // input_index = 2
}

void AddColumn(int** arr, int rows, int* columns, int input_index) {
    *columns += 1;
    int** time_array = new int* [rows];
    for (int y = 0; y < rows; y++) {
        bool zero = false;
        time_array[y] = new int[*columns];
        for (int x = 0; x < *columns; x++) {
            if (x == input_index) {
                time_array[y][x] = 0;
                cout << time_array[y][x] << " ";
                zero = true;
            }
            else {
                if (zero) {
                    time_array[y][x] = arr[y][x - 1];
                    cout << time_array[y][x] << " ";
                }
                else {
                    time_array[y][x] = arr[y][x];
                    cout << time_array[y][x] << " ";
                }
            }
        }
        cout << "\n";
    }

    // input_index = 2
}

int main()
{
    // стартовый массив
    srand(time(NULL));
    int rows = 4;
    int cols = 4;
    int** start_array = new int*[rows];
    for (int i = 0; i < rows; i++) {
        start_array[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            start_array[i][j] = rand() % 10;
            cout << start_array[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    AddRow(start_array, &rows, cols, 2);

    AddColumn(start_array, rows, &cols, 2);
}