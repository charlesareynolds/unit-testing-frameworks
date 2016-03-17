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

```bash
$ make check
LD_LIBRARY_PATH=/home/too1/projects/rose/master/pristine/build/../install/lib:/nfs/casc/overture/ROSE/opt/rhel7/x86_64/boost/1_54_0/gcc/4.8.3/lib:/nfs/casc/overture/ROSE/opt/rhel6/x86_64/java/jdk/1.7.0_51/jre/lib/amd64/server ./VectorTests
vector = [ 1 2 3 ]
vector = [ 1 2 3 ]
vector = [ 1 2 3 ]; index 3 is out of bounds
vector = [ 1 2 3 ]; index 3 is out of bounds
vector = [ 1 2 3 ]
vector = [ 1 2 3 ]
vector = [ 1 2 3 ]; index 3 is out of bounds
vector = [ 1 2 3 ]; index 3 is out of bounds
vector = [ 1 2 -1 -1 -1 ]

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
VectorTests is a Catch v1.3.5 host application.
Run with -? for options

-------------------------------------------------------------------------------
vector assignment T2
  unsuccessful assignment
-------------------------------------------------------------------------------
VectorTests.C:51
...............................................................................

VectorTests.C:39: FAILED:
  REQUIRE( destination[i] == T() )
with expansion:
  1 == -1
with message:
  unit test failed

===============================================================================
test cases:  2 | 1 passed | 1 failed
assertions: 10 | 9 passed | 1 failed

make: *** [check] Error 1
```

