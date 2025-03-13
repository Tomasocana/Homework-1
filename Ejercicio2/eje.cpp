#include <iostream>
#include <fstream>
using namespace std;

enum class errores {DEBUG, INFO, WARNING, ERROR, CRITICAL};

// (a)

string evento(errores NivelSeveridad){
    switch (NivelSeveridad){
        case errores::DEBUG:
            return "DEBUG";
        case errores::INFO:
            return "INFO";
        case errores::WARNING:
            return "WARNING";
        case errores::ERROR:
            return "ERROR";
        case errores::CRITICAL:
            return "CRITICAL";
        default: 
            cout << "No es un error contemplado";
            return "";
    }
}

void logMessage(string mensaje, errores NivelSeveridad) {
    string gravedad = evento(NivelSeveridad);
    ofstream file ("log.txt");
    if (file.is_open()){
        file << gravedad << ": " << mensaje;
        file.close();
    }
    else cout << "No se pudo abrir el archivo";
}

int main(){
    logMessage("Error en el sistema", errores::DEBUG);
    return 0;
}

// (b)
/// (i)
void logMessage(string Mensaje_de_Error, string archivo, int Línea_de_Código){
    ofstream file ("log.txt");
    if (file.is_open()){
        file << "Error en el archivo: " << archivo << ", en la línea " << Línea_de_Código << ": " << Mensaje_de_Error;
        file.close();
    }
    else cout << "No se pudo abrir el archivo";
}

/// (ii)
void logMessage(string Mensaje_De_Acceso, string Nombre_de_Usuario){
    ofstream file ("log.txt");
    if (file.is_open()){
        file << "[SECURITY] " << Nombre_de_Usuario << ": " << Mensaje_De_Acceso << ".\n Proceed.";
        file.close();
    }
    else cout << "No se pudo abrir el archivo";
}

/// (iii)
int main(){
    
}