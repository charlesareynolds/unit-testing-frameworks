#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include <rose.h>

//-----------------------------------------------------------------------------
// ROSE Testing Utilities
//-----------------------------------------------------------------------------
template<typename T>
bool is(SgNode* t){
 return (dynamic_cast<T*>(t) != NULL);
}

//-----------------------------------------------------------------------------
// Unit Tests
//-----------------------------------------------------------------------------
TEST_CASE("Instantiation with default 0 argument constructor works", "[SageBuilder] [BuildIntVal] [SgIntVal]") {
    ::SgIntVal* i = SageBuilder::buildIntVal();

    REQUIRE( i != NULL );
    REQUIRE( is<SgIntVal>(i) );
    REQUIRE( i->get_value() == 0 );
}

TEST_CASE("Instantiation with 1 argument constructor works", "[SageBuilder] [BuildIntVal] [SgIntVal]") {
    const int TEST_VALUE = 222;
    ::SgIntVal* i = SageBuilder::buildIntVal(TEST_VALUE);

    REQUIRE( i != NULL );
    REQUIRE( is<SgIntVal>(i) );
    REQUIRE( i->get_value() == TEST_VALUE );
}

