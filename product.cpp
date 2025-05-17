#include "product.h"

Product::Product(const std::string& name, double calories,
                 double proteins, double fats, double carbs)
    : name(name), calories(calories), proteins(proteins), fats(fats), carbs(carbs) {}

std::string Product::getName() const { return name; }
double Product::getCalories() const { return calories; }
double Product::getProteins() const { return proteins; }
double Product::getFats() const { return fats; }
double Product::getCarbs() const { return carbs; }

void Product::setName(const std::string& name) { this->name = name; }
void Product::setCalories(double calories) { this->calories = calories; }
void Product::setProteins(double proteins) { this->proteins = proteins; }
void Product::setFats(double fats) { this->fats = fats; }
void Product::setCarbs(double carbs) { this->carbs = carbs; }
