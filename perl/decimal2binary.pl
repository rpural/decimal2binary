#! /usr/bin/env perl

use strict; 
use warnings;

# Convert a decimal number into binary

sub method1 {
    (my $number) = @_;
    my $bit = 1 << 30;
    my $sig = 0;
    my $result = "";

    while ( $bit != 0 ) {
        if ( ( $number & $bit ) != 0 ) {
            $result .= "1";
            $sig = 1;
        } else {
            if ( $sig == 1 ) {
                $result .= "0";
            }
        }
        $bit >>= 1;
    }
    return $result;
}


sub method2 {
    (my $number) = @_;
    my @resultTbl;

    while ( $number != 0 ) {
        if ( $number % 2 == 1 ) {
            push @resultTbl, 1;
        } else {
            push @resultTbl, 0;
        }
        $number = int( $number / 2 );
    }

    my $result = "";

    while ( @resultTbl > 0 ) {
        $result .= pop( @resultTbl );
    }

    return $result;
}

my $result1 = method1(5);
my $result2 = method1(1023);
print( "method 1: 5 = $result1, 1023 = $result2\n" );

$result1 = method2(5);
$result2 = method2(1023);
print( "method 2: 5 = $result1, 1023 = $result2\n" );
