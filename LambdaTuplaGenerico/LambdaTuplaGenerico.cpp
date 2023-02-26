/**
* Uso de funciones lamba, funciones con parámetros opcionales y tuplas
* Se crea un nombre de espacio para encapsular las funciones y tipos como ejemplo para uso de espacios
*/

#include <iostream>
#include <tuple>
#include <string>

namespace lambdaConTuplas
{
    // Si se quisiera definir la cabecera se descomentaria la siguiente línea quedando esta tal cual
    // y en la definición de sumaYcalcula SE ELIMINARIA EL VALOR POR DEFECTO ... = 1
    //  
    // template <class T> constexpr std::tuple<std::string, T> sumaYcalcula(T, T, int = 1);

    // Se crea un alias para poder usar el tipo tupla posteriormente
    template <class T> using tupla = std::tuple<std::string, T>;

    template <class T> constexpr std::tuple<std::string, T> sumaYcalcula(T a, T b, int multiplica = 1)
    {
        // Esta línea soluciona la idea (sumar y calcular).
        // Se comenta y se codifica de manera que el ejemplo incluya captura de variables [] y paso de parametros ()
        //
        // return 
        //     [a, b, multiplica] () -> std::tuple<std::string, T>
        //     {
        //         return std::make_tuple(
        //             "calculando " + ((multiplica != 1)?std::to_string(multiplica) + " * ":"") + "( " + std::to_string(a) + " + " + std::to_string(b) + " )", 
        //             multiplica * (a + b)
        //         );
        //     }();

        int tmp = multiplica;
        return 
            [a, b] (int d) -> std::tuple<std::string, T>
            { 
                return std::make_tuple (
                    "calculando " + ((d != 1) ? std::to_string(d) + " * " : "") + "( " + std::to_string(a) + " + " + std::to_string(b) + " )", 
                    d * (a + b)
                );
            } (tmp);
    }
}

using namespace lambdaConTuplas;

int main()
{
    tupla<int> calculo1 = sumaYcalcula<int>(2, 3);
    tupla<float> calculo2 = sumaYcalcula<float>(2.1, 3);
    tupla<float> calculo3 = sumaYcalcula<float>(2.1, 3, 10);
    std::cout << std::get<0>(calculo1) << " = " << std::get<1>(calculo1) << std::endl;
    std::cout << std::get<0>(calculo2) << " = " << std::get<1>(calculo2) << std::endl;
    std::cout << std::get<0>(calculo3) << " = " << std::get<1>(calculo3) << std::endl;
    return EXIT_SUCCESS;
}
