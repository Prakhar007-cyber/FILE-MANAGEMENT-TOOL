#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Function prototypes
void displayMenu();
void createNewFile();
void writeToFile();
void appendToFile();
void readFromFile();
void displayFileContent();
void countFileStats();

int main() {
    int choice;
    
    cout << "====================================" << endl;
    cout << "      CODTECH FILE MANAGEMENT TOOL   " << endl;
    cout << "====================================" << endl;
    
    do {
        displayMenu();
        cout << "Enter your choice (1-6, 0 to exit): ";
        cin >> choice;
        cin.ignore(); // Clear input buffer
        
        switch(choice) {
            case 1:
                createNewFile();
                break;
            case 2:
                writeToFile();
                break;
            case 3:
                appendToFile();
                break;
            case 4:
                readFromFile();
                break;
            case 5:
                displayFileContent();
                break;
            case 6:
                countFileStats();
                break;
            case 0:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != 0);
    
    return 0;
}

void displayMenu() {
    cout << "\nMENU OPTIONS\n";
    cout << "1. Create a new file\n";
    cout << "2. Write data to a file (overwrites existing content)\n";
    cout << "3. Append data to a file\n";
    cout << "4. Read data from a file\n";
    cout << "5. Display file content\n";
    cout << "6. Count file statistics (lines, words, characters)\n";
    cout << "0. Exit\n";
}

void createNewFile() {
    string filename;
    cout << "Enter filename to create: ";
    getline(cin, filename);
    
    ofstream file(filename);
    if(file.is_open()) {
        cout << "File '" << filename << "' created successfully." << endl;
        file.close();
    } else {
        cerr << "Error creating file '" << filename << "'." << endl;
    }
}

void writeToFile() {
    string filename, content;
    cout << "Enter filename to write to: ";
    getline(cin, filename);
    
    cout << "Enter content to write (type 'END' on a new line to finish):\n";
    content = "";
    string line;
    while(true) {
        getline(cin, line);
        if(line == "END") break;
        content += line + "\n";
    }
    
    ofstream file(filename);
    if(file.is_open()) {
        file << content;
        cout << "Content written to '" << filename << "' successfully." << endl;
        file.close();
    } else {
        cerr << "Error opening file '" << filename << "' for writing." << endl;
    }
}

void appendToFile() {
    string filename, content;
    cout << "Enter filename to append to: ";
    getline(cin, filename);
    
    cout << "Enter content to append (type 'END' on a new line to finish):\n";
    content = "";
    string line;
    while(true) {
        getline(cin, line);
        if(line == "END") break;
        content += line + "\n";
    }
    
    ofstream file(filename, ios::app);
    if(file.is_open()) {
        file << content;
        cout << "Content appended to '" << filename << "' successfully." << endl;
        file.close();
    } else {
        cerr << "Error opening file '" << filename << "' for appending." << endl;
    }
}

void readFromFile() {
    string filename;
    cout << "Enter filename to read: ";
    getline(cin, filename);
    
    ifstream file(filename);
    if(file.is_open()) {
        string line;
        cout << "\nContent of '" << filename << "':\n";
        while(getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cerr << "Error opening file '" << filename << "' for reading." << endl;
    }
}

void displayFileContent() {
    string filename;
    cout << "Enter filename to display: ";
    getline(cin, filename);
    
    ifstream file(filename);
    if(file.is_open()) {
        string line;
        int lineNumber = 1;
        cout << "\nContent of '" << filename << "' with line numbers:\n";
        cout << "----------------------------------------\n";
        while(getline(file, line)) {
            cout << setw(4) << lineNumber++ << " | " << line << endl;
        }
        cout << "----------------------------------------\n";
        file.close();
    } else {
        cerr << "Error opening file '" << filename << "' for reading." << endl;
    }
}

void countFileStats() {
    string filename;
    cout << "Enter filename to analyze: ";
    getline(cin, filename);
    
    ifstream file(filename);
    if(file.is_open()) {
        int lines = 0, words = 0, characters = 0;
        string line;
        
        while(getline(file, line)) {
            lines++;
            characters += line.length() + 1; // +1 for newline character
            
            bool inWord = false;
            for(char c : line) {
                if(isalpha(c) || isdigit(c)) {
                    if(!inWord) {
                        words++;
                        inWord = true;
                    }
                } else {
                    inWord = false;
                }
            }
        }
        
        cout << "\nFile statistics for '" << filename << "':\n";
        cout << "Lines: " << lines << endl;
        cout << "Words: " << words << endl;
        cout << "Characters: " << characters << endl;
        
        file.close();
    } else {
        cerr << "Error opening file '" << filename << "' for reading." << endl;
    }
}
