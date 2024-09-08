#include <iostream>
#include <vector>

// Si necesitas una función para agregar espacios, define una así:
std::string add_spaces(int num) {
    return std::to_string(num) + " "; // Agrega un espacio después del número
}

int main()
{
    std::vector<int> v {1,2,3,4,5};

    // Bucle C-style para imprimir con espacios
    for(int i = 0; i < v.size(); ++i)
    {
        std::cout << add_spaces(v[i]); // Llama a la función add_spaces correctamente
    }
    std::cout << std::endl; // Salto de línea después del bucle

    // Bucle Modern C++ para imprimir elementos
    for (const auto& num : v)
    {
        std::cout << num << " "; // Imprime los números separados por espacios
    }
    std::cout << std::endl; // Salto de línea después del bucle

    return 0;
}
