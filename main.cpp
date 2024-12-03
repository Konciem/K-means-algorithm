// main.cpp

#include "kmeans.hpp"
#include "parsing.hpp"
#include "parameters.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

/**
 * @brief Funkcja główna programu K-means.
 *
 * @param argc Liczba argumentów wiersza poleceń.
 * @param argv Tablica argumentów wiersza poleceń.
 * @return Kod wyjścia programu.
 */
int main(int argc, char* argv[]) {
    Parameters params;

    // Sprawdź liczbę argumentów
    if (argc < 2) {
        std::cout << "Za mało argumentów! \n";
        std::cout << "Program obsługuje tylko następujące parametry: \n";
        std::cout << "-i definiuje plik wejściowy \n";
        std::cout << "-o definiuje plik wyjściowy \n";
        std::cout << "-k liczba klastrów \n";
        std::cout << "-d liczba wymiarów \n";

        return 0;
    }

    // Parsuj argumenty wiersza poleceń
    params = parseCommandLineArguments(argc, argv);

    std::cout << "Nazwa pliku wejściowego: " << params.input_filename << "\n";

    std::vector<Point> points;
    readAndSaveData(params.input_filename, points);

    std::vector<Point> centroids;
    LosowanieCentroid(points, centroids, params.k_clusters);

    int itr = 0;
    bool convergence = false;

    // Główna pętla algorytmu
    while (!convergence) {
        PrzypisaniePunktowDoKlastrow(points, centroids, convergence);

        UpdateCentroids(points, centroids);

        itr++;
    }

    writeOutput(params.output_filename, points, centroids);

    std::cout << "Grupowanie punktów w k klastrów: " << params.k_clusters << std::endl;
    std::cout << "Wymiary: " << params.n_dimensions << std::endl;
    std::cout << "Zbieżność w " << itr << " iteracjach." << std::endl;

    return 0;
}
