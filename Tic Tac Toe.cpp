#include <iostream>
#include <windows.h>
#include <limits>

/****************************************************
Author         -  Daniel Glover - Akpey
Date           -  7th September, 2020 ~ 8th September, 2020
Instagram      -  @codingnewbies
Twitter        -  @codingnewbies
IDE            -  Code::Blocks 20.03
Complier       -  G++ ver 8, MingW W64 GCC-8.1.0 x86_64-win32-seh
*****************************************************/

namespace GameBoardDigits
{
    char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
    int player{1};
    char mark{};
}

void gameBoard();

int getUserNumber();

void clearConsole();

void changeBoard(int userNum);

void errorHandler();

int whoWon();

void win();

int main()
{
    do{
       getUserNumber();
    }while(whoWon() == -1);
    gameBoard();
    win();

    return 0;
}

void win()
{
    if(whoWon() == 1 && GameBoardDigits::mark == 'X'){
        std::cout << "Player 1 won!!";
    }else if(whoWon() == 1 && GameBoardDigits::mark == 'O'){
        std::cout << "Player 2 won!!";
    }else{
        std::cout << "It was a draw!!";
    }
}

int whoWon()
{
    if (GameBoardDigits::square[1] == GameBoardDigits::square[2] && GameBoardDigits::square[2] == GameBoardDigits::square[3]){
        return 1;
    }else if (GameBoardDigits::square[4] == GameBoardDigits::square[5] && GameBoardDigits::square[5] == GameBoardDigits::square[6]){
        return 1;
    }else if (GameBoardDigits::square[7] == GameBoardDigits::square[8] && GameBoardDigits::square[8] == GameBoardDigits::square[9]){
        return 1;
    }else if (GameBoardDigits::square[1] == GameBoardDigits::square[4] && GameBoardDigits::square[4] == GameBoardDigits::square[7]){
        return 1;
    }else if (GameBoardDigits::square[2] == GameBoardDigits::square[5] && GameBoardDigits::square[5] == GameBoardDigits::square[8]){
        return 1;
    }else if (GameBoardDigits::square[3] == GameBoardDigits::square[6] && GameBoardDigits::square[6] == GameBoardDigits::square[9]){
        return 1;
    }else if (GameBoardDigits::square[1] == GameBoardDigits::square[5] && GameBoardDigits::square[5] == GameBoardDigits::square[9]){
        return 1;
    }else if (GameBoardDigits::square[3] == GameBoardDigits::square[5] && GameBoardDigits::square[5] == GameBoardDigits::square[7]){
        return 1;
    }else if (GameBoardDigits::square[1] != '1' && GameBoardDigits::square[2] != '2' && GameBoardDigits::square[3] != '3'
                && GameBoardDigits::square[4] != '4' && GameBoardDigits::square[5] != '5' && GameBoardDigits::square[6] != '6'
                && GameBoardDigits::square[7] != '7' && GameBoardDigits::square[8] != '8' && GameBoardDigits::square[9] != '9'){
        return 0;
    }else
        return -1;
}

void changeBoard(int userNum)
{
    if(userNum == 1 && GameBoardDigits::square[userNum] == '1'){
        GameBoardDigits::square[1] = GameBoardDigits::mark;
    }else if(userNum == 2 && GameBoardDigits::square[2] == '2'){
        GameBoardDigits::square[2] = GameBoardDigits::mark;
    }else if(userNum == 3 && GameBoardDigits::square[3] == '3'){
        GameBoardDigits::square[3] = GameBoardDigits::mark;
    }else if(userNum == 4 && GameBoardDigits::square[4] == '4'){
        GameBoardDigits::square[4] = GameBoardDigits::mark;
    }else if(userNum == 5 && GameBoardDigits::square[5] == '5'){
        GameBoardDigits::square[5] = GameBoardDigits::mark;
    }else if(userNum == 6 && GameBoardDigits::square[6] == '6'){
        GameBoardDigits::square[6] = GameBoardDigits::mark;
    }else if(userNum == 7 && GameBoardDigits::square[7] == '7'){
        GameBoardDigits::square[7] = GameBoardDigits::mark;
    }else if(userNum == 8 && GameBoardDigits::square[8] == '8'){
        GameBoardDigits::square[8] = GameBoardDigits::mark;
    }else if(userNum == 9 && GameBoardDigits::square[9] == '9'){
        GameBoardDigits::square[9] = GameBoardDigits::mark;
    }else if(std::cin.fail()){
        errorHandler();
    }else{
        std::cout<<"Invalid move ";

        --GameBoardDigits::player;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }
}

void errorHandler()
{
    std::cout << "That is not a number.";
    std::cin.clear();
    --GameBoardDigits::player;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

int getUserNumber()
{
    gameBoard();

    GameBoardDigits::player = ((GameBoardDigits::player % 2) ? 1 : 2);

    std::cout << "Player " << GameBoardDigits::player << ", enter a number(1-9): ";
    int userNumber{};
    std::cin >> userNumber;

    if(GameBoardDigits::player == 3)
        GameBoardDigits::player = 1;

    GameBoardDigits::mark = ((GameBoardDigits::player == 1) ? 'X' : 'O');

    ++GameBoardDigits::player;

    changeBoard(userNumber);

    return userNumber;
}

void gameBoard()
{
    clearConsole();

    std::cout << "\n\n\t\tTic Tac Toe Console Application\n\n";
    std::cout << "\tPlayer 1 (X) - Player 2 (O)\n\n\n";

    std::cout << "\t     |     |     \n";
    std::cout << "\t  " << GameBoardDigits::square[1] << "  |  " << GameBoardDigits::square[2] << "  |  " << GameBoardDigits::square[3] << '\n';

    std::cout << "\t_____|_____|_____\n";
    std::cout << "\t     |     |     \n";

    std::cout << "\t  " << GameBoardDigits::square[4] << "  |  " << GameBoardDigits::square[5] << "  |  " << GameBoardDigits::square[6] << '\n';

    std::cout << "\t_____|_____|_____\n";
    std::cout << "\t     |     |     \n";

    std::cout << "\t  " << GameBoardDigits::square[7] << "  |  " << GameBoardDigits::square[8] << "  |  " << GameBoardDigits::square[9] << '\n';
    std::cout << "\t     |     |     \n\n";
}

void clearConsole()
{
    HANDLE                      hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO  csbi;
    DWORD                       count;
    DWORD                       cellCount;
    COORD                       homeCoords = {0,0};

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if(hStdOut == INVALID_HANDLE_VALUE) return;

    if(!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    if(!FillConsoleOutputCharacter(
        hStdOut,
        (TCHAR) ' ',
        cellCount,
        homeCoords,
        &count
        )) return;

    if(!FillConsoleOutputAttribute(
        hStdOut,
        csbi.wAttributes,
        cellCount,
        homeCoords,
        &count
        )) return;

    SetConsoleCursorPosition(hStdOut, homeCoords);
}
