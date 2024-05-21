#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct Nodo {
    string dato;
    Nodo* siguiente;
};

class ListaSimple {
private:
    Nodo* primero;
    Nodo* ultimo;
    int size;

public:
    ListaSimple() : primero(nullptr), ultimo(nullptr), size(0) {}

    void insertarElemento(string dato) {
        Nodo* nuevo = new Nodo();
        nuevo->dato = dato;
        nuevo->siguiente = nullptr;

        if (primero == nullptr) {
            primero = nuevo;
            ultimo = nuevo;
        }
        else {
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        }
        size++;
    }

    void mostrarLista() {
        Nodo* actual = primero;
        while (actual != nullptr) {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        cout << endl;
    }

    void ordenarBurbuja() {
        if (size <= 1)
            return;

        for (Nodo* i = primero; i->siguiente != nullptr; i = i->siguiente) {
            for (Nodo* j = primero; j->siguiente != nullptr; j = j->siguiente) {
                if (j->dato > j->siguiente->dato) {
                    string temp = j->dato;
                    j->dato = j->siguiente->dato;
                    j->siguiente->dato = temp;
                }
            }
        }
    }

    void ordenarInsercion() {
        if (size <= 1)
            return;

        Nodo* i = primero->siguiente;
        while (i != nullptr) {
            Nodo* pos = primero;

            while (pos != i && pos->dato < i->dato) {
                pos = pos->siguiente;
            }

            if (pos != i) {
                string temp = i->dato;

                while (pos != i) {
                    string temp2 = pos->dato;
                    pos->dato = temp;
                    temp = temp2;
                    pos = pos->siguiente;
                }
                pos->dato = temp;
            }

            i = i->siguiente;
        }
    }

    int busquedaBinaria(string elemento) {
        if (size == 0)
            return -1;

        int inicio = 0;
        int fin = size - 1;

        while (inicio <= fin) {
            int medio = inicio + (fin - inicio) / 2;

            Nodo* actual = primero;
            for (int i = 0; i < medio; ++i)
                actual = actual->siguiente;

            if (actual->dato == elemento)
                return medio;
            else if (actual->dato < elemento)
                inicio = medio + 1;
            else
                fin = medio - 1;
        }

        return -1; // Elemento no encontrado
    }

    bool busquedaSecuencial(string elemento) {
        Nodo* actual = primero;
        while (actual != nullptr) {
            if (actual->dato == elemento)
                return true;
            actual = actual->siguiente;
        }
        return false; // Elemento no encontrado
    }

    void eliminarNodo() {
        string nodoBuscar;
        cout << "\nIngrese el dato a buscar para eliminarlo: ";
        cin >> nodoBuscar;

        Nodo* actual = primero;
        Nodo* anterior = nullptr;
        bool encontrado = false;

        if (primero != nullptr) {
            while (actual != nullptr && !encontrado) {
                if (actual->dato == nodoBuscar) {
                    cout << "\nElemento " << nodoBuscar << " encontrado\n";

                    if (actual == primero) {
                        primero = primero->siguiente;
                    }
                    else if (actual == ultimo) {
                        anterior->siguiente = nullptr;
                        ultimo = anterior;
                    }
                    else {
                        anterior->siguiente = actual->siguiente;
                    }

                    delete actual;
                    encontrado = true;
                    cout << "\nNodo " << nodoBuscar << " eliminado\n";
                }
                else {
                    anterior = actual;
                    actual = actual->siguiente;
                }
            }
            if (!encontrado) {
                cout << "\nElemento no encontrado\n";
            }
        }
        else {
            cout << "La lista se encuentra vacía\n";
        }
    }

    void modificarNodo() {
        string nodoBuscar;
        cout << "\nIngrese el dato a buscar en la lista: ";
        cin >> nodoBuscar;

        Nodo* actual = primero;
        bool encontrado = false;

        if (primero != nullptr) {
            while (actual != nullptr && !encontrado) {
                if (actual->dato == nodoBuscar) {
                    cout << "\nElemento " << nodoBuscar << " encontrado\n";

                    cout << "\nInserte el nuevo valor: ";
                    cin >> actual->dato;
                    cout << "\nEl dato anterior " << nodoBuscar << " ha sido modificado exitosamente por: " << actual->dato << endl;
                    encontrado = true;
                }
                else {
                    actual = actual->siguiente;
                }
            }
            if (!encontrado) {
                cout << "\nElemento no encontrado\n";
            }
        }
        else {
            cout << "La lista se encuentra vacía\n";
        }
    }

private:
    void QuickSortRecursive(string A[], int primero, int ultimo) {
        if (primero < ultimo) {
            int pivote = Partition(A, primero, ultimo);
            QuickSortRecursive(A, primero, pivote - 1);
            QuickSortRecursive(A, pivote + 1, ultimo);
        }
    }

    int Partition(string A[], int primero, int ultimo) {
        string pivote = A[ultimo];
        int i = primero - 1;
        for (int j = primero; j < ultimo; ++j) {
            if (A[j] < pivote) {
                ++i;
                swap(A[i], A[j]);
            }
        }
        swap(A[i + 1], A[ultimo]);
        return i + 1;
    }

};


struct nodo {
    string nro;
    struct nodo* sgte;
};

typedef struct nodo* Puntero;

class Pila {
public:
    Pila(void);
    void Apilar(string);
    string Desapilar(void);
    void Cima(void);
    bool PilaVacia(void);
    void MostrarPila(void);
    void DestruirPila(void);
    int BuscarEnPila(string);

private:
    Puntero cima;

};

Pila::Pila(void) {
    cima = NULL;
}

bool Pila::PilaVacia(void) {
    if (cima == NULL)
        return true;
    else
        return false;
}

void Pila::Apilar(string x) {

    Puntero p_aux;
    p_aux = new struct nodo;
    p_aux->nro = x;
    p_aux->sgte = cima;
    cima = p_aux;

}

void Pila::Cima() {
    string x;
    if (cima == NULL)
        cout << "\n\n\tPila Vacia...!";
    else {
        x = cima->nro;
        cout << "\n\tLa Cima es: " << x << endl;
    }
}

string Pila::Desapilar(void) {
    string x;
    Puntero p_aux;
    if (cima == NULL)
        cout << "\n\n\tPila Vacia...!!";
    else {
        p_aux = cima;
        x = p_aux->nro;
        cima = cima->sgte;
        delete(p_aux);
    }
    return x;
}

void Pila::MostrarPila(void) {
    Puntero p_aux;
    p_aux = cima;

    while (p_aux != NULL) {
        cout << "\t " << p_aux->nro << endl;
        p_aux = p_aux->sgte;
    }
}

void Pila::DestruirPila(void) {
    Puntero p_aux;

    while (cima != NULL) {
        p_aux = cima;
        cima = cima->sgte;
        delete(p_aux);
    }
}

class Cola {
public:
    Cola(void);
    void Encolar(string);
    string Desencolar(void);
    bool ColaVacia(void);
    void MostrarCola(void);
    void VaciarCola(void);
    int BuscarEnCola(string);

private:
    Puntero delante; // puntero al primer elemento de la cola
    Puntero atras;   // puntero al ultimo elemento de la cola
};

Cola::Cola(void) {
    delante = NULL; // inicializamos los punteros
    atras = NULL;
}

bool Cola::ColaVacia() {

    if (delante == NULL)
        return true;
    else return false;
}
void Cola::Encolar(string x) {

    Puntero p_aux;

    p_aux = new struct nodo;
    p_aux->nro = x;
    p_aux->sgte = NULL;

    if (delante == NULL)
        delante = p_aux;
    else atras->sgte = p_aux;

    atras = p_aux;
}

string Cola::Desencolar(void) {

    string n;
    Puntero p_aux;

    p_aux = delante;
    n = p_aux->nro;
    delante = (delante)->sgte;
    delete(p_aux);
    return n;
}

void Cola::MostrarCola(void) {
    Puntero p_aux;
    p_aux = delante;
    while (p_aux != NULL) {
        cout << "\n\n\t" << p_aux->nro;
        p_aux = p_aux->sgte;
    }

}

void Cola::VaciarCola(void) {

    Puntero p_aux, r_aux;
    p_aux = delante;
    while (p_aux != NULL) {
        r_aux = p_aux;
        p_aux = p_aux->sgte;
        delete(r_aux);
    }
    delante = NULL;
    atras = NULL;
}

int Pila::BuscarEnPila(string x) {
    Puntero p_aux = cima;
    int posicion = 1;

    while (p_aux != NULL) {
        if (p_aux->nro == x) {
            return posicion;
        }
        p_aux = p_aux->sgte;
        posicion++;
    }

    return -1; // Si no se encuentra el elemento
}

int Cola::BuscarEnCola(string x) {
    Puntero p_aux = delante;
    int posicion = 1;

    while (p_aux != NULL) {
        if (p_aux->nro == x) {
            return posicion;
        }
        p_aux = p_aux->sgte;
        posicion++;
    }

    return -1; // Si no se encuentra el elemento
}

int main()
{
    ListaSimple lista;
    Cola cola;
    Pila pila;

    int opcion, opcion2, opcion3;
    string x, elemento;

    do {
        cout << "Porfavor Identificate" << endl;
        cout << "1. Cliente\n";
        cout << "2. Vendedor\n";
        cout << "3. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            do {
                cout << "Bievenido a Los Diamantes y Compania" << endl;
                cout << "Selecciona lo que quieras hacer" << endl;
                cout << "1. Buscar Producto\n";
                cout << "2. Agregar Producto\n";
                cout << "3. Ver Carrito\n";
                cout << "4. Eliminar Producto\n";
                cout << "5. Salir\n";
                cout << "Opcion: ";
                cin >> opcion2;

                switch (opcion2)
                {
                case 1:
                    cout << "Selecciona la forma de busqueda" << endl;
                    cout << "1. Busqueda Por Nombre\n";
                    cout << "2. Buequeda Por Precio\n";
                    cout << "Opcion: ";
                    cin >> opcion3;

                    switch (opcion3)
                    {
                    case 1: //Busqueda Binaria
                        cout << "Ingrese el elemento a buscar: ";
                        cin >> elemento;
                        if (lista.busquedaBinaria(elemento) != -1)
                            cout << "Elemento encontrado en la posicion: " << lista.busquedaBinaria(elemento) << endl;
                        else
                            cout << "Elemento no encontrado\n";
                        break;
                    case 2: //Busqueda Secuencial
                        cout << "Ingrese el elemento a buscar: ";
                        cin >> elemento;
                        if (lista.busquedaSecuencial(elemento))
                            cout << "Elemento encontrado\n";
                        else
                            cout << "Elemento no encontrado\n";
                        break;
                    default:
                        break;
                    }
                    break;
                case 2: //Agrega un elemento a la Lista
                    cout << "Ingrese el elemento: ";
                    cin >> elemento;
                    lista.insertarElemento(elemento);
                    break;
                case 3: //Muestra el carrito
                    cout << "Carrito actual: ";
                    lista.mostrarLista();
                    break;
                case 4:
                    lista.eliminarNodo();
                    cout << "Producto Eliminado...\n";
                    break;
                default:
                    break;
                }

                cout << endl << endl;
                system("pause");
                system("cls");

            } while (opcion2 != 4);
            break;
        case 2:
            do {
                cout << "Bievenido a Los Diamantes y Compania" << endl;
                cout << "Selecciona lo que quieras hacer" << endl;
                cout << "1. Reporte de productos desde el mas actual\n";
                cout << "2. Reporte de productos desde el mas antiguo\n";
                cout << "3. Reporte de productos por caducidad\n";
                cout << "4. Agergar Producto\n";
                cout << "5. Buacar Producto\n";
                cout << "6. Eliminar Producto\n";
                cout << "7. Salir\n";
                cout << "Opcion: ";
                cin >> opcion2;

                switch (opcion2)
                {
                case 1: //Pilas
                    cout << "\n\n\tMostrando Pila\n\n";
                    if (!pila.PilaVacia())
                        pila.MostrarPila();
                    else
                        cout << "\n\n\tReporte vacio.\n";
                    break;
                case 2: //Colas
                    cout << "\n\n\tMostrando Cola\n\n";
                    if (!cola.ColaVacia())
                        cola.MostrarCola();
                    break;
                case 3:
                    break;
                case 4: //Agregar elemeto a la Cola o ala Pila
                    cout << "Ingrese el Elemento: ";
                    cin >> x;

                    cola.Encolar(x);
                    pila.Apilar(x);
                    cout << "\nNumero " << x << " agregado con exito.\n";

                    break;
                case 5: //Buscar elemnto en la Cola o en la Pila
                    cout << "Ingrese el numero a buscar: ";
                    cin >> x;

                    if (cola.ColaVacia() == true)
                        cout << "\n\n\tVacia....";
                    else {
                        int posicion = cola.BuscarEnCola(x);
                        if (posicion != -1)
                            cout << "\n\n\tEl numero " << x << " se encuentra en la posicion " << posicion << " de la cola.\n";
                        else
                            if (pila.PilaVacia() == true)
                                cout << "\n\n\tPila Vacia....";
                            else {
                                int posicion = pila.BuscarEnPila(x);
                                if (posicion != -1)
                                    cout << "\n\n\tEl numero " << x << " se encuentra en la posicion " << posicion << " de la pila.\n";
                                else
                                    cout << "\n\n\tEl numero " << x << " no se encuentra.\n";
                            }
                    }

                    break;
                case6: //Eliminar elemento de la Cola o de la Pila
                    if (!cola.ColaVacia()) {
                        x = cola.Desencolar();
                        cout << "\n\n\tEl numero " << x << " ha sido eliminado de la cola.\n";
                    }
                    else if (!pila.PilaVacia()) {
                        x = pila.Desapilar();
                        cout << "\n\n\tEl numero " << x << " ha sido eliminado de la pila.\n";
                    }
                    else
                        cout << "\n\n\tNo hay elementos para eliminar....";
                    break;
                default:
                    break;
                }

                cout << endl << endl;
                system("pause");
                system("cls");

            } while (opcion2 != 7);
            break;
        case 3:
            cout << "\n\n\n\tHasta pronto....\n\n";
            break;
        default:
            cout << "\n\n\n\tOpcion no valida....\n\n";
            break;
        }

        cout << endl << endl;
        system("pause");
        system("cls");

    } while (opcion != 3);

    return 0;
}
