#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    /*
    int winning = 57;
    int user = 0;
    char day;

    cout << "Enter a number: ";
    cin >> user;
    cout << endl;

    cout << "Enter the day: ";
    cin >> day;
    cout << endl;

    if(user <= winning || day == 'W')
    {
        if(day == 'W')
        {
            cout << "I always win on Wednesday!" << endl;
        }
        cout << "I win!!!!" << endl;
        cout << "You lose!!" << endl;
    }
    else
    {
        cout << "I didn't win :(" << endl;
        cout << "I'll beat you next Wednesday!" << endl;
    }
    cout << "Thank you for playing." << endl;
    cout << "Goodbye!" << endl;

    if(3.0/7.0 + 2.0/7.0 + 2.0/7.0 == 1.0)
        cout << 3.0/7.0 + 2.0/7.0 + 2.0/7.0 << endl;
*/
   
    /* int num;
    cout << "Enter an integer: ";
    cin >> num;
    if(!cin)
    {
        cout << "You entered something that is not a number!" << endl;
        return 0;
    }
    else if (num < 0) 
    {
        cout << "please enter a positive number" << endl;
    }
    cout << endl;
    if(0 <= num && num <= 10)
        cout << num << " is within 0 and 10." << endl;
    else 
        cout << num << " is not within 0 and 10." << endl; */

    ifstream infile;
    infile.open("grades.txt");

    int student1, student2, student3;
    double grade1, grade2, grade3;
    int userStudent;

    infile >> student1 >> grade1;
    infile >> student2 >> grade2;
    infile >> student3 >> grade3;

    if(grade1 >= 90)
    {
        cout << student1 << " has earned an A." << endl;
    }
    else 
    {
        cout << student1 << " did not earn an A." << endl;
    }
    if(grade2 >= 90)
    {
        cout << student2 << " has earned an A." << endl;
    }
    else 
    {
        cout << student2 << " did not earn an A." << endl;
    }
    if(grade3 >= 90)
    {
        cout << student3 << " has earned an A." << endl;
    }
    else 
    {
        cout << student3 << " did not earn an A." << endl;
    }

    cout << "Enter your five digit student id: ";
    cin >> userStudent;
    cout << endl;

    //input validation

    if(userStudent == student1)
    {
        if(grade1 >= 90)
        {
            cout << "You have earned an A." << endl;
        }
        else if (grade1 >= 80)
        {
            cout << "You have earned a B." << endl;
        }
        else if(grade1 >= 70)
        {
            cout << "You have earned a C." << endl;
        }
        else if(grade1 >= 60)
        {
            cout << "You have earned a D." << endl;
        }
        else
        {
            cout << "You have earned a F." << endl;
        }
    }

    else if(userStudent == student2)
    {
        if(grade2 >= 90)
        {
            cout << "You have earned an A." << endl;
        }
        else if (grade2 >= 80)
        {
            cout << "You have earned a B." << endl;
        }
        else if(grade2 >= 70)
        {
            cout << "You have earned a C." << endl;
        }
        else if(grade2 >= 60)
        {
            cout << "You have earned a D." << endl;
        }
        else
        {
            cout << "You have earned a F." << endl;
        }
    }

    else if(userStudent == student3)
    {
        if(grade3 >= 90)
        {
            cout << "You have earned an A." << endl;
        }
        else if (grade3 >= 80)
        {
            cout << "You have earned a B." << endl;
        }
        else if(grade3 >= 70)
        {
            cout << "You have earned a C." << endl;
        }
        else if(grade3 >= 60)
        {
            cout << "You have earned a D." << endl;
        }
        else
        {
            cout << "You have earned a F." << endl;
        }
    }
    else 
    {
        cout << "Your grade information is not in the file." << endl;
    }

    return 0;
}