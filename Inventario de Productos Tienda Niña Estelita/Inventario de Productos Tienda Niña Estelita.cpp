#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>
#include <chrono>
#include <iomanip>

using namespace std;

struct Producto {
int codigo;
string nombre;
int existencias;
double precio;
};

list<Producto> inventario;

//Buscar productos por Codigo
list<Producto>::iterator buscarCodigo(int codigo) {
  for (auto it = inventario.begin(); it != inventario.end(); ++it) {
if (it->codigo == codigo)
  return it;
  }
return inventario.end();
}

//Para Registar un Producto
void registrarProducto() {
  Producto p;

//cout siempre mostrara el detalle que aparecera en la consola de Ejecucion //cin sera la informacion que se guardara en la variable
cout << "Codigo: ";
if (!(cin >> p.Codigo) || p.Codigo <= 0){
cout << "Codigo Invalido.\n";
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
return;
}

if (buscarCodigo(p.codigo) !=inventario.end()) {
cout << "El codigo ya existe. \n";
return;
}

cin.ignore(numeric_limits<streamsize>::max(), '\n';
cout << "Nombre: ";
getline(cin, p.nombre);

if (p.nombre.empty()) {
cout << "El nombre no puede estar vacio .n";
return;
}

cout << "Precio: ";
if (!(cin >> p.precio) || p.precio < 0){
cout << "Precio Invalido. \n"
  cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
return;
}

inventario.push_back(p);
cout << "Producto Registrado Correctamente. \n";
}

//Mostrar Inventario

void mostrarInventario() {
  if (inventario.empty()) {
cout << "EL inventario esta Vacio.\n";
return;
  }

cout << "\n --- Inventario --- \n";

for (const Producto& p : inventario) {
cout << "Codigo: " << p.codigo
  << " | Nombre: " <<p.nombre
  << " | Existencias: " <<p.existencias
  << " | Precio: $" << p.precio << '\n';
}
}

//Modificar Los Productos
void modificarProducto() {
  int codigo;
cout << "Codigo del Producto> ";

if (!(cin >> codigo)) {
cout << "Codigo Invalido.\n";
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
return;
}

auto it = buscarCodigo(codigo);

if (it == inventario.end()) {
cout << "Producto no Encontrado. \n";
return;
}

cin.ignore(numeric_limits<streamsize>::max(), '\n');
string nombre;
cout << "Nuevo nombre: ";
getline(cin, nombre);

if (nombre, empty()) {
cout << "Nombre invalido. \n";
return;
}

int existencias;
double precio;

cout << "Nuevas existencias: ";
if (!(cin >> existencias) || existencias < 0) {
cout << "Existencias invalidas. \n";
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
return;
}

cout << "Nuevo precio: ";
if (!(cin >> precio) || precio < 0){
cout << "Precio Invalido.\n";
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
return;
}

it->nombre = nombre;
it->existencias = existencias;
it->precio = precio;

cout << "Producto modificado correctamente.\n";
}

//Para Eliminar Producto
void eliminarProducto() {
  int codigo;
cout << "Codigo del producto: ";

if (!(cin >> codigo)) {
cout << "Codigo Invalido.\n";
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n\);
return;
}

auto it = buscarCodigo(codigo);

if (it == inventario.end()) {
cout << "Producto no encontrado.\n";
return;
}

//Busqueda lineal Por Codigo
void busquedaLineal() {
  int codigo;
cout << "Codigo a buscar: ";

if (!(cin >> codigo)) {
cout << "Codigo invalido.\n";
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
return;
}

auto inicio = chrono::high_resolution_clock::now();

auto it = buscarCodigo(codigo);

auto fin = chrono::high_resolution_clock::now();

auto tiempo = chrono::duration_cast<chrono::nanoseconds>(
fin - inicio).count()

if (it != inventario.end()) {
cout << "Encontrado: " << it->nombre
  << " | Precio: $" << it->precio << '\n';
} else {
cout << "Producto no encontrado.\n";
}

cout << "Tiempo de busqueda lineal: "
  <<tiempo << "segundos\n";
}

//Busqueda binaria por codigo
void busquedaBinaria() {
  int codigo;
cout << "Codigo a buscar: ";

if (!(cin >> codigo)) {
cout << "Codigo Invalid.\n";
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n';
return;
}

vector<Producto> productos(
inventario.begin(), inventario.end());

sort(productos.begin(), productos.end(),
  [](const Producto& a, const Producto& b) {
return a.codigo < b.codigo;
  });

auto inicio = chrono::high_resolution_clock::now();

int izquierda = 0;
int derecha = static_cast<int>(productos.size()) -1;
int posicion = -1;

while (izquierda <= derecha) {
int medio = izquierda + (derecha - izquierda) / 2;

if (productos[medio].codigo == codigo) {
posicion =  medio,
  break;
} else if (productos[medio].codigo < codigo){
izquierda = medio + 1:
  } else {
derecha =  medio -1;
}
}

auto fin =  chrono::high_resolution_clock::now();

auto tiempo = chrono::duration_cast<chrono::nanoseconds>(
fin - inicio).count();

if (posicion != -1) {
cout << "Encontrado: " << productos[posicion].nombre
  << " | Precio: $" << productos[posicion].precio << '\n\;
} else {
cout << "Producto no encontrado. \n";
}

cout << "Tiempo de busqueda binaria: "
  << tiempo << " nanosegundos\n";
}

//Busqueda por Nombre
void buscarNombre() {
  string nombre;

cin.ignore(numeric_limits<streamsize>::max(), '\n';
cout << "Nombre del producto: ";
getline(cin, nombre);

bool encontrado = false;
for (const Producto& p : inventario) {
if (p.nombre.find(nombre) != string::npos) {
cout << "Codigo: " << p.codigo
  << " | Nombre: " << p.nombre
  << " | Precio: $" << p.precio
  << " | Existencias: " << p.existencias << '\n';

encontrado = true;
}
}

if (!encontrado)
  cout << "Producto no encontrado. \n";
}

//Ordenar por Precio
void ordernarPorPrecio() {
  inventario.sort([](const Producto& a, const Producto& b) {
return a.precio < b.precio;
  });

  cout << "Inventario ordenado por precio. \n";
  mostrarInventario();
}

int main () {
  int opcion;

do {
cout << "\n ********** SISTEMA DE INVENTARIADO **********\n";
cout << "1. Registrar Producto\n";
cout << "2. Mostrar Inventario\n";
cout << "3. Modificar Producto\n";
cout << "4. Eliminar Producto\n";
cout << "5. Buscar por Codigo (lineal)\n";
cout << "6. Buscar por Codigo (binaria)\n";
cout << "7. Buscar por Nombre\n";
cout << "8. Ordenar por Precio\n";
cout << "9. Salir\n";
cout << "Seleccione una Opcion: ";

if (!(cin >> opcion)) {
cout << "Debe ingresar un numero.\n";
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
continue;
}

Switch (opcion) {
case 1: registrarProducto(); break;
case 2: mostrarInventario(); break;
case 3: modificarProducto(); break;
case 4: eliminarProducto(); break;
case 5: busquedaLineal(); break;
case 6: busquedaBinaria(); break;
case 7: buscarNombre(); break;
case 8: ordenarPorPrecio(); break;
case 9: cout << "Programa Finalizado.\n"; break;
default: cout << "Opcion no valida.\n";
}

} while (opcion !=9);

returno 0;

}



