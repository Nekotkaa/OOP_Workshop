#ifndef CONTAINER_H
#define CONTAINER_H

class Container {
private:
    // int for unique container registration number
    int number;
    // double for empty container weight (tare)
    double tareWeight;
    // double for maximum total weight with load
    double maxWeight;
    // double for maximum stacking strength
    double strength;
    // double for current net weight of the cargo
    double cargo;

public:
    // Constructors
    Container();
    explicit Container(int number);

    // Getters
    int getNumber() const;
    double getTare() const;
    double getMaxWeight() const;
    double getStrength() const;
    double getNetWeight() const;

    // Calculated properties
    double getGrossWeight() const;
    double getMaxCargo() const;

    // Setters (protected against invalid states when cargo is loaded)
    void setTare(double tareWeight);
    void setMaxWeight(double maxWeight);
    void setStrength(double strength);

    // Cargo management methods
    void loadCargo(double amount);
    void unloadCargo(double amount);
};

#endif // CONTAINER_H