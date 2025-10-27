#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdio>   
#include <cctype>   
using namespace std;


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


void inicializarUsuarios(vector<Usuario> &usuarios) {
    usuarios.clear();
    usuarios.push_back((Usuario){1, "Giovanni Torres Zabaleta", "giovanni.torres@email.com", "PassGio123", "Calle 1 #1-01", "Tarjeta credito"});
    usuarios.push_back((Usuario){2, "Juan Andres Berber Rivera", "juan.berber@email.com", "PassJuan456", "Carrera 2 #2-02", "PayPal"});
    usuarios.push_back((Usuario){3, "Samuel Nunez", "samuel.nunez@email.com", "PassSam789", "Avenida 3 #3-03", "Transferencia bancaria"});
    usuarios.push_back((Usuario){4, "Alejandro Ruiz", "alejandro.ruiz@email.com", "PassAlej101", "Calle 4 #4-04", "Tarjeta debito"});
    usuarios.push_back((Usuario){5, "Usuario Demo", "demo.user@email.com", "Demo000", "Direccion Demo", "Efectivo"});
}

void inicializarProductos(vector<Producto> &productos) {
    productos.clear();
    productos.push_back((Producto){1, "Laptop", "Portatil con pantalla Full HD y SSD 512GB", 89999.0, 10});
    productos.push_back((Producto){2, "Smartphone", "Telefono con camara 108MP y carga rapida", 49950.0, 20});
    productos.push_back((Producto){3, "Tablet", "Tablet 10 pulgadas tactil", 29999.0, 15});
    productos.push_back((Producto){4, "Auriculares", "Audifonos inalambricos con cancelacion ruido", 12999.0, 25});
    productos.push_back((Producto){5, "Teclado", "Teclado mecanico con iluminacion RGB", 8999.0, 30});
    productos.push_back((Producto){6, "Mouse", "Mouse inalambrico alta precision", 5999.0, 50});
    productos.push_back((Producto){7, "Monitor", "Monitor 27 pulgadas 4K", 49900.0, 12});
    productos.push_back((Producto){8, "Impresora", "Impresora laser multifuncional Wi-Fi", 17999.0, 18});
    productos.push_back((Producto){9, "Camara", "Camara digital profesional", 79999.0, 8});
    productos.push_back((Producto){10, "Smartwatch", "Reloj inteligente con GPS", 19999.0, 22});
    productos.push_back((Producto){11, "Silla Gamer", "Silla ergonomica ajustable", 29999.0, 14});
    productos.push_back((Producto){12, "Microondas", "Microondas con funciones multiples", 12999.0, 40});
    productos.push_back((Producto){13, "Refrigerador", "Frigorifico doble puerta No Frost", 119999.0, 5});
    productos.push_back((Producto){14, "Lavadora", "Lavadora automatica 10kg", 59999.0, 7});
    productos.push_back((Producto){15, "Cafetera", "Cafetera express con vaporizador", 14999.0, 35});
    productos.push_back((Producto){16, "Drone", "Drone con camara 4K", 69999.0, 9});
    productos.push_back((Producto){17, "Bocina Bluetooth", "Altavoz portatil sonido envolvente", 8999.0, 33});
    productos.push_back((Producto){18, "Videocamara", "Videocamara profesional 4K", 99999.0, 6});
    productos.push_back((Producto){19, "TV LED", "Televisor 55 pulgadas Smart TV", 74999.0, 11});
    productos.push_back((Producto){20, "Bateria Externa", "Powerbank 20000mAh", 3999.0, 45});
    productos.push_back((Producto){21, "Disco Duro", "HDD externo 2TB", 12999.0, 28});
    productos.push_back((Producto){22, "Memoria USB", "Pendrive 128GB", 2999.0, 60});
    productos.push_back((Producto){23, "Router", "Router Wi-Fi 6", 19999.0, 16});
    productos.push_back((Producto){24, "Joystick", "Control inalambrico para videojuegos", 7999.0, 20});
    productos.push_back((Producto){25, "Fuente de Poder", "Fuente PSU 750W", 8999.0, 17});
    productos.push_back((Producto){26, "SSD", "SSD 1TB NVMe", 14999.0, 32});
    productos.push_back((Producto){27, "Altavoces", "Par de altavoces estereo con subwoofer", 13999.0, 23});
    productos.push_back((Producto){28, "Webcam", "Camara web Full HD con microfono", 6999.0, 37});
    productos.push_back((Producto){29, "Procesador", "CPU Intel i7 de ultima generacion", 34999.0, 9});
    productos.push_back((Producto){30, "Motherboard", "Placa base compatible", 19999.0, 13});
    productos.push_back((Producto){31, "Memoria RAM", "RAM DDR4 16GB", 7999.0, 41});
    productos.push_back((Producto){32, "Panel Solar", "Panel solar portable 60W", 24999.0, 4});
    productos.push_back((Producto){33, "Control Remoto", "Mando universal TV", 2499.0, 50});
    productos.push_back((Producto){34, "Termostato", "Termostato digital programable", 9999.0, 22});
    productos.push_back((Producto){35, "Smart Lock", "Cerradura electronica huella digital", 19999.0, 6});
    productos.push_back((Producto){36, "Proyector", "Proyector LED Full HD", 29999.0, 12});
    productos.push_back((Producto){37, "Switch Ethernet", "Switch 8 puertos", 5999.0, 38});
    productos.push_back((Producto){38, "Reloj Digital", "Reloj inteligente pantalla AMOLED", 8999.0, 26});
    productos.push_back((Producto){39, "Luces LED", "Tiras LED RGB", 3999.0, 55});
    productos.push_back((Producto){40, "Estabilizador", "Estabilizador de voltaje", 15999.0, 10});
    productos.push_back((Producto){41, "Cargador Inalambrico", "Base carga inalambrica rapida", 4999.0, 30});
    productos.push_back((Producto){42, "HDD Externo 4TB", "Disco duro 4TB portable", 17999.0, 15});
    productos.push_back((Producto){43, "Microfono", "Microfono profesional condensador", 14999.0, 7});
    productos.push_back((Producto){44, "Altavoz Inteligente", "Altavoz con asistente de voz", 12999.0, 20});
    productos.push_back((Producto){45, "Antena Wi-Fi", "Amplificador señal inalambrica", 7999.0, 33});
    productos.push_back((Producto){46, "Climatizador", "Aire acondicionado portable", 29999.0, 5});
    productos.push_back((Producto){47, "Raspberry Pi", "Kit Raspberry Pi 4", 12999.0, 19});
    productos.push_back((Producto){48, "Capturadora", "Placa captura video HD", 19999.0, 8});
    productos.push_back((Producto){49, "Smart Plug", "Enchufe inteligente Wi-Fi", 3999.0, 42});
    productos.push_back((Producto){50, "Timbre Inteligente", "Timbre con camara Wi-Fi", 14999.0, 10});
}

void inicializarComentarios(vector<Comentario> &comentarios) {
    comentarios.clear();
    comentarios.push_back((Comentario){1, 1, 1, "Excelente rendimiento; muy rapido.", "01/05/2025"});
    comentarios.push_back((Comentario){2, 2, 2, "Buena camara pero la bateria dura poco.", "03/05/2025"});
    comentarios.push_back((Comentario){3, 3, 3, "No me gusto; pantalla de baja calidad.", "05/05/2025"});
    comentarios.push_back((Comentario){4, 4, 4, "Sonido aceptable pero material frágil.", "06/05/2025"});
    comentarios.push_back((Comentario){5, 5, 5, "Muy buen teclado mecanico; excelente respuesta.", "08/05/2025"});
    comentarios.push_back((Comentario){6, 6, 2, "El sensor no es tan preciso como esperaba.", "10/05/2025"});
    comentarios.push_back((Comentario){7, 7, 3, "Colores vibrantes y buena resolucion.", "12/05/2025"});
    comentarios.push_back((Comentario){8, 8, 1, "Tarda mucho en imprimir; no me convence.", "13/05/2025"});
    comentarios.push_back((Comentario){9, 9, 4, "Increible calidad de imagen; fotos nitidas.", "15/05/2025"});
    comentarios.push_back((Comentario){10, 10, 5, "Buena bateria; pantalla poco brillante.", "18/05/2025"});
    comentarios.push_back((Comentario){11, 11, 1, "Comodidad espectacular; perfecto para jugar.", "20/05/2025"});
    comentarios.push_back((Comentario){12, 12, 2, "Calienta bien pero hace mucho ruido.", "22/05/2025"});
    comentarios.push_back((Comentario){13, 13, 3, "Espacioso y enfria rapido; recomendado.", "24/05/2025"});
    comentarios.push_back((Comentario){14, 14, 4, "Lava bien pero el ciclo es largo.", "26/05/2025"});
    comentarios.push_back((Comentario){15, 15, 5, "Hace cafe delicioso; facil de usar.", "28/05/2025"});
    comentarios.push_back((Comentario){16, 16, 1, "Muy divertido pero la bateria dura poco.", "30/05/2025"});
    comentarios.push_back((Comentario){17, 17, 2, "Sonido potente y conexion Bluetooth estable.", "01/06/2025"});
    comentarios.push_back((Comentario){18, 18, 3, "Perfecta para grabaciones profesionales.", "03/06/2025"});
    comentarios.push_back((Comentario){19, 19, 4, "Imagen excelente pero el sonido podria mejorar.", "05/06/2025"});
    comentarios.push_back((Comentario){20, 20, 5, "Carga bien pero es un poco pesada.", "07/06/2025"});
    comentarios.push_back((Comentario){21, 21, 1, "Gran capacidad; funciona rapido.", "09/06/2025"});
    comentarios.push_back((Comentario){22, 22, 2, "Buen tamano pero velocidad de transferencia baja.", "11/06/2025"});
    comentarios.push_back((Comentario){23, 23, 3, "Senal potente; cubre toda la casa.", "13/06/2025"});
    comentarios.push_back((Comentario){24, 24, 4, "Comodo y resistente; ideal para gaming.", "15/06/2025"});
    comentarios.push_back((Comentario){25, 25, 5, "Funciona bien pero cables muy cortos.", "17/06/2025"});
    comentarios.push_back((Comentario){26, 26, 1, "Velocidad increible; mi PC va mas rapido.", "19/06/2025"});
    comentarios.push_back((Comentario){27, 27, 2, "Sonido envolvente; muy buena compra.", "21/06/2025"});
    comentarios.push_back((Comentario){28, 28, 3, "Imagen clara pero el microfono es deficiente.", "23/06/2025"});
    comentarios.push_back((Comentario){29, 29, 4, "Rendimiento impecable; ideal para diseño.", "25/06/2025"});
    comentarios.push_back((Comentario){30, 30, 5, "Buenas prestaciones pero instalacion complicada.", "27/06/2025"});
    comentarios.push_back((Comentario){31, 31, 1, "Expande bien el rendimiento del sistema.", "29/06/2025"});
    comentarios.push_back((Comentario){32, 32, 2, "Energia confiable pero bateria pequena.", "01/07/2025"});
    comentarios.push_back((Comentario){33, 33, 3, "Facil de usar; reconoce muchos dispositivos.", "03/07/2025"});
    comentarios.push_back((Comentario){34, 34, 4, "Regula bien; intuitivo de usar.", "05/07/2025"});
    comentarios.push_back((Comentario){35, 35, 5, "Seguridad y tecnologia en un solo dispositivo.", "07/07/2025"});
    comentarios.push_back((Comentario){36, 36, 1, "Imagen nitida pero requiere sala oscura.", "09/07/2025"});
    comentarios.push_back((Comentario){37, 37, 2, "Buena velocidad de conexion; estable.", "11/07/2025"});
    comentarios.push_back((Comentario){38, 38, 3, "Pantalla atractiva pero bateria dura poco.", "13/07/2025"});
    comentarios.push_back((Comentario){39, 39, 4, "Buenas opciones de colores; buen diseno.", "15/07/2025"});
    comentarios.push_back((Comentario){40, 40, 5, "Protege contra variaciones de voltaje.", "17/07/2025"});
    comentarios.push_back((Comentario){41, 41, 1, "Carga rapido pero requiere posicionamiento preciso.", "19/07/2025"});
    comentarios.push_back((Comentario){42, 42, 2, "Mucho espacio; resistente y confiable.", "21/07/2025"});
    comentarios.push_back((Comentario){43, 43, 3, "Calidad de sonido profesional; ideal para podcast.", "23/07/2025"});
    comentarios.push_back((Comentario){44, 44, 4, "Responde bien a comandos de voz; util en casa.", "25/07/2025"});
    comentarios.push_back((Comentario){45, 45, 5, "Amplifica bien la senal pero el rango limitado.", "27/07/2025"});
    comentarios.push_back((Comentario){46, 46, 1, "Enfria rapido pero es algo ruidoso.", "29/07/2025"});
    comentarios.push_back((Comentario){47, 47, 2, "Perfecto para proyectos electronicos.", "31/07/2025"});
    comentarios.push_back((Comentario){48, 48, 3, "Ideal para streaming y grabaciones.", "02/08/2025"});
    comentarios.push_back((Comentario){49, 49, 4, "Muy practico; facil de conectar.", "04/08/2025"});
    comentarios.push_back((Comentario){50, 50, 5, "Buena camara; util para seguridad.", "06/08/2025"});
}


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
