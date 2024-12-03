// kmeans.cpp

#include "kmeans.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <unordered_set>

/**
 * @brief Losuje początkowe centroidy.
 *
 * @param points Punkty danych.
 * @param centroids Wektor wynikowy dla centroidów.
 * @param k Liczba klastrów.
 */
void LosowanieCentroid(const std::vector<Point>& points, std::vector<Point>& centroids, int k) {
    centroids.clear();
    std::mt19937 mt(std::time(0));

    std::unordered_set<int> selectedIndices;

    for (int i = 0; i < k; i++) {
        int index;
        do {
            index = mt() % points.size();
        } while (selectedIndices.count(index) > 0);

        selectedIndices.insert(index);
        centroids.push_back(points[index]);
    }
}

/**
 * @brief Przypisuje punkty do klastrów na podstawie centroidów.
 *
 * @param points Punkty danych.
 * @param centroids Centroidy.
 * @param convergence Zmienna wyjściowa wskazująca zbieżność.
 */
void PrzypisaniePunktowDoKlastrow(std::vector<Point>& points, const std::vector<Point>& centroids, bool& convergence) {
    convergence = true; // Zakładamy zbieżność na początku

    for (Point& point : points) {
        double minDistance = std::numeric_limits<double>::max();
        int assignedCluster = -1;

        for (int i = 0; i < centroids.size(); i++) {
            double distance = 0.0;
            for (int j = 0; j < point.coordinates.size(); j++) {
                distance += std::pow(point.coordinates[j] - centroids[i].coordinates[j], 2);
            }
            distance = std::sqrt(distance);

            if (distance < minDistance) {
                minDistance = distance;
                assignedCluster = i;
            }
        }

        if (point.clusterIndex != assignedCluster) {
            point.clusterIndex = assignedCluster;
            convergence = false; // Ustaw zbieżność na false, jeśli nastąpiła zmiana
        }
    }
}

/**
 * @brief Aktualizuje centroidy na podstawie przypisanych punktów.
 *
 * @param points Punkty danych.
 * @param centroids Centroidy.
 */
void UpdateCentroids(std::vector<Point>& points, std::vector<Point>& centroids) {
    std::vector<int> clusterSizes(centroids.size(), 0);
    std::vector<std::vector<double>> clusterSums(centroids.size(), std::vector<double>(centroids[0].coordinates.size(), 0.0));

    for (const Point& point : points) {
        int cluster = point.clusterIndex;
        clusterSizes[cluster]++;

        for (int i = 0; i < centroids[0].coordinates.size(); i++) {
            clusterSums[cluster][i] += point.coordinates[i];
        }
    }

    for (int i = 0; i < centroids.size(); i++) {
        for (int j = 0; j < centroids[0].coordinates.size(); j++) {
            if (clusterSizes[i] > 0) {
                centroids[i].coordinates[j] = clusterSums[i][j] / clusterSizes[i];
            }
        }
    }
}

/**
 * @brief Zapisuje wyniki do pliku wyjściowego.
 *
 * @param outputFileName Nazwa pliku wyjściowego.
 * @param points Punkty danych.
 * @param centroids Centroidy.
 */
void writeOutput(const std::string& outputFileName, const std::vector<Point>& points, const std::vector<Point>& centroids) {
    std::ofstream output_file(outputFileName);
    if (!output_file.is_open()) {
        std::cerr << "Błąd!!!: " << outputFileName << std::endl;
        return;
    }

    for (int i = 0; i < centroids.size(); i++) {
        output_file << "Klaster " << i << ":\n";
        for (const Point& point : points) {
            if (point.clusterIndex == i) {
                for (double value : point.coordinates) {
                    output_file << value << ' ';
                }
                output_file << '\n';
            }
        }
        output_file << '\n';
    }

    // Zapisz centroidy
    for (size_t i = 0; i < centroids.size(); ++i) {
        output_file << "Centroid " << i << ' ';
        for (double value : centroids[i].coordinates) {
            output_file << value << ' ';
        }
        output_file << '\n';
    }

    output_file.close();
}
