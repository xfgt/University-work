//
// Created by User on Чт-4.7.2024 г..
//
#include <iostream>
#include <vector>
#include <limits>


struct Student{
    std::string m_Name;
    std::string m_Surname;
    double m_totalAvg;


    Student(std::string name ="", std::string surname ="", double avg =0.0){
        m_Name = std::move(name);
        m_Surname = std::move(surname);
        m_totalAvg = avg;
    }


    void printInfo() const {
        std::cout.precision(2);
        std::cout << m_Name << ' ' << m_Surname << ' ' << m_totalAvg  << std::endl;
    }
};

double getAvg(std::vector<Student*>& xV){
    double sumOfAll{};
    int sz = xV.size();


    for(const auto& f : xV){
        sumOfAll += f->m_totalAvg;
    }

    return sumOfAll / sz;

}

int main(){
    std::vector<Student*> studentsVector;

    int N{};
    while(!(std::cin>>N)){
        std::cin.clear();
        std::cin.ignore();
    }
    studentsVector.reserve(N);

    std::string s_name, s_surName;
    double avg{};

    Student* sp = nullptr;


    for(int i = 0; i < N; i++){
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::getline(std::cin, s_name);
        std::getline(std::cin, s_surName);

        while(!(std::cin>>avg)){
            std::cin.clear();
            std::cin.ignore();
        }

        if(s_name == "" || s_surName == "" || avg == 0){continue;}


        sp = new Student(s_name, s_surName, avg);
        studentsVector.push_back(sp);


    }

    if(!(studentsVector.empty())){
        for(const auto& x : studentsVector)
            x->printInfo();
        std::cout << getAvg(studentsVector) << std::endl;
        //  Memory management
        for(auto& x : studentsVector){
            delete x;
            x = nullptr;
        }

        sp = nullptr;
        studentsVector.clear();
    } else {
        std::cout << "Invalid input" << std::endl;
    }




    return 0;
}