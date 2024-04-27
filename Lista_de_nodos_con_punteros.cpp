// Lista_de_nodos con punteros dobles.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

struct Nodo {
    Nodo* next = nullptr;
    int value = 0;
    Nodo(int x, Nodo** t) { //Recibe el dato
        value = x;    //Guarda el dato en la clase
        next = *(t);
    };
};
struct Lista {
    Nodo* h = nullptr;
    //Nodo** p; //Nodo**& p no puede inicializarse por que es una referencia, tiene que hacer referencia a algo que ya. 
              //existe. punto, no puede referenciar a algo nuevo por crear, ejp = nullptr XD

    void add(int x);
    void imprimir();
    bool find(int x, Nodo**& p);

    Lista(){
        //p = &h;
    };
};

void Lista::add(int x) {
    int a;
    Nodo** posi;
    a = find(x, posi);
    if (!a) {
        // Aqui ocurre la magia
        // Aqui el Nodo t es un nodo temporal
        // Apunta al mismo lugar que p
        // 
        // Me explico:
        // 
        // //Digamos que queremos agregar el 1
        //
        //   //        p  t
        //             |  |
        //             v  v           0x12
        //           -------->(nodo2) -----> null
        //            
        //            0x11
        // 
        // Hemos detectado donde tiene que ir el 1
        // Entonces, le pasamos al constructor
        // 
        // 
        // Y lo crea asi:
        // 
        //             Dentro del constructor:
        //             Linea 1: 
        //             value = x;    //Guarda el dato en la clase
        //               p                   
        //               |                   
        //               v                   
        //           -------->(nodo nuevo1)--------> null
        // 
        // 
        // 
        //             Linea 2:
        //             next = *(t);    //Asigna el valor del nodo que seguia
        // 
        //               p                   t  En el next del nuevo nodo
        //               |                   |  p
        //               v                   v
        //           -------->(nodo nuevo1)-------->(nodo2) -----> null
        // 
        // En pocas palabras, t guarda la direccion del nodo que sigue
        // y luego le asigna al next del nuevo nodo
        // 
        // Y asi aumentando la serpiente que estamos creando, sin descabezarla
        // Se podra hacer un snake con una lista enlazada? misterio XD
        //
        Nodo** t;
        t = posi;
        *posi = new Nodo(x, t);
    }
    
    /*if (!h) {
        h = new Nodo(x);
        return;
    }*/

    
}

bool Lista::find(int x, Nodo**& p) {
    p = &h;
    while (*p) {
        if ((**p).value == x) {
            cout << "Encontrado en" << p;
            return 1;
        }
        else if ((**p).value > x) {
            cout << "Valor del nodo apuntado: " << (**p).value << " Valor agregado: " << x << endl;
            return 0;
        }
        cout << "Valor del nodo apuntado: " << (**p).value << " Valor agregado: " << x << endl;

        //Ojo gigante:


        //*p =  (**p).next; Esta NO es la forma
        // Con esta forma estamos cambiando el contenido de p (*p  el puntero a nodo)
        // Por el contenido actual de (**p).next, que como no esta apuntando a nadie
        // Es nulo
        // 
        // Me explico:
        // 
        //   //    p (  contenido  )
        //             |    <- p
        //             v           0x12
        //           ----->(nodo) -----> null
        //             ^ *p ^(**p)        ^ (**p).next
        //            0x11
        // 
        // con (**p).next estamos apuntando a un nodo que no existe
        // Basicamente le estamos diciendo a p con *p:
        // 
        //          *p = (**p).next
        //    "Iguala el        a      un nodo vacio
        //  contenido de p"                null
        // 
        // (Tecnicamente borrando el nodo
        // 
        // Entonces queda:
        // 
        // //    p (  contenido  )
        //             |    <- p
        //             v           0x12
        //           -----> null -----> null
        //             ^ *p ^(**p)        ^ (**p).next
        //            0x11
        // 
        // Por eso solo cambiaba el primero
        // Nacia, y se hacia el harikiri despues XD
        // 
        // Y como lo reparamos ahora?
        // 
        // Facil:
        // 
        // con p = &(**p).next tenemos:
        // 
        // //              p (  contenido  )
        //                          |    <- p
        //                          v 0x12          
        //           ----->(nodo) -----> null
        //             ^ *p ^(**p)   ^     ^ (**p).next
        //            0x11           | &(**p).next
        // 
        // Le estamos diciendo a p:
        // 
        //          p         =       &(**p).next
        //     "Igual p a"         "La direccion que
        //                          este nodo tiene
        //                             como next"
        // 
        // Ahora si estamos apuntando a la flecha siguiente
        //
        //                       Aqui   Y ya no aqui                      
        //                        |     |
        //                        v     v
        //          ----->(nodo)------>null
        // 
        // Asi que ya sabes , si cuaja, no significa que funciona igual XD
        // 
        // Es decir, no por que no bote warning o error significa que funciona XD
        //

        p = &(**p).next; // Esta si es la forma


        //
        //    p (  contenido  )
        //             |    <- p
        //             v
        //           -----> (nodo) -----> null  <-(**p).next
        //             ^ *p  ^**p   ^&(**p).next
        //
    }
    cout << p << endl;
    return 0;
}
void Lista::imprimir() {
    Nodo** corredor = &h;
    while ((*corredor)) {
        cout << (**corredor).value << ", ";
        //La flecha apunta a la flecha que apunta al nodo
        // 
        //      corredor     //Guarda la direccion de h;
        //         |
        //         v
        //        --->  [nodo1 val:  1  ]
        //         h    [      next: null]---> null
        // 
        // 
        // Al avanzar:
        // 
        //         corredor     // va a ser igual a la direccion que guarda el nodo en next
        //            |
        //             -----------------------
        //            ---> [nodo1 val:  1  ]  \   <- Esto de aqui
        //             h   [      next: null]---> null
        // 
        // Si solo fuera corredor = (**corredor).next
        // Solo apuntariamos al nodo
        // 
        //           corredor
        //              |
        //              -----------------------------
        //             ---> [nodo1 val:  1  ]       |     
        //              h   [      next: null]---> null  <- Esto de aqui
        // 
        // Que primero nos botaria un error por apuntar a otra cosa que no es el mismo tipo
        // Luego que hariamos para seguir avanzando? XD
        // 
        // Por eso es &((**corredor).next) y no (**corredor).next
        // Para apuntar a la direccion que se guarda en .next del nodo
        // En pocas palabras, apuntamos al puntero que apunta al nodo siguiente, no al nodo en si
        //
        corredor = &((**corredor).next);
    }
    cout << endl;
}

int main()
{
    Lista Lis;
    Lis.add(1);
    Lis.add(2);
    //  Si fuera    i != 10, ingresaria 9 numeros, por que cuando i es 10, ya sale del bucle
    for (int i = 3; i <= 10; i++) {
        //Aqui va a agregar la resta del limite (10) - el inicio (3) + 1
        // 1 2    3 4 5 6   7 8 9 10
        Lis.add(i);
    }
    //cout << "Impreso: " << endl;
    Lis.add(13);
    Lis.add(12); //Y que pasa si agregamos uno anterior al ultimo?
    Lis.add(11);
    Lis.imprimir();

}
