#include <iostream>
using namespace std;

// (A)
int square_matrix(int n){
    if (n < 1) cout << "Error: n debe ser positivo y mayor a 1" << "\n"; return 0;

    int matrix[n];
    int flag = 1;
    for (const int i: matrix){
        int line[n];
        for (const int j = 0; j < n; j++){
            line[j] = flag;
            flag++;
        }
        matrix[i] = line;
    }
    return matrix;
    
}

// (B)
int main(){
    int n;
    cout << "Ingrese el tamaño de la matriz cuadrada: ";
    cin >> n;
    matrix = square_matrix(n);
    int fila = n - 1;
    int columna = n - 1;
    for (int i = 0; i < n**2; i++){
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