#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cctype>

//using namespace std;
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::setw;
using std::setfill;
using std::left;

enum productType
{
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H
};

/*
const int A = 0;
const int B = 1;
const int C = 2;*/
const double TAX_RATE = .17;
const double SHIPPING = 14.95;

productType getProduct(char);
double calculateLineTotal(productType, int);
void outputTableHeading();
void outputProdLine(productType, int, double);
std::string outputProduct(productType);
void outputBottomTableRow(std::string, double);
string toLowerCaseStr(string);

int main()
{
    std::cout << std::setprecision(2) << std::fixed << std::showpoint;
    productType product = A;
    char prodCode;
    int quantity;
    double subTotal = 0;
    double tax;
    double lineTotal;

    std::ifstream order;
    order.open("order.txt");
    outputTableHeading();
    while (!order.eof())
    {
        order >> prodCode >> quantity;
        product = getProduct(prodCode);
        lineTotal = calculateLineTotal(product, quantity);
        subTotal += lineTotal; // subTotal = subTotal + lineTotal;
        outputProdLine(product, quantity, lineTotal);
    }
    outputBottomTableRow("Subtotal", subTotal);
    tax = TAX_RATE * subTotal;
    outputBottomTableRow("Tax", tax);
    outputBottomTableRow("Shipping", SHIPPING);
    outputBottomTableRow("Grand Total", subTotal + tax + SHIPPING);

    string str = "Have a nice day!";
    str[0] = 'D';
    cout << str << endl;

    return 0;
}

productType getProduct(char p)
{
    switch (p)
    {
    case 'A':
        return A;
    case 'B':
        return B;
    case 'C':
        return C;
    case 'D':
        return D;
    case 'E':
        return E;
    case 'F':
        return F;
    case 'G':
        return G;
    case 'H':
        return H;
    default:
        return A;
    }
}

double calculateLineTotal(productType p, int q)
{
    double line;
    switch (p)
    {
    case A:
        line = 17.46 * q;
        break;
    case B:
        line = 10.13 * q;
        break;
    case C:
        line = 2.11 * q;
        break;
    case D:
        line = 23.13 * q;
        break;
    case E:
        line = 74.56 * q;
        break;
    case F:
        line = 1.11 * q;
        break;
    case G:
        line = 9.34 * q;
        break;
    case H:
        line = 3.45 * q;
        break;
    default:
        line = 0;
    }

    return line;
}

void outputTableHeading()
{
    cout << "Thank You! Your order is summarized below:" << endl;
    cout << setw(52) << setfill('-') << "-" << endl;
    cout << setfill(' ');
    cout << "| " << setw(15) << left << "Product"
         << "| " << setw(15) << "Quantity"
         << "| " << setw(15) << "Line Total"
         << "|" << endl;
    cout << setw(52) << setfill('-') << "-" << endl;
    cout << setfill(' ');
}

void outputProdLine(productType p, int q, double l)
{
    cout << "| " << setw(15) << left << outputProduct(p) << "| " << setw(15) << q
         << "| $" << setw(15) << l << "|" << endl;
    cout << setw(52) << setfill('-') << "-" << endl;
    cout << setfill(' ');
}

string outputProduct(productType p)
{
    switch (p)
    {
    case A: return "A";
    case B: return "B";
    case C: return "C";
    case D: return "D";
    case E: return "E";
    case F: return "F";
    case G: return "G";
    case H: return "H";
    default: return "Unknown Product";
    }
}

void outputBottomTableRow(string label, double value)
{
    cout << "| " << setw(15) << left << label << "| " << setw(15) << " "
         << "| $" << setw(15) << value << "|" << endl;
    cout << setw(52) << setfill('-') << "-" << endl;
    cout << setfill(' ');
}

string toLowerCaseStr(string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}
