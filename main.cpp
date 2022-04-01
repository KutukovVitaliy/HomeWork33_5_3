#include <iostream>
#include <vector>
#include "Register.h"
#include <limits>

template<typename T1, typename T2>
void WorkWithRegister(){
    Register<T1, T2> reg;
    std::string command;
    T1 key;
    T2 value;
    while(true){
        std::cout << "Input command or type \"exit\" to exit: ";
        std::cin >> command;
        if(command == "exit") return;
        else if(command == "add")
        {
            while(true)
            {
                std::cout << "Input the key: ";
                std::cin >> key;
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Bad input! Try again." << std::endl;
                }
                else break;
            }
            while(true)
            {
                std::cout << "Input the value: ";
                std::cin >> value;
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Bad input! Try again." << std::endl;
                }
                else break;
            }
            Pair<T1, T2> pair{key, value};
            reg.AddElement(pair);
        }
        else if(command == "print")
        {
            std::cout << reg;
        }
        else if(command == "find")
        {
            std::cout << "Input key: ";
            std::cin >> key;
            std::vector<Pair<T1, T2>> result = reg.FindElements(key);
            for(auto& el : result)
            {
                std::cout << el.key << ":" << el.value << "  ";
            }
            std::cout << std::endl;
        }
        else if(command == "remove")
        {
            std::cout << "Input key: ";
            std::cin >> key;
            reg.RemoveElements(key);
        }
        else
        {
            std::cout << "Wrong command! Try again!" << std::endl;
        }
    }
}
int main() {
    WorkWithRegister<int, int>();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
