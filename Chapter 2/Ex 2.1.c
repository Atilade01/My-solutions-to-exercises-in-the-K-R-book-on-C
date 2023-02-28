/* QUESTION – Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned, by printing appropriate values from standard headers and by direct computation. 
/* Harder if you compute them: determine the ranges of the various floating-point types. */
/* This program contains the direct computation */

#include <stdio.h>
#include <math.h>

#define BITS_CHAR 8
#define BITS_INT 32
#define BITS_FLOAT 32
#define BITS_DOUBLE 64

int main() 
{
    int uRangeLowest = 0;  /* lowest range for unsigned ints and unsigned floats */

    /* Note that the highest range for unsigned datatypes is pow(2, n-1), where n is the bitsize of the datatype. */
    /* For instance, an int is represented as 4 bytes on a computer. That means n will be 8 bits in 4 places, since n is expressed in bits rather than bytes */
    /* However, we will not use this information in our program */
    
    /* Below is declarations for signed values */
    /* For char */
    double sRangeLowestC = (-1 * pow(2, BITS_CHAR-1)); /* lowest range for signed char */
    double sRangeHighestC = (pow(2, BITS_CHAR-1) - 1); /* highest range for signed char */
    
    /* For int */
    double sRangeLowestI = (-1 * pow(2, BITS_INT-1)); /* lowest range for signed int */
    double sRangeHighestI = (pow(2, BITS_INT-1) - 1); /* highest range for signed int */
    
     /* For float */
    double sRangeLowestF = (-1 * pow(2, BITS_FLOAT-1)); /* lowest range for signed float */
    double sRangeHighestF = (pow(2, BITS_FLOAT-1) - 1); /* highest range for signed float */
    
     /* For double */
    double sRangeLowestD = (-1 * pow(2, BITS_DOUBLE-1)); /* lowest range for signed double */
    double sRangeHighestD = (pow(2, BITS_DOUBLE-1) - 1); /* highest range for signed double */

    /* Now, printing the ranges to stdout using 'printf' */

    /* For unsigned datatypes */
    printf("The range of values for unsigned datatypes are: \n");
    printf("DATATYPE\tMINIMUM\t\t\tMAXIMUM\n");
    printf("Char\t\t%d \t\t\t%3.0f \n", uRangeLowest, pow(2, BITS_CHAR));
    printf("Int \t\t%d \t\t\t%3.0f \n", uRangeLowest, pow(2, BITS_INT));
    printf("Float\t\t%d \t\t\t%3.0f \n", uRangeLowest, pow(2, BITS_FLOAT));
    printf("Double\t\t%d \t\t\t%3.0f \n\n", uRangeLowest, pow(2, BITS_DOUBLE));
    
    /* For signed datatypes */
    printf("\n\nThe range of values for signed datatypes are: \n");
    printf("DATATYPE\tMINIMUM\t\t\tMAXIMUM\n");
    printf("Char\t\t%3.0f \t\t\t%3.0f \n", sRangeLowestC, sRangeHighestC);
    printf("Int \t\t%3.0f \t\t%3.0f \n", sRangeLowestI, sRangeHighestI);
    printf("Float\t\t%3.0f \t\t%3.0f \n", sRangeLowestF, sRangeHighestF);
    printf("Double\t\t%3.0lf \t%3.0lf \n", sRangeLowestD, sRangeHighestD);
    
    return 0;
}
