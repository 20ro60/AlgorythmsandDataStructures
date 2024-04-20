#include <iostream>

using namespace std;

class Nodo {

public:
    int lista[10];

    Nodo* next = nullptr;
    Nodo* prev = nullptr;

    int numElementos;


    //Constructor

    Nodo() {
        numElementos = 0;
    }

    // Si esta lleno
    bool estaLleno() {
        return numElementos == 10;
    }

    // Si esta Vacio
    bool estaVacio() {
        return numElementos == 0;
    }
};

struct Elementor {

    Nodo* masIzquierda; // Apuntamos a los nodos para verificarlos
    Nodo* masDerecha;

public:
    Elementor() {

        masIzquierda = nullptr;
        masDerecha = nullptr;
    }

    void add(int valor) {
        // [] inicio o [lleno] -> [crear nuevo]
        if (!masDerecha || masDerecha->estaLleno()) {
            // Crear un nuevo nodo
            Nodo* nuevoNodo = new Nodo();

            if (masDerecha) {
                masDerecha->next = nuevoNodo;
                nuevoNodo->prev = masDerecha;
            }
            else {
                // Si el primer comando es este:
                masIzquierda = nuevoNodo;
            }
            masDerecha = nuevoNodo;
        }
        masDerecha->lista[masDerecha->numElementos++] = valor;
    }

    void deletor() {
        // Caso base, cuando esta vacio
        if (!masDerecha) {
            cout << "Error, no hay lista que modificar" << endl;
            return;
        }
        //Si es que no esta vacio
        masDerecha->numElementos--;
        // Eliminarlo (bueno, todavia no XD)
        if (masDerecha->estaVacio()) {
            Nodo* temp = masDerecha;
            masDerecha = masDerecha->prev; //Avanzamos al anterior

            // Se elimina el nodo y del anterior [nodo]->null
            if (masDerecha) {
                masDerecha->next = nullptr;
            }
            else {
                //actualizar masIzquierda
                masIzquierda = nullptr;
            }
            // AHora si XD
            delete temp;
        }
    }

    void imprimir() {
        Nodo* actual = masIzquierda; // El que esta mas a la izquierda
        while (actual) {
            cout << "[";
            for (int i = 0; i < actual->numElementos; ++i) {
                cout << actual->lista[i] << ", ";
            }
            cout << "] -> ";
            actual = actual->next;
        }
        cout << "null" << endl;
    }

    int* buscar(int a) {
        Nodo* actual = masIzquierda;
        int* buscador = nullptr;

        while (actual) {
            if (actual->lista[0] <= a || actual->lista[9] >= a) {
                for (int i = 0; i < actual->numElementos; ++i) {
                    if (actual->lista[i] == a) {
                        buscador = &(actual->lista[i]);
                        return buscador;
                    }
                }
            }
            else {
                actual = actual->next;
            }
            return 0;
        }
    }

};

int main()
{
    Elementor Elemento;

    // Prueba
    cout << "Add: " << endl;
    for (int i = 1; i <= 21; ++i) {
        Elemento.add(i);
    }
    Elemento.imprimir();

    cout << "deletor: " << endl;
    for (int i = 1; i <= 21; ++i) {
        Elemento.deletor();
        Elemento.imprimir();
    }
    Elemento.imprimir();


    cout << "Add: " << endl;
    for (int i = 1; i <= 21; ++i) {
        Elemento.add(i);
    }
    Elemento.imprimir();

    int* r = nullptr;
    r = Elemento.buscar(2);
    cout << "r: " << *r;
}
