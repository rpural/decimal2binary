#! /usr/bin/env python3

''' decimal2binary.py

Convert a positive decimal number to binary, demonstrating two separate 
methods of doing so: Method 1 uses bit masking to interogate each bit, and
method 2 uses modulo division to isolate each bit, which produces a list
in reverse of the desired order, so it reverses the list and returns the value.
'''

def method1(value):
    result = ""
    bit = 1 << 64
    number = value
    sig = False

    while bit != 0:
        if number & bit != 0:
            result = result + "1"
            sig = True
        else:
            if sig:
                result = result + "0"
        bit = bit >> 1

    return result


def method2(value):
    resultTbl = []
    number = value

    while number > 0:
        resultTbl.append( number % 2 )
        number = number // 2

    result = ""
    while len( resultTbl ) > 0:
        result = result + str( resultTbl.pop() )

    return result


print("method 1: {} = {}, {} = {}".format(5, method1(5), 1023, method1(1023)))
print("method 2: {} = {}, {} = {}".format(5, method2(5), 1023, method2(1023)))

