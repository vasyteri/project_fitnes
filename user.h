#ifndef USER_H
#define USER_H

class User {
public:
    User(double height = 0, double weight = 0);

    double getHeight() const;
    double getWeight() const;
    double getDailyCalories() const;

    void setHeight(double height);
    void setWeight(double weight);
    void calculateDailyCalories();

private:
    double height; // in cm
    double weight; // in kg
    double dailyCalories;
};

#endif // USER_H
