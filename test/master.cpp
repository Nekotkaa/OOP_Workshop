#define BOOST_AUTO_TEST_MAIN // root of all test suites and cases
#define BOOST_TEST_DYN_LINK  // use shared boost library
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

struct MyConfig {
    MyConfig() {
        // You can configure global settings here if needed (e.g. tolerance)
    }

    ~MyConfig() {}
};

BOOST_GLOBAL_FIXTURE(MyConfig);