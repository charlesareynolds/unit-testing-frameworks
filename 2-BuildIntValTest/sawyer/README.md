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
```

Typical of unix programs: no output since all the tests pass.

When run with a non-zero command-line option we get a failure:
```bash
$ make TEST_ARG=1 check
SgIntVal has unexpected value: got 2147483647 but expected -2147483648
BuildIntValTest[62774] 0.00119s rose[FATAL]: assertion failed:
BuildIntValTest[62774] 0.00147s rose[FATAL]:   BuildIntValTest.cpp:37
BuildIntValTest[62774] 0.00169s rose[FATAL]:   void test_IntVal_int_builder(int, int)
BuildIntValTest[62774] 0.00206s rose[FATAL]:   required: intVal->get_value() == test_value + delta
BuildIntValTest[62774] 0.00250s rose[FATAL]:   unit test failed
```
