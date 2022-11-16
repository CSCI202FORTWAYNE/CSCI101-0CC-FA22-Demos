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
    G = 67,
    H
};
const int TOTAL_PROD = 8;

const char productCodes[TOTAL_PROD] = {'A','B','C','D','E','F','G','H'};
const productType products[TOTAL_PROD] = {A, B, C, D, E, F, G, H};
const double productPrices[TOTAL_PROD] = {17.46, 10.13, 2.11, 23.13, 74.56, 1.11, 9.34, 3.45};
const string productOutput[TOTAL_PROD] = {"A", "B", "C", "D", "E", "F", "G", "H"};


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

    
    return 0;
}

productType getProduct(char p)
{
    for(int i = 0; i < TOTAL_PROD; i++)
    {
        if(p == productCodes[i])
        {
            return products[i];
        }
    }
    return products[0];
}

double calculateLineTotal(productType p, int q)
{
    double line;
    int i;
    for(i = 0; i < TOTAL_PROD; i++)
    {
        if(products[i] == p)
            break;
    }
    line = productPrices[i] * q;
   

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
    for(int i = 0; i < TOTAL_PROD; i++)
    {
        if(p == products[i])
            return productOutput[i];
    }
    return "Unknown Product";
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
