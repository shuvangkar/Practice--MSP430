/*
 * hardwareSerial.c
 *
 *  Created on: Aug 25, 2020
 *      Author: Shuvangkar
 */

#include "hardwareSerial.h"

void str_reverse(char *head);
char *int_to_str(int value, char *buf);

//char *tx_ptr = NULL;

#define BAUD 9600

#if BAUD == 9600
    #define UCA0BR0_VAL     104
    #define UCA0BR1_VAL     0
    #define UCA0MCTL_VAL    UCBRS_1
#elif BAUD == 19200
    #define UCA0BR0_VAL     52
    #define UCA0BR1_VAL     0
    #define UCA0MCTL_VAL    UCBRS_0
#elif BAUD == 38400
    #define UCA0BR0_VAL     26
    #define UCA0BR1_VAL     0
    #define UCA0MCTL_VAL    UCBRS_0
#elif BAUD == 56000
    #define UCA0BR0_VAL     17
    #define UCA0BR1_VAL     0
    #define UCA0MCTL_VAL    UCBRS_7
#elif BAUD == 115200
    #define UCA0BR0_VAL     8
    #define UCA0BR1_VAL     0
    #define UCA0MCTL_VAL    UCBRS_6
#else
    #error BAUD RATE NOT SUPPORTED
#endif


void serial_begin(void)
{
    P1SEL |= BIT1+BIT2;         //PxSEL & PxSEL2 both registers select the pin attribute
    P1SEL2 |= BIT1+BIT2;        //P1.1 = RXD | P1.2 = TXD
    UCA0CTL1 |= UCSWRST;        //USCI logic held in reset state means disabled

    UCA0CTL1 |= UCSSEL_2;       //SMCLK clock source

    UCA0BR0 = UCA0BR0_VAL;      // 104 defined in datasheet for 9600 baudrate while SMCLK is selected
    UCA0BR1 = UCA0BR1_VAL;      //ignore
    UCA0MCTL = UCA0MCTL_VAL;    //modulation stage comes from baud rate table.


    UCA0CTL0 = 0x00;            //ignore
    UCA0CTL1 &= ~UCSWRST;       // Initialize USCI state machine

//    IE2 |= UCA0TXIE;                  // Enable the Transmit interrupt
//    _BIS_SR(GIE);                     // Enable the global interrupt
}
void serial_print(char *str)
{
//    tx_ptr = str;

    while(*str)
    {
        UCA0TXBUF = *str;
        while(UCA0STAT & UCBUSY); //UCBUSY Flag = 1(Transmit/Receive) | 0(Inactive)
        str++;
    }
}


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


void serial_print_int(int var)
{
    char buf[10];
    serial_print(int_to_str(var,buf));
}


//#pragma vector = USCIAB0TX_VECTOR
//__interrupt void TransmitInterrupt(void)
//{
//    UCA0TXBUF = *tx_ptr;
//    tx_ptr ++;
//}

void set_mcu_clock(void)
{
    //Set MCLK = SMCLK = 1MHz
    BCSCTL1 = CALBC1_1MHZ; // Set DCO Clock to 1MHz
    DCOCTL = CALDCO_1MHZ;
}
