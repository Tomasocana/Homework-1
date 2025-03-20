#include <iostream>
#include <chrono>
#include <cstring>
using namespace std;

// (a)
bool sonIguales(string a, string b) {
    static int i = 0; //Defino un static int para ir comparando caracter por caracter de forma recursiva
    if (a[i] != b[i]) return false; //False cuando un caracter es distinto
    if (i == (int)a.size()) return true; //True cuando se recorrieron todos los caracteres y no se encontraron discrepancias.
    i++;
    return sonIguales(a, b);
}

// (b)
int main() {
    string a = "La  entrega  se  realizará  mediante  un  archivo  de  texto  que  contenga  los  enlaces  a  los repositorios  de  GitHub  con  la  solución  de  cada  ejercicio,  organizados  en  carpetas separadas.";
    string b = "La  entrega  se  realizará  mediante  un  archivo  de  texto  que  contenga  los  enlaces  a  los repositorios  de  GitHub  con  la  solución  de  cada  ejercicio,  organizados  en  carpetas separadas.";
    auto startTime = std::chrono::high_resolution_clock::now(); 
    cout << sonIguales(a, b) << endl; 
    auto endTime = std::chrono::high_resolution_clock::now(); 
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime); 
    
    cout  << "A sonIguales le tomó: "<<  elapsedTime.count()  << " nanosegundos" << endl;
    return 0;
}

// Elijo trabajar con tipo string ya que toma menos tiempo de ejecución (83.509 nanosegundos) que
// usar tipo char* (115.720 nanosegundos) y además es más sencillo de trabajar.

// (c)

constexpr bool sonIguales(const char* a, const char* b, int i = 0) { //Cambio la firma de la función porque no se pueden utilizar variables estaticas en tiempo de compilación.
    if (a[i] != b[i]) return false;
    if (i == (int)strlen(a)) return true;
    return sonIguales(a, b, i + 1);
}

int main() {
    auto startTime = std::chrono::high_resolution_clock::now(); 
    cout << sonIguales("La entrega se realizará mediante un archivo de texto que", "La entrega se realizará mediante un archivo de texto que") << endl; 
    auto endTime = std::chrono::high_resolution_clock::now(); 
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime); 
    
    cout  << "A sonIguales le tomó: "<<  elapsedTime.count()  << " nanosegundos" << endl;
    return 0;
}

// Al realizar la comparación de los textos en tiempo de compilación, tenemos que tarda un total
// de 70.363 nanosegundos (utilizando const char*), a diferencia de realizarlo en tiempo de 
// ejecución que tarda 83.509 nanosegundos (utilizando string).
// Por lo tanto, es más eficiente realizar la comparación en tiempo de compilación.