#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    cout << setprecision(2) << fixed << showpoint;
    double length = 0;
    double width = 0;
    double area = 0;

    length = 7;
    width = 12;
    cout << "Enter the length of the rectangle: ";
    cin >> length;
    cout << endl;

    cout << "Enter the width of the rectangle: ";
    cin >> width;
    cout << endl;

    area = length * width;
    cout << "area = " << area << endl;

    int x = 5.0;
    int y = 2;

    double z = static_cast<double>(x) / y;
    cout << "5/2 is " << z << endl;

    string name = "Angela Venable";
    string myStr;

    cout << "Enter something: ";
    getline(cin >> ws, myStr);
    cout << "You entered " << myStr << endl;

    double answer = pow(length, width);

    cout << setfill('-') << left;
    cout << "+" << setw(20) << "-" << "+" << setw(20) << "-" << "+" << setw(20) << "-" << "+"<< endl;
    cout << setfill(' ');
    cout << "|"<<setw(20) << "Length" << "|" << setw(20) << "Width" << "|" << setw(20) << "Area" << "|"<< endl;
    cout << setfill('-') << left;
    cout << "+" << setw(20) << "-" << "+" << setw(20) << "-" << "+" << setw(20) << "-" << "+"<< endl;
    cout << setfill(' ');
    cout << "|"<<setw(20) << length << "|" << setw(20) << width << "|" << setw(20) << area << "|"<< endl;
    cout << setfill('-');
    cout << "+"<< setw(20) << "-" << "+" << setw(20) << "-" << "+" << setw(20) << "-" << "+"<< endl;
    return 0;
}













