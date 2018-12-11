/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * Name: Bugvi Benjamin Magnussen
 * Userid: Group70
 * Studentid: 14777
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */

#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/* 
 * thirdBits - return word with every third bit (starting from the LSB) set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void) {
  /*A simple build up approach using shifts and addition*/
  int x1 = 0x49;
  int x2 = (x1 << 9);
  int x3 = x1 + x2;
  int x4 = (x3 << 18);
  return x3 + x4;
}
/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {
  /*Utilising the fact that XOR'ing a bit sequence with another will yield 0 if they are the same*/
  int mask = (0x55 << 24) + (0x55 << 16) + (0x55 << 8) + 0x55; //even bits mask
  int result = (x & mask) ^ mask; // using and to isolate even bits and the XOR
  return !result; 
}
/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
  /* Identifying how many bits to shift to the left.
   * Then shifting c to the appropriate position.
   * Then building a mask with all bits set to 1 except for the byte in the
   * position to be replaced, which has its bits set to 0 .
   * x & mask will set all bits in the byte to be replaced in x to 0
   * x | replShift will replace the now empty byte in x with c.
   */
  int num_Of_Bits_to_Shift = (n << 3);
  int replShift = (c << num_Of_Bits_to_Shift);
  int mask = ~(0xFF << num_Of_Bits_to_Shift);
  x &= mask;
  x |= replShift;
  return x;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  /*
   * First we build the masks that are needed for the Hamming weight calculation.
   * Then we apply those masks while calculating the Hamming weight of the int.
   */
  int mask = (0x11 << 24) + (0x11 << 16) + (0x11 << 8) + 0x11;
  int mask1 = mask + (mask << 2);
  int mask2 = mask + (mask << 1);
  int mask3 = (0x0F << 24) + (0x0F << 16) + (0x0F << 8) + 0x0F;
  int mask4 = (0xFF << 16) + 0xFF;
  int mask5 = (0xFF << 8) + 0xFF;;

  // Calculating the Hamming weight
  x = (x & mask1) + ((x >> 1) & mask1);
  x = (x & mask2) + ((x >> 2) & mask2);
  x = (x & mask3) + ((x >> 4) & mask3);
  x = (x & mask4) + ((x >> 8) & mask4);
  x = (x & mask5) + ((x >> 16) & mask5);

  return x;
}

/* 
 * fitsShort - return 1 if x can be represented as a 
 *   16-bit, two's complement integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x) {
  /* First shift 15 to the right.
   * If x fits in a short, then the shifted x will be a  bit sequences consisting of 
   * only 1's or only 0's. 
   * We add one. By doing this, we will either have only 0's or 0's followed by a single 1 bit in the 
   * least significant position.
   * Then we negate the shifted x and the shifted x with 1 added. If one of these is zero, the result
   * will be true and x fits in a short.
   */
  int a = (x >> 15);
  int b = a + 0x01;
  int c = !b | !a;
  return c;
}
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
  /*
   * We shift x one to the left in order to focus on the other bits.
   * We then convert the rest to a boolean. This will result in either a value of 0 or of 1
   * We then shift x 31 to the right. This will either result in a sequence of 0's or 1's.
   * Finally we OR the result, which will lead to either 0, 1 or -1 being returned. 
   * If x was negative then we get -1 on the left side of the OR. If x was 0 then we have 0 | 0 
   * Finally, if x was positive we have 0 | 1 -> 1 . 
   */
  int left_shift = (x << 1);
  int rest = !!left_shift;
  int sign = (x >> 31);
  int result = sign | rest;
  return result;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  /*
   * First we isolate the signs of x and y.
   * We then calculate if their signs are the same by using XOR and a boolean cast.
   * In order to avoid so called edge cases, we check whether x and why have different sign bits
   * and whether x is negative. If that is the case, then x is smaller than y. 
   * Then we calculate the difference between x and y. Then we cast to a boolean in order
   * to find out if the difference is positive or negative.
   * 
   */
  int xSign = (x>>31);
  int ySign = (y>>31);
  int same_sign = !(xSign^ySign);
  int xSmallerThanY = (!same_sign) & xSign;
  int difference = y + (~x + 1);
  int posOrEq = !(difference >> 31);
  return xSmallerThanY | (same_sign & posOrEq);
}
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {
  /*
   * First, we figure out if the sign bit of x is positive or negative.
   * We then calculate (x-1), in order to exploit the fact that x & (x-1)
   * can tell us if x is a power of two. 
   * An edge case is if x is 0. We therefore cast x to a boolean in order to check for this in the
   * final result.
   * Finally, we return a large AND expression, where we assert that x is not zero, x has 0 as sign bit,
   * and that x & (x-1) returns 0 .
   */
  int posSign = !(x >> 31);
  int subtract = x + (~1 + 1);
  int isZero = !x;
  return (!isZero) & posSign & !(x & subtract);
  
}
