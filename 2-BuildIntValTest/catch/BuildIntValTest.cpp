#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include <rose.h>
#include <Sawyer/CommandLine.h>

//-----------------------------------------------------------------------------
// Global test data from CLI
//-----------------------------------------------------------------------------
 // Convenient struct to hold settings from the command-line all in one place.
struct Settings {
    int delta;
    Settings(): delta(0) {}
} gSettings;

Sawyer::CommandLine::ParserResult
parseCommandLine(int argc, char *argv[], Settings &settings) {
  using namespace Sawyer::CommandLine;

  SwitchGroup switches;
  // --delta <arg>
  switches.insert(Switch("delta")
                  .argument("delta", integerParser<int>(settings.delta)));

  Parser parser;
  return parser.with(switches).parse(argc, argv).apply();
}

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

// For each SECTION the TEST_CASE is executed from the start, yielding 15 total assertions (5x3)
TEST_CASE("Instantiation with 1 argument constructor works", "[SageBuilder] [BuildIntVal] [SgIntVal]") {
    int TEST_VALUE;

    SECTION("initialization with 0") {
        TEST_VALUE = 0;
    }
    SECTION("initialization with 1") {
        TEST_VALUE = 1;
    }
    SECTION("initialization with -1") {
        TEST_VALUE = -1;
    }
    SECTION("initialization with INT_MAX") {
        TEST_VALUE = INT_MAX;
    }
    SECTION("initialization with INT_MIN") {
        TEST_VALUE = INT_MIN;
    }

    ::SgIntVal* i = SageBuilder::buildIntVal(TEST_VALUE);

    REQUIRE(i != NULL);
    REQUIRE(is<SgIntVal>(i));
    REQUIRE(i->get_value() == TEST_VALUE + gSettings.delta);
}

int main(int argc, char* argv[]) {
  Sawyer::CommandLine::ParserResult cmdline = parseCommandLine(argc, argv, gSettings);
  std::vector<std::string> catchArgs = cmdline.unreachedArgs();

  Catch::Session session; // There must be exactly once instance
  //int returnCode = session.applyCommandLine(
  //  argc,
  //  const_cast<char const**>( argv ),
  //  Catch::Session::OnUnusedOptions::Ignore);
  //if(returnCode != 0)
  //    return returnCode;

  return session.run();
}
