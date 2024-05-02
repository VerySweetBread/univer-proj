#pragma once
#include <iostream>
#include "archive.h"
#include "icecream.hpp"
#include <ncurses.h>

/*                     —À”∆≈¡Õ€≈/¬—œŒÃŒ√¿“≈À‹Õ€≈ ‘”Õ ÷»»                     */

namespace InputSystem {
    enum InsertMode {Back, Front, OneValue, SeveralValues};

    template <typename T>
    T* insert(size_t& n, size_t& pos, InputSystem::InsertMode& mode) noexcept {
        T* value = nullptr;
        mode = Back;
        int user;
        std::cout
            << "Choose insert mode:\n"
            << "1 - to the back,\n"
            << "2 - to the front,\n"
            << "3 - at given position.\n"
            << "Your choose: ";
        std::cin >> user;
        if (user == 1) { mode = Back; }
        if (user == 2) { mode = Front; }
        if (user == 3) {
            std::cout
                << "How many values need to insert:\n"
                << "1 - one value,\n"
                << "2 - several values.\n"
                << "Your choose: ";
            std::cin >> user;
            if (user == 1) { mode = OneValue; }
            if (user == 2) { mode = SeveralValues; }
        }
        if (mode == Back || mode == Front || mode == OneValue) {
            n = 1;
            value = new T[n];
            std::cout << "Input value for insert: ";
            std::cin >> value[0];
        }
        if (mode == SeveralValues) {
            std::cout << "Input number of values for insert: ";
            std::cin >> n;
            value = new T[n];
            std::cout << "Input values for insert (between space): ";
            for (size_t i = 0; i < n; i++) {
                std::cin >> value[i];
            }
        }
        if (mode == OneValue || mode == SeveralValues) {
            std::cout << "Input position for insert: ";
            std::cin >> pos;
        }
        return value;
    }
}

namespace OutputSystem {
    static void setCursor(int column, int row) {
        move(row, column);
    }

    static void getCursor(int& column, int& row) noexcept {
        getyx(stdscr, row, column);
    }

    static void insert() noexcept {
        std::cout << "Done." << std::endl;
    }

    template <typename T>
    void show(const TArchive<T>& archive) noexcept {
        std::cout << "Archive: { ";
        archive.print();
        if (!archive.empty()) {
            // ÒÚË‡ÂÏ ÔÓÒÎÂ‰Ì˛˛ Á‡ÔˇÚÛ˛
            int column, line;
            getCursor(column, line);
            column -= 2;
            setCursor(column, line);
        }
        std::cout << " }\n";
    }
}
