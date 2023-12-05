#include <stdio.h>
//prototype
void printMatrix (int a, int b);

int main() {
    //declare and initialize variables
  FILE *fptr;
  fptr = fopen("matrixIn.txt", "r");
  int A[5][5];
  int B[5][5];
  int C[5][5];
  int rowsA;
  int columnsA;
  int rowsB;
  int columnsB;
  char choice;

    //check if file opened correctly
  if (!fptr){
      printf("Error opening file. Closing program");
      return 1;
  }
    //scan in the dimensions of the matrix
  fscanf(fptr, "%d", &rowsA);
  fscanf(fptr, "%d", &columnsA);

    //tell user the dimensions
  printf("The first matrix is a %dx%d matrix.\nIt contains the following data:", rowsA, columnsA);
    //print out the matrix in correct format
  printMatrix (rowsA, columnsA);
    //scan in dimensions of the second matrix
  fscanf(fptr, "%d", &rowsB);
  fscanf(fptr, "%d", &columnsB);

    //tells user dimensions of the second matrix
  printf("\n\nThe second matrix is a %dx%d matrix.\nIt contains the following data:", rowsB, columnsB);

    //print out the matrix in correct format
  printMatrix (rowsB, columnsB);
    //checks if they can be added or subtracted
  if (rowsA == rowsB && columnsA == columnsB){
        //asks user which operation they want to do
      printf("\n\nMatrices have same dimensions;\nto add matrices type '+'\nto subtract type '-'\nto multiply type '*'\nEnter choice: ");
      scanf("%c", &choice);
      switch (choice){
        case '+' : 
        //prints sum
            printf("\nSum of matrices are:");
            for (int r = 0; r<rowsA; r++){
                printf("\nRow %d: ", r + 1);
                for (int c = 0; c<columnsA; c++){
                    C[r][c] = A[r][c] + B[r][c];
                    printf("%d ", C[r][c]);
                }
            }
        break;
        case '-' : 
        //prints difference
            printf("\nThe difference in the matrices are:");
             for (int r = 0; r<rowsA; r++){
                printf("\nRow %d: ", r + 1);
                for (int c = 0; c<columnsA; c++){
                    C[r][c] = A[r][c] - B[r][c];
                    printf("%d ", C[r][c]);
                }
            }
        break;
        case '*' : //if the columns in A aren't equal to rows in B, won't do multiplication
                if (rowsB != columnsA){
                    printf("Matrices are not multipliable");
                }
                break;
            //if user doesn't enter valid operation
        default : printf("Needs a valid  input, closing program");
                break;
        }
            //if matrices don't have same dimensions, won't ask if they want to add or subtract
    } else {
        printf("\n\nMatrices do not have the same dimensions");
    } //if columns in A ARE equal to rows in B
    if (rowsB == columnsA){
        //asks if user wants to multiply
        printf("\n\nMultiplication possible, would you like to multiply the matrices?(y/n): ");
        scanf(" %c", &choice);
        switch (choice){
        
        case 'y' : 
        //does the multiplication
                for (int i = 0; i<rowsA; i++){
                    for (int j = 0; j<columnsB;j++){
                        C[i][j] = 0;
                        for (int k = 0; k<rowsB; k++){
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
                for (int i = 0; i<rowsA;i++){
                    printf("\nRow %d: ", i + 1);
                    for (int j = 0; j<columnsB;j++){
                        printf("%d ", C[i][j]);
                    }
                }
                //doesn't do anything if user says no
        case 'n' : break;
                
        }
    } 
    fclose(fptr);

    return 0;
}

void printMatrix (int &a, int &b){
    FILE * fptr;
    fptr = fopen("matrixIn.txt", "r");
    int A[5][5];

    for (int r = 0; r<a; r++){
        printf("\nRow %d: ", r + 1);
        for (int c = 0; c<b; c++){
            fscanf(fptr,"%d", &A[r][c]);
            printf(" %d", A[r][c]);
        }
    }
}