# QFixedSizeMatrix
Some C++11 optimization/template tests

I just finished a training about test driven development and wanted to test it quickly with a very small project.

I was trying to implement an array like container with helper functions to rotate it (maybe useful in some chess/tetris game?)
At first I wrote the interface and did not implement any of the provided api.
Next I wrote the test cases and after all that I started implementing all methods until all tests succeeded.
Looks like it worked nicely.

![Screenshot of the succeeding tests](https://raw.githubusercontent.com/0xFEEDC0DE64/QFixedSizeMatrix/master/tests.png)

I also wanted to know more about templated classes and functions and about their performance at runtime.
Looks like the compiler removes all my function calls and just places the resulting integers into the executable:

[Example on godbolt](https://godbolt.org/g/JheVzi)
