#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MATRIX 10
#define MIN_MATRIX -9
#define MIN_STRING 4
#define MAX_STRING 10
#define MIN_COLUMN 5

int rand_number(int min_rand,int max_rand)                                  /*Random function*/
{
    int g = min_rand + rand()%(max_rand - min_rand + 1);
    return g;
}

int main()
{
    int n, m;                                                               /*The size of matrix by random function*/
    srand(time(NULL));
    m = rand_number(MIN_STRING, MAX_STRING);
    n = rand_number(MIN_COLUMN, MAX_STRING);
    int random_matrix[m][n];
    int i, j;
    printf("First task: create a random matrix.\n");
    printf("Result:\n");
    for (i=0; i<m; i++)                                                     /*Matrix by random function*/
	{
        for (j=0; j<n; j++)
		{
			random_matrix[i][j] = rand_number(MIN_MATRIX, MAX_MATRIX);
			printf("%4d ", random_matrix[i][j]);
		}
		printf("\n");
	}

    printf("Second task: swap first and last lines and turn over them.");
    int new_matrix[m][n], x = 0;
    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            new_matrix[i][j] = random_matrix[i][j];
        }
    }
    for (j=0; j<n; j++)                                                     /*Swap first and last lines and turn over them*/
	{
		new_matrix[0][j] = random_matrix[m-1][n-1-j];
		new_matrix[m-1][n-1-j] = random_matrix[0][j];
	}
    printf("\nResult:\n");
    for (i=0; i<m; i++)                                                     /*Withdraw the changed matrix*/
	{
		for (j=0; j<n; j++)
		{
			printf("%4d ", new_matrix[i][j]);
		}
		printf("\n");
	}

    printf("Third task:find minimum element of random matrix and delete line and column,\nat the intersection of which is located it.\n");
    int minimums=0, min=0;
    int massive_coord[2], min_matrix[m-1][n-1];
    for (i=0; i<2; i++)
    {
        massive_coord[i] = 0;
    }
    for (i=0; i<m; i++)                                                     /*Minimum of matrix*/
    {
        for (j=0; j<n; j++)
        {
            if ( random_matrix[i][j] < min )
            {
                min = random_matrix[i][j];
            }
        }
    }
    printf("Minimum: %d\n", min);
    for (i=0; i<m; i++)                                                    /*How many are there minimums?*/
    {
        for (j=0; j<n; j++)
        {
            if ( random_matrix[i][j] == min )
            {
                minimums++;
            }
        }
    }
    if ( minimums == 1 )                                                   /*If there is one minimum, we must find its*/
    {                                                                      /*string and column, delete it and show changed matrix*/
        for (i=0; i<m; i++)
        {
            for (j=0; j<n; j++)
            {
                if ( random_matrix[i][j] == min )
                {
                    massive_coord[0] = i;
                    massive_coord[1] = j;
                }
            }
        }
        printf("Result:\n");
        for (i=0; i<m; i++)
        {
            for (j=0; j<n; j++)
            {
                if ( i != massive_coord[0] && j != massive_coord[1])
                {
                    min_matrix[i][j] = random_matrix[i][j];
                    printf("%3d ", min_matrix[i][j]);
                }
            }
            if ( i != massive_coord[0] )
            {
                printf("\n");
            }
        }
    }
    else                                                           /*If there are several same minimums, the program must choose anybody,*/
    {
        int number;                                                /*find its string and column, delete it and show changed matrix*/
        printf("%d mins\n", minimums);
        printf("What will number be delete? ");
        number = rand_number(1,minimums);
        printf("Number %d\n", number);
        minimums=0;
        for (i=0; i<m; i++)
        {
            for (j=0; j<n; j++)
            {
                if ( random_matrix[i][j] == min )
                {
                minimums++;
                    if ( minimums == number )
                    {
                        massive_coord[1] = i;
                        massive_coord[2] = j;
                    }
                }
            }
        }
        printf("Result:\n");
        for (i=0; i<m; i++)
        {
            for (j=0; j<n; j++)
            {
                if ( i != massive_coord[1] && j != massive_coord[2])
                {
                    min_matrix[i][j] = random_matrix[i][j];
                    printf("%3d ", min_matrix[i][j]);
                }
            }
            if ( i != massive_coord[1] )
            {
                printf("\n");
            }
        }
    }

    printf("Forth task: enter a matrix manually.\nSize of random matrix: %d:%d\n", m, n);
    int k, l;
    printf("Enter the size of matrix(k:l):");
    scanf("%d:%d", &k, &l);
    printf("Enter the matrix:\n");
    int matrix[k][l], size;
    size = k*l;
    int stack[size];
    int numeric;
    x = 0;
    for (i=0; i<size; i++)                                                 /*By stack input elements of future matrix*/
    {
        scanf("%d", &numeric);
        stack[i] = numeric;
    }
    for (i=0; i<k; i++)                                                   /*Stack of elements of future matrix -> Matrix*/
    {
        for (j=0; j<l; j++)
        {
            if ( x < size )
            {
                matrix[i][j] = stack[x];
                x++;
            }
            else
                printf("loser\n");
        }
    }
    printf("Result:\n");
    for (i=0; i<k; i++)
    {
        for (j=0; j<l; j++)
        {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("Fifth task: find the composition of two matrix.");
    int s;
    if ( n == k )
    {
        int result_matrix[m][l];
        for (i=0; i<m; i++)
        {
            for (j=0; j<l; j++)
            {
                   result_matrix[i][j] = 0;
            }
        }
        for (i=0; i<m; i++)
        {
            for(j=0; j<l; j++)
            {
                for(s=0; s<m; s++)
                {
                    result_matrix[i][j] += random_matrix[i][s] * matrix[s][j];
                }
            }
        }
        printf("\nResult:\n");
        for (i=0; i<m; i++)
        {
            for (j=0; j<l; j++)
            {
                printf("%3d ", result_matrix[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Their composition does not exist");
    }

    return 0;

}
