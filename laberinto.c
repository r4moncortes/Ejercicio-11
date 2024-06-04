#include <stdio.h>
#define MAX 100

int countPaths(int maze[MAX][MAX], int m, int n) {
    int dp[MAX][MAX] = {0};

    // Si el punto de inicio es un obstáculo, no hay rutas posibles
    if (maze[0][0] == 1) {
        return 0;
    }

    // Inicializar el punto de partida
    dp[0][0] = 1;

    for (int i = 1; i < m; i++) {
        if (maze[i][0] == 0) {
            dp[i][0] = dp[i - 1][0];
        }
    }
    
    for (int j = 1; j < n; j++) {
        if (maze[0][j] == 0) {
            dp[0][j] = dp[0][j - 1];
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (maze[i][j] == 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[m - 1][n - 1];
}

int main() {
    int maze[MAX][MAX] = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    int m = 3; // Numero de filas
    int n = 3; // Numero de columnas

    int result = countPaths(maze, m, n);
    printf("Numero de rutas posibles: %d\n", result);

    return 0;
}

