## Unit Testing Frameworks

This project contains a number of demo unit testing workspaces in order to perform an apples-to-apples comparison of different unit testing frameworks.

Each unit testing workspace consists of a number of subdirectories, one for each framework being compared. Each framework's workspace contains a `README` file and a `Makefile` with targets `make`, `make check`, and `make clean`:

```bash
$ cd <#-TestDirectory>/
$ cd <unit-testing-framework-directory>/

$ make
$ make check
$ make clean
```

*Note*: `ROSE_HOME` must be set to the directory where you installed ROSE. In other words, the path used during ROSE configuration: `ROSE/configure --prefix=/path/for/your/rose/installation`.

