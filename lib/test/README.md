# Testing
This test suite is built around nothing but return codes.
It is the most minimal test suite one can have, which makes it
the most lightweight, the easiest to learn, and the most natural.
No big messy frameworks to deal with. Though this also means it
is lacking certain features (such as mocking) which exist in bigger
frameworks.

## Creating a test.
To add a test to the test suite, simply follow these steps

1. Write the test, see the section on writing tests below
2. Add the test to Makefile.am, see the section below on how to add it.

That is all. Your test will now run with `make check`

## Writing a test
To write a test, there is no framework or reference manual
that you need to adhere to. Just write your test with normal
C or C++ code as you would any other code. You may log any
interesting information with printf, and you flag a test
failure by returning a non-zero value from main. Or by calling
`exit` with a non-zero value. It's that simple.

You may use the built in `assert` to make test assertions.

### Test Organization
A good way to organize tests is to write each test case
as a function, and use main() as the test harness.

A basic example:

```
#include <cassert>

void test_1() {
    // First test case
    assert(1 == 1);
}

void test_2() {
    // Second test case
    assert(1 == 0);
}

int main () {
    test_1();
    test_2();
}
```

## Adding the test to Makefile.am
In makefile.am there is a line `check_PROGRAMS = ...`
Add the name of your test program here. For example

```
target_dir = compiled
check_PROGRAMS = $(target_dir)/test_example ...
```

Next create a line called `test_example_SOURCES = your_test_file.cpp`.
the prefix `compiled_<prefix>_SOURCES` must match the name you added to
`check_PROGRAMS`. After the `=` sign you specify the cpp files that
make up your test.

```
compiled_test_example_SOURCES = test_example.cpp ../Example.cpp
```

## Running tests
`make check`

