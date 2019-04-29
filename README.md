# cpp-advanced-course
Sources for the Learn Advanced C++ Udemy Course

## Certificate

<p align="center">
  <img src="https://github.com/LucianoPAlmeida/cpp-advanced-course/blob/master/UC-HGV3N3FJ.jpg" title="Certificate">
</p>

## Important Notes

C++ 11

### LValues and RValue
* A LValue is anything that you can take a reference from. Anything else is RValue.
* Returns of functions are RValues.
* Normally temporary values are RValues. e.g. Expressions, function returns.
* Const LValues refs are able to bind RValues.
* Move constructor and move assign operators are cool.

### Cast 
* **static_cast** Is the simpler type of cast. We uset that instead of C old style cast. It forces the cast and it maybe lead to errors if not used carefully. Is a compile time cast that doesn't do any check in runtime.
* **dynamic_cast** Only works with RTTI(Run time type information) on. Checks at runtime if can cast. 
* **reinterpreter_cast** Do less check than **static_cast** just a binary cast. Less safe cast. 