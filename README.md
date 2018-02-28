# Symantec-Project1

Symcode is a binary-to-txt decoding scheme, representing binary data ascii strings.
Symcode uses a radix-8 representation, with each character representing 3 bits of data.

The Symcode index table is		
0 1 2 3 4 5 6 7 
s y m a n t e c

This program reads a given input file, and produces an output file for which each line of output is the Symcoded representation.

For example, the word “gimble” is represented by the hexadecimal ascii string:
0x67 0x69 0x6d 0x62 0x6c 0x65
Next, Sub-dividing the bytes into 3-bit blocks, then applying the encoding from the above index table.
At last, Pad the trailing zeros with dollar signs ‘$’ 
