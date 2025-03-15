#include <iostream>
#include <fstream>
using namespace std;;

// (a)

void logMessage(string mensaje, const char* NivelSeveridad) {
    ofstream file ("log_error.txt", ios::app);
    if (file.is_open()){
        file << NivelSeveridad << ": " << mensaje << "\n";
        file.close();
    }
    else cout << "No se pudo abrir el archivo";
}

// Este main verifica el funcionamiento del codigo con todas las entradas posibles
// y las coloca todas dentro del mismo log.
int main(){
    const char* errores[] = {"DEBUG", "INFO", "WARNING", "ERROR", "CRITICAL"};
    for (auto i : errores){
        logMessage("Mensaje de prueba", i);
    }
    return 0;
}

// (b)
/// (ii)
void logMessage(string Mensaje_de_Error, string archivo, int Línea_de_Código){
    ofstream file ("log_linea_error.txt");
    if (file.is_open()){
        file << "Error en el archivo: " << archivo << "; en la línea: " << Línea_de_Código << "; Mensaje del sistema: " << Mensaje_de_Error << endl;
        file.close();
    }
    else cout << "No se pudo abrir el archivo";
}

/// (iii)
void logMessage(string Mensaje_De_Acceso, string Nombre_de_Usuario){
    ofstream file ("log_acceso.txt");
    if (file.is_open()){
        file << "[SECURITY] " << Nombre_de_Usuario << ": " << Mensaje_De_Acceso << endl;
        file.close();
    }
    else cout << "No se pudo abrir el archivo";
}

// (iv)
int main(){
    // Codigo que verifica la funcionalidad requerida del sistema
    cout << "Que desea realizar?\n1. Log de error\n2. Log de error con archivo y línea de código\n3. Log de acceso\n";
    int opcion;
    cin >> opcion;
    switch (opcion){
        case 1:{
            string mensaje;
            cout << "Mensaje de error: ";
            cin >> mensaje;
            logMessage(mensaje, (const char*) "ERROR");
            break;
        }
        case 2:{
            string mensaje;
            cout << "Mensaje de error: ";
            cin >> mensaje;
            logMessage(mensaje, "archivo.cpp", 10);
            break;
        }
        case 3:{
            string acceso;
            cout << "Mensaje de acceso: ";
            cin >> acceso;
            logMessage(acceso, (string) "Usuario1");
            break;
        }
        default:
            cout << "Opción no válida" << endl;
    }

    // Codigo que muestra que puede capturar un error en runtime, crear una entrada en el log
    // detener la ejecución del programa y salir del mismo con código de error.

    try {
        throw runtime_error("Error en tiempo de ejecución");
    }
    catch (runtime_error &e){
        logMessage("Error en tiempo de ejecución", (const char*) "ERROR");	
        exit(1);
    }
}