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
    if (!alguno) cout << "No hay carritos para este usuario.\n";
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
            cout << "Saliendo... Hasta luego.\n";
            break;
        } else {
            cout << "Opcion invalida.\n";
        }
    }
    return 0;
}
