//
// Created by User on 002-2.7.2024 г..
//


/*
 * place;                                                                               string
 * coordinates (latitude <horizontal lines> [_x], longitude <vertical lines> [_y]);     float
 *
 *
 *  No two locations have the same name!            (_x1, _y1 -> name1; _x2, _y2 -> name2; name1 != name2)
 *  Some locations may have the same coordinates!   (nameN -> _x1 || _x2 && _y1 || _y2)
 *
 *
 *  INPUT: [name,latitude,longitude]
 *  the output has to be the same format in the same order
 *
 */


#include <iostream>
#include <utility>
#include <sstream>
#include <vector>

class Location{

private:
    std::string m_place{};
    float _m_latitude;
    float _m_longitude;

public:
    // explicit for constructor call with one argument
    Location(std::string p ="", float x =0.0f, float y =0.0f) : m_place(std::move(p)), _m_latitude(x), _m_longitude(y) {}

    ~Location(){}

    void getInfo() const{
        std::cout << this->m_place << ',' << this->_m_latitude << ',' << this->_m_longitude << std::endl;
    }


    std::string getLocationName() const { return this->m_place; }
    float getLocationLatitude() const { return this->_m_latitude; }
    float getLocationLongitude() const { return this->_m_longitude; }

};




int main(){

    std::vector<Location*> collection;

    std::string input{};
    std::string place{};
    std::string s_x{};
    std::string s_y{};
    float x{};
    float y{};


    Location* loc = nullptr;


//  entering locations
    while(std::getline(std::cin, input)){
        if(input == ".") break;

        std::stringstream ss(input);
        while(std::getline(ss, place, ',')){
            std::getline(ss, s_x, ',');
            std::getline(ss, s_y);
            x=std::stof(s_x);
            y=std::stof(s_y);
        }

        loc = new Location(place, x, y);
        collection.push_back(loc);
    }


//  entering queries
    std::string query{};
    std::string _coord_X{};
    std::string _coord_Y{};

    float _coord_X_f{};
    float _coord_Y_f{};
    std::string searchedLocation{};
    while(std::getline(std::cin, query)){
        if(query == ".") break;
        std::stringstream qss(query);

        qss >> _coord_X;
//      entered coordinates
        if(qss >> _coord_Y){
            //std::cout << "\nOK!" << std::endl;
            _coord_X_f = std::stof(_coord_X);
            _coord_Y_f = std::stof(_coord_Y);
            //perfom search
            //std::cout << "Searching for location by coordinates...\t[" << _coord_X_f << ", " << _coord_Y_f << "]" << std::endl;

            for(const auto& x : collection){
                if(x->getLocationLatitude() == _coord_X_f && x->getLocationLongitude() == _coord_Y_f){
                    x->getInfo();
                }
            }


        }
//      entered location only
        else {
            //std::cout << "\nIts a single string!" << std::endl;
            searchedLocation = _coord_X;
            // perform search
            //std::cout << "Searching for location by name only...\t[" << searchedLocation << "]" << std::endl;
            for(const auto& x : collection){
                if(x->getLocationName() == searchedLocation){
                    x->getInfo();
                }
            }
        }
    }







//    print collection
//    for(const auto& x : collection)
//        x->getInfo();


// Memory management
    for(auto & it : collection)
        delete it;
    collection.clear();

    return 0;
}