#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// input data struncture
typedef struct {
    int i;
    char s[4];
} Element;

// Input Data
extern Element ArrInput[];
int N = 75;


// 
char TheCharNum[62];
void f( int n );

/********************************************************************************************
 According to the input and output characteristics of f(), it is guessed that the output is 
 a special number, including "0~9", "A~Z", "a~z", which means the output is a 62-base number, 
 but the order of these letters is unclear. Therefore, the purpose of writing a program is to 
 find this order based on the 10-based number to 62-based number conversion result. 
 And, after the conversion, it is found that one character is missing, and the missing 
 character is also found through another pice of program.
********************************************************************************************/
int main() {

    int dig3,dig2,dig1;
    int total_dig = 0;

    // Step 1 to find all the 62-base digits in correct order
    for(int i = 0; i < 62; i++) TheCharNum[i] = 0;

    for(int i = 0; i < N; i++) {
        dig3 = ArrInput[i].i/3844;
        dig2 = (ArrInput[i].i%3844)/62;
        dig1 = ArrInput[i].i%62;

        if( 0 == TheCharNum[dig3] ){
            TheCharNum[dig3] =  ArrInput[i].s[0];
            total_dig++;
        }else if( TheCharNum[dig3] !=  ArrInput[i].s[0] ){
            printf( "err1... %c \n", ArrInput[i].s[0] );
        }
        if( 0 == TheCharNum[dig2] ){
            TheCharNum[dig2] =  ArrInput[i].s[1];
            total_dig++;
        }else if( TheCharNum[dig2] !=  ArrInput[i].s[1] ){
            printf( "err2... %c \n", ArrInput[i].s[1] );
        }
        if( 0 == TheCharNum[dig1] ){
            TheCharNum[dig1] =  ArrInput[i].s[2];
            total_dig++;
        }else if( TheCharNum[dig1] !=  ArrInput[i].s[2] ){
            printf( "err3... %c \n", ArrInput[i].s[2] );
        }
    }

    // Step 2 to find the only one missed 62-base digit and put it into the correct position
    printf( "Total number char is %d\n", total_dig );
    if( total_dig < 62 ){
        printf("The unappered (position)nunber: ");
        for( int i=0; i<62; i++ ){
            if( 0 == TheCharNum[i] ){
                printf( " %d", i);
            }
        }
        printf("\n");
    }

    char temp[128];
    for( int i=0; i<128; i++ ) temp[i] = 0;

    for( int i=0; i<62; i++ ) temp[TheCharNum[i]] = 1;

    for( char c='0'; c<='9'; c++ ){
        if( 0 == temp[c] ){
            TheCharNum[21] = c;
            printf( "The unappered char is %c\n", c);
        }
    }
    for( char c='A'; c<='Z'; c++ ){
        if( 0 == temp[c] ){
            TheCharNum[21] = c;
            printf( "The unappered char is %c\n", c);
        }
    }
    for( char c='a'; c<='z'; c++ ){
        if( 0 == temp[c] ){
            TheCharNum[21] = c;
            printf( "The unappered char is %c\n", c);
        }
    }

    // Step 3 finds results for Q2 b)
    f( 30001 );
    f( 55555 );
    f( 77788 );

    // Step 4 finds results for Q2 c)
    printf( "The upper limit or maximum range of this function is 62^3-1 = %d \n", 62*62*62-1);

    return 0;
}

/********************************************************************************************
 Function f(), 10-base number to 62-based number conversion
********************************************************************************************/
void f( int n )
{
    printf( "%d = %c%c%c\n", n, TheCharNum[n/3844], TheCharNum[(n%3844)/62], TheCharNum[n%62] );
}


/********************************************************************************************
 The input data
********************************************************************************************/
Element ArrInput[] = {
{ 15840 , "cGp" },
{ 16465 , "cmW" },
{ 17941 , "cX3" },
{ 17942 , "cXB" },
{ 18898 , "ctR" },
{ 19172 , "ckN" },
{ 20512 , "PVg" },
{ 20626 , "PD4" },
{ 20758 , "PBR" },
{ 25736 , "MYM" },
{ 25893 , "MSL" },
{ 26039 , "MUk" },
{ 26134 , "MIE" },
{ 26345 , "Mgr" },
{ 26346 , "MgK" },
{ 26676 , "MKd" },
{ 28161 , "GVT" },
{ 31622 , "vNx" },
{ 31873 , "vwP" },
{ 32028 , "vV9" },
{ 35260 , "zAj" },
{ 36368 , "zO9" },
{ 36428 , "zu1" },
{ 38716 , "AcO" },
{ 38805 , "APF" },
{ 40111 , "AHl" },
{ 40893 , "ALW" },
{ 40956 , "AQ9" },
{ 40957 , "AQs" },
{ 40958 , "AQq" },
{ 40959 , "AQL" },
{ 40960 , "AQQ" },
{ 42541 , "Zcz" },
{ 47987 , "yuk" },
{ 49137 , "yh2" },
{ 49169 , "yIi" },
{ 49443 , "yau" },
{ 49444 , "yap" },
{ 49639 , "ytL" },
{ 50047 , "T7T" },
{ 50048 , "T7N" },
{ 50127 , "Tx8" },
{ 50128 , "TxE" },
{ 50129 , "Tx2" },
{ 51183 , "Tn2" },
{ 51184 , "Tn1" },
{ 51204 , "Tnf" },
{ 52071 , "T2a" },
{ 52977 , "Thu" },
{ 54650 , "NTO" },
{ 55908 , "N2e" },
{ 56100 , "N9g" },
{ 57924 , "ocd" },
{ 60538 , "oeH" },
{ 60539 , "oe0" },
{ 60540 , "oeO" },
{ 61474 , "okE" },
{ 63141 , "dH6" },
{ 64436 , "dUw" },
{ 64437 , "dUn" },
{ 67416 , "m2D" },
{ 72677 , "wtT" },
{ 73039 , "nCi" },
{ 73040 , "nCc" },
{ 73211 , "nxJ" },
{ 73654 , "nzb" },
{ 73756 , "nZq" },
{ 74037 , "ndz" },
{ 74038 , "ndA" },
{ 76081 , "nIG" },
{ 76082 , "nIv" },
{ 79467 , "VXS" },
{ 79564 , "VYw" },
{ 79790 , "VeK" },
{ 79791 , "Vel" }
};
