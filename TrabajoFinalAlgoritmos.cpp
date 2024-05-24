#include <iostream>
#include <string>

using namespace std;

struct Nodo {
    string dato;
    float precio;
    Nodo* siguiente;
    Nodo* anterior;
};

class ListaDoble {
private:
    Nodo* primero;
    Nodo* ultimo;
    int size;

public:
    ListaDoble() : primero(nullptr), ultimo(nullptr), size(0) {}

    void insertarElemento(string dato, float precio);
    void mostrarLista();
    void eliminarNodo(string dato);
    int busquedaSecuencial(string elemento);
    int busquedaPorPrecio(float precio);
};

void ListaDoble::insertarElemento(string dato, float precio) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = dato;
    nuevo->precio = precio;
    nuevo->siguiente = nullptr;

    if (primero == nullptr) {
        primero = nuevo;
        ultimo = nuevo;
        nuevo->anterior = nullptr;
    }
    else {
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
        ultimo = nuevo;
    }
    size++;
}

void ListaDoble::mostrarLista() {
    Nodo* actual = primero;
    while (actual != nullptr) {
        cout << actual->dato << " - Precio: " << actual->precio << endl;
        actual = actual->siguiente;
    }
    cout << endl;
}

void ListaDoble::eliminarNodo(string dato) {
    Nodo* actual = primero;
    while (actual != nullptr) {
        if (actual->dato == dato) {
            if (actual == primero) {
                primero = actual->siguiente;
                if (primero != nullptr)
                    primero->anterior = nullptr;
                else
                    ultimo = nullptr;
            }
            else if (actual == ultimo) {
                ultimo = actual->anterior;
                ultimo->siguiente = nullptr;
            }
            else {
                actual->anterior->siguiente = actual->siguiente;
                actual->siguiente->anterior = actual->anterior;
            }
            delete actual;
            size--;
            return;
        }
        actual = actual->siguiente;
    }
    cout << "Dato no encontrado.\n";
}

int ListaDoble::busquedaSecuencial(string elemento) {
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

int ListaDoble::busquedaPorPrecio(float precio) {
    Nodo* actual = primero;
    int posicion = 1;
    while (actual != nullptr) {
        if (actual->precio == precio)
            return posicion;
        actual = actual->siguiente;
        posicion++;
    }
    return -1; // Precio no encontrado
}

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
        while (pos != i && pos->dato.compare(i->dato) < 0) {
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
                if (primero == nullptr)
                    ultimo = nullptr;
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

Pila pilaInventario;
Cola colaInventario;

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
    delante = nullptr;
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
    ListaDoble listaProveedor;

    int opcion, opcion2, opcion3;
    string x, elemento;
    string dato;
    float precio;
    float precioBuscado;

    do {
        cout << "Por favor, identifícate" << endl;
        cout << "1. Proveedor\n";
        cout << "2. Vendedor\n";
        cout << "3. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            system("cls");

            do {
                cout << "Bienvenido a Los Diamantes y Compania" << endl;
                cout << "1. Agregar Producto\n";
                cout << "2. Mostrar Inventario\n";
                cout << "3. Eliminar Producto\n";
                cout << "4. Buscar Producto\n";
                cout << "5. Salir\n";
                cout << "Opcion: ";
                cin >> opcion;

                switch (opcion) {
                case 1:
                    system("cls");

                    cout << "Ingrese el nombre del medicamento: ";
                    cin >> dato;
                    cout << "Ingrese el precio del medicamento: ";
                    cin >> precio;
                    listaProveedor.insertarElemento(dato, precio);
                    cout << "Medicamento agregado con exito.\n";
                    break;
                case 2:
                    system("cls");

                    cout << "Lista de medicamentos:\n";
                    listaProveedor.mostrarLista();
                    break;
                case 3:
                    system("cls");

                    listaProveedor.mostrarLista();
                    cout << "Ingrese el nombre del medicamento a eliminar: ";
                    cin >> dato;
                    listaProveedor.eliminarNodo(dato);
                    cout << "\n\n\tEl producto " << dato << " ha sido eliminado del inventario.\n";
                    break;
                case 4:
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
                        if (listaProveedor.busquedaSecuencial(elemento) != -1)
                            cout << "Elemento encontrado en la posicion: " << listaProveedor.busquedaSecuencial(elemento) << endl;
                        else
                            cout << "Elemento no encontrado\n";
                        break;
                    case 2:
                        system("cls");

                        cout << "Ingrese el precio a buscar: ";
                        cin >> precioBuscado;

                        int posicionPrecio = listaProveedor.busquedaPorPrecio(precioBuscado);
                        if (posicionPrecio != -1) {
                            cout << "El medicamento con precio " << precioBuscado << " se encuentra en el inventario" << endl;
                        }
                        else {
                            cout << "No se encontro ningun medicamento con precio " << precioBuscado << endl;
                        }
                        break;
                    }
                    break;
                case 5:
                    system("cls");

                    cout << "¡Hasta luego!\n";
                    break;
                default:
                    system("cls");
                    cout << "Opcion no valida.\n";
                    break;
                }
                cout << endl;
                system("pause");
                system("cls");
            } while (opcion != 5);
            break;
        case 2:
            system("cls");

            do {
                cout << "Bienvenido a Los Diamantes y Compania" << endl;
                cout << "Selecciona lo que quieras hacer" << endl;
                cout << "1. Reporte de productos desde el mas actual\n";
                cout << "2. Reporte de productos desde el mas antiguo\n";
                cout << "3. Mostrar Inventario\n";
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
                    if (!pilaInventario.PilaVacia())
                        pilaInventario.MostrarPila();
                    else
                        cout << "\n\n\tReporte vacio.\n";
                    break;
                case 2:
                    system("cls");

                    cout << "\n\n\tMostrando Reporte\n\n";
                    if (!colaInventario.ColaVacia())
                        colaInventario.MostrarCola();
                    else
                        cout << "\n\n\tReporte vacio.\n";
                    break;
                case 3:
                    system("cls");

                    cout << "\n\n\tMostrando Inventario\n\n";
                    lista.ordenarInsercion();
                    lista.mostrarLista();
                    break;
                case 4:
                    system("cls");

                    cout << "Ingrese el Elemento: ";
                    cin >> x;
                    colaInventario.Encolar(x);
                    pilaInventario.Apilar(x);
                    lista.insertarElemento(x);
                    cout << "\nElemento " << x << " agregado al inventario con exito.\n";
                    break;
                case 5:
                    system("cls");

                    cout << "Ingrese el producto a buscar: ";
                    cin >> x;

                    if (lista.busquedaSecuencial(x) != -1) {
                        cout << "\n\n\tEl producto " << x << " se encuentra en el inventario.\n";
                    }
                    else {
                        cout << "\n\n\tEl producto " << x << " no se encuentra en el inventario.\n";
                    }
                    break;
                case 6:
                    system("cls");

                    cout << "\n\n\tMostrando Inventario\n\n";
                    lista.ordenarInsercion();
                    lista.mostrarLista();
                    cout << "\nIngresa el elemento a eliminar (o ingresa 0 para volver al menu anterior): ";
                    cin >> x;
                    lista.eliminarNodo(x);
                    cout << "\n\n\tEl producto " << x << " ha sido eliminado del inventario.\n";
                    break;
                case 7:
                    system("cls");

                    cout << "\n\n\n\t¡Hasta pronto!\n\n";
                    break;
                default:
                    system("cls");

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
            system("cls");

            cout << "\n\n\n\tOpcion no valida.\n\n";
            break;
        }

        cout << endl << endl;
        system("pause");
        system("cls");

    } while (opcion != 3);

    return 0;
}
