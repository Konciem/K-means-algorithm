// parameters.hpp

#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

#include <string>

/**
 * @brief Struktura przechowująca parametry programu.
 */
struct Parameters {
    std::string input_filename; /**< Nazwa pliku wejściowego. */
    std::string output_filename; /**< Nazwa pliku wyjściowego. */
    int k_clusters; /**< Liczba klastrów. */
    int n_dimensions; /**< Liczba wymiarów. */
};

/**
 * @brief Parsuje argumenty wiersza poleceń i zapisuje je w strukturze Parameters.
 *
 * @param argc Liczba argumentów wiersza poleceń.
 * @param argv Tablica argumentów wiersza poleceń.
 * @return Struktura Parameters.
 */
Parameters parseCommandLineArguments(int argc, char* argv[]);

#endif /* PARAMETERS_HPP */
