#include "Container.h"
#include <iostream>
#include <algorithm>

// Default constructor initializing fields to 0.0
Container::Container() : number(0), tareWeight(0.0), maxWeight(0.0), strength(0.0), cargo(0.0) {}

// Parameterized constructor with standard default values for a real container
Container::Container(int number) : number(number), tareWeight(1000.0), maxWeight(25000.0), strength(50000.0), cargo(0.0) {}

// Getters
int Container::getNumber() const { return number; }
double Container::getTare() const { return tareWeight; }
double Container::getMaxWeight() const { return maxWeight; }
double Container::getStrength() const { return strength; }
double Container::getNetWeight() const { return cargo; }

// Calculated weights
double Container::getGrossWeight() const {
    return tareWeight + cargo;
}

double Container::getMaxCargo() const {
    return maxWeight - tareWeight;
}

// Protected Setter: checks if current cargo fits within the new tare weight limit
void Container::setTare(double tareWeight) {
    if (this->cargo <= (this->maxWeight - tareWeight)) {
        this->tareWeight = tareWeight;
    } else {
        std::cout << "Error: Cannot change tare weight. Current cargo exceeds new capacity!\n";
    }
}

// Protected Setter: checks if current cargo fits within the new maximum weight limit
void Container::setMaxWeight(double maxWeight) {
    if (this->cargo <= (maxWeight - this->tareWeight)) {
        this->maxWeight = maxWeight;
    } else {
        std::cout << "Error: Cannot lower max weight. Current cargo exceeds new limit!\n";
    }
}

void Container::setStrength(double strength) {
    this->strength = strength;
}

// Protected load method: prevents overloading beyond getMaxCargo()
void Container::loadCargo(double amount) {
    if (amount <= 0) return;
    double availableSpace = getMaxCargo() - cargo;
    if (amount > availableSpace) {
        std::cout << "Warning: Requested load exceeds capacity. Loading maximum available space (" << availableSpace << " kg).\n";
        cargo = getMaxCargo();
    } else {
        cargo += amount;
    }
}

// Protected unload method: prevents unloading more than what is currently inside
void Container::unloadCargo(double amount) {
    if (amount <= 0) return;
    if (amount > cargo) {
        std::cout << "Warning: Attempted to unload more than current cargo. Unloading all remaining (" << cargo << " kg).\n";
        cargo = 0.0;
    } else {
        cargo -= amount;
    }
}