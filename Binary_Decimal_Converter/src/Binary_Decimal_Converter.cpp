// Program Description:  This program has a converts binary numbers to decimal numbers, and vice versa.
//                              Additionally, the program checks the number entered for error before conversion.

// Author:  Thomas Stuart

// Creation Date: 2/7/18

// Revisions: 2/8/18, 2/10/18

// Date: 2/11/18

// Operating System:  MacOS HS

// IDE/Compiler:  xCode

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//Function Prototypes
/*  The binary to decimal function takes a binary number, checks if it is too large in value for conversion or has inccorect digits, performs
 a array styled calculation, and returns the correct decimal equivalence*/
int binaryToDecimal(int);
/*  The decimal to binary function takes a decimal number, checks if it is too large in value for conversion, performs
 a repeated division and remainder process, and returns the correct binary equivalence*/
void decimalToBinary(int);

int main() {


    int binaryNum;
    int decimalNum;
    string answer;  //  used for repeating the program.   Takes input
    bool again = true;  // determines whether or not to continue the do while loop

    cout << " Binary/Decimal converter Program.  Assignment #1 " << endl <<endl << endl;

    do{

    //step#1 is to ask the user for a binary number and check for an error  (the FX corrects the error)
    cout << "1.) Enter a Binary number with a max of 8 digits " <<endl;
    cin >> binaryNum;
    binaryNum = abs(binaryNum);
    //step#2  Convert the binary number to decimal and display it
    cout << binaryToDecimal(binaryNum) <<endl <<endl <<endl;

    //step #3 Ask the user for a decimal number.
    cout << "2.) Enter a decimal number between 0-255" <<endl;
    cin >> decimalNum;
    decimalNum = abs(decimalNum);

    // If they type something other than a decimal number, give them an error message and try again
    while(decimalNum > 255){
        cout << "You entered a number greater than 255, please enter a lower valued number within bounds " <<endl;
        cin >> decimalNum;
    }

    // step #4  Convert that number to binary and display it.
    decimalToBinary( decimalNum);  // Sent to the function already error checked and ready to be converted


        //step#5 Keep asking until the user types QUIT or quit in #1
        cout << endl <<endl << endl << " Did you want to run the program again? Enter \"QUIT\" for no " << endl;
        cin  >> answer;

        if( answer == "QUIT" || answer == "quit")
            again = false;
        else
            again = true;

        cout << endl << endl << endl <<endl;

    }while( again == true );

    return 0;
}


int binaryToDecimal( int binaryNum){


    int binaryArray[8]; //per hint instructions, the number should have a max of 8 digits
    bool isBinary = false;  // check whether the number is binary or not

    int counterIsNotBinary=0;  // how many digits are not binary
    int countDigit=0;  //helps to fill the array properly

    //This while loop takes the BinaryNumber stored as an integer and stores it into an array
    while(countDigit != 8){
        binaryArray[countDigit] = binaryNum%10;
        binaryNum = binaryNum/10;
        countDigit++;
    }

    //This code segment determines how many occurances of non-binary digits their are
    for( int i=0; i < 8; i++){
        if(binaryArray[i] == 1 || binaryArray[i] == 0)
            cout <<"";
        else
            counterIsNotBinary++;
    }
    cout << " Occurances of non-binary digits: " << counterIsNotBinary<<endl;

    if( counterIsNotBinary == 0 )
        isBinary = true;

    counterIsNotBinary =0;
    while( binaryNum > 11111111 || isBinary == false){
        cout << " You entered an incorrect binary number, please enter a new one (Allowed digits, 0 & 1)" << endl;
        cin>> binaryNum;
        countDigit = 0;
        while(countDigit != 8){
            binaryArray[countDigit] = binaryNum%10;
            binaryNum = binaryNum/10;
            countDigit++;
        }
        for( int i=0; i < 8; i++){
            if(binaryArray[i] == 1 || binaryArray[i] == 0)
                cout <<"";
            else
                counterIsNotBinary++;
        }

        if( counterIsNotBinary == 0 )
            isBinary = true;
        counterIsNotBinary =0;
    }

    cout << endl << " Binary number to be converted: ";
    for( int k=7; k >=0; k--)
        cout<< binaryArray[k];

    int sumOfBinaryToDec =0;
    cout << endl;

    for( int k=0; k < 8; k++){
        //cout << k  << " " << binaryArray[k] << endl;
        sumOfBinaryToDec +=  pow(2.0,k) * binaryArray[k];
    }
    cout << endl << "Decimal Conversion: " <<endl;
    return sumOfBinaryToDec;
}

void decimalToBinary(int num){

    vector <int> binary;  // stores digits entered by the user as a whole, as individual numbers

    int quiotient =0;
    int remainder =0;
    cout << endl<< " Decimal number to be converted: " << num << endl <<endl;

    //This segement of code takes the number entered as a integer, and seperates it into digits
    while (num > 0){

        quiotient = num/2;  // 11/2 = 5   5/2 = 2
        //cout << "quotient" << quiotient <<endl;
        remainder = num%2; // remainder of 1     rem of 1    rem  of zero
        //cout << "remainder " << remainder <<endl;

        binary.push_back( remainder ); //stores the numbers one by one
        //cout << "num " << num <<endl;
        num = quiotient;
    }

    cout <<  "Binary Conversion: " <<endl;
    unsigned long size = binary.size();
    for(int t = size-1; t >= 0; t--){
        cout << binary[t] ;
    }
    cout <<endl;
}
