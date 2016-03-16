## Build the tests

```bash
$ make -j2
```

## Run the tests

```bash
$ make check
```

## Cleanup

```bash
$ make clean
```

## Example Output

```bash
$ make check
./VectorAssignmentTestPass
===============================================================================
All tests passed (7 assertions in 1 test case)

./VectorAssignmentTestFail

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
VectorAssignmentTestFail is a Catch v1.3.5 host application.
Run with -? for options

-------------------------------------------------------------------------------
vector assignment is successful
  std::vector<int> assignment
-------------------------------------------------------------------------------
VectorAssignmentTestFail.cpp:44
...............................................................................

VectorAssignmentTestFail.cpp:38: FAILED:
  REQUIRE( v1.size() == 5 )
with expansion:
  3 == 5

-------------------------------------------------------------------------------
vector assignment is successful
  std::vector<char> assignment
-------------------------------------------------------------------------------
VectorAssignmentTestFail.cpp:44
...............................................................................

VectorAssignmentTestFail.cpp:38: FAILED:
  REQUIRE( v1.size() == 5 )
with expansion:
  2 == 5

===============================================================================
test cases: 1 | 1 failed
assertions: 9 | 7 passed | 2 failed

make: *** [check] Error 2
```

