#include <iostream>
#include <utility>
using namespace std;

int row (char matrix[99][99], int a, int b, int N)
{
    for (int i = 0; i < N; ++i)
    {
        swap(matrix[a -1][i], matrix[b - 1][i]);
    }
}

int column (char matrix[99][99], int a, int b, int N)
{
    for (int i = 0; i < N; ++i)
    {
        swap(matrix[i][a - 1], matrix[i][b - 1]);
    }
}

int increase (char matrix[99][99], int N)
{
    for (int row = 0; row < N; ++row)
    {
        for (int column = 0; column < N; ++column)
        {
            matrix[row][column] += 1;
            if (matrix[row][column] > '9')
            {
                matrix[row][column] = '0';
            }
            else if (matrix[row][column] < '0')
            {
                matrix[row][column] = '9';
            }
        }
    }
}

int decrease (char matrix[99][99], int N)
{
    for (int row = 0; row < N; ++row)
    {
        for (int column = 0; column < N; ++column)
        {
            matrix[row][column] -= 1;
            if (matrix[row][column] > '9')
            {
                matrix[row][column] = '0';
            }
            else if (matrix[row][column] < '0')
            {
                matrix[row][column] = '9';
            }
        }
    }
}

int transpose (char matrix[99][99], int N)
{
    int temp = 0;
    for (int row = 0; row < N; ++row)
    {
        for (int column = temp; column < N; ++column)
        {
            swap(matrix[row][column], matrix[column][row]);
        }
        ++temp;
    }
}

int main()
{
    int times, counter = 0, N, operations, a, b;
    char matrix[99][99] = {{}};
    string functions;
    cin >> times;
    for (int A = 1; A <= times; ++A)
    {
        ++counter;
        cin >> N;
        for (int row = 0; row < N; ++row)
        {
            for (int column = 0; column < N; ++column)
            {
                cin >> matrix[row][column];
            }
        }
        cin >> operations;
        for (int B = 1; B <= operations; ++B)
        {
            cin >> functions;
            if (functions == "row")
            {
                cin >> a >> b;
                row(matrix, a, b, N);
            }
            else if (functions == "col")
            {
                cin >> a >> b;
                column(matrix, a, b, N);
            }
            else if (functions == "inc")
            {
                increase(matrix, N);
            }
            else if (functions == "dec")
            {
                decrease(matrix, N);
            }
            else if (functions == "transpose")
            {
                transpose(matrix, N);
            }
        }
        cout << "Case #" << counter << endl;
        for (int C = 0; C < N; ++C)
        {
            for (int D = 0; D < N; ++D)
            {
                cout << matrix[C][D];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
