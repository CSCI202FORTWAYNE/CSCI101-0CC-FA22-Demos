#include <iostream>
#include <string>
#include <climits>

using namespace std;

const int SIZE = 100; 

bool validateInput();
void initialize(int[], int);
void inputData(int[], int);
void printData(int[], int);
void sumAndAvg(int[], int, int&, double&);
void findLargest(int[], int, int&);
void twoDArray(int table[5][7],int,int);

int main()
{
    int table[5][7];
    table[4][4];
    int list[SIZE];
    /*int s;
    cout << "How many numbers do you want to work with? ";
    cin >> s;*/

    initialize(list, SIZE);
    inputData(list,SIZE);
    printData(list,SIZE);

    int sum = 0;
    double avg;
    sumAndAvg(list, SIZE, sum, avg);

    cout << "The sum of the items is " << sum << endl;
    cout << "The average of the items is " << avg << endl;

    int largestPos = 0;
    findLargest(list, SIZE, largestPos);

    cout << "The largest element is " << list[largestPos] 
         << " found at position " << largestPos << endl;
    

    return 0;
}

bool validateInput()
{
    if(!cin)
    {
        cout << "You entered something that is not a number." << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        return false;
    }
    return true;
}

void initialize(int l[], int size)
{
    for(int i = 0; i < size; i++) //i = i + 1;
    {
        l[i] = 0;
    }
}

void inputData(int l[], int size)
{
    for(int i = 0; i < size; i++)
    {
        bool valid = false;
        while(!valid)
        {
            cout << "Enter a number (" << i << "): ";
            cin >> l[i];
            cout << endl;
            valid = validateInput();
        }
    }
}

void printData(int l[], int size)
{
    for(int i = 0; i < SIZE; i++)
    {
        cout << l[i] << endl;
    }
}

void sumAndAvg(int l[], int size, int& sum, double& avg)
{
    sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += l[i]; //sum = sum + l[i];
    }
    avg = static_cast<double>(sum) / size;
}

void findLargest(int l[], int size, int& largestPos)
{
    largestPos = 0;
    for(int i = 1; i < SIZE; i++)
    {
        if(l[largestPos] < l[i])
        {
            largestPos = i;
        }
    }
}