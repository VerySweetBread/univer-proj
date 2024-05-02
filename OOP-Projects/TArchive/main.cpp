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
    InputSystem::InsertMode mode;

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
            if (mode == InputSystem::InsertMode::OneValue) {
                try {
                    archive.insert(values[0], pos);
                    success = true;
                }
                catch (std::exception err) {
                    std::cerr << err.what() << std::endl;
                }
            }
            else {
                std::cout << "TBD" << std::endl;
            }
            if (success) {
                OutputSystem::insert();
            }
            pause;
            break;
        case Actions::FIND:
            IC("Not implemented");
            pause;
            break;
        case Actions::REMOVE:
            IC("Not implemented");
            pause;
            break;
        case Actions::CLEAN:
            IC("Not implemented");
            break;
        }
    }

    return 0;
}
