// DATE: 4/1/2025
// SET NUMBER: 2
// 1. NAME: SHASYA SHAFIEQAH BINTI SHAHARUDDIN
//    MATRICS NUMBER: A25CS0350
// 2. NAME: FARAH AISYA BINTI JAAFAR
//    MATRICS NUMBER: A25CS0218

#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;

const int SIZE = 20;
void getInput(string uniName[], int numIntakeStudents[], int numEnrolmentStudents[], int output[]);
int calcTotal(int arr[]);
int getLowest(int arr[]);
int getHighest(int arr[]);
double calcAverage(int total);

int main()
{
    string uniName[SIZE];
    int numIntakeStudents[SIZE], numEnrolmentStudents[SIZE], output[SIZE];
    int totalIntake, totalEnrolment, totalOutput;
    double avgIntake, avgEnrolment, avgOutput;
    int lowestNumIntake, lowestNumEnrolment, lowestNumOutput;
    int highestNumIntake, highestNumEnrolment, highestNumOutput;
    int rangeIntake, rangeEnrolment, rangeOutput;

    // read input from file
    getInput(uniName, numIntakeStudents, numEnrolmentStudents, output);

    // create & write to output file
    ofstream outFile("output.txt");

    // header
    outFile << setw(67) << "NUMBER OF STUDENTS INTAKE, ENROLMENT AND OUTPUT" << endl;
    outFile << setw(59) << "IN PUBLIC UNIVERSITIES (2015)" << endl;
    outFile << "--------------------------------------------------------------------------------------------" << endl;
    // column
    outFile << right << setw(15) << "UNIVERSITIES" << right << setw(25) << "INTAKE" << setw(25) << "ENROLMENT" << setw(20) << "OUTPUT" << endl;
    outFile << "--------------------------------------------------------------------------------------------" << endl;
    // input.txt
    for (int i = 0; i < SIZE; i++)
    {
        outFile << "      " << setw(7) << left << uniName[i] << right << setw(27) << numIntakeStudents[i] << setw(25) << numEnrolmentStudents[i] << setw(20) << output[i] << endl;
    }
    outFile << "--------------------------------------------------------------------------------------------" << endl;

    // total
    totalIntake = calcTotal(numIntakeStudents);
    totalEnrolment = calcTotal(numEnrolmentStudents);
    totalOutput = calcTotal(output);

    // average
    avgIntake = calcAverage(totalIntake);
    avgEnrolment = calcAverage(totalEnrolment);
    avgOutput = calcAverage(totalOutput);

    // write total & average
    outFile << "      " << setw(7) << left << "TOTAL" << right << setw(27) << totalIntake << right << setw(25) << totalEnrolment << right << setw(20) << totalOutput << endl;
    outFile << "      " << setw(7) << left << "AVERAGE" << right << setw(27) << fixed << setprecision(2) << avgIntake << setw(25) << avgEnrolment << setw(20) << avgOutput << endl;
    outFile << "--------------------------------------------------------------------------------------------" << endl;

    // lowest
    lowestNumIntake = getLowest(numIntakeStudents);
    lowestNumEnrolment = getLowest(numEnrolmentStudents);
    lowestNumOutput = getLowest(output);

    // highest
    highestNumIntake = getHighest(numIntakeStudents);
    highestNumEnrolment = getHighest(numEnrolmentStudents);
    highestNumOutput = getHighest(output);

    // range
    rangeIntake = numIntakeStudents[highestNumIntake] - numIntakeStudents[lowestNumIntake];
    rangeEnrolment = numEnrolmentStudents[highestNumEnrolment] - numEnrolmentStudents[lowestNumEnrolment];
    rangeOutput = output[highestNumOutput] - output[lowestNumOutput];

    // write lowest
    outFile << endl;
    outFile << "THE LOWEST NUMBER OF STUDENTS' INTAKE    = " << numIntakeStudents[lowestNumIntake] << " (" << uniName[lowestNumIntake] << ") " << endl;
    outFile << "THE LOWEST NUMBER OF STUDENTS' ENROLMENT = " << numEnrolmentStudents[lowestNumEnrolment] << " (" << uniName[lowestNumEnrolment] << ") " << endl;
    outFile << "THE LOWEST NUMBER OF STUDENTS' OUTPUT    = " << output[lowestNumOutput] << " (" << uniName[lowestNumOutput] << ") " << endl;
    outFile << endl;

    // write highest
    outFile << "THE HIGHEST NUMBER OF STUDENTS' INTAKE    = " << numIntakeStudents[highestNumIntake] << " (" << uniName[highestNumIntake] << ") " << endl;
    outFile << "THE HIGHEST NUMBER OF STUDENTS' ENROLMENT = " << numEnrolmentStudents[highestNumEnrolment] << " (" << uniName[highestNumEnrolment] << ") " << endl;
    outFile << "THE HISGHEST NUMBER OF STUDENTS' OUTPUT   = " << output[highestNumOutput] << " (" << uniName[highestNumOutput] << ") " << endl;
    outFile << endl;

    // write range
    outFile << "THE RANGE OF NUMBER OF STUDENTS' INTAKE    = " << rangeIntake << endl;
    outFile << "THE RANGE OF NUMBER OF STUDENTS' ENROLMENT = " << rangeEnrolment << endl;
    outFile << "THE RANGE OF NUMBER OF STUDENTS' OUTPUT    = " << rangeOutput<< endl;
    outFile << endl; 

    outFile << "-----------------------------------------------------------------------------------------" << endl;

    // close file
    outFile.close();

    return 0;
}

void getInput(string uniName[], int numIntakeStudents[], int numEnrolmentStudents[], int output[])
{
    // open file
    ifstream inFile("input.txt");

    // check
    if (!inFile)
    {
        cout << "Error: Cannot open input file" << endl;
        exit(1);
    }

    int count = 0;
    while (inFile >> uniName[count] >> numIntakeStudents[count] >> numEnrolmentStudents[count] >> output[count])
    {
        count++;
    }
    // close file
    inFile.close();
}

int calcTotal(int arr[])
{
    int total = 0;
    for (int i = 0; i < SIZE; i++)
    {
        total += arr[i];
    }
    return total;
}

int getLowest(int arr[])
{
    int indexLowest = 0;
    for (int i=0; i < SIZE; i++)
    {
        if (arr[i] < arr[indexLowest])
        {
            indexLowest = i;
        }
    }
    return indexLowest;
}

int getHighest(int arr[])
{
    int indexHighest = 0;
    for (int i=0; i < SIZE; i++)
    {
        if (arr[i] > arr[indexHighest])
        {
            indexHighest = i;
        }
    }
    return indexHighest;
}

double calcAverage(int total)
{
    double totalAvg = static_cast<double>(total) / SIZE;
    return totalAvg;
}