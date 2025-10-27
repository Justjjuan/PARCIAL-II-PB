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


int iniciarSesion(const vector<Usuario> &usuarios) {
    string correo, clave;
    cout << "\n--- Iniciar sesion ---\n";
    cout << "Correo: ";
    getline(cin, correo);
    cout << "Contrasena: ";
    getline(cin, clave);
    for (size_t i = 0; i < usuarios.size(); ++i) {
        if (usuarios[i].correoElectronico == correo) {
            if (usuarios[i].contrasena == clave) {
                cout << "Bienvenido, " << usuarios[i].nombre << "!\n";
                return usuarios[i].idUsuario;
            } else {
                cout << "Contrasena incorrecta.\n";
                return -1;
            }
        }
    }
    cout << "Usuario no encontrado.\n";
    return -1;
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
    if (!alguno) cout << "No hay productos con stock menor a 15.\n";
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
            // buscar nombre producto y usuario
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
    if (!alguno) cout << "No hay comentarios desde esa fecha.\n";
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
        cout << "ID invalido.\n";
        return;
    }
    Producto* prod = buscarProductoPorId(productos, idProd);
    if (prod == NULL) {
        cout << "Producto no encontrado.\n";
        return;
    }
    cout << "Ingrese cantidad: ";
    getline(cin, line);
    stringstream ss2(line);
    ss2 >> cantidad;
    if (cantidad <= 0) {
        cout << "Cantidad invalida.\n";
        return;
    }
    if (prod->stock < cantidad) {
        cout << "Stock insuficiente. Stock actual: " << prod->stock << "\n";
        return;
    }

