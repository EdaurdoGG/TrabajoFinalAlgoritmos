#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct Nodo {
    string dato;
    Nodo* siguiente;
};

class Pila; // Declaracion adelante

class ListaSimple {
private:
    Nodo* primero;
    Nodo* ultimo;
    int size;

public:
    ListaSimple() : primero(nullptr), ultimo(nullptr), size(0) {}

    void insertarElemento(string dato);
    void mostrarLista();
    void ordenarInsercion();
    int busquedaSecuencial(string elemento);
    void eliminarNodo(string dato);
    void guardarPilaEnLista(Pila& pila);
};

class Pila {
public:
    Pila(void);
    void Apilar(string);
    string Desapilar(void);
    void MostrarPila(void);
    bool PilaVacia(void);
    int BuscarEnPila(string);
private:
    Nodo* cima;
};

class Cola {
public:
    Cola(void);
    void Encolar(string);
    string Desencolar(void);
    void MostrarCola(void);
    bool ColaVacia(void);
    int BuscarEnCola(string);
private:
    Nodo* delante;
    Nodo* atras;
};

void ListaSimple::insertarElemento(string dato) {
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

void ListaSimple::mostrarLista() {
    Nodo* actual = primero;
    while (actual != nullptr) {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}

void ListaSimple::ordenarInsercion() {
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

int ListaSimple::busquedaSecuencial(string elemento) {
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

void ListaSimple::eliminarNodo(string dato) {
    Nodo* actual = primero;
    Nodo* anterior = nullptr;
    bool encontrado = false;

    while (actual != nullptr && !encontrado) {
        if (actual->dato == dato) {
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
        }
        else {
            anterior = actual;
            actual = actual->siguiente;
        }
    }
}

void ListaSimple::guardarPilaEnLista(Pila& pila) {
    static bool pilaCopiada = false; // Flag para indicar si la pila ya ha sido copiada
    if (!pilaCopiada) {
        Pila pilaAux = pila; // Creamos una copia de la pila solo si aun no se ha copiado
        while (!pilaAux.PilaVacia()) {
            insertarElemento(pilaAux.Desapilar());

        }
        pilaCopiada = true; // Establecemos el flag como true para indicar que la pila ha sido copiada
    }
}


Pila::Pila(void) {
    cima = nullptr;
}

void Pila::Apilar(string x) {
    Nodo* p_aux = new Nodo;
    p_aux->dato = x;
    p_aux->siguiente = cima;
    cima = p_aux;
}

string Pila::Desapilar(void) {
    string x;
    if (cima == nullptr) {
        cout << "\n\n\tPila Vacia...!!";
        return "";
    }
    else {
        Nodo* p_aux = cima;
        x = p_aux->dato;
        cima = cima->siguiente;
        delete p_aux;
        return x;
    }
}

void Pila::MostrarPila(void) {
    Nodo* p_aux = cima;
    while (p_aux != nullptr) {
        cout << "\t " << p_aux->dato << endl;
        p_aux = p_aux->siguiente;
    }
}

bool Pila::PilaVacia(void) {
    return cima == nullptr;
}

int Pila::BuscarEnPila(string x) {
    Nodo* p_aux = cima;
    int posicion = 1;
    while (p_aux != nullptr) {
        if (p_aux->dato == x) {
            return posicion;
        }
        p_aux = p_aux->siguiente;
        posicion++;
    }
    return -1; // Si no se encuentra el elemento
}

Cola::Cola(void) {
    delante = nullptr; // inicializamos los punteros
    atras = nullptr;
}

void Cola::Encolar(string x) {
    Nodo* p_aux = new Nodo;
    p_aux->dato = x;
    p_aux->siguiente = nullptr;
    if (delante == nullptr)
        delante = p_aux;
    else
        atras->siguiente = p_aux;
    atras = p_aux;
}

string Cola::Desencolar(void) {
    string n;
    if (delante == nullptr) {
        cout << "\n\n\tCola Vacia...!!";
        return "";
    }
    else {
        Nodo* p_aux = delante;
        n = p_aux->dato;
        delante = (delante)->siguiente;
        delete p_aux;
        return n;
    }
}

void Cola::MostrarCola(void) {
    Nodo* p_aux = delante;
    while (p_aux != nullptr) {
        cout << "\n\n\t" << p_aux->dato;
        p_aux = p_aux->siguiente;
    }
}

bool Cola::ColaVacia(void) {
    return delante == nullptr;
}

int Cola::BuscarEnCola(string x) {
    Nodo* p_aux = delante;
    int posicion = 1;
    while (p_aux != nullptr) {
        if (p_aux->dato == x) {
            return posicion;
        }
        p_aux = p_aux->siguiente;
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
            system("cls");

            do {
                cout << "Bienvenido a Los Diamantes y Compania" << endl;
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
                    system("cls");

                    cout << "Selecciona la forma de busqueda" << endl;
                    cout << "1. Busqueda Por Nombre\n";
                    cout << "2. Busqueda Por Precio\n";
                    cout << "3. Salir\n";
                    cout << "Opcion: ";
                    cin >> opcion3;

                    switch (opcion3) {
                    case 1:
                        system("cls");

                        cout << "Ingrese el elemento a buscar: ";
                        cin >> elemento;
                        if (lista.busquedaSecuencial(elemento) != -1)
                            cout << "Elemento encontrado en la posicion: " << lista.busquedaSecuencial(elemento) << endl;
                        else
                            cout << "Elemento no encontrado\n";
                        break;
                    case 2:
                        system("cls");

                        break;
                    default:
                        break;
                    }
                    break;
                case 2:
                    system("cls");

                    cout << "Ingrese el elemento: ";
                    cin >> elemento;
                    lista.insertarElemento(elemento);
                    cout << "\n\n\tEl Producto " << elemento << " se a agregado al carrito.\n";
                    break;
                case 3:
                    system("cls");

                    cout << "Carrito actual: ";
                    lista.ordenarInsercion();
                    lista.mostrarLista();
                    break;
                case 4:
                    system("cls");

                    cout << "\n";
                    lista.mostrarLista();
                    cout << "Ingrese el producto a eliminar: ";
                    cin >> x;
                    lista.eliminarNodo(x);
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
            system("cls");

            do {
                cout << "Bienvenido a Los Diamantes y Compania" << endl;
                cout << "Selecciona lo que quieras hacer" << endl;
                cout << "1. Reporte de productos desde el mas actual\n";
                cout << "2. Reporte de productos desde el mas antiguo\n";
                cout << "3. Reporte de productos por caducidad\n";
                cout << "4. Agregar Producto\n";
                cout << "5. Buscar Producto\n";
                cout << "6. Eliminar Producto\n";
                cout << "7. Salir\n";
                cout << "Opcion: ";
                cin >> opcion2;

                switch (opcion2) {
                case 1:
                    system("cls");

                    cout << "\n\n\tMostrando Reporte\n\n";
                    if (!pila.PilaVacia())
                        pila.MostrarPila();
                    else
                        cout << "\n\n\tReporte vacio.\n";
                    break;
                case 2:
                    system("cls");

                    cout << "\n\n\tMostrando Reporte\n\n";
                    if (!cola.ColaVacia())
                        cola.MostrarCola();
                    else
                        cout << "\n\n\tReporte vacio.\n";
                    break;
                case 3:
                    break;
                case 4:
                    system("cls");

                    cout << "Ingrese el Elemento: ";
                    cin >> x;
                    cola.Encolar(x);
                    pila.Apilar(x);
                    cout << "\nElemento " << x << " agregado al inventario con exito.\n";
                    break;
                case 5:
                    system("cls");

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
                    do {
                        system("cls");

                        cout << "\n\n\tMostrando Inventario\n\n";
                        lista.guardarPilaEnLista(pila);
                        lista.ordenarInsercion();
                        lista.mostrarLista();
                        cout << "\nIngresa el elemento a eliminar (o ingresa 0 para volver al menu anterior): ";
                        cin >> x;
                        if (x != "0") {
                            lista.eliminarNodo(x);
                            cout << "\n\n\tEl producto " << x << " ha sido eliminado del inventario.\n";
                        }
                        cout << endl << endl;
                        system("pause");
                        system("cls");
                    } while (x != "0");
                    break;
                case 7:
                    system("cls");

                    cout << "\n\n\n\t¡Hasta pronto!\n\n";
                    break;
                default:
                    cout << "\n\n\n\tOpcion no valida.\n\n";
                    break;
                }

                cout << endl << endl;
                system("pause");
                system("cls");

            } while (opcion2 != 7);
            break;
        case 3:
            system("cls");

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
