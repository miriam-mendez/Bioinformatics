/*
 * To compile this C program, placing the executable file in 'global', type:
 *
 *      gcc -o levenshtein levenshtein.c
 *
 * To run the program, type:
 *
 *      ./levenshtein
 */

#include <stdio.h>

#define MAX_LENGTH	100


int min(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

int main()
{ 
	int	i, j;
	int	m, n;
	int	 cost;
	char	X[MAX_LENGTH+1] = "KITTEN";

	char	Y[MAX_LENGTH+1] = "SITTING";

    int D[MAX_LENGTH+1][MAX_LENGTH+1]; /* distance matrix */

	/*
	 * Find lengths of (null-terminated) strings X and Y
	 */
	m = 0;
	n = 0;
	while ( X[m] != 0 ) {
		m++;
	}
	while ( Y[n] != 0 ) {
		n++;
	}


	/*
	 * Initialise matrices
	 */

    D[0][0] = 0;
	for ( i=1 ; i<=m ; i++ ) {
        D[i][0] = i;
	}
	for ( j=1 ; j<=n ; j++ ) {
        D[0][j] = j;
	}


 	/*
	 * Fill matrices
	 */

	for ( i=1 ; i<=m ; i++ ) {

		for ( j=1 ; j<=n ; j++ ) {
	
            cost = (X[i-1] == Y[j-1]) ? 0 : 1;
            D[i][j] = min(D[i-1][j] + 1, D[i][j-1] + 1, D[i-1][j-1] + cost);
 		}
	}



    // Question 5 - calculate the levenshtein distance (between the aligned sequence strings)
    for (i = 0; i < m; ++i) {
        printf("%c",X[i]);
    }
    printf("\n");
    for (i = 0; i < n; ++i) {
        printf("%c",Y[i]);
    }
    printf("\n");
    printf("\n");
	printf("Levenshtein Distance : %d\n", D[m][n]);

    return(1);
}
