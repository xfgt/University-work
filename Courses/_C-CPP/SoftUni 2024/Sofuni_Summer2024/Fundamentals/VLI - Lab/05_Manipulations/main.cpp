//
// Created by twister on 9/6/24.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>



int main(){

    std::vector<int> v;


    int x{};
    while(std::cin >> x)
        v.push_back(x);
    std::cin.clear(); /// !!!!



    std::string inputCommand{}, command{};



    while(true){
        std::getline(std::cin, inputCommand);
        std::stringstream ss(inputCommand);
        ss >> command;
        if(command == "end")
            break;



        if(command == "Add"){
            ss >> x;
            v.push_back(x);


        } else if (command == "Remove"){
            ss >> x;
            auto it = std::find(v.begin(), v.end(), x);
            if(it != v.end())
                v.erase(it);


        } else if ( command == "RemoveAt"){
            ss >> x;
            int& index = x;
            if(index <= v.size()){
                v.erase(v.begin() + index);
            }



        } else if( command == "Insert"){
            int value{}, pos{};
            ss >> value;
            ss >> pos;


            if(pos <= v.size()){
                auto p = v.begin()+pos;
                v.insert(p, value);
            }



        }




        std::cin.clear();

    }









//  print
    for(const auto& it : v)
        std::cout << it << ' ';
    return 0;
}