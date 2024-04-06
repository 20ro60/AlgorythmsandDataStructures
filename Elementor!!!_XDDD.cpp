// Elementor!!!_XDDD.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

class Elementor {
    int datos[10];
    int* Cabeza = NULL;
    int* Fin = NULL;
   

public:
    void Imprimir() {
        if (Fin == NULL) {
            cout << " ]" << endl;
            return;
        }
        Cabeza = datos;
        cout << "[ ";
        int* corredor = Cabeza;
        while (corredor != Fin) {
            cout << *corredor << ", ";
            corredor++;
        }
        cout << " ]" << endl;
    }

    void add(int a) {
        if (Cabeza == NULL) {
            Cabeza = datos;
            Fin = datos;
            *Fin = a;
            Fin++;
            Imprimir();
        }
        else if (Fin == &(datos[10])) {
           cout << "Aqui deberia crear una nueva lista" << endl;
           
        }
        else {
            //cout << "Aqui deberia agregar mas datos" << endl;
            *Fin = a;
            Fin++;
            Imprimir();
        }
    }

    void delet(int a) {

    }

    int* find(int a) {
        int* posicion = NULL;
        if (*Cabeza <= a && a <= *Fin) {
            cout << "Esta en el rango" << endl;
            for (posicion = datos; posicion++; posicion) {
                if (*posicion == a) {
                    cout << "Contenido de posicion: " << *posicion << endl;
                    return posicion;
                }
            }
        }
        else if (a > *Fin && *Fin != NULL) {
            cout << "Esta en el siguiente" << endl;
        }
        else {
            cout << "No esta en el rango" << endl;
        }
    }
};


int main()
{
    std::cout << "Hello World!\n";
    Elementor a;
    a.Imprimir();
    a.add(1);
    a.add(2);
    a.add(3);
    a.add(4);
    a.add(5);
    a.add(6);
    a.add(7);
    a.add(8);
    a.add(9);
    a.add(10); // Hasta aqui la primera lista

    a.add(11);
    a.add(12);
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
