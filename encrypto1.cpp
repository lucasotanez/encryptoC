#include <iostream>
#include <cstring>
#include <cctype>
#include <ctime>
#include "shiftkey.h"

using namespace std;

void swapShifter(int* key, int i); //not used in Encrypto1... possibly usable in later versions
int randAlphabet(); //return a-z

int main(int argc, char* argv[]){

    char password[50]; //extra storage for handling longer strings

    //shift key: included by header // meaningless for this version

    if (argc == 2) {
        strcpy(password, argv[1]);
        while (strlen(password) > 20){ //strlen function gets everything before null character
            cout << "     ERROR: Please enter a password under 21 characters long." << endl;
            cin >> password; // initializes password when input string <= 20 characters
        };
    }
    else{
        cout << "Enter your password: ";
        cin >> password;
        while (strlen(password) > 20){
            cout << "     ERROR: Please enter a password under 21 characters long." << endl;
            cout << "Enter your password: ";
            cin >> password;
        }
    }

    srand(time(0));

    int capLoc = rand() % 3; //capital location

    int shifterSeed = rand() % 9 + 1 ; //seeds from 1 - 9 
    // UNCOMMENT FOR HINTS cout << "SEED " << shifterSeed << endl;;

    int shift = randAlphabet();
    while (shift == 116) shift = randAlphabet();
    // UNCOMMENT FOR HINTS cout << "SHIFT " << shift << endl;

    //cout << strlen(password) << endl; //error checking

    //cout << password[2] << endl;

    //range for shift: 48 - 57 for # and 65 - 90 for CAPS and 97 - 122 for lowercase

    //srand(shifterSeed); //meaningless

    for (unsigned i = 0; i < 62; i++){
        swapShifter(shifter, i);
    }

    // for (int i = 0; i < 62; i++){
    //     cout << shifter[i] << " " << endl;
    // }

   // srand(time(0)); meaningless
    
    char ciphertext[28];
    for (unsigned i = 0; i < 3; i++){
        if (i == capLoc){
            ciphertext[i] = shift - 32; //uppercase
        }
        else{
            ciphertext[i] = randAlphabet();
        }
    }

    for (unsigned i = 0; i < strlen(password); i++){
        int newAscii = password[i] + shift;
        while (newAscii > 122) newAscii = 48 + newAscii - 123;
        if (newAscii == 92) newAscii = 36; //special case;
        //if (newAscii > 57 && newAscii < 65) newAscii = 65 + newAscii - 57;
        //if (newAscii > 90 && newAscii < 97) newAscii = 97 + newAscii - 90;
        ciphertext[i+3] = newAscii;
    }

    for (unsigned i = strlen(password) + 3; i < 24; i++){
        ciphertext[i] = shifter[rand() % 62];
    }

    if (strlen(password) < 10){ //setting password length
        ciphertext[24] = randAlphabet();
        ciphertext[25] = 48 + strlen(password); // ASCII number characters
    } 
    else{
        ciphertext[24] = strlen(password) / 10 + 48;
        ciphertext[25] = strlen(password) - ((ciphertext[24] - 48) * 10) + 48;
    };

    ciphertext[26] = randAlphabet();
    ciphertext[27] = '\0';

    cout << ciphertext << endl;

    return 0;
}

void swapShifter(int* key, int i)
{
    int swapWith = rand() % 62;
    int temp = key[i];
    key[i] = key[swapWith];
    key[swapWith] = temp;
    return;
}

int randAlphabet()
{
    return rand() % 26 + 97;
}