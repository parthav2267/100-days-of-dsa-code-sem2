#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    int mat1[m][n], mat2[m][n];
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &mat1[i][j]);
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &mat2[i][j]);
        for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", mat1[i][j] + mat2[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
