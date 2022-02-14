#include <iostream>
#include <time.h>
using namespace std;

int main()
{

    srand(time(NULL));

    int vPos1, vPos2, vPos3, vPos4;     // solution digits by position
    const int vMAX = 6;                 // maximum digit allowed
    int vGuess;                         // user's guess
    bool vGuessValid;                   // whether guess is valid
    int vgPos1, vgPos2, vgPos3, vgPos4; //digits from the guess
    int vDigits = 0;                    // how many are in the wrong place
    int vPosition = 0;                  // how many are in the correct place

    // 1) Set the solution
    do
    {
        vPos1 = rand() % vMAX + 1;
        vPos2 = rand() % vMAX + 1;
        vPos3 = rand() % vMAX + 1;
        vPos4 = rand() % vMAX + 1;
        cout << vPos1 << vPos2 << vPos3 << vPos4 << endl;
    } while (vPos1 == vPos2 || vPos1 == vPos3 || vPos1 == vPos4 || vPos2 == vPos3 || vPos2 == vPos4 || vPos3 == vPos4);

    // 2) Keep prompting the user for guesses until they are correct (loop)
    do
    {
        // Prompt the user for a guess
        do
        {
            vGuessValid = true;

            do
            {
                // Verify 4 digit code
                cout << "Ingresa un código de 4 digitos: ";
                cin >> vGuess;
            } while (vGuess < 1000 || vGuess > 9999);

            // break apart code
            vgPos4 = vGuess % 10; //stores last digit
            vGuess = vGuess / 10; //removes last digit

            vgPos3 = vGuess % 10; //stores last digit
            vGuess = vGuess / 10; //removes last digit

            vgPos2 = vGuess % 10; //stores last digit
            vGuess = vGuess / 10; //removes last digit

            vgPos1 = vGuess % 10; //stores last digit
            vGuess = vGuess / 10; //removes last digit

            if (vgPos1 == 0 || vgPos2 == 0 || vgPos3 == 0 || vgPos4 == 0)
                vGuessValid = false;
            else if (vgPos1 > vMAX || vgPos2 > vMAX || vgPos3 > vMAX || vgPos4 > vMAX)
                vGuessValid = false;
            else if (vgPos1 == vgPos2 || vgPos1 == vgPos3 || vgPos1 == vPos4 || vgPos2 == vgPos3 || vgPos2 == vgPos4 || vgPos3 == vgPos4)
            {
                vGuessValid = false;
            }

            // verify each digit is unique

        } while (vGuessValid == false);
        // Generate hints
        vDigits = 0;
        vPosition = 0;
        // a) how may digits are in the correct place
        if (vgPos1 == vPos1)
            vPosition++;
        if (vgPos2 == vPos2)
            vPosition++;
        if (vgPos3 == vPos3)
            vPosition++;
        if (vgPos4 == vPos4)
            vPosition++;

        // a) how may in the answer but in the wrong place
        if (vgPos1 == vPos2 || vgPos1 == vPos3 || vgPos1 == vPos4)
            vDigits++;
        if (vgPos2 == vPos1 || vgPos2 == vPos3 || vgPos2 == vPos4)
            vDigits++;
        if (vgPos3 == vPos1 || vgPos3 == vPos2 || vgPos3 == vPos4)
            vDigits++;
        if (vgPos4 == vPos1 || vgPos4 == vPos2 || vgPos4 == vPos3)
            vDigits++;
        cout << "Números que no están en la posición correcta: " << vDigits << endl;
        cout << "Números que están en la posición correcta: " << vPosition << endl;

    } while (vPosition < 4);

    cout << "Ha ganado!" << endl;
}