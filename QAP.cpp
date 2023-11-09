#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

int calcularCosto(const vector<vector<int>>& flujo, const vector<vector<int>>& distancia, const vector<int>& asignacion) {
    int costo = 0;
    int n = flujo.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int asignado_i = asignacion[i];
            int asignado_j = asignacion[j];
            costo += flujo[i][j] * distancia[asignado_i][asignado_j];
        }
    }

    return costo;
}

bool esFactible(int i, int j, const vector<int>& asignacion) {
    for (int k = 0; k < i; k++) {
        if (asignacion[k] == j)
            return false;
    }

    return true;
}

void fordwardChecking(int i, int n, vector<int>& asignacion, const vector<vector<int>>& flujo, const vector<vector<int>>& distancia, int& mejorCosto, vector<int>& mejorAsignacion) {
    if (i == n) {
        int costo = calcularCosto(flujo, distancia, asignacion);
        if (costo < mejorCosto) {
            mejorCosto = costo;
            mejorAsignacion = asignacion;
        }
    }
    else {
        for (int j = 0; j < n; j++) {
            if (esFactible(i, j, asignacion)) {
                asignacion[i] = j;
                fordwardChecking(i + 1, n, asignacion, flujo, distancia, mejorCosto, mejorAsignacion);
                asignacion[i] = -1;
            }
        }
    }
}

void mostrarMatriz(const vector<int>& asignacion) {
    int n = asignacion.size();
    vector<vector<int>> matrizAsignacion(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        int asignado = asignacion[i];
        matrizAsignacion[i][asignado] = 1;
    }

    cout << "Matriz de asignaciones:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrizAsignacion[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    //Solicitud de nombre de la carpteta y del archivo a leer
    string carpeta;
    string archivo;
    cout << "Ingrese el nombre de la carpeta: ";
    cin >> carpeta;
    cout << "Ingrese el nombre del archivo: ";
    cin >> archivo;
    //concatenizacion de la ruta
    string rutaCompleta = "Instancias/"+ carpeta + "/" + archivo + ".dat";

    ifstream archivoEntrada(rutaCompleta);
    //verificacion si se encontro el archivo
    if (!archivoEntrada.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return 0;
    }
    //asignacion del tamaño del problema
    int n;
    archivoEntrada >> n;


    const int MAX_INT = std::numeric_limits<int>::max();

    //int n; Tamaño del problema
    //cout << "Ingrese el tamaño del problema: ";
    //cin >> n;

    vector<vector<int>> flujo(n, vector<int>(n));
    vector<vector<int>> distancia(n, vector<int>(n));

    //lectura de la matriz de flujo
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            archivoEntrada >> flujo[i][j];
        }
    }
    cout << "Lectura de la matriz de flujo exitosa\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            archivoEntrada >> distancia[i][j];
        }
    }
    cout << "Lectura de la matriz de distancia exitosa\n";
    //se cierra el archivo
    archivoEntrada.close();

    vector<int> asignacion(n, -1); // Vector para almacenar la asignación
    int mejorCosto = MAX_INT; //asignacion de un valor muy grande para notar mejora y poder comparar
    vector<int> mejorAsignacion;

    
    //! Iniciar el cronómetro
    auto startTime = high_resolution_clock::now();
    fordwardChecking(0, n, asignacion, flujo, distancia, mejorCosto, mejorAsignacion);
    //! Finalizar el cronómetro y calcular la duración
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(endTime - startTime);

    //!escritura del archivo de salida
    string saldia = "Soluciones/" + archivo + ".out"; //creacion del archivo de salida
    // Abrir el archivo de salida
    ofstream archivoSalida(saldia);

    if (!archivoSalida.is_open()) {
        cout << "Error al crear el archivo de salida." << endl;
        return 0;
    }

    // Escribir los resultados en el archivo de salida
    archivoSalida << mejorCosto << " " << duration.count()/1000000.0 << endl;
    archivoSalida << n << endl;

    for (int i = 0; i < n; i++) {
        archivoSalida << mejorAsignacion[i] << " ";
    }

    archivoSalida.close();

    cout << "Archivo de salida generado exitosamente." << endl;

    return 0;
}
