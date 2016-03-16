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

Oomitting noise from "make" itself...

```bash
$ make check
vector = [ 1 2 -1 -1 -1 ]; vector[0] = 1
vector = [ 1 2 3 ]; vector[0] = 1
VectorTests[23419] 0.00098s rose[FATAL]: assertion failed:
VectorTests[23419] 0.00126s rose[FATAL]:   VectorTests.C:35
VectorTests[23419] 0.00144s rose[FATAL]:   void testVectorAssignment(const std::vector<Value>&) [with T = VectorUnitTest::T2]
VectorTests[23419] 0.00218s rose[FATAL]:   required: destination[i] == T()
VectorTests[23419] 0.00249s rose[FATAL]:   unit test failed
```

(The lines starting with "VectorTests" are red up to the first colon when emitted to a tty.)
