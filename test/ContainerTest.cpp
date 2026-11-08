#include <boost/test/unit_test.hpp>
#include "Container.h"

BOOST_AUTO_TEST_SUITE(ContainerTestSuite)

// 1. Checking the initial state of the empty container with a given registration number
BOOST_AUTO_TEST_CASE(testContainer_withRegistrationNumber) {
    Container container(234);
    BOOST_REQUIRE_EQUAL(container.getNumber(), 234);
    BOOST_REQUIRE_EQUAL(container.getTare(), 0.0);
    BOOST_REQUIRE_EQUAL(container.getMaxWeight(), 0.0);
    BOOST_REQUIRE_EQUAL(container.getNetWeight(), 0.0);
    BOOST_REQUIRE_CLOSE_FRACTION(container.getGrossWeight(), 0.0, 0.00001);
}

// 2. Checking the initial state of the non-container (default constructor, no registration number)
BOOST_AUTO_TEST_CASE(testContainer_defaultConstructor) {
    Container container;
    BOOST_REQUIRE_EQUAL(container.getNumber(), 0);
    BOOST_REQUIRE_EQUAL(container.getNetWeight(), 0.0);
}

// 3. Initial setting of tare weight and maximum weight
BOOST_AUTO_TEST_CASE(testContainer_setWeightsAndGetters) {
    Container container(100);
    container.setTare(1000.0);
    container.setMaxWeight(25000.0);

    BOOST_REQUIRE_CLOSE_FRACTION(container.getTare(), 1000.0, 0.00001);
    BOOST_REQUIRE_CLOSE_FRACTION(container.getMaxWeight(), 25000.0, 0.00001);
    BOOST_REQUIRE_CLOSE_FRACTION(container.getMaxCargo(), 24000.0, 0.00001);
}

// 4. Load the container below maximum weight, check the weight of the load
BOOST_AUTO_TEST_CASE(testContainer_loadCargo_valid) {
    Container container(101);
    container.setTare(1000.0);
    container.setMaxWeight(10000.0); // Max cargo = 9000

    container.loadCargo(5000.0);
    BOOST_REQUIRE_CLOSE_FRACTION(container.getNetWeight(), 5000.0, 0.00001);
    BOOST_REQUIRE_CLOSE_FRACTION(container.getGrossWeight(), 6000.0, 0.00001);
}

// 5. Attempt to load the container above the maximum weight limit
BOOST_AUTO_TEST_CASE(testContainer_loadCargo_exceedsMax) {
    Container container(102);
    container.setTare(1000.0);
    container.setMaxWeight(10000.0); // Max cargo = 9000

    container.loadCargo(15000.0); // Tries to overload
    BOOST_REQUIRE_CLOSE_FRACTION(container.getNetWeight(), 9000.0, 0.00001); // Capped at max cargo
}

// 6. Unload the container below the current load, check weight
BOOST_AUTO_TEST_CASE(testContainer_unloadCargo_valid) {
    Container container(103);
    container.setTare(1000.0);
    container.setMaxWeight(10000.0);

    container.loadCargo(6000.0);
    container.unloadCargo(2000.0);
    BOOST_REQUIRE_CLOSE_FRACTION(container.getNetWeight(), 4000.0, 0.00001);
}

// 7. Attempt to unload more load than the container currently contains
BOOST_AUTO_TEST_CASE(testContainer_unloadCargo_excessive) {
    Container container(104);
    container.setTare(1000.0);
    container.setMaxWeight(10000.0);

    container.loadCargo(3000.0);
    container.unloadCargo(5000.0); // Tries to unload more than 3000
    BOOST_REQUIRE_CLOSE_FRACTION(container.getNetWeight(), 0.0, 0.00001); // Should clamp to 0
}

BOOST_AUTO_TEST_SUITE_END()