#include <iostream>
using namespace std;

// (A)
int** square_matrix(int n){
    if (n < 1){
        cout << "Error: n debe ser positivo y mayor a 1" << "\n"; 
        return nullptr;
    }

    int** matrix = new int*[n];
    int flag = 1;
    for (int i = 0; i < n; i++){
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++){
            matrix[i][j] = flag;
            flag++;
        }
    }
    return matrix;
    
}

// (B)
int main(){
    int n;
    cout << "Ingrese el tamaño de la matriz cuadrada: ";
    cin >> n;
    int** matrix = square_matrix(n);
    if (matrix == nullptr) return 1;
    int fila = n - 1;
    int columna = n - 1;
    int end = n*n;
    for (int i = 0; i < end; i++){
        cout << "M" << n << "[" << fila << "][" << columna << "] = " << matrix[fila][columna] << "\n";
        if (columna > 0){
            columna--;
        }else{
            fila--;
            columna = n - 1;
        }
    }
    return 0;
}