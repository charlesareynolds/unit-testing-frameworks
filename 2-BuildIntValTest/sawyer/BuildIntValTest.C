#include <rose.h>

//-----------------------------------------------------------------------------
// ROSE Testing Utilities
//-----------------------------------------------------------------------------
template<typename T>
bool is(SgNode* t){
 return (dynamic_cast<T*>(t) != NULL);
}

static std::string
printIntVal(const SgIntVal *intVal, int expectedValue) {
    std::cerr <<"SgIntVal has unexpected value: got " <<intVal->get_value() <<" but expected " <<expectedValue <<"\n";
    return "unit test failed";
}

//-----------------------------------------------------------------------------
// Unit Tests
//-----------------------------------------------------------------------------

#define check(COND) ASSERT_always_require(COND)
#define check2(COND, MESG) ASSERT_always_require2(COND, MESG)

static void
test_IntVal_default_builder() {
    SgIntVal *intVal = SageBuilder::buildIntVal();
    check(intVal != NULL);
    check(is<SgIntVal>(intVal));
    check(intVal->get_value() == 0);
}

static void
test_IntVal_int_builder(int test_value, int delta = 0) {
    SgIntVal *intVal = SageBuilder::buildIntVal(test_value);
    check(intVal != NULL);
    check(is<SgIntVal>(intVal));
    check2(intVal->get_value() == test_value + delta, printIntVal(intVal, test_value + delta));
}


// Lets pretend that we want to configure the tests from a makefile. For instance, if we were testing some ROSE frontend
// feature we might want to supply various ROSE switches and small input source files, but for this example, lets just take
// zero or one argument. If an argument is specified (assume it's an integer) and it's non-zero, then cause one of your tests
// to fail somehow.
int main(int argc, char *argv[]) {
    int delta = argc > 1 ? strtol(argv[1], NULL, 0) : long(0);

    rose::Diagnostics::initialize();
    test_IntVal_default_builder();

    // These are the values that are most likely to cause failures
    test_IntVal_int_builder(0);
    test_IntVal_int_builder(1);
    test_IntVal_int_builder(-1);
    test_IntVal_int_builder(INT_MAX, delta);
    test_IntVal_int_builder(INT_MIN);
}
