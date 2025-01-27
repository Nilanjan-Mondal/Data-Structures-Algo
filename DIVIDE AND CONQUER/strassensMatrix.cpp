#include <stdio.h>
#define MAX 64 
int count = 0;
void addMatrix(int n, int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrix(int n, int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassen(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX]) {
    if (n == 1) {
        // Base case: Multiply single elements
        C[0][0] = A[0][0] * B[0][0];
        return;
    } 
    else {
        count += 7;
        int k = n / 2;

        int A11[MAX][MAX], A12[MAX][MAX], A21[MAX][MAX], A22[MAX][MAX];
        int B11[MAX][MAX], B12[MAX][MAX], B21[MAX][MAX], B22[MAX][MAX];
        int P[MAX][MAX], Q[MAX][MAX], R[MAX][MAX], S[MAX][MAX], T[MAX][MAX], U[MAX][MAX], V[MAX][MAX];
        int temp1[MAX][MAX], temp2[MAX][MAX];
    
        // Divide matrices into submatrices
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + k];
                A21[i][j] = A[i + k][j];
                A22[i][j] = A[i + k][j + k];
    
                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + k];
                B21[i][j] = B[i + k][j];
                B22[i][j] = B[i + k][j + k];
            }
        }
    
        // Compute P to V
        addMatrix(k, A11, A22, temp1);             // temp1 = A11 + A22
        addMatrix(k, B11, B22, temp2);             // temp2 = B11 + B22
        strassen(k, temp1, temp2, P);              // P = (A11 + A22) * (B11 + B22)
    
        addMatrix(k, A21, A22, temp1);             // temp1 = A21 + A22
        strassen(k, temp1, B11, Q);                // Q = (A21 + A22) * B11
    
        subtractMatrix(k, B12, B22, temp2);        // temp2 = B12 - B22
        strassen(k, A11, temp2, R);                // R = A11 * (B12 - B22)
    
        subtractMatrix(k, B21, B11, temp2);        // temp2 = B21 - B11
        strassen(k, A22, temp2, S);                // S = A22 * (B21 - B11)
    
        addMatrix(k, A11, A12, temp1);             // temp1 = A11 + A12
        strassen(k, temp1, B22, T);                // T = (A11 + A12) * B22
    
        subtractMatrix(k, A21, A11, temp1);        // temp1 = A21 - A11
        addMatrix(k, B11, B12, temp2);             // temp2 = B11 + B12
        strassen(k, temp1, temp2, U);              // U = (A21 - A11) * (B11 + B12)
    
        subtractMatrix(k, A12, A22, temp1);        // temp1 = A12 - A22
        addMatrix(k, B21, B22, temp2);             // temp2 = B21 + B22
        strassen(k, temp1, temp2, V);              // V = (A12 - A22) * (B21 + B22)
    
        // Combine results into C
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                C[i][j] = P[i][j] + S[i][j] - T[i][j] + V[i][j];         // C11
                C[i][j + k] = R[i][j] + T[i][j];                         // C12
                C[i + k][j] = Q[i][j] + S[i][j];                         // C21
                C[i + k][j + k] = P[i][j] - Q[i][j] + R[i][j] + U[i][j]; // C22
            }
        }
    }

    
}

void printMatrix(int n, int matrix[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the size of the matrix (power of 2): ");
    scanf("%d", &n);

    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX] = {0};

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    strassen(n, A, B, C);

    printf("Resultant matrix C:\n");
    printMatrix(n, C);
    printf("Count: %d", count);

    return 0;
}
