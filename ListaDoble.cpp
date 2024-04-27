// Lista doble (CList).cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

struct Nodo {
    Nodo* next;
    Nodo* prev;
    int value;
    // Asi se construye el constructor, basicamente  Nodo(valores que van a entrar, digamos, int x){
    //              value = x; // El valor de x se asignara a value
    //             } y se cierra de nuevo XD
    // 
    // Si no le ponemos nada en los parentensis, sera el constructor por defecto
    // 
    // Nodo(){
    // 
    //     }
    // Algo asi, que se llamara cuando no haya nada dentro de los parentesis, es lo que ya viene construido basicamente
    //
    Nodo(int x) {
        value = x;

        next = 0;
        prev = 0;
    }
};
struct Manager {
    Nodo* h = 0;
    Nodo* f = 0;

    Nodo* actual = 0;

    bool push_front(int x);
    bool push_back(int x);
    bool pop_front();
    bool pop_back();

    bool operator[](int x);
    bool find(int x, Nodo*& n);
    void imprimir();
};

///////////////////////// Push Front
/////////////////////////      Tiempo: 30 mins approx
///////////////////////
bool Manager::push_front(int x) {
    Nodo* t;
    //a = find(x, t);

    if (!h) {
        actual = new Nodo(x);
        h = actual;
        f = actual;
        return 1;
    }
    else if (h) {
        while (actual->next) {
            actual = actual->next;
        }
        t = new Nodo(x);
        t->prev = actual;
        actual->next = t;
        f = t;
        return 1;
    }
    return 0;
}

///////////////////////////////////Push back
///////////////////////////////////// 12 minutos

bool Manager::push_back(int x) {

    Nodo* t;
    actual = f;  ///////////////////// Es importante indicar en donde va cada pedazo

    if (!f) {
        actual = new Nodo(x);
        h = actual;
        f = actual;
        return 1;
    }
    else if (f) {
        while (actual->prev) {
            actual = actual->prev;
        }
        t = new Nodo(x);
        t->next = actual;   /// Lo mismo pero invertido
        actual->prev = t;   /// Igual para aqui XD
        h = t;
        return 1;
    }
    return 0;
}

bool Manager::pop_front() {

    actual = h; //Importante siempre
    // 12 MINUTOS
    Nodo* t;

    if (!h) {
        return 0;
    }
    else if (h) {
        while (actual->next) {
            actual = actual->next;
        }
        t = actual->prev; //Apuntamos al anterior
        cout << endl << t->value << endl; // El anterior
        delete actual;
        t->next = nullptr;
        f = t;
        return 1;
    }
}

bool Manager::pop_back() {

    actual = f; //Importante siempre
    // 3 MINUTOS
    //Me quedaron 3 minutos para subir XD
    Nodo* t;

    if (!h) {
        return 0;
    }
    else if (h) {
        while (actual->prev) {
            actual = actual->prev;
        }
        t = actual->next; //Apuntamos al posterior
        cout << endl << t->value << endl; // El poste
        delete actual;
        t->prev = nullptr;
        h = t;
        return 1;
    }
}

//9 mins

bool Manager::operator[](int x) {
    actual = h;

    if (!h) {
        return 0;
    }
    else if (h) {
        int i = 0;
        while (actual->next && i != x) {
            actual = actual->next;
            i++;
        }
        cout << "[" << x << "]: " << actual->value << endl;
        return 1;
    }
    return 0;
}

bool Manager::find(int x, Nodo*& n) {
    actual = h;

    while (actual) {
        if (!(actual)) {
            return 0;
        }
        else if (actual->value == x) {
            cout << "Encontrado en: " << actual << endl;
            n = actual;
            return 1;
        }
        actual = (actual->next);
    }
    return 0;
}

void Manager::imprimir() {
    actual = h;
    while (actual) {
        cout << actual->value << ", ";
        actual = actual->next;
    }
    cout << endl;
}



int main()
{
    //std::cout << "Hello World!\n";

    Manager M;
    M.push_front(1);
    M.push_front(2);
    for (int i = 3; i != 10; i++) {
        M.push_front(i);
    }
    M.imprimir();

    M.push_back(11);
    M.push_back(12);
    M.imprimir();

    M.pop_front();
    M.imprimir();

    M.pop_back();
    M.imprimir();

    M[2];
