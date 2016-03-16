#include <vector>
#include <boost/assign/list_of.hpp>

#define check(COND, MESG) \
    REQUIRE(COND);        \
    INFO(MESG);

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// Print vectors and index to standard error and then return a string saying
// that the unit test failed.
template<class T>
static std::string
printVector(const std::vector<T> &v1, const std::vector<T> &v2, size_t index) {
  throw std::exception();
  return "";
}

// Ditto, but only print one vector.
template<class T>
static std::string
printVector(const std::vector<T> &v1) {
  return "";
}

template<class T>
static void
testAssignment(const std::vector<T> &input) {
    std::vector<T> v1(5);
    try {
        v1 = input; // unit being tested
        check(v1.size() == input.size(), printVector(v1));
        for (size_t i = 0; i < v1.size(); ++i)
            check(v1[i] == input[i], printVector(v1, input, i)); 
    } catch (...) {
        // Assignment must be exception-safe
        check(v1.size() == 5, printVector(v1));
        for (size_t i = 0; i < v1.size(); ++i)
            check(v1[i] == T(), printVector(v1, input, i));
    }
}

TEST_CASE( "vector assignment is successful", "[vector] [assignment]" ) {
   SECTION( "std::vector<int> assignment" ) {
        std::vector<int> v = boost::assign::list_of(1)(2)(3);
        testAssignment(v);
    }
    SECTION( "std::vector<char> assignment" ) {
        std::vector<char> v = boost::assign::list_of('a')('b');
        testAssignment(v);
    }
}

