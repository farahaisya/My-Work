// FARAH AISYA BINTI JAAFAR
// A25CS0218
// 26 DECEMBER 2025
// Topic 6 Input and Output In-Class Activity

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{

    string name;
    int id;
    double fee;
    // TODO 1: Ask user to enter student name
    // TODO 2: Read full name using getline
    cout << "Enter student name: ";
    getline(cin, name);

    // TODO 3: Ask user to enter student ID
    // TODO 4: Read student ID using cin
    cout << "Enter student ID: ";
    cin >> id;

    // TODO 5: Ask user to enter total fee paid
    // TODO 6: Read fee using cin
    cout << "Enter total fee paid: ";
    cin >> fee;

    // TODO 7: Create an ofstream object named outFile
    // TODO 8: Open a file named "payment.txt"
    ofstream outFile;
    outFile.open("payment.txt");

    cout << "----------------------------------------" << endl;
    cout << "Student Payment Summary" << endl;
    cout << "----------------------------------------" << endl;

    // TODO 9: Display name on screen
    cout << "Name       : " << name << endl;

    // TODO 10: Display ID on screen
    cout << "ID         : " << id << endl;

    // TODO 11: Display fee using setw(), fixed, setprecision(2)
    cout << right;
    cout << fixed;
    cout << "Total Fee  : " << setw(10) << setprecision(2) << fee << endl;

    cout << "----------------------------------------" << endl;
    // TODO 12: Write the SAME formatted output into the file
    outFile << "----------------------------------------" << endl;
    outFile << "Student Payment Summary" << endl;
    outFile << "----------------------------------------" << endl;

    outFile << "Name       : " << name << endl;
    outFile << "ID         : " << id << endl;

    outFile << right;
    outFile << fixed;
    outFile << "Total Fee  : " << setw(10) << setprecision(2) << fee << endl;
    outFile << "----------------------------------------" << endl;

    // TODO 13: Close the file
    outFile.close();
    return 0;
}