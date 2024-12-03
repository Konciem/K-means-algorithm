// parameters.cpp

#include "parameters.hpp"
#include <iostream>
#include <cstring>

/**
 * @brief Parsuje argumenty wiersza poleceń i zapisuje je w strukturze Parameters.
 *
 * @param argc Liczba argumentów wiersza poleceń.
 * @param argv Tablica argumentów wiersza poleceń.
 * @return Struktura Parameters.
 */
Parameters parseCommandLineArguments(int argc, char* argv[]) {
    Parameters params;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-i") == 0)
            params.input_filename = argv[i + 1];
        if (strcmp(argv[i], "-o") == 0)
            params.output_filename = argv[i + 1];
        if (strcmp(argv[i], "-k") == 0)
            params.k_clusters = std::atoi(argv[i + 1]);
        if (strcmp(argv[i], "-d") == 0)
            params.n_dimensions = std::atoi(argv[i + 1]);
    }

    return params;
}
