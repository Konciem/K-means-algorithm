// parsing.cpp

#include "parsing.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

/**
 * @brief Wczytuje dane z pliku i zapisuje je w wektorze punktów.
 *
 * @param input_filename Nazwa pliku wejściowego.
 * @param points Wektor wynikowy dla punktów danych.
 */
void readAndSaveData(const std::string& input_filename, std::vector<Point>& points) {
    std::fstream input_file(input_filename);
    if (!input_file.is_open()) {
        std::cerr << "Błąd!!!: " << input_filename << std::endl;
        return;
    }

    std::string line_text;
    while (getline(input_file, line_text)) {
        Point point;
        std::stringstream lineStream(line_text);
        double coordinates;

        while (lineStream >> coordinates) {
            point.coordinates.push_back(coordinates);
        }
        points.push_back(point);
    }

    input_file.close();

    for (int i = 0; i < points.size(); i++) {
        for (int j = 0; j < points[i].coordinates.size(); j++) {
            std::cout << points[i].coordinates[j] << " ";
        }
        std::cout << std::endl;
    }
}
