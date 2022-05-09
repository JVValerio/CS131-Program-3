////
// Name: Josh Valerio
// Section: CS 131 - 2830
// Program Name: Word Counter
//
// Description: The goal of this task is to show our knowledge from Lectures 1 to 6.
//				This program is created to count the number of words per letter length from a given user file.
//              The letter lengths will be separately counted from 1 to 8. Any numbers past 8 will be combined.
//              It will continue receiving input from the file with a loop until it fufills the condition.
//              This info will be outputed via console for users to see.
////

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void readAndProcessFiles();

int main()
{
    cout << "\t\t ~ Word Counter ~ " << endl << endl;
    readAndProcessFiles();

    system("pause");
    return 0;
}

void readAndProcessFiles() {
    string userInput;
    string fileInput;
    int wordLength;
    // Integers below used to count letter length
    int counter = 0;
    int nOne = 0, nTwo = 0, nThree = 0, nFour = 0,
        nFive = 0, nSix = 0, nSeven = 0, nEight = 0, nMore8 = 0;

    while (userInput != "exit") {
        ifstream userFile;
        cout << "Enter the file name you wish to be counted (or type exit to quit): ";
        cin >> userInput;
        // If user inputs exit into the console they will be ejected out of the loop
        if (userInput == "exit") {
            cout << "Thank you for using the program." << endl;
            break;
        }
        // If user enters a file that cannot be found, then they will be given an option to try again
        userFile.open(userInput);
        if (userFile.fail() && userInput != "exit") {
            cout << "Cannot find file. Try again." << endl;
            continue;
        }
        while (!userFile.eof()) {
            userFile >> fileInput;
            wordLength = fileInput.length();
            switch (wordLength) {
                case 1:
                    nOne++;
                    break;
                case 2:
                    nTwo++;
                    break;
                case 3:
                    nThree++;
                    break;
                case 4:
                    nFour++;
                    break;
                case 5:
                    nFive++;
                    break;
                case 6:
                    nSix++;
                    break;
                case 7:
                    nSeven++;
                    break;
                case 8:
                    nEight++;
                    break;
                default:
                    nMore8++;
                    break;
            }
            counter++;
        }
        userFile.close();
        cout << "\n\t\t Length:\tCount:" << endl;
        cout << "\t\t 1\t\t" << nOne << endl;
        cout << "\t\t 2\t\t" << nTwo << endl;
        cout << "\t\t 3\t\t" << nThree << endl;
        cout << "\t\t 4\t\t" << nFour << endl;
        cout << "\t\t 5\t\t" << nFive << endl;
        cout << "\t\t 6\t\t" << nSix << endl;
        cout << "\t\t 7\t\t" << nSeven << endl;
        cout << "\t\t 8\t\t" << nEight << endl;
        cout << "\t\t >8\t\t" << nMore8 << endl << endl;
        cout << "The total words in the file: " << counter << endl;
    }
}
