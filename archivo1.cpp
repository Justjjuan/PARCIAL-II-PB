#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdio>
#include <cctype>
using namespace std;

/* Estructuras */
struct Usuario {
    int idUsuario;
    string nombre;
    string correoElectronico;
    string contrasena;
    string direccion;
    string metodoDePago;
};

struct Producto {
    int idProducto;
    string nombre;
    string descripcion;
    double precio;
    int stock;
};

struct Comentario {
    int idComentario;
    int idProducto;
    int idUsuario;
    string comentario;
    string fecha;
};

struct CarritoItem {
    int idProducto;
    string nombre;
    double precioUnitario;
    int cantidad;
};

struct CarritoDeCompras {
    int idCarrito;
    int idUsuario;
    vector<CarritoItem> productos;
    double subtotal;
    double impuestos;
};

/* Funciones utiles */
string upperStr(string s) {
    for (size_t i = 0; i < s.size(); ++i) s[i] = toupper((unsigned char)s[i]);
    return s;
}

bool fechaMayorOIgual(const string &fA, const string &fB) {
    int dA=0, mA=0, yA=0;
    int dB=0, mB=0, yB=0;
    sscanf(fA.c_str(), "%d/%d/%d", &dA, &mA, &yA);
    sscanf(fB.c_str(), "%d/%d/%d", &dB, &mB, &yB);
    if (yA != yB) return yA > yB;
    if (mA != mB) return mA > mB;
    return dA >= dB;
}

void inicializarUsuarios(vector<Usuario> &usuarios);
void inicializarProductos(vector<Producto> &productos);
void inicializarComentarios(vector<Comentario> &comentarios);
