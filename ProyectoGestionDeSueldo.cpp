#include <iostream>
#include <string>
#include <limits>

/**
 * Enumeración para las categorías de empleados.
 */
enum class Categoria {
    A = 300,
    B = 350,
    C = 400,
    D = 0
};

/**
 * Clase que representa a un empleado.
 */
class Empleado {
private:
    int id; /**< Identificador del empleado. */
    float salarioMensualMedio; /**< Salario mensual medio del empleado. */
    Categoria bonificacionAsociada; /**< Bonificación asociada al empleado. */
    std::string nombre; /**< Nombre del empleado. */
    std::string apellido; /**< Apellido del empleado. */

public:
    static int proximaEvaluacion; /**< Fecha de la próxima evaluación. */

    // Constructor por defecto
    Empleado() = default;

    // Constructor con parámetros
    Empleado(int id, std::string nombre, std::string apellido)
        : id(id), nombre(nombre), apellido(apellido) {}

    // Setters y getters para acceder a los atributos privados
    void setId(int id) {
        this->id = id;
    }

    int getId() const {
        return id;
    }

    void setNombre(const std::string& nombre) {
        this->nombre = nombre;
    }

    std::string getNombre() const {
        return nombre;
    }

    void setApellido(const std::string& apellido) {
        this->apellido = apellido;
    }

    std::string getApellido() const {
        return apellido;
    }

    void setSalarioMensualMedio(float salario) {
        salarioMensualMedio = salario;
    }

    float getSalarioMensualMedio() const {
        return salarioMensualMedio;
    }

    void setBonificacion(Categoria categoria) {
        bonificacionAsociada = categoria;
    }

    int getBonificacion() const {
        return static_cast<int>(bonificacionAsociada);
    }
};

int Empleado::proximaEvaluacion = 2025;

// Funciones
std::string getMes(int indice);
float calcularSalarioMensualMedio(float salarios[]);
Categoria getBonificacion(char categoria);
void mostrarMenu();
void registrarEmpleado(Empleado& empleado);
void mostrarInformacion(const Empleado& empleado);

int main() {
    Empleado empleado;
    int opcion;

    do {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                registrarEmpleado(empleado);
                break;
            case 2:
                mostrarInformacion(empleado);
                break;
            case 0:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opción inválida, por favor intenta de nuevo.\n";
        }

    } while (opcion != 0);

    return 0;
}

/**
 * Muestra el menú principal del programa.
 */
void mostrarMenu() {
    std::cout << "\n--- Menú Principal ---\n";
    std::cout << "1. Registrar empleado\n";
    std::cout << "2. Mostrar información del empleado\n";
    std::cout << "0. Salir\n";
    std::cout << "Elige una opción: ";
}

/**
 * Función que solicita los datos del empleado y los registra.
 */
void registrarEmpleado(Empleado& empleado) {
    int id;
    std::string nombre, apellido;
    float salarios[12];

    std::cout << "\n--- Registro de Empleado ---\n";

    std::cout << "Identificador: ";
    std::cin >> id;
    empleado.setId(id);

    std::cout << "Nombre: ";
    std::cin >> nombre;
    empleado.setNombre(nombre);

    std::cout << "Apellido: ";
    std::cin >> apellido;
    empleado.setApellido(apellido);

    // Pedir salarios mensuales
    for (int i = 0; i < 12; ++i) {
        std::cout << "Salario para " << getMes(i) << ": ";
        while (!(std::cin >> salarios[i])) {
            std::cout << "Entrada inválida. Introduce un valor numérico para el salario: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // Calcular salario mensual medio
    empleado.setSalarioMensualMedio(calcularSalarioMensualMedio(salarios));

    // Pedir categoría del empleado
    char categoriaALaQuePertenece;
    std::cout << "¿A qué categoría pertenece? (A, B, C): ";
    std::cin >> categoriaALaQuePertenece;

    // Asignar bonificación según la categoría
    empleado.setBonificacion(getBonificacion(categoriaALaQuePertenece));

    std::cout << "Empleado registrado con éxito.\n";
}

/**
 * Muestra la información completa del empleado registrado.
 */
void mostrarInformacion(const Empleado& empleado) {
    std::cout << "\n--- Información del Empleado ---\n";
    std::cout << "ID: " << empleado.getId() << "\n";
    std::cout << "Nombre: " << empleado.getNombre() << " " << empleado.getApellido() << "\n";
    std::cout << "Salario mensual medio: " << empleado.getSalarioMensualMedio() << " euros\n";
    std::cout << "Bonificación asociada: " << empleado.getBonificacion() << " euros\n";
    std::cout << "Próxima evaluación: " << Empleado::proximaEvaluacion << "\n";
}

/**
 * Función que devuelve el nombre del mes según su índice.
 * @param indice Índice del mes (0-11).
 * @return Nombre del mes.
 */
std::string getMes(int indice) {
    std::string meses[] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
    return meses[indice];
}

/**
 * Función que calcula el salario mensual medio.
 * @param salarios Salarios mensuales del empleado.
 * @return Salario mensual medio.
 */
float calcularSalarioMensualMedio(float salarios[]) {
    float suma = 0;
    for (int i = 0; i < 12; ++i) {
        suma += salarios[i];
    }
    return suma / 12;
}

/**
 * Función que devuelve la bonificación según la categoría.
 * @param categoria Categoría del empleado (A, B, C).
 * @return Bonificación asociada a la categoría.
 */
Categoria getBonificacion(char categoria) {
    switch (categoria) {
        case 'A':
            return Categoria::A;
        case 'B':
            return Categoria::B;
        case 'C':
            return Categoria::C;
        default:
            return Categoria::D;
    }
}
