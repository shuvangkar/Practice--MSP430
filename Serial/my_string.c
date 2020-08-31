/*
 * my_string.c
 *
 *  Created on: Aug 26, 2020
 *      Author: Shuvangkar
 */

#include "my_string.h"

void str_reverse(char *head)
{
  if (!head) return;
  char *tail = head;
  while(*tail) ++tail;  // find the 0 terminator, like head+strlen
  --tail;               // tail points to the last real char

  char h;
  char t;
  for( ; head < tail; ++head, --tail) {
      // walk pointers inwards until they meet or cross in the middle
      h = *head;
      t = *tail;
      *head = t;           // swapping
      *tail = h;
  }
}

char *int_to_str(int value, char *buf)
{
    int num = abs(value);
    char *bufPtr = buf;
    while(num>0)
    {
        int mod = num%10;
        *bufPtr = mod+'0';
        bufPtr++;
        num = num/10;
    }
    if(value<0)
    {
        *bufPtr = '-';
        bufPtr++;
    }
    *bufPtr = '\0';
    str_reverse(buf);

    return buf;
}


