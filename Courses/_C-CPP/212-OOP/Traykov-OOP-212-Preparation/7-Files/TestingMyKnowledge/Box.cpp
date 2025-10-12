//
// Created by LOCAL_ADMIN on 12.10.2025 г..
//

#include "Box.h"

#include <limits>
#include <sstream>


Box::Box(std::string boxName, bool hasTape) :
    b_ID(this),
    b_name(std::move(boxName)),
    b_hasTape(hasTape)
    {}

const Box* Box::getID() const {
    return b_ID;
}

std::string Box::getName() const {
    return b_name;
}

bool Box::hasTape() const {
    return b_hasTape;
}

std::set<std::string> Box::getToysCollection() const {
    std::set<std::string> temp(b_toys_Collection);
    return temp;
}


void Box::setName(const std::string& name) { b_name = name; }
void Box::setTape()          { b_hasTape = true; }
void Box::removeTape()       { b_hasTape = false; }

void Box::fillWithToys(const std::set<std::string>& obj) {

    for (const auto& i : obj)
        b_toys_Collection.insert(i);

}

void Box::fillWithToys(const std::string& comma_list) {

    std::set<std::string> tempSet;
    std::stringstream ss(comma_list);

    while (ss.good()) {
        std::string substring;
        std::getline(ss, substring, ',');
        tempSet.emplace(substring);
    }

    for (const auto& i : tempSet)
        b_toys_Collection.insert(i);

}

void Box::fillWithToys(std::istream& in) {
    std::string single_toy;
    while (std::getline(in, single_toy) && !(single_toy.empty())) {
        b_toys_Collection.insert(single_toy);
    }
}


void Box::showToys() const {
    if (this->hasTape() == false) {
        if (b_toys_Collection.empty()) {
            std::cout << "\t* Empty box * [" << this << "]\n";
        }
        for (const auto& i : b_toys_Collection)
            std::cout << i << '\n';
        std::cout << std::endl;
    }
    else
        std::cout << "~ Remove the tape first!\r\n";

}

void Box::removeToys() {

    if(!(b_toys_Collection.empty())) {

        if (this->hasTape() == false)
            b_toys_Collection.clear();
        else
            std::cout << "~ Remove the tape first!\r\n";
    }
    else {
        showToys(); // goes to empty box statement
    }

}

void Box::resetBox() {
    this->setName("");
    this->removeTape();
    if (!this->b_toys_Collection.empty())
        this->removeToys();
}


std::ostream& operator<<(std::ostream& out, const Box& obj) {
    out << "Box [" << obj.getID() <<"]\r\n\t"
                "Name: "<< obj.getName() << "\r\n\tHas tape: " << std::boolalpha << obj.hasTape() << std::endl;

    return out;
}

std::istream& operator>>(std::istream& in, Box& obj) {
    std::string name;
    bool tape;
    bool fill;
    in >> name >> tape >> fill;

    obj.setName(name);

    if (tape)
        obj.setTape();

    if (fill) {
        in.clear();
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        obj.fillWithToys(in);
    }



    return in;
}