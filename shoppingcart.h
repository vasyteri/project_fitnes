#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <vector>
#include "product.h"

class ShoppingCart {
public:
    void addProduct(const Product& product);
    void removeProduct(size_t index);
    void clear();

    double getTotalCalories() const;
    double getTotalProteins() const;
    double getTotalFats() const;
    double getTotalCarbs() const;

    const std::vector<Product>& getItems() const;
    size_t getItemCount() const;

private:
    std::vector<Product> items;
};

#endif // SHOPPINGCART_H
