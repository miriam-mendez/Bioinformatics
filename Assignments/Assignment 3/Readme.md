# Assignment 3: Main chain modelling

## Background
A high resolution X-ray crystallography experiment can give "a set of free atoms that reproduce the density well" (Morris et al. 2002). The set of free atoms can be represented by a set of 3-D coordinates, which are the centres of the heavy atoms (the carbon, nitrogen, oxygen and sulphur atoms) in a protein, but the identities of the atoms are initially unknown (i.e. we don't initially know the element type of each atom, and we don't know which residue each atom belongs to).

A useful first step in interpreting the free atoms is to try to identify a subset of the free atoms that can be assigned to be the alpha-carbons in a protein's main chain. In doing this, we can use the fact that the centres of consecutive alpha-carbon atoms are about 3.8 Å apart.

## Exercises

Write programs that can read the coordinates of a set of free atoms from a file, and then identify the order of alpha-carbon atoms in the chain.

1. Start with a simple case, where all of the free atoms in the input file are alpha-carbon atoms, and we just need to figure out their order in the chain. The direction of the chain doesn't matter (we have no way of knowing whether the chain of alpha-carbons that we find is in the direction from the N-terminal to the C-terminal, or in the reverse direction).

    Regarding how much the distance between consecutive alpha-carbon atoms can vary from 3.8 Å, you can choose your own value for this. As a guide, you could write a program to print out values for distances between consecutive alpha-carbon atoms, or their difference from 3.8 Å, to see what values are typical.

    Test your program with files [test_q1.txt](./test_q1.txt) and [data_q1.txt](./data_q1.txt). Each line of these files contains an atom serial number followed by the x-, y- and z-coordinates of a free atom.

    Running your program on file test_q1.txt should give the following output (or the same sequence in reverse):

    ```
        8
        10
        9
        7
        6
        5
        3
        1
        4
        2
    ```

    When you submit your solution, please include the output for file test_q1.txt and file data_q1.txt.

2. Now consider a data file where only some of the free atoms in the input file are alpha-carbon atoms. Find the longest chain of candidate alpha-carbon atoms. For this exercise, the direction of the chain doesn't matter (that is, it doesn't mater if the candidate alpha-carbon atoms in the output are listed in the direction from the N-terminal to the C-terminal, or in the reverse direction).

    Test your program with file [data_q2.txt](./data_q2.txt). Each line of that file contains an atom serial number followed by the x-, y- and z-coordinates of a free atom.

    The "correct" output for this data file should have between 40 and 50 residues. If you find more than 50 residues, it is likely that your program is working "correctly", and is finding a feasible chain of free atoms that is even longer than the chain of "true" alpha-carbon atoms. This could give a good grade, but it could be possible to improve the solution further. In the referenced paper, the authors look for other main chain atoms in the peptide plane between two candidate alpha-carbons (Figure 2). Another approach would be to consider the "pseudo-valence angles" defined by three consecutive alpha-carbon atoms (Section 2.5 of the referenced paper). As a guide, you could write a program to print out values for angles defined by three consecutive alpha-carbon atoms to see what values are typical.

    (The program described by Morris et al. does much more than you are expected to do in this exercise. You might get some inspiration from looking at their paper, but you are not expected to implement everything that they did!)