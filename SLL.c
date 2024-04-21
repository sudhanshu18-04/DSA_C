#include <stdio.h>
#include<stdlib.h>
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dfs(int x, int y, char (*mat)[y], int row, int colm) {
    if (row < 0 || row >= x || colm < 0 || colm >= y || mat[row][colm] != 'O') {
        return;
    }

    mat[row][colm] = 'V';  

    
    for (int d = 0; d < 4; d++) {
        int newRow = row + dr[d];
        int newcolm = colm + dc[d];
        dfs(x, y, mat, newRow, newcolm);
    }
}

void fill(int n, int m, char (*mat)[y]) {
    
    for (int i = 0; i < n; i++) {
        dfs(n, y, mat, i, 0);
        dfs(n, y, mat, i, m - 1);
    }
    for (int j = 0; j < y; j++) {
        dfs(n, y, mat, 0, j);
        dfs(n, y, mat, n - 1, j);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < y; j++) {
            if (mat[i][j] == 'O') {
                mat[i][j] = 'X';
            } else if (mat[i][j] == 'V') {
                mat[i][j] = 'O';
            }
        }
    }
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    char mat[a][b];
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            scanf(" %c", &mat[i][j]);
        }
    }

    fill(a, b, mat);
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < b; j++) {
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}