/*----------------------------------------------------------
 *				HTBLA-Leonding / Class
 * ---------------------------------------------------------
 * Exercise digitber: 0
 * Title:			deletable_primes.c
 * Author:			P. Bauer
 * Due Date:		October 16, 2012
 * ----------------------------------------------------------
 * Description:
 * Implementation of deletable_primes.h.
 * ----------------------------------------------------------
 */
#include "deletable_primes.h"
#include <math.h>


  unsigned long remove_digit(int digit, unsigned long number) {
    unsigned long left = 0 ;
    double total = 0;
    double right = 0;
    if (digit == 0) {
      return number / 10;
    }
    left = number / pow(10, digit + 1);
    right = number % (unsigned long)pow(10, digit);
    total = left * pow(10, digit) + right;
    return total;
  }

  int get_ways(unsigned long number) {
    int length = 0;
    for (int i = 0; i < get_length(number); i++) {
      if (get_length(number) == 1) {
        if (is_prime(number) == true) {
          return 1;
        }
        return 0;
      }
      else if (is_prime(remove_digit(i, number))) {
        length += get_ways(remove_digit(i, number));
      }
    }
    return length;
  }

  int get_length(unsigned long number) {
   unsigned long length = 0;
   unsigned long copied = number;
   if (number < 10) {
     return 1;
   }
   while (copied != 0) {
     copied = copied / 10;
     length++;
   }
   return length;
 }

 bool is_prime(unsigned long number) {
   if (number == 1) {
     return false;
   }
   unsigned long copied = number;
   for (unsigned long i = 2; i <= sqrt(number); i++) {
     if (copied % i == 0) {
       return false;
     }
   }
   return true;
 }
