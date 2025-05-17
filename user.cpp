#include "user.h"

User::User(double height, double weight) : height(height), weight(weight), dailyCalories(0) {}

double User::getHeight() const { return height; }
double User::getWeight() const { return weight; }
double User::getDailyCalories() const { return dailyCalories; }

void User::setHeight(double height) { this->height = height; }
void User::setWeight(double weight) { this->weight = weight; }

void User::calculateDailyCalories() {
    // Mifflin-St Jeor Formula
    dailyCalories = 10 * weight + 6.25 * height - 5 * 30 + 5; // 30 is age, 5 is male (for female it's -161)
    // Simplified version, in real app you would ask for age and gender
}
