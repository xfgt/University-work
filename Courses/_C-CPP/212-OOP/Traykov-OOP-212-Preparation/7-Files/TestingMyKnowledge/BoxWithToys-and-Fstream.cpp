//
// Created by LOCAL_ADMIN on 12.10.2025 г..
//

#include "Box.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

#include "binio.cpp"





enum FILEErrorType { // fstream
    CANT_OPEN_FILE = 320,
    ALREADY_OPEN,
    EMPTY_FILE = 400
};

// get file size
std::streamoff getFileBytes(std::fstream& file_object) {

    file_object.seekg(0, std::ios_base::beg);
    auto start = file_object.tellg();
    file_object.seekg(0, std::ios_base::end);
    auto end = file_object.tellg();

    // reset the cursor position!
    file_object.seekg(0, std::ios_base::beg);

    return (end - start);
}


int main() {
    Box amazonBox;

// Box class tests

    // Testing member-fucntions
    {

        // Testing opening taped box
        {
            amazonBox.setTape();
            std::cout << amazonBox;
            std::cout << "Toys:\r\n"; amazonBox.showToys();
        }

        // Testing sticking new toys to already existing set with different methods (copy of set object, user input, const char comma seperated list)
        // Testing opening box and removing toys with taped and untaped states
        {

            std::set<std::string> x;
            x.insert("Lego");
            x.insert("RC helicopter");
            x.insert("Doll");
            amazonBox.fillWithToys(x);
            amazonBox.setTape();

            std::cout << amazonBox;
            std::cout << "Toys:\r\n"; amazonBox.showToys();

            amazonBox.removeTape();

            std::cout << amazonBox;
            std::cout << "Toys:\r\n"; amazonBox.showToys();


            amazonBox.setTape();

            amazonBox.removeToys();
            std::cout << amazonBox;
            std::cout << "Toys:\r\n"; amazonBox.showToys();

            amazonBox.removeTape();

            amazonBox.removeToys();
            std::cout << amazonBox;
            std::cout << "Toys:\r\n"; amazonBox.showToys();
        }


        // testing the same with string argument of setter member-fucntion
        {
            amazonBox.removeTape();
            amazonBox.fillWithToys("Heros 108 figures, Spongebob water pistol, Yo-Yo");
            std::cout << amazonBox;
            std::cout << "Toys: "; amazonBox.showToys();
            amazonBox.setTape();
            std::cout << amazonBox;
            std::cout << "Toys: "; amazonBox.showToys();
            amazonBox.removeToys();
        }



    }


    // Vector of pointers to Box objects with Memory management!
    {
        Box* p_box;
        std::vector<Box*> boxes;
        for (int i = 0; i < 5; i++) boxes.push_back(new Box());

        for (const auto& i : boxes) {
            std::cout << *i << '\n';
            std::cout <<"Toys: ";
            i->showToys();
        }



        // Memory management
        for (auto& x : boxes) {
            delete x;
            x=nullptr;
        }
        boxes.clear();
    }



    // Testing all three different methods of filling the box with toys ~
    // ~ ready set object, user input, comma seperated list
    {

         std::set<std::string> f;
         f.insert("aasdf");
         f.insert("asfrew");
         f.insert("hgdq");
         amazonBox.fillWithToys(std::cin);
         amazonBox.showToys();

         amazonBox.fillWithToys(f);
         amazonBox.showToys();


         amazonBox.fillWithToys("toy1,toy2,Penguins of Madagascar figures");
         amazonBox.showToys();

         amazonBox.setTape();
         amazonBox.setName("Present for kids in school");
         std::cout << amazonBox;




    }

//  Fstream
    {

        std::fstream file_object;
        try {
             {
                 file_object.open("./file.txt", std::ios_base::out | std::ios_base::app); // it goes where the binary lives
                 if (!file_object.is_open())
                     throw CANT_OPEN_FILE;

                 const char* str = "Hello";
                 file_object.write(str, strlen(str));
                 std::cout << "Content written!";
                 file_object.close(); // explicit!
             }

             {
                 std::string fileName{};
                 std::cout << "Enter file name (path): ";
                 std::getline(std::cin, fileName);
                 file_object.open(fileName.c_str(), std::ios_base::in);
                 if (!file_object.is_open())
                     throw CANT_OPEN_FILE;


                 auto bytes = getFileBytes(file_object);
                 if (bytes == 0)
                     throw EMPTY_FILE;

                 char* str = new char[bytes]; // The string which will hold the data form the file.
                     file_object.read(str, bytes);
                     str[bytes] = '\0';
                 std::cout << str;


                 delete[] str;
                 file_object.close();
             }


             amazonBox.resetBox();
             std::cout << amazonBox;
             amazonBox.showToys();


            std::vector<Box*> MyNewBoxes;
            // Creating a collection of boxes; filling them with data.
             Box* p_Box;
             for (int i = 0; i < 3; i++) {
                 p_Box = new Box();
                 std::cin >> *p_Box;
                 MyNewBoxes.push_back(p_Box);
             }

            // WRITE
            binio::save_boxes("Boxes.bin", MyNewBoxes);

            // cleanup originals if you want to prove we really reload from disk
            for (auto*& p : MyNewBoxes) { delete p; p = nullptr; }
            MyNewBoxes.clear();

            // READ
            MyNewBoxes = binio::load_boxes("Boxes.bin");

            // DISPLAY
            for (const Box* x : MyNewBoxes) {
                std::cout << *x;           // uses your operator<< (prints ID pointer, name, tape). :contentReference[oaicite:4]{index=4}
                std::cout << "Toys:\n";
                x->showToys();
                std::cout << '\n';
            }

            // cleanup
            for (auto*& p : MyNewBoxes) { delete p; p = nullptr; }
            MyNewBoxes.clear();





        } catch (const FILEErrorType& x) {

            std::cerr << "Caught ENUM exception No. " << x << std::endl;
            file_object.close();

        } catch (const std::exception& e) {
            std::cerr << "Caught exception " << e.what() << std::endl;
            file_object.close();
        }




    }



    std::cout << "\r\n\r\nPress any key to close...";
    std::cin.get();
    return 0;
}