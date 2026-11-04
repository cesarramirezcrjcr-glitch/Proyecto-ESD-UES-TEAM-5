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









