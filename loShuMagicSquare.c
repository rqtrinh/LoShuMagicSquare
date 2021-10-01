/*Import necessary libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    //Init variables
    int magicSquare[3][3] = {1,2,3,4,5,6,7,8,9};
    int attempts = 0;
    //Declarations
    int indexRowOne, indexColumnOne, 
    indexRowTwo, indexColumnTwo, tempNumber,
    sumRowOne, sumRowTwo, sumRowThree,
    sumColmOne, sumColmTwo, sumColmThree,
    sumDiagnolOne, sumDiagnolTwo;
    time_t t;

    //Init random number generator
    srand((unsigned) time(&t));

    //Create new squares until Lo Shu Magic Square is prodcued
    do
    {
        //add to count
        attempts++;
        //scramble the numbers inside square 25 times
        for(int i = 0; i<25; i++)
        {
            indexRowOne = rand() % 3;
            do
            {
                indexRowTwo = rand() % 3;
            } while (indexRowOne == indexRowTwo);

            indexColumnOne = rand() % 3;
            do
            {
                indexColumnTwo = rand() % 3;
            } while (indexColumnOne == indexColumnTwo);

            //swap numbers at two locations in the array
            tempNumber = magicSquare[indexRowOne][indexColumnOne];
            magicSquare[indexRowOne][indexColumnOne] = magicSquare[indexRowTwo][indexColumnTwo];
            magicSquare[indexRowTwo][indexColumnTwo] = tempNumber;

        }
        //find the sum of all rows, columns, and the two diagnols
        sumRowOne = magicSquare[0][0] + magicSquare[0][1] + magicSquare[0][2];
        sumRowTwo = magicSquare[1][0] + magicSquare[1][1] + magicSquare[1][2];
        sumRowThree = magicSquare[2][0] + magicSquare[2][1] + magicSquare[2][2];
        sumColmOne = magicSquare[0][0] + magicSquare[1][0] + magicSquare[2][0];
        sumColmTwo = magicSquare[0][1] + magicSquare[1][1] + magicSquare[2][1];
        sumColmThree = magicSquare[0][2] + magicSquare[1][2] + magicSquare[2][2];
        sumDiagnolOne = magicSquare[0][0] + magicSquare[1][1] + magicSquare[2][2];
        sumDiagnolTwo = magicSquare[0][2] + magicSquare[1][1] + magicSquare[2][0];

    //continue loop until all sums are = 15
    }while((sumRowOne!=15)||(sumRowTwo!=15)||(sumRowThree!=15)||
            (sumColmOne!=15)||(sumColmTwo!=15)||(sumColmThree!=15)||
            (sumDiagnolOne!=15)||(sumDiagnolTwo!=15));

    //Print number of attempts
    printf("Squares generated and tested before success: %d\n", attempts);

    //Print the square
    for(int row =0; row<3; row++)
    {
        printf("[ ");
        for(int colm = 0; colm<3; colm++)
        {
            printf("%d ", magicSquare[row][colm]);
        }
        printf("]\n");
    }
}

