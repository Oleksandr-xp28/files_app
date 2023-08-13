// files_app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


bool isLong(string word) {

    int count = 0;

    for (char c : word) {

        if (isalpha(c)) {
            count++;
        }
    }

    return count >= 7;
}


void addFile(string filename) {

    ofstream file(filename);

    file.close();
}


int main() {

    addFile("output.txt");

    ifstream inputFile("input.txt");

    if (!inputFile) {
        cout << "Error opening input file" << endl;
        return -1;
    }

    ofstream outputFile("output.txt");

    if (!outputFile) {
        cout << "Error opening output file" << endl;
        return -1;
    }

    string word;

    while (inputFile >> word) {

        if (isLong(word)) {

            outputFile << word << " ";
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
