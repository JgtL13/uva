#include <iostream>
#include <stdio.h>
using namespace std;

char maze[50][100];
void fill(int x, int y) {
    if (maze[x][y] == ' ' || maze[x][y] == '*')
    {
        maze[x][y] = '#';
        fill(x+1, y);
        fill(x-1, y);
        fill(x, y+1);
        fill(x, y-1);
    }
}
int main() {
    int t, i, j;
    cin >> t;
    getchar();
    while(t--)
    {
        int k = 0;
        while(gets(maze[k]))
        {
            if(maze[k][0] == '_')
            {
                break;
            }
            else
            {
                k++;
            }
        }
        for(i = 0; i < k; i++) {
            for(j = 0; maze[i][j]; j++)
            {
                if(maze[i][j] == '*')
                {
                    fill(i, j);
                }
            }
        }
        for(i = 0; i <= k; i++)
        {
            cout << maze[i] << endl;
        }
    }
    return 0;
}
