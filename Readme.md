The Program Takes a Value of N, Number of String in the first Line.
We have to input the number of strings in N.
From the Second Line we have to take N number of inputs in different lines as Strings.
After execution the Largest and Second Largest Compund Strings will be given as Output.

We ar using Trie Data Structure for storing all the strings. The Complexity for storing and validating each string is O(N), thus on iterating all strings will result in overall Complexity if O(N^2) in Worst Case. We are storing all the valid strings in a Vector, and Sorting it in Descending Order with respect to Size.

After that we are simply taking two string from the vector as Answer.
