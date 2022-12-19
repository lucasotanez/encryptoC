#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
    
    char* ciphertext = new char[28];
    char errorNE[59] = "     ERROR: This password was not ecrypted with Encrypto1.";

    if (argc == 2) { 
        strcpy(ciphertext, argv[1]);
        while (strlen(ciphertext) != 27){ //strlen function gets everything before null character
            cout << errorNE << endl;
            cout << "\nEnter encrypted ciphertext: ";
            cin >> ciphertext; // initializes password when input string <= 20 characters
        }
    }
    else{
        cout << "Enter encrypted ciphertext: ";
        cin >> ciphertext;
        while (strlen(ciphertext) != 27){
            cout << errorNE << endl;
            cout << "\nEnter encrypted ciphertext: ";
            cin >> ciphertext;
        }
    }

    int unshift = -1;

    for (unsigned i = 0; i < 3; i++){
        if (isupper(ciphertext[i])){
            unshift = ciphertext[i] + 32;
            break;
        }
        else if (i == 2){
            cout << errorNE << endl;
            cout << "Exiting decryption..." << endl;
            return 1; // 1 error
        }
    }

    if (unshift == -1){ // sanity check; should never fire
        cout << "     ERROR: Internal decryption error." << endl;
        cout << "Exiting decryption..." << endl;
        return 1; // 1 error
    }

    int passLen = 0;

    if ((ciphertext[24] < 58) && (ciphertext[24] > 47)){
        passLen = (ciphertext[24] - 48) * 10 + (ciphertext[25] - 48);
    }
    else passLen = ciphertext[25] - 48;

    if (passLen > 20) { //sanity check; should never fire
        cout << "     ERROR: Internal decryption error." << endl;
        cout << "Exiting decryption..." << endl;
        return 1; // 1 error
    }

    char* password = new char[passLen];

    for (unsigned i = 3; i < passLen+3; i++){
        if (ciphertext[i] == 36){
            password[i-3] = 92;
            continue;
        }
        int backShift = ciphertext[i] - unshift;
        while (backShift < 48) backShift = 123 - (48 - backShift);
        password[i-3] = backShift;
    }

    delete [] ciphertext;

    cout << "Password decrypted successfully: ";
    cout << " ###  " << password << "  ### " << endl;

    delete [] password;
    return 0;
}