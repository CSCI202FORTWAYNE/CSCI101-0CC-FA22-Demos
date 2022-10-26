#include <iostream>
#include <cmath>
#include <string>
#include <climits>
#include <cctype>

using namespace std;

int main()
{
    int mar;
    double memorySize;
    char unit;
    long bytes;

    cout << "Enter the memory size: ";
    cin >> memorySize;
    cout << endl;
    while (!cin || memorySize <= 0)
    {
        if (!cin)
        {
            cout << "You entered something that is not a number." << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        else
        {
            cout << "The memory size should be greater than 0." << endl;
        }
        cout << "Enter the memory size: ";
        cin >> memorySize;
        cout << endl;
    }

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

    if(unit == 'B')
    {
        bytes = ceil(memorySize);
    }
    else if (unit == 'K')
    {
        bytes = ceil(memorySize * pow(2,10));
    }
    else if (unit == 'M')
    {
        bytes = ceil(memorySize *pow(2,20));
    } 
    else if (unit == 'G')
    {
        bytes = ceil(memorySize * pow(2,30));
    }
    else if (unit == 'T')
    {
        bytes = ceil(memorySize * pow(2,40));
    }
    cout << "The minimum MAR size for " << memorySize <<  " " << unit << "B (" << bytes << " bytes)";
    cout << " of memory is " << ceil(log2(bytes)) << " bits." << endl; 

    return 0;
}