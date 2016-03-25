// Demos how to write a unit test for std::vector<T> assignment.

// All vector unit test examples should include these two files
//#include <rose.h>
//#include <VectorUnitTest.h>
#include "../VectorUnitTest.h"

// These next files are used only by this example
#include <boost/assign/list_of.hpp>
#include "gtest/gtest.h"

using namespace VectorUnitTest;                         // from VectorUnitTest.h

template<class T>
static void
testVectorAssignment(const std::vector<T> &input) {
    std::vector<T> destination(5);                      // fill a vector with some default constructe Ts.
    try {
        destination = input;

        // Assignment succeeded, therefore destination must equal input
        EXPECT_EQ(destination.size(), input.size());
        for (size_t i = 0; i < destination.size(); ++i)
            EXPECT_EQ(destination[i], input[i]);
    } catch (...) {
        // Assignment failed, therefore destination must be unchanged.
        //
        // NOTE: std::vector only has basic exception safety guarantees (destination is in a consistent state with no leaked
        // memory), but we're testing for strong guarantee (destination is unchanged). This is intentional to demonstrate what
        // happens when a unit test fails.
        EXPECT_EQ(destination.size(), 5);
        for (size_t i = 0; i < destination.size(); ++i)
            EXPECT_EQ(destination[i], T());
    }
}

// googletest:

// TEST first parm is test case name, second is test name

// Test 1: successful assignment of type T1
TEST(VectorAssignmentT1, SuccessfulAssignment) {
   std::vector<T1> v1 = boost::assign::list_of (T1(1)) (T1(2)) (T1(3));
   testVectorAssignment(v1);
}

// Test 2: successful assignment of type T2
TEST(VectorAssignmentT2, SuccessfulAssignment) {
   std::vector<T2> v2 = boost::assign::list_of (T2(1)) (T2(2)) (T2(3));
   testVectorAssignment(v2);
}

// Test 3: unsuccessful assignment of type T2
TEST(VectorAssignmentT2, UnsuccessfulAssignment) {
   std::vector<T2> v2 = boost::assign::list_of (T2(1)) (T2(2)) (T2(3));
   // Causes exception in assignment:
   v2[2].causeCopyError = true;
   testVectorAssignment(v2);
}
