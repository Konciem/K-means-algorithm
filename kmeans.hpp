// kmeans.hpp

#ifndef KMEANS_HPP
#define KMEANS_HPP

#include <vector>
#include <string>

/**
 * @brief Struktura reprezentująca punkt w przestrzeni.
 */
struct Point {
    std::vector<double> coordinates; /**< Współrzędne punktu. */
    int clusterIndex;                /**< Indeks przypisanego klastra. */
};

/**
 * @brief Wczytuje dane z pliku i zapisuje je w wektorze punktów.
 *
 * @param input_filename Nazwa pliku wejściowego.
 * @param points Wektor wynikowy dla punktów danych.
 */
void readAndSaveData(const std::string& input_filename, std::vector<Point>& points);

/**
 * @brief Losowo wybiera początkowe centroidy.
 *
 * @param points Punkty danych.
 * @param centroids Wektor wynikowy dla centroidów.
 * @param k Liczba klastrów.
 */
void LosowanieCentroid(const std::vector<Point>& points, std::vector<Point>& centroids, int k);

/**
 * @brief Przypisuje punkty do klastrów na podstawie centroidów.
 *
 * @param points Punkty danych.
 * @param centroids Centroidy.
 * @param convergence Zmienna wyjściowa wskazująca zbieżność.
 */
void PrzypisaniePunktowDoKlastrow(std::vector<Point>& points, const std::vector<Point>& centroids, bool& convergence);

/**
 * @brief Aktualizuje centroidy na podstawie przypisanych punktów.
 *
 * @param points Punkty danych.
 * @param centroids Centroidy.
 */
void UpdateCentroids(std::vector<Point>& points, std::vector<Point>& centroids);

/**
 * @brief Zapisuje wyniki do pliku wyjściowego.
 *
 * @param outputFileName Nazwa pliku wyjściowego.
 * @param points Punkty danych.
 * @param centroids Centroidy.
 */
void writeOutput(const std::string& outputFileName, const std::vector<Point>& points, const std::vector<Point>& centroids);

#endif

