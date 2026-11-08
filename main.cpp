#include <iostream>
#include "Container.h"

// Bring the standard library namespace into scope for this file so we don't need std:: prefix
using namespace std;

// 1. Display function passing Container object by value (receives a copy)
void display(Container c) {
    cout << "--- [Display by Value (Copy)] ---\n";
    cout << "Container Number (int): " << c.getNumber() << "\n";
    cout << "Tare Weight (double): " << c.getTare() << " kg\n";
    cout << "Max Weight (double): " << c.getMaxWeight() << " kg\n";
    cout << "Current Net Weight / Cargo (double): " << c.getNetWeight() << " kg\n\n";
}

// 2. Test local stack object creation
void testLocalObject() {
    cout << "=== Testing Local Object on Stack ===\n";
    Container localContainer(202); // Created on the stack (automatic object)
    localContainer.setTare(1200.0);
    localContainer.setMaxWeight(30000.0);
    display(localContainer);
}

// 3. Display current cargo weight passing Container by reference
void displayCargo(Container& c) {
    cout << "-> Current Cargo Weight (netWeight): " << c.getNetWeight() << " kg\n";
}

// 4. Container handling procedure (load and unload test)
void testLoadAndUnload(Container& c, double goods) {
    cout << "=== Testing Load and Unload Procedure ===\n";

    cout << "Initial state:\n";
    displayCargo(c); // Display initial cargo

    cout << "Loading " << goods << " kg of goods...\n";
    c.loadCargo(goods); // Load goods into object passed by reference (modifiable)
    displayCargo(c); // Display final weight after loading

    cout << "Unloading " << (goods / 2) << " kg of goods...\n";
    c.unloadCargo(goods / 2); // Unload half from object passed by reference
    displayCargo(c); // Display final weight after unloading
    cout << "\n";
}

// 5. Create dynamic object on the heap using operator new, load goods, and return pointer
Container* prepare(int number, double goods) {
    Container* pContainer = new Container(number); // Created on heap using operator new
    pContainer->loadCargo(goods);                  // Load initial quantity
    return pContainer;                             // Return pointer to heap object
}

// 6. Overloaded display function passing Container by pointer (memory address)
void display(Container* p) {
    if (p == nullptr) return;
    cout << "--- [Display by Pointer (Heap)] ---\n";
    cout << "Memory Address: " << p << "\n";
    cout << "Container Number (int): " << p->getNumber() << "\n";
    cout << "Gross Weight (double): " << p->getGrossWeight() << " kg\n\n";
}

// 7. Test dynamic object creation, display, and memory deallocation
void testDynamicObject() {
    cout << "=== Testing Dynamic Object on Heap ===\n";

    // Create heap object via prepare function
    Container* myDynamicContainer = prepare(303, 10000.0);

    // Display using pointer overload
    display(myDynamicContainer);

    // Free memory using delete operator to prevent memory leaks
    delete myDynamicContainer;
    myDynamicContainer = nullptr; // Good practice: nullify pointer after deletion
    cout << "Dynamic object memory freed successfully.\n\n";
}

// Main entry point of the C++ executable program
int main() {
    // Invoke local object test on the stack
    testLocalObject();

    // Invoke dynamic object test on the heap
    testDynamicObject();

    // Test load/unload with a reference container object
    Container refContainer(404);
    testLoadAndUnload(refContainer, 8000.0);

    return 0; // Return 0 to indicate successful execution
}