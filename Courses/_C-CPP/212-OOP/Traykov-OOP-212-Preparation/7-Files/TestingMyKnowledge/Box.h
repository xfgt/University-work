//
// Created by LOCAL_ADMIN on 12.10.2025 г..
//

#ifndef CPP_BOX_H
#define CPP_BOX_H

#include <set>
#include <iostream>

class Box {

    friend std::ostream& operator<<(std::ostream& out, const Box& obj);
    friend std::istream& operator>>(std::istream& in, Box& obj);

private:
    std::set<std::string> b_toys_Collection;
    std::string b_name;
    bool b_hasTape;
    const Box* const b_ID;


public:
    explicit Box(std::string boxName="", bool hasTape=false);

    // getters
    const Box* getID() const;
    std::string getName() const;
    bool hasTape() const;

    std::set<std::string> getToysCollection() const;
    void showToys() const;


    // setters
    void setName(const std::string& name);
    void setTape();
    void removeTape();

    void fillWithToys(const std::set<std::string>& obj);
    void fillWithToys(const std::string& comma_list);
    void fillWithToys(std::istream& in);

    void removeToys();

    void resetBox();



};

#endif //CPP_BOX_H