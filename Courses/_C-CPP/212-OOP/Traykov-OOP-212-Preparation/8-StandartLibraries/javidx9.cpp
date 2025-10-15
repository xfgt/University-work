//
// Created by LOCAL_ADMIN on 14.10.2025 г..
//


/*
 * Thanks to the great explanation of STL contianers im thankfull to give all the credit to
 * Mr. OneLoneCoder (javidx9) for making this video:
 * https://youtu.be/6OoSgY6NVVk
 *
 * He made a great "silly" program explaining containers in c++ and how they are located in memory.
 * This is a copy from the video.
 * Educaitonal purposes only. (Sync storage and notes)
 *
 * There might be slight modifications.
 */


// Use std=c++17

#include <chrono>
#include <deque>
#include <iostream>
#include <iomanip> // setw
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <vector>


using std::setw;
int main() {


    srand(time(0));



    auto roll = []() { return rand() % 6 + 1; };


    // uncomment to change the container
    // std::vector<int> container;
    // std::list<int> container;
    // std::deque<int> container;

     //std::set<int> container;
    // std::unordered_set<int> container; // faster



    //container.push_back(roll());
    {/*
        container.insert(roll()); // set
        const int* pAddressOfOriginalItemZero = &(*container.begin());


        std::chrono::duration<double> durInsertTime(0);

        do {
            const int* pAddressOfItemZero = &(*container.begin());
            std::cout << "Contains " << container.size() << " elements, took " <<
                std::chrono::duration_cast<std::chrono::microseconds>(durInsertTime).count() << " us.\n";

            for (const auto& i : container) {

                const int* pAddressOfItemX = &i;
                int pItemOffset = pAddressOfItemX - pAddressOfItemZero;
                int pItemOffsetOriginal = pAddressOfItemX - pAddressOfOriginalItemZero;

                std::cout << setw (5) <<
                    "Offset From Original: " << pItemOffsetOriginal << setw (35) <<
                    "Offset From Zero: " << pItemOffset             << setw (35) <<
                    ":\t\tContent: " << i << '\n';
            }

            auto tp1 = std::chrono::high_resolution_clock::now();

            // container.push_back(roll());
            container.insert(roll()); // set
            auto tp2 = std::chrono::high_resolution_clock::now();
            durInsertTime = ( tp2 - tp1 );


        } while (getc(stdin));
    */
    }

    {
        std::unordered_map<std::string, int> container;

        container["one"] = 1;
        container["two"] = 2;
        container["three"] = 3;
        container["four"] = 4;
        container["five"] = 5;
        container["six"] = 6;

        // pair: key value, value value

        for (const auto& i : container)
            std::cout << i.first << i.second << std::endl;
    }












































    std::cin.get();

    return 0;
}


