# uva10008
What's Cryptanalysis?

Cryptanalysis is the process of breaking someone else’s cryptographic writing. This sometimes involves
some kind of statistical analysis of a passage of (encrypted) text. Your task is to write a program which
performs a simple analysis of a given text.

# Input
The first line of input contains a single positive decimal integer n. This is the number of lines which
follow in the input. The next n lines will contain zero or more characters (possibly including whitespace).
This is the text which must be analyzed.

# Output
Each line of output contains a single uppercase letter, followed by a single space, then followed by a
positive decimal integer. The integer indicates how many times the corresponding letter appears in
the input text. Upper and lower case letters in the input are to be considered the same. No other
characters must be counted. The output must be sorted in descending count order; that is, the most
frequent letter is on the first output line, and the last line of output indicates the least frequent letter.
If two letters have the same frequency, then the letter which comes first in the alphabet must appear
first in the output. If a letter does not appear in the text, then that letter must not appear in the
output.
