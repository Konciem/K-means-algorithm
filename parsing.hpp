// parsing.hpp

#ifndef PARSING_HPP
#define PARSING_HPP

#include <vector>
#include <string>

#include "kmeans.hpp" // Dołącz nagłówek kmeans.hpp, aby używać struktury Point

/**
 * @brief Wczytuje dane z pliku i zapisuje je w wektorze punktów.
 *
 * @param input_filename Nazwa pliku wejściowego.
 * @param points Wektor wynikowy dla punktów danych.
 */
void readAndSaveData(const std::string& input_filename, std::vector<Point>& points);

#endif /* PARSING_HPP */
