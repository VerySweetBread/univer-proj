#include <iostream>
#include "archive.h"
#include "utilities.h"
#include "icecream.hpp"

#define pause system("read -p \"Press any key to resume ...\"")

enum Actions { EXIT, INSERT, FIND, REMOVE, CLEAN };

int main() {
    TArchive<int> archive;
    size_t n, pos;
    int* values = nullptr;
    int user;

    std::exception err;
    bool exit = false;
    bool success;
    InputSystem::InsertMode mode; // TODO: delete this

    while (!exit) {
        system("clear");
        OutputSystem::show(archive);
        std::cout
            << "Menu:\n"
            << "1. insert,\n"
            << "2. find,\n"
            << "3. delete,\n"
            << "4. clean,\n"
            << "0. exit.\n"
            << "\n"
            << "Your choose: ";
        std::cin >> user;
        switch (user) {
        case Actions::EXIT:
            exit = true;
            break;
        case Actions::INSERT:
            if (values != nullptr) { delete[] values; values = nullptr; }
            values = InputSystem::insert<int>(n, pos, mode);
            success = false;
            try {
                switch (mode) {
                    case InputSystem::InsertMode::OneValue:
                        archive.insert(values[0], pos);
                        success = true;
                        break;

                    case InputSystem::InsertMode::SeveralValues:
                        archive.insert(values, n, pos);
                        success = true;
                        break;

                    case InputSystem::InsertMode::Back:
                        archive.push_back(values[0]);
                        success = true;
                        break;

                    case InputSystem::InsertMode::Front:
                        archive.push_front(values[0]);
                        success = true;
                        break;
                }
            } catch (std::exception err) {
                std::cerr << err.what() << std::endl;
            }

            if (success) {
                OutputSystem::insert();
            }
            pause;
            break;
        case Actions::FIND:
            size_t value, index;
            
            std::cout
                << "1 - find first\n"
                << "2 - find last\n"
                << "3 - find all\n";
            std::cin >> user;

            switch (user) {
                case 1:
                    std::cout << "Enter value: ";
                    std::cin >> value;
                    if ((index = archive.find_first(value)) == -1)
                        std::cout << "Not found" << std::endl;
                    else
                        std::cout << index << std::endl;
                    break;

                case 2:
                    std::cout << "Enter value: ";
                    std::cin >> value;
                    if ((index = archive.find_last(value)) == -1)
                        std::cout << "Not found" << std::endl;
                    else
                        std::cout << index << std::endl;
                    break;

                case 3:
                    std::cout << "Enter value: ";
                    std::cin >> value;
                    size_t* indexes = archive.find_all(value);
                    if (indexes[0]) {
                        for (size_t i = 1; i <= indexes[0]; i++)
                            std::cout << indexes[i] << ", ";
                        std::cout << std::endl;
                    } else
                        std::cout << "Not found" << std::endl;
            }
            
            pause;
            break;
        case Actions::REMOVE:
            std::cout
                << "1 - remove first\n"
                << "2 - remove last\n"
                << "3 - remove by index\n"
                << "4 - remove by value\n"
                << "\n"
                << "Your choice: ";
            std::cin >> user;

            switch (user) {
                case 1:
                    std::cout << "Value: ";
                    std::cin >> value;
                    archive.remove_first(value);
                    break;
                case 2:
                    std::cout << "Value: ";
                    std::cin >> value;
                    archive.remove_last(value);
                    break;
                case 3:
                    std::cout << "Index: ";
                    std::cin >> value;
                    archive.remove(value);
                    break;
                case 4:
                    std::cout << "Value: ";
                    std::cin >> value;
                    archive.remove_all(value);
            }
                        
            break;
        case Actions::CLEAN:
            archive.clear();
            break;
        }
    }

    return 0;
}
