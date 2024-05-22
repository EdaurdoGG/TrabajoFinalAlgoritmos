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

    int busquedaSecuencial(string elemento) {
        Nodo* actual = primero;
        int posicion = 1;
        while (actual != nullptr) {
            if (actual->dato == elemento)
                return posicion;
            actual = actual->siguiente;
            posicion++;
        }
        return -1; // Elemento no encontrado
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
    return cima == NULL;
}

void Pila::Apilar(string x) {
    Puntero p_aux = new struct nodo;
    p_aux->nro = x;
    p_aux->sgte = cima;
    cima = p_aux;
}

string Pila::Desapilar(void) {
    string x;
    if (cima == NULL) {
        cout << "\n\n\tPila Vacia...!!";
        return "";
    }
    else {
        Puntero p_aux = cima;
        x = p_aux->nro;
        cima = cima->sgte;
        delete p_aux;
        return x;
    }
}

void Pila::MostrarPila(void) {
    Puntero p_aux = cima;
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
        delete p_aux;
    }
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
    return delante == NULL;
}

void Cola::Encolar(string x) {
    Puntero p_aux = new struct nodo;
    p_aux->nro = x;
    p_aux->sgte = NULL;
    if (delante == NULL)
        delante = p_aux;
    else
        atras->sgte = p_aux;
    atras = p_aux;
}

string Cola::Desencolar(void) {
    string n;
    if (delante == NULL) {
        cout << "\n\n\tCola Vacia...!!";
        return "";
    }
    else {
        Puntero p_aux = delante;
        n = p_aux->nro;
        delante = (delante)->sgte;
        delete p_aux;
        return n;
    }
}

void Cola::MostrarCola(void) {
    Puntero p_aux = delante;
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
        delete r_aux;
    }
    delante = NULL;
    atras = NULL;
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

int main() {
    ListaSimple lista;
    Cola cola;
    Pila pila;

    int opcion, opcion2, opcion3;
    string x, elemento;

    do {
        cout << "Por favor, identificate" << endl;
        cout << "1. Cliente\n";
        cout << "2. Vendedor\n";
        cout << "3. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            do {
                cout << "Bienvenido a Los Diamantes y Companía" << endl;
                cout << "Selecciona lo que quieras hacer" << endl;
                cout << "1. Buscar Producto\n";
                cout << "2. Agregar Producto\n";
                cout << "3. Ver Carrito\n";
                cout << "4. Eliminar Producto\n";
                cout << "5. Salir\n";
                cout << "Opcion: ";
                cin >> opcion2;

                switch (opcion2) {
                case 1:
                    cout << "Selecciona la forma de busqueda" << endl;
                    cout << "1. Busqueda Por Nombre\n";
                    cout << "2. Busqueda Por Precio\n";
                    cout << "3. Salir\n";
                    cout << "Opcion: ";
                    cin >> opcion3;

                    switch (opcion3) {
                    case 1: // Búsqueda Secuencial
                        cout << "Ingrese el elemento a buscar: ";
                        cin >> elemento;
                        if (lista.busquedaSecuencial(elemento) != -1)
                            cout << "Elemento encontrado en la posicion: " << lista.busquedaSecuencial(elemento) << endl;
                        else
                            cout << "Elemento no encontrado\n";
                        break;
                    case 2: // Búsqueda Secuencial
                        // Implementa la búsqueda por precio
                        break;
                    default:
                        break;
                    }
                    break;
                case 2:
                    cout << "Ingrese el elemento: ";
                    cin >> elemento;
                    lista.insertarElemento(elemento);
                    cout << "\n\n\tEl Producto " << elemento << " se a agregado al carrito.\n";
                    break;
                case 3:
                    cout << "Carrito actual: ";
                    lista.ordenarInsercion();
                    lista.mostrarLista();
                    break;
                case 4:
                    cout << "\n";
                    lista.mostrarLista();
                    lista.eliminarNodo();
                    cout << "Producto Eliminado...\n";
                    break;
                default:
                    break;
                }

                cout << endl << endl;
                system("pause");
                system("cls");

            } while (opcion2 != 5);
            break;
        case 2:
            do {
                cout << "Bienvenido a Los Diamantes y Companía" << endl;
                cout << "Selecciona lo que quieras hacer" << endl;
                cout << "1. Reporte de productos desde el más actual\n";
                cout << "2. Reporte de productos desde el más antiguo\n";
                cout << "3. Reporte de productos por caducidad\n";
                cout << "4. Agregar Producto\n";
                cout << "5. Buscar Producto\n";
                cout << "6. Eliminar Producto\n";
                cout << "7. Salir\n";
                cout << "Opción: ";
                cin >> opcion2;

                switch (opcion2) {
                case 1:
                    cout << "\n\n\tMostrando Reporte\n\n";
                    if (!pila.PilaVacia())
                        pila.MostrarPila();
                    else
                        cout << "\n\n\tReporte vacio.\n";
                    break;
                case 2:
                    cout << "\n\n\tMostrando Reporte\n\n";
                    if (!cola.ColaVacia())
                        cola.MostrarCola();
                    else
                        cout << "\n\n\tReporte vacio.\n";
                    break;
                case 3:
                    break;
                case 4:
                    cout << "Ingrese el Elemento: ";
                    cin >> x;
                    cola.Encolar(x);
                    pila.Apilar(x);
                    cout << "\nElemento " << x << " agregado al inventario con exito.\n";
                    break;
                case 5:
                    cout << "Ingrese el producto a buscar: ";
                    cin >> x;
                    if (cola.ColaVacia()) {
                        cout << "\n\n\tEl inventario esta vacio.\n";
                    }
                    else {
                        int posicion = cola.BuscarEnCola(x);
                        if (posicion != -1)
                            cout << "\n\n\tEl Producto " << x << " se encuentra en el inventario.\n";
                        else {
                            if (pila.PilaVacia())
                                cout << "\n\n\tEl inventario esta vacio.\n";
                            else {
                                int posicion = pila.BuscarEnPila(x);
                                if (posicion != -1)
                                    cout << "\n\n\tEl producto " << x << " se encuentra en el inventario.\n";
                                else
                                    cout << "\n\n\tEl producto " << x << " no se encuentra en el inventario.\n";
                            }
                        }
                    }
                    break;
                case 6:
                    if (!cola.ColaVacia()) {
                        cout << "Inventario:\n";
                        cola.MostrarCola();
                        cout << "Ingresa el elemento a eliminar\n";
                        cin >> x;
                        x = cola.Desencolar();
                        cout << "\n\n\tEl producto " << x << " ha sido eliminado del inventario.\n";
                    }
                    else if (!pila.PilaVacia()) {
                        cout << "Inventario:\n";
                        pila.MostrarPila();
                        cout << "Ingresa el elemento a eliminar\n";
                        cin >> x;
                        x = pila.Desapilar();
                        cout << "\n\n\tEl producto " << x << " ha sido eliminado del inventario.\n";
                    }
                    else
                        cout << "\n\n\tNo hay elementos para eliminar.\n";
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
            cout << "\n\n\n\t¡Hasta pronto!\n\n";
            break;
        default:
            cout << "\n\n\n\tOpcion no valida.\n\n";
            break;
        }

        cout << endl << endl;
        system("pause");
        system("cls");

    } while (opcion != 3);

    return 0;
}
