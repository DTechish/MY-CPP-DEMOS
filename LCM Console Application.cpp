#include <iostream>
#include <vector>

/********************************************************************
Author         ->  Daniel Glover
Date           ->  18th September 2020 ~ 19th September 2020
IDE            ->  Code::Blocks 20.03
Complier       ->  G++ ver 8, MingW W64 GCC-8.1.0 x86_64-win32-seh
*********************************************************************/

namespace myVector
{
    std::vector<int> allUserInputStored{};
}

int getNumberOfInput();

void getUserInput(int numOfInput);

int calculateLCM();

int GCD(int firstNumber, int secondNumber);

int main()
{
    //LCM CONSOLE APPLICATION
    int numOfValues{getNumberOfInput()};
    getUserInput(numOfValues);

    std::cout << "The LCM is: " << calculateLCM() << '\n';
    return 0;
}

int getNumberOfInput()
{
    std::cout << "How many numbers do you want to find LCM: ";
    int numOfLCMValues{};
    std::cin >> numOfLCMValues;

    return numOfLCMValues;
}

void getUserInput(int numOfInput)
{
    int userInput{};
    for(int Iterator{1}; Iterator <= numOfInput; ++Iterator){
        std::cout << "Enter number #" << Iterator << ": ";
        std::cin >> userInput;
        myVector::allUserInputStored.push_back(userInput);
    }
}

int GCD(int firstNumber, int secondNumber)
{
    return ((secondNumber == 0) ? firstNumber : GCD(secondNumber, firstNumber % secondNumber));
}

int calculateLCM()
{
    int LCM{myVector::allUserInputStored.at(0)};
    for(std::size_t Iterator{1}; Iterator < myVector::allUserInputStored.size(); ++Iterator){
        LCM = (((myVector::allUserInputStored.at(Iterator) * LCM)) / (GCD(myVector::allUserInputStored.at(Iterator),LCM)));
    }

    return LCM;
}
