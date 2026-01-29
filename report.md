Report for project 1

1. Why Bitwise Operations Work for Arithmetic

1.1 Binary Number Representation
Computers represent integers in binary. For 32-bit signed integers, the two's complement representation is used:
Positive numbers: standard binary representation
Negative numbers: invert all bits and add 1

1.2 Addition 
Addition can be decomposed into 3 parts:
(1) XOR (^): Computes the sum without considering carry bits
(2) AND (&) + Left Shift (<<): Computes the carry bits
(3) Repeat until no more carry

1.3 Subtraction
Using the two's complement identity:
a - b = a + (-b) = a + (~b + 1)

1.4 Multiplication
Multiplication is implemented as repeated addition with left shifts:
For each bit position where b has a 1, add (a << position) to the result

1.5 Division
Using binary long division:
Process dividend bit by bit from MSB to LSB 
Build up the quotient by checking if the divisor fits into the current remainder

2. Solution for arithematic operations & 3. Difficulties Encountered and Solutions

2.1 Add Function
The first challenge was the main algorithm applied to use bitwise operators and logical operators to implement addition. The main thought is to separate the addition process into 2 parts: sum without carry （using ^）and carry part (using & and <<) and add the sum without carry part and carry part repeatedly until the carry part is 0. I asked AI for help to get the solution finally.
Another challenge was implementing add without control flow. Since we cannot use loops in "add()", I unrolled the loop 32 times (maximum iterations needed for 32-bit integers).
It's important to use the function "static_cast<uint32_t>()" to transfer (a & b) to unsigned integer to avoid leftshifting negative numbers that may cause error. This is also a reminder from AI.

2.2 Subtract Function
Built upon "add()" by computing the two's complement negation:
(1) Compute '~b'
(2) Add 1 using add function
(3) Add the result to 'a' using add function as well

2.3 Multiply Function

(1)Extract signs and compute absolute values 
(2) Use shift-and-add algorithm on the absolute values with a loop
(3) Apply the final sign(by XOR of the 2 sign)

difficulties:Handling Negative Numbers
We must correctly handle negative numbers and produce results matching C++ behavior.
To get the sign, we can extract sign bit using '>> 31'
Then, convert to absolute values using 'add(~a, 1)'


2.4 Divide Function
The algorithm itself is difficult to implement using bitwise operators, so I asked AI for help. The most difficult part of the algorithm is to judge whether remainder >= divisor without using comparison operators. The thoughts are as follows:
(1) Extract signs and compute absolute values
(2) Process 32 bits from MSB to LSB
(3) For each bit, check if divisor fits into current remainder
(4) Apply the final sign

2.5 Modulo Function
Using the mathematical identity:
a % b = a - (a / b) * b 
With the add(), subtract(), multiplication() and division() methods written before, it can be handled easily

4. Time Complexity 
Function: add() Time complexity: O(1) Explanation: Fixed 32 iterations (unrolled) 
Function: subtract() Time complexity: O(1) Explanation: Fixed iterations for negation + O(1) add 
Function: multiply() Time complexity: O(n) Explanation: n = 32 bits, one loop iteration per bit 
Function: divide() Time complexity: O(n) Explanation: n = 32 bits, one loop iteration per bit 
Function: modulo() Time complexity: O(n) Explanation: One divide + one multiply + one subtract 

5. Thoughts on Unit Testing

Unit testing is crucial because bitwise operations are prone to edge-case errors that might not appear in standard inputs. I realized that testing simple cases like add(2, 3) is not enough. Effective testing must cover Boundary Values (Edge Cases), such as:
(1)0，since operations involving 0 often trigger special logic.
(2)INT_MAX / INT_MIN, since these are critical for verifying overflow behavior and sign bit handling.
(3)Negative Numbers, which verifies that arithmetic shifts and two's complement logic work correctly for negative inputs.
The approach to verifying the correctness of my functions was to compare them against the native C++ arithmetic operators. This ensures that my bitwise implementation perfectly mimics the hardware behavior abstracted by the C++ language.

6. Additional thoughts
This project demonstrates that all arithmetic operations fundamentally reduce to bit manipulation, which is how hardware ALUs actually work. Understanding this connection between high-level operations and low-level implementation is valuable for computer architecture knowledge.

Usage of LLM: 
1. the thought of addition using bitwise operators
2. the algorithm of division and the code to implement it
3. the usage of the function "static_cast<uint32_t>()"

The conversation with AI is in the AI_conversation file in the AI_conversation folder