#include <iostream>

using namespace std;

class lista {

    int listalista[100];

public:
    //             fijo      fijo     ddev        input
    bool bimbus(int* ini, int* fin, int*& pos, int valor) {
        ini = listalista;
        fin = &(listalista[100]);

        int* buscador = listalista;
        for (;buscador != &(listalista[100]); buscador++) {
            if (*buscador == valor) {
                cout << "Encontrado" << endl;
                pos = *&buscador;
                return 1;
            }
        }
        cout << "No encontrado " << endl;
    }

    void add() {
        for (int i = 0; i != 100; i++) {
            listalista[i] = i;
        }
    }
    void print() {
        int* prini;
        cout << "[";
        for (prini = listalista; prini != &(listalista[100]); prini++) {
            cout << *prini << ", ";
        }
        cout << "]";
        cout << endl;
    }
    void printesp(int a) {
        cout << &(listalista[a]) << endl;
    }
};



int main()
{
    lista a;
    // Rellenar la lista
    a.add();
    a.print();
    int* ini = NULL; 
    int* fin = NULL; 
    int *(&pos) = ini;

    cout << "Primero: " << endl;
    //Prueba Primero:
    a.bimbus(ini, fin, pos, 0);

    cout << "Posicion de 0: ";
    a.printesp(0);


    cout << "Posicion de pos: ";
    cout << pos << endl;
    cout << endl;

    //Prueba Ultimo:
    cout << "Ultimo: " << endl;
    a.bimbus(ini, fin, pos, 99);

    cout << "Posicion de 99: ";
    a.printesp(99);


    cout << "Posicion de pos: ";
    cout << pos << endl;
    cout << endl;

    //Prueba Medio:
    cout << "Medio: " << endl;
    a.bimbus(ini, fin, pos, 55);

    cout << "Posicion de 99: ";
    a.printesp(55);


    cout << "Posicion de pos: ";
    cout << pos << endl;
    cout << *pos << endl;
    cout << endl;



    //Prueba no esta:
    cout << "No deberia estar: " << endl;
    a.bimbus(ini, fin, pos, 101);
    cout << endl;

}
