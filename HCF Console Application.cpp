#include <iostream>
#include <vector>

/********************************************************************
Author         ->  Daniel Glover - Akpey aka DNA Programmers
Date           ->  21th September 2020
Instagram      ->  @dnaprogrammers & @danielglover607
Twitter        ->  @dnaprogrammers
Facebook Page  ->  DNA Programmers
IDE            ->  Code::Blocks 20.03
Complier       ->  G++ ver 8, MingW W64 GCC-8.1.0 x86_64-win32-seh
*********************************************************************/

namespace myVector
{
    std::vector<int> allUserInput{};
}

int getNumberOfInputs();

void getUserInputs(int numOfInput);

int GCD(int firstNumber, int secondNumber);

int calculateHCF();

int main()
{
    int numOfUserInput{getNumberOfInputs()};
    getUserInputs(numOfUserInput);

    std::cout << "The HCF is: " << calculateHCF() << '\n';
    return 0;
}

int getNumberOfInputs()
{
    std::cout << "How many numbers do you want to find HCF: ";
    int numOfInputs{};
    std::cin >> numOfInputs;

    return numOfInputs;
}

void getUserInputs(int numOfInput)
{
    for(int Iterator{1}; Iterator <= numOfInput; ++Iterator){
        std::cout << "Enter number #" << Iterator << ": ";
        int userInput{};
        std::cin >> userInput;
        myVector::allUserInput.push_back(userInput);
    }
}

int GCD(int firstNumber, int secondNumber)
{
    return ((firstNumber == 0) ? secondNumber : GCD(secondNumber % firstNumber, firstNumber));
}

int calculateHCF()
{
    int HCF{myVector::allUserInput.at(0)};
    for(std::size_t Iterator{1}; Iterator < myVector::allUserInput.size(); ++Iterator){
        HCF = GCD(myVector::allUserInput.at(Iterator), HCF);

        if(HCF == 1){
            return 1;
        }
    }
    return HCF;
}
