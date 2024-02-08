/*
 * To compile this C program, placing the executable file in 'global', type:
 *
 *      gcc -o local local_alignment.c
 *
 * To run the program, type:
 *
 *      ./local
 */

#include <stdio.h>

#define MAX_LENGTH	100

#define MATCH_SCORE	2
#define MISMATCH_SCORE	-1
#define GAP_PENALTY	2

#define STOP		0
#define UP		1
#define LEFT		2
#define DIAG		3


int main()
{ 
	int	i, j;
	int	m, n;
	int	alignmentLength, score, tmp;
	char	X[MAX_LENGTH+1] = "ACGATAGCGAAACCAAAA";

	char	Y[MAX_LENGTH+1] = "CACGTAGCCGATGTC";

	int	F[MAX_LENGTH+1][MAX_LENGTH+1];		/* score matrix */
	int	trace[MAX_LENGTH+1][MAX_LENGTH+1];	/* trace matrix */
	char	alignX[MAX_LENGTH*2];		/* aligned X sequence */
	char	alignY[MAX_LENGTH*2];		/* aligned Y sequence */


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

	F[0][0] = 0;
	trace[0][0] = STOP;
	for ( i=1 ; i<=m ; i++ ) {
		F[i][0] = 0;
		trace[i][0] = STOP;
	}
	for ( j=1 ; j<=n ; j++ ) {
		F[0][j] = 0;
		trace[0][j] = STOP;
	}


 	/*
	 * Fill matrices
	 */

	for ( i=1 ; i<=m ; i++ ) {

		for ( j=1 ; j<=n ; j++ ) {
	
			if ( X[i-1]==Y[j-1] ) {
				score = F[i-1][j-1] + MATCH_SCORE;
			} else {
				score = F[i-1][j-1] + MISMATCH_SCORE;
			}
			trace[i][j] = DIAG;

			tmp = F[i-1][j] - GAP_PENALTY;
			if ( tmp>score ) {
				score = tmp;
				trace[i][j] = UP;
			}

			tmp = F[i][j-1] - GAP_PENALTY;
			if( tmp>score ) {
				score = tmp;
				trace[i][j] = LEFT;
			}
            tmp = 0;
            if (tmp > score) {
                score = tmp;
                trace[i][j] = STOP;
            }

			F[i][j] = score;
 		}
	}


	/*
	 * Print score matrix
	 */

	printf("Score matrix:\n      ");
	for ( j=0 ; j<n ; ++j ) {
		printf("%5c", Y[j]);
	}
	printf("\n");
	for ( i=0 ; i<=m ; i++ ) {
		if ( i==0 ) {
			printf(" ");
		} else {
			printf("%c", X[i-1]);
		}
		for ( j=0 ; j<=n ; j++ ) {
			printf("%5d", F[i][j]);
		}
		printf("\n");
	}
	printf("\n");


	/*
	 * Trace back from the lower-right corner of the matrix
	 */

	i = m;
	j = n;
	alignmentLength = 0;



	while ( trace[i][j] != STOP ) {

		switch ( trace[i][j] ) {

			case DIAG:
				alignX[alignmentLength] = X[i-1];
				alignY[alignmentLength] = Y[j-1];
				i--;
				j--;
				alignmentLength++;
				break;

			case LEFT:
				alignX[alignmentLength] = '-';
				alignY[alignmentLength] = Y[j-1];
				j--;
				alignmentLength++;
				break;

			case UP:
				alignX[alignmentLength] = X[i-1];
				alignY[alignmentLength] = '-';
				i--;
				alignmentLength++;
		}
	}


	/*
	 * Unaligned beginning
	 */

	while ( i>0 ) {
		alignX[alignmentLength] = X[i-1];
		alignY[alignmentLength] = '-';
		i--;
		alignmentLength++;
	}

	while ( j>0 ) {
		alignX[alignmentLength] = '-';
		alignY[alignmentLength] = Y[j-1];
		j--;
		alignmentLength++;
	}


	for ( i=alignmentLength-1 ; i>=0 ; i-- ) {
		printf("%c",alignX[i]);
	}
	printf("\n");

	// Question 1, 2 - indicate exact matches & calaculate the percent identity
	int num_matches = 0;
	int shortest_seq = (n < m ? n : m);
	int non_gaps = alignmentLength;
	for ( i=alignmentLength-1 ; i>=0 ; i-- ) {
		if ( (alignX[i] == alignY[i])) {
			printf("|");
			++num_matches;
		}
		else {
			if (alignX[i] == '-' || alignY[i] == '-') --non_gaps;
			printf(" ");
		}
	}
	printf("\n");

	for ( i=alignmentLength-1 ; i>=0 ; i-- ) {
		printf("%c",alignY[i]);
	}
	printf("\n\n");
	printf("Percent Identity: \n");
	printf("  - Divided by the shortest sequence (%d): %.2f%%\n", shortest_seq, (float) num_matches/shortest_seq * 100.0);
	printf("  - Divided by the length of the alignment (%d): %.2f%%\n", alignmentLength, (float) num_matches/alignmentLength * 100.0);
	printf("  - Divided by the average length of the sequence (%.2f): %.2f%%\n", ((n+m)/2.f), (float) num_matches/((n+m)/2.f) * 100.0);
	printf("  - Divided by the number of non-gap positions (%d): %.2f%%\n", non_gaps, (float) num_matches/non_gaps * 100.0);
	// printf("  - Divided by the number of equivalenced positions excluding overhangs: %.2f%%\n",  (float) num_matches/shortest_seq * 100.0);
    printf("\n");

	// Question 3 - calculate the hamming distance (between the aligned sequence strings)
    if (m == n)
	    printf("Hamming Distance : %d\n", alignmentLength - num_matches);
	
   
    return(1);
}
