# Compute Statistics

Intention of this code is to compute statistics on a sequence of human temperature measurements.

This project uses the
[gtest framework](http://google.github.io/googletest/reference/assertions.html)
to test functionality.

## Pass the tests

The code is not complete and doesn't even compile.
See the results of compilation and execution in the GitHub 'Actions' tab.

Recognize the intention of the code by reading the tests.
Design the return type in the code.

You can modify the existing code. Or you could make new tests and code, while keeping the intent.

Take care not to leave behind any compiler warnings in your solution.

## Optional activities

1. Complete the test to handle empty input and implement it
2. Mistake-proofing: The input is an array of temperature values in Fahrenheit. However, a caller can pass the values in a different unit like Celsius. How far "left" can you handle this?
    - Unit test
    - Name the variables, such that an LLM would auto-complete with conversion code
    - Use specific types to show "red squiggles" when this happens
    - Any other method?
3. Add any other tests you can think of.

## Discussion

What's `epsilon` doing in the test? If _you_ had to choose its value, what would it be?
