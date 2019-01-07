#include <stdio.h>
#include <stdlib.h>

char *method1(int value) {
    int number = value;
    char *result;
    int position = 0;
    int sig = 0;

    result = malloc( 65 * sizeof(char) );

    int bit = 1 << 30;  /* Shift a 1 into the 64th bit position */
    while ( bit != 0 ) {
        if ( number & bit ) {
            result[position++] = '1';
            sig = 1;
        } else {
            if ( sig ) {
                result[position++] = '0';
            }
        }
        bit = bit >> 1;
    }
    result[position] = 0;

    return result;
}

char *method2(int value) {
    int number = value;
    char *result;
    int resultTbl[64];
    int position = 0;
    int resposition = 0;

    result = malloc( 65 * sizeof(char) );

    while ( number != 0 ) {
        if ( number % 2 == 1 ) {
            resultTbl[position++] = 1;
        } else {
            resultTbl[position++] = 0;
        }
        number = number / 2;
    }

    for( int i = position - 1; i >= 0; i-- ) {
        result[resposition++] = ( resultTbl[i] == 1 ? '1' : '0' );
    }
    result[resposition] = 0;

    return result;
}


int main(int argc, char **argv) {
    printf( "method1: 5 = %s, 1023 = %s\n", method1( 5 ), method1( 1023 ));
    printf( "method2: 5 = %s, 1023 = %s\n", method2( 5 ), method2( 1023 ));

    return 0;
}
