#include "productdatabase.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

bool ProductDatabase::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    products.clear();
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name;
        double calories, proteins, fats, carbs;

        if (std::getline(iss, name, ',') &&
            iss >> calories && iss.ignore() &&
            iss >> proteins && iss.ignore() &&
            iss >> fats && iss.ignore() &&
            iss >> carbs) {

            products.emplace_back(name, calories, proteins, fats, carbs);
        }
    }

    return true;
}

bool ProductDatabase::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    for (const auto& product : products) {
        file << product.getName() << ","
             << product.getCalories() << ","
             << product.getProteins() << ","
             << product.getFats() << ","
             << product.getCarbs() << "\n";
    }

    return true;
}

void ProductDatabase::addProduct(const Product& product) {
    products.push_back(product);
}

std::vector<Product> ProductDatabase::searchProduct(const std::string& query) const {
    std::vector<Product> results;
    std::string lowerQuery = query;
    std::transform(lowerQuery.begin(), lowerQuery.end(), lowerQuery.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    for (const auto& product : products) {
        std::string lowerName = product.getName();
        std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(),
                       [](unsigned char c) { return std::tolower(c); });

        if (lowerName.find(lowerQuery) != std::string::npos) {
            results.push_back(product);
        }
    }

    return results;
}

const std::vector<Product>& ProductDatabase::getAllProducts() const {
    return products;
}
