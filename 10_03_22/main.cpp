#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <climits>

using namespace std;

int main()
{
    ifstream infile;
    infile.open("grades.txt");

    ofstream outfile;
    outfile.open("out.txt");
    //outfile << setprecision(2) << showpoint << fixed;

    int count = 0;
    int studentNum;
    double score;
    int userNum;
    cout << "Enter your student num: ";
    cin >> userNum;
    cout << endl;
    while (!cin || userNum < 10000 || userNum > 99999)
    {
        if (!cin)
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');

            cout << "You did not enter a number. Try again." << endl;
        }
        else
        {
            cout << "Student numbers are 5 digits. Please try again." << endl;
        }
        cout << "Enter your student num: ";
        cin >> userNum;
        cout << endl;
    }
    bool isFound = false;

    while (!infile.eof())
    {
        //cout << count << " " << !infile.eof() << endl;
        infile >> studentNum >> score;
        //cout << count << " " <<!infile.eof() << endl;
        if(!infile)
        {
            break;
        } 
        if (studentNum == userNum)
        {
            isFound = true;
        }
        outfile << studentNum;
        if (score >= 90)
        {
            outfile << " has earned an A." << endl;
        }
        else if (score >= 80)
        {
            outfile << " has earned a B." << endl;
        }
        else if (score >= 70)
        {
            outfile << " has earned a C." << endl;
        }
        else if (score >= 60)
        {
            outfile << " has earned a D." << endl;
        }
        else
        {
            outfile << " has earned a F." << endl;
        }

        count++; // count = count + 1;
    }
    if (!isFound)
    {
        cout << "You were not found in the file." << endl;
    }

    int winning = rand() % 100 + 1;
    int user = 0;
    char play;
    cout << "Do you want to play? ";
    cin >> play;
    cout << endl;
    play = toupper(play);
    while(play != 'N' && play != 'Y')
    {
        cout << "I do not understand. Please enter Y or N." << endl;
        cout << "Do you want to play? ";
        cin >> play;
        cout << endl;
        play = toupper(play);
    }
    while (play != 'N')
    {
        cout << "Enter a number: ";
        cin >> user;
        cout << endl;
        while (!cin || user < 1 || user > 100)
        {
            if (!cin)
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');

                cout << "You did not enter a number. Try again." << endl;
            }
            else 
            {
                cout << "You need to enter a number between 1 and 100." << endl;
            }
            cout << "Enter a number: ";
            cin >> user;
            cout << endl;
        }

        if (user <= winning)
        {
            cout << "I win!!!!" << endl;
            cout << "You lose!!" << endl;
        }
        else
        {
            cout << "I didn't win :(" << endl;
            cout << "I'll beat you next Wednesday!" << endl;
        }

        cout << "Do you want to play again? ";
        cin >> play;
        cout << endl;
        play = toupper(play);

        while(play != 'N' && play != 'Y')
        {
            cout << "I do not understand. Please enter Y or N." << endl;
            cout << "Do you want to play again? ";
            cin >> play;
            cout << endl;
            play = toupper(play);
        }

        winning = rand() % 100 + 1;
    }
    cout << "Thank you for playing." << endl;
    cout << "Goodbye!" << endl;

    return 0;
}