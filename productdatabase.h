#ifndef PRODUCTDATABASE_H
#define PRODUCTDATABASE_H

#include <vector>
#include <string>
#include "product.h"

class ProductDatabase {
public:
    bool loadFromFile(const std::string& filename);
    bool saveToFile(const std::string& filename) const;

    void addProduct(const Product& product);
    std::vector<Product> searchProduct(const std::string& query) const;
    const std::vector<Product>& getAllProducts() const;

private:
    std::vector<Product> products;
};

#endif // PRODUCTDATABASE_H
