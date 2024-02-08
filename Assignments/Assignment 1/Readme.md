# Assignment 1: Sequence alignment

## Objectives

* implement a dynamic programming algorithm to find optimal pairwise sequence alignments

* describe difference between global and local alignment algorithms

* calculate the Hamming distance and Levenshtein distance between a pair of sequences.

## Exercises

1. Build the the program global_alignment.c so that an extra line of output is printed between the two aligned sequence, indicating exact matches with the character "|", e.g.

```
AT-CGAT
|| || |
ATACG-T
```
      
2. Modify the program global_alignment.c so that the percent identity between the two sequences is written out.
Add a comment to your program explaining how you have decided to calculate the percent identity.

3. Modify the program global_alignment.c to output the Hamming distance between the aligned sequence strings.

4. Copy the program global_alignment.c to the file local_alignment.c. Modify this program so that it implements the Smith-Waterman algorithm for finding an optimal local alignment.
Test your program with the sequences "PAWHEAE" and "HDAGAWGHEQ". Check your results with the [online program](https://www.cse.chalmers.se/~kemp/cgi-bin/local_alignment.shtml) 


5. Copy the program global_alignment.c to the file levenshtein.c. Modify this program so that it calculates the Levenshtein distance (the edit distance) between the two sequences.

6. Modify the program global_alignment.c (or equivalent) so that it counts the total number of optimal alignments for the two sequences.
Test your program with the sequences "ATTA" and "ATTTTA".

7. Modify the program global_alignment.c so that it writes out all of the optimal alignments for the two sequences.