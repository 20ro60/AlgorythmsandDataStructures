// Colaconpunteros.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

class cola{
    int A[10];
    int* head = nullptr;
    int* tail = nullptr;

public:
    bool push(int v);

    bool pop(int& v);

    void coutc();
};

bool cola::push(int v) {
    if (head == nullptr && tail == nullptr) {
        head = A, tail = A;
        *tail = v;
        return 1;
    }

    else if ((tail == &A[9]) && *A == 0) { //Caso inicio de la lista vacia
        tail = A;
        *tail = v;
        return 1;
    }

    //Casos normales

    else if (tail == &(A[9]) && head) { //Esto necesariamente tiene que ir en este orden, por orden de verificacion
        return 0;
    }

    else if (head == tail) {
        tail++;
        *tail = v;
        return 1;
    }

    else if (tail != head) {
        tail++;
        *tail = v;
        return 1;
    }
    
}
bool cola::pop(int& v) {
    //cout << "Contenido de head: " << *head << endl;
    //cout << head << endl;
    if (!head && !tail) {
        return 0;
    }

    else if (*head == 0 && head != tail) {
        head++;
        v = *head;
        *head = NULL;
        return 1;
    }

    else if (head == &(A[9]) && head) {
        v = *head;
        *head = NULL;
        head = A;
    }

    else if (*head == 0 && head == tail) {
        return 0;
    }

    else if (head == A) {
        v = *head;
        *head = NULL;
        return 1;
        
    }
    
}

void cola::coutc() {
    int* printeador = A;
    if (printeador) {
        int i = 0;
        while (i != 11) {
            cout << *printeador << " , ";
            printeador++;
            i++;
        }
    }
    else if (head == nullptr && tail == nullptr) {
        cout << "La lista esta vacia" << endl;
    }
    cout << endl;
}

int main()
{
    std::cout << "Hello World!\n";

    cola c;
    c.push(1);
    c.push(2);
    c.push(3);
    c.coutc();
    cout << endl;
    for (int i = 4; i != 10; i++) {
        c.push(i);
    }
    c.coutc();

    cout << endl;

    int a = c.push(10); // Este deberia botar que esta lleno
    if (a == 0) {
        cout << "Error, la cola esta llena" << endl;
    }
    else if (a == 1) {
        cout << "Agregado con exito" << endl;
    }

    int v;
    cout << "Pops" << endl; 
    c.pop(v);
    c.coutc();
    c.pop(v);
    c.coutc();

    for (int i = 2; i != 10; i++) {
        c.pop(v);
        cout << "Valor eliminado: " << v << endl;
        //c.coutc();
    }
    a = c.pop(v); //Este deberia botar error
    if (a == 0) {
       cout << "Error, la cola esta vacia" << endl;
    }
    else if (a == 1) {
       cout << "Eliminado con exito" << endl;
    }

    cout << "La vuelta" << endl;
    c.push(11);
    c.coutc();

    c.push(12);
    c.coutc();

    c.push(13);
    c.coutc();

    for (int i = 14; i != 21; i++) {
        c.push(i);
    }
    c.coutc();

    a = c.push(22); //Este deberia botar error
    if (a == 0) {
        cout << "Error, la cola esta llena" << endl;
    }
    else if (a == 1) {
        cout << "Agregado con exito" << endl;
    }
    c.coutc();

    c.pop(v);
    cout << "Valor ELiminado: " << v << endl;
    c.coutc();

    c.pop(v);
    cout << "Valor ELiminado: " << v << endl;
    c.coutc();
    
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
