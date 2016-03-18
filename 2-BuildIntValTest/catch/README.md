## Build the tests

```bash
$ make 
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

### Passing test

```bash
$ make check
LD_LIBRARY_PATH=/home/too1/projects/rose/master/pristine/build/../install/lib:/nfs/casc/overture/ROSE/opt/rhel7/x86_64/boost/1_54_0/gcc/4.8.3/lib:/nfs/casc/overture/ROSE/opt/rhel6/x86_64/java/jdk/1.7.0_51/jre/lib/amd64/server ./BuildIntValTest 
===============================================================================
All tests passed (18 assertions in 2 test cases)
```

### Failing test

```bash
$ make TEST_ARG="--delta 1" check
LD_LIBRARY_PATH=/home/too1/projects/rose/master/pristine/build/../install/lib:/nfs/casc/overture/ROSE/opt/rhel7/x86_64/boost/1_54_0/gcc/4.8.3/lib:/nfs/casc/overture/ROSE/opt/rhel6/x86_64/java/jdk/1.7.0_51/jre/lib/amd64/server ./BuildIntValTest --delta 1

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 is a Catch v1.3.5 host application.
Run with -? for options

-------------------------------------------------------------------------------
Instantiation with 1 argument constructor works
-------------------------------------------------------------------------------
BuildIntValTest.cpp:36
...............................................................................

BuildIntValTest.cpp:59: FAILED:
  REQUIRE( i->get_value() == TEST_VALUE + gSettings.delta )
with expansion:
  0 == 1

-------------------------------------------------------------------------------
Instantiation with 1 argument constructor works
-------------------------------------------------------------------------------
BuildIntValTest.cpp:36
...............................................................................

BuildIntValTest.cpp:59: FAILED:
  REQUIRE( i->get_value() == TEST_VALUE + gSettings.delta )
with expansion:
  1 == 2

-------------------------------------------------------------------------------
Instantiation with 1 argument constructor works
-------------------------------------------------------------------------------
BuildIntValTest.cpp:36
...............................................................................

BuildIntValTest.cpp:59: FAILED:
  REQUIRE( i->get_value() == TEST_VALUE + gSettings.delta )
with expansion:
  -1 == 0

-------------------------------------------------------------------------------
Instantiation with 1 argument constructor works
-------------------------------------------------------------------------------
BuildIntValTest.cpp:36
...............................................................................

BuildIntValTest.cpp:59: FAILED:
  REQUIRE( i->get_value() == TEST_VALUE + gSettings.delta )
with expansion:
  2147483647 (0x7fffffff) == -2147483648

-------------------------------------------------------------------------------
Instantiation with 1 argument constructor works
-------------------------------------------------------------------------------
BuildIntValTest.cpp:36
...............................................................................

BuildIntValTest.cpp:59: FAILED:
  REQUIRE( i->get_value() == TEST_VALUE + gSettings.delta )
with expansion:
  -2147483648 == -2147483647

===============================================================================
test cases:  2 |  1 passed | 1 failed
assertions: 18 | 13 passed | 5 failed

make: *** [check] Error 5
```

