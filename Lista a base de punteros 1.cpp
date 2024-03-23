// Lista a base de punteros 1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

#include <string>
using namespace std;

class Pila {
    int elem[10];
    int* top = NULL;

    int* final = NULL;

public:
    //Funciones
    int Push(int a) {
        if (top == NULL) {
            top = elem;
            *top = a;
            top++;
            Imprimir();
            return 1;
        }

        else {
            if (top == &(elem[10])) {
                cout << "Error, la lista ya esta llena" << endl;
                return 0;
            }
            *top = a;
            top++;
            Imprimir();
            return 1;

        }
    }

    int Pop(int& a) {
        if (top == NULL) {
            cout << "Error, la lista esta vacia!" << endl;
            return 0;
        }
        else {
            int* xp = elem;
            if (top == xp) {
                *top == NULL;
                xp = NULL;
                Imprimir();
                return 1;
            }
            while ((xp + 1) != top) {
                cout << "xp: " << *xp << endl;
                cout << "top: " << *top << endl;
                xp++;
            }
            cout << "xp: " << *xp << endl;
            *top = NULL;
            top = xp;
            Imprimir();
        }
    }

    void Imprimir() {
        int* inicio = elem;
        int largo;
        largo = sizeof(elem) / sizeof(elem[0]);
        int i = 0;
        while (i != largo) {
            cout << *inicio;
            inicio++;
            i++;
        }
        cout << endl;
    }
};


int main()
{
    cout << "";
    Pila Esta_es_la_pila;
    Esta_es_la_pila.Push(1);
    Esta_es_la_pila.Push(2);
    Esta_es_la_pila.Push(3);
    Esta_es_la_pila.Push(4);
    Esta_es_la_pila.Push(5);
    Esta_es_la_pila.Push(6);
    Esta_es_la_pila.Push(7);
    Esta_es_la_pila.Push(8);
    Esta_es_la_pila.Push(9);
    Esta_es_la_pila.Push(10);

    Esta_es_la_pila.Push(11); // Este debe botar error (si funciona XD)


    int* a = NULL;
    Esta_es_la_pila.Pop(*a);
    Esta_es_la_pila.Pop(*a);
    Esta_es_la_pila.Pop(*a);
    Esta_es_la_pila.Pop(*a);
    Esta_es_la_pila.Pop(*a);
    Esta_es_la_pila.Pop(*a);
    Esta_es_la_pila.Pop(*a);
    Esta_es_la_pila.Pop(*a);
    Esta_es_la_pila.Pop(*a);
    Esta_es_la_pila.Pop(*a);

    Esta_es_la_pila.Pop(*a);

    Esta_es_la_pila.Pop(*a);



};


// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
