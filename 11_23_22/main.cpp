#include <iostream>
#include <string>
#include <fstream>
#include <climits>

using namespace std;

const int NUM_COLORS = 6;
const int DECK_SIZE = 60;
const int BOARD_SIZE = 115;
const int MAX_PLAYERS = 6;

enum colorType
{
    START = -1,
    RED,
    PURPLE,
    YELLOW,
    GREEN,
    BLUE,
    ORANGE
};
const colorType colors[] = {RED, PURPLE, YELLOW, GREEN, BLUE, ORANGE};
const string colorName[] = {"Red", "Purple", "Yellow", "Green", "Blue", "Orange"};
const string colorStr[] = {"\033[38;5;196m\033[48;5;88m",
                           "\033[38;5;135m\033[48;5;53m",
                           "\033[38;5;226m\033[48;5;178m",
                           "\033[38;5;118m\033[48;5;2m",
                           "\033[38;5;81m\033[48;5;4m",
                           "\033[38;5;214m\033[48;5;166m"};
const string STARTCOLOR = "\033[1m";
const string RESETCOLOR = "\033[0m";

struct cardType
{
    colorType color;
    bool isDouble = false;
};

struct deckType
{
    cardType deck[DECK_SIZE];
    bool used[DECK_SIZE];
    int numUsed;
};

struct playerType
{
    string name;
    colorType color;
    int position = 0;
};

struct playerListType
{
    playerType playerList[MAX_PLAYERS];
    int numPlayers;
};

string printConsoleColor(colorType);
string printCard(cardType);
void generateBoard(colorType[], int);
void printBoard(colorType[], int, playerListType&);
void generateDeck(deckType &, int);
playerType createAPlayer(int);
int getNumPlayers();
void resetStream();
colorType inputColor();
void setupPlayers(playerListType &);
void printColorMenu();
void printPlayerOnBoard(playerListType&, int, string);
int drawCard(deckType&);
void startGame(playerListType&, deckType&, colorType[], int);
void takeTurn(playerType&, deckType&, colorType[], int, bool&);

int main()
{
    colorType board[BOARD_SIZE];
    generateBoard(board, BOARD_SIZE);
    deckType theDeck;
    generateDeck(theDeck, DECK_SIZE);
    playerListType pl;
    setupPlayers(pl);
    printBoard(board, BOARD_SIZE, pl);
    startGame(pl, theDeck, board, BOARD_SIZE);
    cout << "Game Over! Thanks for playing!" << endl;

    return 0;
}

string printConsoleColor(colorType c)
{
    string out = STARTCOLOR;
    if (c == START)
    {
        out = RESETCOLOR;
    }
    else
    {
        out += colorStr[c];
    }
    return out;
}

string printCard(cardType theCard)
{
    string doubled = "";
    int num = 1;
    if (theCard.isDouble)
    {
        doubled = "Double ";
        num = 2;
    }
    string output = doubled + colorName[theCard.color] + " ";
    for (int i = 0; i < num; i++)
    {
        output += printConsoleColor(theCard.color) + "[ ]";
        output += RESETCOLOR + " ";
    }
    return output;
}

void generateBoard(colorType board[], int spaces)
{
    ifstream in;
    in.open("boardSequence.txt");
    board[0] = START;
    for (int i = 1; i < spaces; i++)
    {
        int c;
        in >> c;
        board[i] = colors[c % NUM_COLORS];
    }
    in.close();
}

void printBoard(colorType board[], int spaces, playerListType& pl)
{
    for (int i = 0; i < spaces; i++)
    {
        cout << printConsoleColor(board[i]) << "[ ";
        printPlayerOnBoard(pl,i,printConsoleColor(board[i]));
        cout << " ]";
        cout << RESETCOLOR << " ";
        if ((i + 1) % 5 == 0)
        {
            cout << endl
                 << endl;
        }
    }
}

void generateDeck(deckType &theDeck, int deckSize)
{
    for (int i = 0; i < NUM_COLORS; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            theDeck.deck[i * 10 + j].color = colors[i];
            theDeck.deck[i * 10 + j].isDouble = (j >= 6);
            theDeck.used[i * 10 + j] = false;
        }
    }
}

playerType createAPlayer(int n)
{
    playerType newPlayer;
    cout << "Player " << n << " enter your name: ";
    getline(cin >> ws, newPlayer.name);
    return newPlayer;
}

int getNumPlayers()
{
    int numPlayers;
    cout << "Enter the number of players between 2 and " << MAX_PLAYERS << ": ";
    cin >> numPlayers;
    cout << endl;
    while (!cin || numPlayers < 2 || numPlayers > MAX_PLAYERS)
    {
        if (!cin)
        {
            resetStream();
        }
        cout << "That is not a valid value." << endl;
        cout << "Enter the number of players between 2 and " << MAX_PLAYERS << ": ";
        cin >> numPlayers;
        cout << endl;
    }
    return numPlayers;
}

void resetStream()
{
    cin.clear();
    cin.ignore(INT_MAX, '\n');
}
void printColorMenu()
{
    cout << "Choose a color" << endl;
    for (int i = 0; i < NUM_COLORS; i++)
    {
        cout << i + 1 << ": " << colorName[i] << endl;
    }
    cout << "Your Choice: ";
}

colorType inputColor()
{
    colorType c;
    int colorInt;
    printColorMenu();
    cin >> colorInt;
    cout << endl;

    while (!cin || colorInt < 1 || colorInt > NUM_COLORS)
    {
        if (!cin)
        {
            resetStream();
        }
        cout << "That is not a valid choice." << endl;
        printColorMenu();
        cin >> colorInt;
        cout << endl;
    }
    c = colors[colorInt - 1];
    return c;
}

void setupPlayers(playerListType &pl)
{
    pl.numPlayers = getNumPlayers();
    for (int i = 0; i < pl.numPlayers; i++)
    {
        pl.playerList[i] = createAPlayer(i + 1);
        cout << "Hello " << pl.playerList[i].name << "! You can now pick a color." << endl;
        pl.playerList[i].color = inputColor();
        for (int j = 0; j < i; j++)
        {
            if (pl.playerList[j].color == pl.playerList[i].color)
            {
                cout << pl.playerList[j].name 
                     << " has already picked that color. Please pick again." << endl;
                pl.playerList[i].color = inputColor();
                j = -1;
            }
        }
    }
}

void printPlayerOnBoard(playerListType& pl, int boardSpace, string spaceColor)
{
    for(int i = 0; i < pl.numPlayers; i++)
    {
        if(pl.playerList[i].position == boardSpace)
        {
            cout << printConsoleColor(pl.playerList[i].color);
            cout << i + 1;
            cout << spaceColor;
        }
        else
        {
            cout << " ";
        }
    }
}

int drawCard(deckType& d)
{
    static ifstream in("gameplay.txt");

    if(d.numUsed == DECK_SIZE)
    {
        cout << "All the cards in the deck have been used. Resetting deck." << endl;
        d.numUsed = 0;
        for(int i = 0; i < DECK_SIZE; i++)
        {
            d.used[i] = false;
        }
    }
    if(!in.is_open())
    {
        in.open("gameplay.txt");
    }
    bool valid = false;
    int card;
    while(!valid && !in.eof())
    {
        in >> card;
        if(d.used[card])
        {
            continue;
        }
        else
        {
            valid = true;
            d.used[card] = true;
            d.numUsed++;
        }
    }

    if(in.eof())
    {
        in.close();
    }
    return card;

}

void startGame(playerListType& pl, deckType& d, colorType b[], int boardSize)
{
    bool winner = false;
    while(!winner)
    {
        for(int i = 0; i < pl.numPlayers; i++)
        {
            takeTurn(pl.playerList[i], d, b, boardSize, winner);
        }
        printBoard(b, boardSize, pl);
    }
}

void takeTurn(playerType& p, deckType& d, colorType b[], int boardSize, bool& win)
{
    cout << p.name << "'s turn: " << endl;
    cout << "Press any key to draw a card.";
    cin.ignore();
    cin.get();
    cardType playerCard = d.deck[drawCard(d)];
    cout << p.name << " drew a " << printCard(playerCard) << endl;
    int num = 1;
    if(playerCard.isDouble)
    {
        num = 2;
    }
    for(int i = 0; i < num; i++)
    {
        for(int j = p.position + 1; j < boardSize; j++)
        {
            if(playerCard.color == b[j])
            {
                p.position = j;
                break;
            }
        }
    }

    if(p.position == boardSize - 1)
    {
        cout << p.name << " has reached the end!" << endl;
        win = true;
    }
}