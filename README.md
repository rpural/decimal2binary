# decimal2binary
Examples of converting a decimal number to its binary representation in various  languages.
No language-specific optimizations have been done. Each implementation is the same two
methods, and should be easily compared to one another.

The two methods demonstrated here are:
1.  Using a bit mask to expose each bit individually in turn, producing the binary value.
2.  Dividing the value by 2 and capturing the remainder, generating a reversed list of
the binary digits. Returning this list, first reversed, produces the binary value.

The current languages represented are:
*  C
*  Python
*  Perl
