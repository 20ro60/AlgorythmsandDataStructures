// Elementor!!!_XDDD.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

class Nodo {

public:
    int lista[10];

    Nodo* next = nullptr;
    Nodo* prev = nullptr;

    int numElementos;
    

    //Constructor

    Nodo(){
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

class Elementor {

    Nodo* masIzquierda; // Apuntamos a los nodos para verificarlos
    Nodo* masDerecha;

public:
    Elementor(){

        masIzquierda = nullptr;
        masDerecha = nullptr;
    }

    void push_back(int valor) {
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

    void push_front(int valor) {
        // Si es el primero, o esta lleno [] <- [lleno]
        if (!masIzquierda || masIzquierda->estaLleno()) {

            Nodo* nuevoNodo = new Nodo();

            //Si esta vacio, el ultimo sera [0,0,0,0,0,valor]
            nuevoNodo->lista[0] = valor;
            nuevoNodo->numElementos = 1;

            if (masIzquierda) {
                // Nos movemos a la izquierda
                nuevoNodo->next = masIzquierda; // apuntamos a la izquierda
                masIzquierda->prev = nuevoNodo; //Nos movemos ahi XD
            }
            else {
                masDerecha = nuevoNodo;
            }
            masIzquierda = nuevoNodo;
        }
        else {
            // Desplaza los elementos existentes hacia la derecha para hacer espacio al nuevo valor.
            //Avanza de la derecha [0,0,0,0,0,0,0,0, aqui] hacia la izquierda
            for (int i = masIzquierda->numElementos; i > 0; --i) {
                masIzquierda->lista[i] = masIzquierda->lista[i - 1];
            }
            
            masIzquierda->lista[0] = valor;
            masIzquierda->numElementos++;
        }
    }

    void pop_front() {
        // Caso base, cuando esta vacio
        if (!masIzquierda) {
            cout << "Error, no hay lista que modificar" << endl;
            return;
        }

        //Marcamos el inicio de la lista como 0 [0,1,2,3,4,5,6,7,8,9,10]
        masIzquierda->lista[0] = 0;

        // Si estamos en el primer elemento (la lista va a quedar vacia despues del pop)
        if (masIzquierda->numElementos == 1) {
            // Nos preparamos para borrar este nodo
            Nodo* temp = masIzquierda;
            masIzquierda = masIzquierda->next;
            // null -> []
            if (masIzquierda) {
                masIzquierda->prev = nullptr; //Avanzamos al que le sigue
            }
            else {
                // Actualizar mas derecha
                masDerecha = nullptr;
            }
            delete temp;
        }
        else {
            // mas elementos?
            masIzquierda->numElementos--;
        }
    }

    void pop_back() {
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

    ~Elementor() {
        while (masIzquierda) {
            Nodo* temp = masIzquierda;
            masIzquierda = masIzquierda->next;
            delete temp;
        }
    }

    void imprimir() {
        Nodo* actual = masIzquierda; // El que esta mas a la izquierda
        while (actual) {
            cout << "[";
            for (int i = 0; i < actual->numElementos; ++i) {
                cout << actual->lista[i] <<  ", ";
            }
            cout << "] -> ";
            actual = actual->next;
        }
        cout << "null" << endl;
    }
};

int main() {
    Elementor Elemento;

    // Prueba
    cout << "Push back: " << endl;
    for (int i = 1; i <= 21; ++i) {
        Elemento.push_back(i);
    }
    Elemento.imprimir();

    cout << "Pop back: " << endl;
    for (int i = 1; i <= 21; ++i) {
        Elemento.pop_back();
        Elemento.imprimir();
    }
    Elemento.imprimir();
    
    cout << endl << "Push front: " << endl;
    // Deberia hacerlo alreves
    for (int i = 1; i <= 21; ++i) {
        Elemento.push_front(i); //Si funciona
        Elemento.imprimir();
    }
    
    cout << endl << "Pop front: " << endl;
    for (int i = 1; i <= 21; ++i) {
        Elemento.pop_front(); //Si funciona
        Elemento.imprimir();
    }

    Elemento.imprimir();

    return 0;
}




/*
	// [1,1,,22,2,3,2] -> [ creacion del de aqui] //pushes
	nodo(nodo* anterior, int numercillo, int tipito) : prev(anterior) ,nuevonumero(numercillo){
		next = nullptr; 
		prev = anterior; //Apuntar al anterior
		
	}
	// [Creacion del de aqui] <- [1,1,1,2,23,,23,2,]  //pops
	nodo(nodo* posterior, int tipo) : next(posterior) {
		next = posterior; //Apuntar al posterior
		prev = nullptr;
		nodo::push_front(numercillo);
	}

public:

	void push_back(int numero) {
		// Caso base
		if (head == nullptr) {
			head = lista; // Apuntamos a la lista
			*head = numero; //Cambiamos el primero por el numero dado
		}
		else {
			if (head != &(lista[10])) {
				head++;
				*head = numero;
			}
			else if (head == &lista[10]) {
				cout << "Lista llena, creando nueva..." << endl;
				nodo* nodonuevo = new nodo(this,numero,2);
			}
			
		}
	};

	void push_front(int numero) {
		// Caso base
		if (head == nullptr ) {
			//Inicializamos con el ultimo
			head = &(lista[9]);
			*head = numero;
		}
		else {
			if (head != &(lista[0])) {
				head--;
				*head = numero;
			}
			else if (head == &lista[0]) {
				cout << "Lista llena, creando nueva..." << endl;
				nodo* nodonuevo = new nodo(this, numero, 1);
			}

		}
	};
	void eliminar(int numero) {
		if (head) {

		}
		else {
			
		}
	}
	
};

int main() {

}*/

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
