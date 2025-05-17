#include "shoppingcart.h"

void ShoppingCart::addProduct(const Product& product) {
    items.push_back(product);
}

void ShoppingCart::removeProduct(size_t index) {
    if (index < items.size()) {
        items.erase(items.begin() + index);
    }
}

void ShoppingCart::clear() {
    items.clear();
}

double ShoppingCart::getTotalCalories() const {
    double total = 0;
    for (const auto& item : items) {
        total += item.getCalories();
    }
    return total;
}

double ShoppingCart::getTotalProteins() const {
    double total = 0;
    for (const auto& item : items) {
        total += item.getProteins();
    }
    return total;
}

double ShoppingCart::getTotalFats() const {
    double total = 0;
    for (const auto& item : items) {
        total += item.getFats();
    }
    return total;
}

double ShoppingCart::getTotalCarbs() const {
    double total = 0;
    for (const auto& item : items) {
        total += item.getCarbs();
    }
    return total;
}

const std::vector<Product>& ShoppingCart::getItems() const {
    return items;
}

size_t ShoppingCart::getItemCount() const {
    return items.size();
}
