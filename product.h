#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
    Product(const std::string& name = "", double calories = 0,
            double proteins = 0, double fats = 0, double carbs = 0);

    std::string getName() const;
    double getCalories() const;
    double getProteins() const;
    double getFats() const;
    double getCarbs() const;

    void setName(const std::string& name);
    void setCalories(double calories);
    void setProteins(double proteins);
    void setFats(double fats);
    void setCarbs(double carbs);

private:
    std::string name;
    double calories;
    double proteins;
    double fats;
    double carbs;
};

#endif // PRODUCT_H
