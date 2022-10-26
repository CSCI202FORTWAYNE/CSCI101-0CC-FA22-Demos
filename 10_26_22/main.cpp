#include <iostream>
#include <cmath>
#include <string>
#include <climits>
#include <cctype>
#include <fstream>

using namespace std;

double getDoubleGreaterThan0(string prompt);
char getMemUnits();
long getbytes(double memSize, char unit);
int secret(int);
double secret(double);
void readLineFromFile(ifstream &, int &, double &);
char gradeFromScore(double);
const double PI = 3.14;

int main()
{
    int mar;
    double memorySize = getDoubleGreaterThan0("Enter the memory size: ");
    char unit = getMemUnits();
    long bytes = getbytes(memorySize, unit);
    cout << "The minimum MAR size for " << memorySize << " " << unit << "B (" << bytes << " bytes)";
    cout << " of memory is " << ceil(log2(bytes)) << " bits." << endl;
    bytes = getbytes(16, 'G');
    
    cout << secret(3) << endl;

    string sentence;
    cout << "Enter a sentence: ";
    getline(cin >> ws, sentence);
    cout << endl;
    cout << sentence << endl;

    ifstream grades;
    grades.open("grades.txt"); //\\wsl$\Ubuntu\home\avenable11\CSCI101-FA22-W\10_03_22
    int studentNum;
    double score;
    while (!grades.eof())
    {
        readLineFromFile(grades, studentNum, score);
        char grade = gradeFromScore(score);
        cout << studentNum << " - " << grade << endl;
    }

    return 0;
}

double getDoubleGreaterThan0(string prompt)
{
    double x;
    cout << prompt;
    cin >> x;
    cout << endl;
    while (!cin || x <= 0)
    {
        if (!cin)
        {
            cout << "You entered something that is not a number." << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        else
        {
            cout << "The number should be greater than 0." << endl;
        }
        cout << prompt;
        cin >> x;
        cout << endl;
    }
    return x;
}

char getMemUnits()
{
    char unit;
    cout << "Enter the units (B = bytes, K = KB, M = MB, G = GB, T = TB): ";
    cin >> unit;
    cout << endl;
    unit = toupper(unit);
    while (unit != 'B' && unit != 'K' && unit != 'M' && unit != 'G' && unit != 'T')
    {
        cout << "You entered invalid units." << endl;
        cout << "Enter the units (B = bytes, K = KB, M = MB, G = GB, T = TB): ";
        cin >> unit;
        cout << endl;
        unit = toupper(unit);
    }

    return unit;
}

long getbytes(double memSize, char unit)
{
    long bytes;

    if (unit == 'B')
    {
        bytes = ceil(memSize);
    }
    else if (unit == 'K')
    {
        bytes = ceil(memSize * pow(2, 10));
    }
    else if (unit == 'M')
    {
        bytes = ceil(memSize * pow(2, 20));
    }
    else if (unit == 'G')
    {
        bytes = ceil(memSize * pow(2, 30));
    }
    else if (unit == 'T')
    {
        bytes = ceil(memSize * pow(2, 40));
    }
    return bytes;
}

int secret(int x)
{
    if (x > 5)
        return 2 * x;

    return x;
}

void readLineFromFile(ifstream &in, int &num, double &score)
{
    in >> num >> score;
}

char gradeFromScore(double score)
{
    if (score >= 90)
    {
        return 'A';
    }
    else if (score >= 80)
    {
        return 'B';
    }
    else if (score >= 70)
    {
        return 'C';
    }
    else if (score >= 60)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}