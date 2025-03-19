#include <iostream>
using namespace std;

// (A)
int** square_matrix(int n){
    if (n < 1){ //Si n es menor a 1, no se puede crear una matriz cuadrada.
        cout << "Error: n debe ser positivo y mayor a 1" << "\n"; 
        return nullptr;
    }

    int** matrix = new int*[n];
    int flag = 1; //Defino un flag que me va a servir para asignar los valores a la matriz.
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
//Utilizo dos flags, donde al inicio voy a estar posicionado en la posición (n,n) de la matriz, y voy disminuyendo.
//principalmente el valor de las filas (asi voy de atras para adelante) y si ya no hay mas que imprimir, voy a la 
//fila de arriba y me posiciono en la ultima columna nuevamente
void print_matrix(int** matrix, int n){
    int fila = n - 1;   
    int columna = n - 1; 
    int end = n*n;       //Defino un flag para saber cuándo terminar de recorrer la matriz.
    int flag_to_end = 0;
    while (flag_to_end < end){
        cout << "M" << n << "[" << fila << "][" << columna << "] = " << matrix[fila][columna] << "\n"; //Imprimo el valor con el formato requerido
        if (columna > 0){ //Voy disminuyendo los valores de las flags para ir recorriendo la matriz.
            columna--;
        }else{
            fila--;
            columna = n - 1; //Si se termina la fila, vuelvo a la última columna.
        }
        flag_to_end++;
    }
}

int main(){
    int n;
    cout << "Ingrese el tamaño de la matriz cuadrada: ";
    cin >> n;
    int** matrix = square_matrix(n);
    if (matrix == nullptr) return 1;
    print_matrix(matrix, n);
    return 0;
}