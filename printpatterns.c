#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main() 
{
    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    
    int r = 2*n-1;
    int c = r;
    int k = 0;
    int print = n;
    int start = 0;
    int checkr = r-1;
    int checkc = c-1;
    
    int **mat = (int**) malloc(c*r*sizeof(int*));
    for(int i=0; i <r; i++){
        mat[i] = (int*) malloc(c*sizeof(int*));
    }
    //initialize number
    while(k < n){
        for (int i = start; i <  r-start; i++){ 
            for (int j = start; j < c-start; j++){
                if((i == start) || (j == start) || (i == r-start-1) || (j == c-start-1))
                    mat[i][j] = print;
                else
                    mat[checkr][j] = print;
            }
        }
        start++;
        k++;
        print--;
        checkr--;
    }
    //print it out.
    for (int i = 0; i <  r; i++){ 
      for (int j = 0; j < c; j++){ 
         printf("%d ", mat[i][j]); 
      }
      printf("\n");
    }

    return 0;
}