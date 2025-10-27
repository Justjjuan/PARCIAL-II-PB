#include "parte1.h"
#include "parte2.h"

/
Producto* buscarProductoPorId(vector<Producto> &productos, int id) {
    for (size_t i = 0; i < productos.size(); ++i) {
        if (productos[i].idProducto == id) return &productos[i];
    }
    return NULL;
}


int siguienteIdCarrito(const vector<CarritoDeCompras> &carritos) {
    int mx = 0;
    for (size_t i = 0; i < carritos.size(); ++i) {
        if (carritos[i].idCarrito > mx) mx = carritos[i].idCarrito;
    }
    return mx + 1;
}

void listarProductosBajoStock(const vector<Producto> &productos) {
    cout << "\n--- Productos con stock < 15 ---\n";
    bool alguno = false;
    for (size_t i = 0; i < productos.size(); ++i) {
        if (productos[i].stock < 15) {
            cout << "ID:" << productos[i].idProducto
                 << " | " << productos[i].nombre
                 << " | Precio: " << productos[i].precio
                 << " | Stock: " << productos[i].stock << "\n";
            alguno = true;
        }
    }
    if (!alguno) cout << "No hay productos con stock menor a 15." << "\n";
}

void mostrarComentariosDesde(const vector<Comentario> &comentarios,
                             const vector<Producto> &productos,
                             const vector<Usuario> &usuarios) {
    cout << "\nIngrese fecha desde (DD/MM/YYYY): ";
    string fecha;
    getline(cin, fecha);
    cout << "\n--- Comentarios desde " << fecha << " ---\n";
    bool alguno = false;
    for (size_t i = 0; i < comentarios.size(); ++i) {
        if (fechaMayorOIgual(comentarios[i].fecha, fecha)) {
            
            string nombreProd = "Desconocido";
            string nombreUsu = "Desconocido";
            for (size_t j = 0; j < productos.size(); ++j) {
                if (productos[j].idProducto == comentarios[i].idProducto) {
                    nombreProd = productos[j].nombre;
                    break;
                }
            }
            for (size_t k = 0; k < usuarios.size(); ++k) {
                if (usuarios[k].idUsuario == comentarios[i].idUsuario) {
                    nombreUsu = usuarios[k].nombre;
                    break;
                }
            }
            cout << "ID Comentario: " << comentarios[i].idComentario
                 << " | Producto: " << nombreProd
                 << " | Usuario: " << nombreUsu
                 << " | Fecha: " << comentarios[i].fecha << "\n";
            cout << "  \"" << comentarios[i].comentario << "\"\n";
            alguno = true;
        }
    }
    if (!alguno) cout << "No hay comentarios desde esa fecha." << "\n";
}

void listarUsuarios(const vector<Usuario> &usuarios) {
    cout << "\n--- Usuarios (sin contrasenas) ---\n";
    for (size_t i = 0; i < usuarios.size(); ++i) {
        cout << "ID: " << usuarios[i].idUsuario
             << " | NOMBRE: " << upperStr(usuarios[i].nombre)
             << " | Correo: " << usuarios[i].correoElectronico
             << " | Direccion: " << usuarios[i].direccion
             << " | Metodo pago: " << usuarios[i].metodoDePago << "\n";
    }
}


void adicionarProductoAlCarrito(vector<CarritoDeCompras> &carritos,
                                vector<Producto> &productos,
                                int idUsuario) {
    cout << "\n--- Adicionar producto al carrito ---\n";
    string line;
    int idProd = 0;
    int cantidad = 0;
    cout << "Ingrese ID del producto: ";
    getline(cin, line);
    stringstream ss1(line);
    ss1 >> idProd;
    if (idProd <= 0) {
        cout << "ID invalido." << "\n";
        return;
    }
    Producto* prod = buscarProductoPorId(productos, idProd);
    if (prod == NULL) {
        cout << "Producto no encontrado." << "\n";
        return;
    }
    cout << "Ingrese cantidad: ";
    getline(cin, line);
    stringstream ss2(line);
    ss2 >> cantidad;
    if (cantidad <= 0) {
        cout << "Cantidad invalida." << "\n";
        return;
    }
    if (prod->stock < cantidad) {
        cout << "Stock insuficiente. Stock actual: " << prod->stock << "\n";
        return;
    }

    CarritoDeCompras carrito;
    carrito.idCarrito = siguienteIdCarrito(carritos);
    carrito.idUsuario = idUsuario;
    carrito.subtotal = 0.0;
    carrito.impuestos = 0.0;

    CarritoItem item;
    item.idProducto = prod->idProducto;
    item.nombre = prod->nombre;
    item.precioUnitario = prod->precio;
    item.cantidad = cantidad;

    carrito.productos.push_back(item);

   
    prod->stock -= cantidad;

    carrito.subtotal = item.precioUnitario * item.cantidad;
    carrito.impuestos = carrito.subtotal * 0.19; 

    carritos.push_back(carrito);
    cout << "Producto agregado al carrito ID " << carrito.idCarrito << ". Subtotal: " << carrito.subtotal << "\n";
}


void listarProductosDelCarrito(const vector<CarritoDeCompras> &carritos, int idUsuario) {
    cout << "\n--- Carritos del usuario ID: " << idUsuario << " ---\n";
    bool alguno = false;
    for (size_t i = 0; i < carritos.size(); ++i) {
        if (carritos[i].idUsuario == idUsuario) {
            alguno = true;
            cout << "Carrito ID: " << carritos[i].idCarrito << "\n";
            for (size_t j = 0; j < carritos[i].productos.size(); ++j) {
                cout << "  - " << carritos[i].productos[j].nombre
                     << " | Cant: " << carritos[i].productos[j].cantidad
                     << " | Precio unit: " << carritos[i].productos[j].precioUnitario << "\n";
            }
            double envio = (carritos[i].subtotal < 50000.0 ? 5000.0 : 0.0);
            double total = carritos[i].subtotal + carritos[i].impuestos + envio;
            cout << "  Subtotal: " << carritos[i].subtotal
                 << " | Impuestos: " << carritos[i].impuestos
                 << " | Envio: " << envio
                 << " | Total: " << total << "\n";
        }
    }
    if (!alguno) cout << "No hay carritos para este usuario." << "\n";
}


void menuUsuario(vector<Usuario> &usuarios,
                 vector<Producto> &productos,
                 vector<Comentario> &comentarios,
                 vector<CarritoDeCompras> &carritos,
                 int idUsuario) {
    while (1) {
        cout << "\n--- MENU ---\n";
        cout << "1) Listar productos con stock < 15\n";
        cout << "2) Mostrar comentarios desde fecha\n";
        cout << "3) Listar usuarios (sin contrasenas)\n";
        cout << "4) Adicionar producto al carrito\n";
        cout << "5) Listar productos del carrito\n";
        cout << "6) Cerrar sesion\n";
        cout << "Opcion: ";
        string opcion;
        getline(cin, opcion);
        if (opcion == "1") {
            listarProductosBajoStock(productos);
        } else if (opcion == "2") {
            mostrarComentariosDesde(comentarios, productos, usuarios);
        } else if (opcion == "3") {
            listarUsuarios(usuarios);
        } else if (opcion == "4") {
            adicionarProductoAlCarrito(carritos, productos, idUsuario);
        } else if (opcion == "5") {
            listarProductosDelCarrito(carritos, idUsuario);
        } else if (opcion == "6") {
            cout << "Cerrando sesion...\n";
            break;
        } else {
            cout << "Opcion invalida.\n";
        }
    }
}


int main() {
    vector<Usuario> usuarios;
    vector<Producto> productos;
    vector<Comentario> comentarios;
    vector<CarritoDeCompras> carritos;

    inicializarUsuarios(usuarios);
    inicializarProductos(productos);
    inicializarComentarios(comentarios);

    cout << "=== SISTEMA DE VENTAS - PARCIAL II ===\n";
    while (1) {
        cout << "\n1) Iniciar sesion\n2) Salir\nOpcion: ";
        string op;
        getline(cin, op);
        if (op == "1") {
            int id = iniciarSesion(usuarios);
            if (id > 0) {
                menuUsuario(usuarios, productos, comentarios, carritos, id);
            } else {
                
            }
        } else if (op == "2") {
            cout << "Saliendo... Hasta luego." << "\n";
            break;
        } else {
            cout << "Opcion invalida.\n";
        }
    }
    return 0;
}
