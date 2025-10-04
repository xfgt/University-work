#include <iostream>
#include <cstring>

#include <cassert>

class virtBase{

public:
    virtual void _sayHello()
    // = 0; can't get an instance.
    { std::cout << "Initial Hello! (" << this << ")\n"; }

};

class A : public virtBase {

private:

    char* m_name;
    float m_time;

public:
    A(const char* _name="", float _time=0.f){
        std::cout << "A constructor called! (" << this << ")\n";

        m_name = new char[strlen(_name) + 1];
        assert(m_name != nullptr);
        strcpy(m_name, _name);

        m_time = _time;
    }

    ~A(){
        std::cout << "A destructor called! (" << this << ")\n";
        delete[] m_name;
    }

    A(const A& obj){
        std::cout << "A copy constructor called! (" << this << ")\n";
        m_name = new char[strlen(obj.m_name) + 1];
        assert(m_name != nullptr);
        strcpy(m_name, obj.m_name);

        m_time = obj.m_time;
    }


    void setName(const char* name){
        if(name != nullptr) delete[] name;
        m_name = new char[strlen(name) + 1];
        assert(m_name != nullptr);
        strcpy(m_name, name);
    }

    void setTime(float time){
        m_time = time;
    }

    char* getName() const{
        return m_name;
    }

    float getTime() const{
        return m_time;
    }


    void print(){
        std::cout << "A: " <<  this << " \"" << m_name << "\", " << m_time << '\n';
    }
    void _sayHello() override {
        std::cout << "Hello from A, I am " << this << "\n";
    }
};

class B : public A{

private:
    char* m_faculty;

public:
    B(const char* _name="", float _time=0.f, const char* _fac="") : A(_name, _time) {
        std::cout << "B constructor called! (" << this << ")\n";
        m_faculty = new char[strlen(_fac) + 1];
        assert(m_faculty != nullptr);
        strcpy(m_faculty, _fac);
    }


    ~B(){
        std::cout << "B destructor called! (" << this << ")\n";
        delete[] m_faculty;
    }


    /// Note: When defining the copy constructor of inherited object \
    ///         You involve the base constructor as well.

    B(const B& obj) : A(obj.getName(), obj.getTime()){
        std::cout << "B copy constructor called! (" << this << ")\n";
        m_faculty = new char[strlen(obj.m_faculty) + 1];
        assert(m_faculty != nullptr);
        strcpy(m_faculty, obj.m_faculty);
    }


    void print() {
        A::print();
        std::cout << "B " << this << ", " << m_faculty << "\n";
    }

    void _sayHello() override {
        std::cout << "Hello from B, IAM " << this << "\n";
    }
};



int main(){

    // std::cout << "gh\n\n";

    A obj1("Harry", 3.145);
    A obj2(obj1);
    A obj3 = obj2;

    
    obj1.print();
    obj2.print();
    obj3.print();

    std::cout << std::endl;

    virtBase vb; // can't get an instance if declaration = 0
    vb._sayHello();
    std::cout << std::endl;

    A objs;
    objs._sayHello();
    objs.print();
    std::cout << std::endl;

    B Bok1("Benson", 18.5221, "0152146");
    Bok1._sayHello();
    Bok1.print();
    

    std::cout << "\nAfter upcasting... ";
    A* bk11;
    bk11 = new A(Bok1); // upcasting

    bk11->_sayHello();
    bk11->print();

    delete bk11; // if not deleted - leak.

    std::cout << "\nA ptr now points to -> objs... ";
    bk11 = &objs; // line 155
    bk11->_sayHello();
    bk11->print();



    bk11 = nullptr;

    return 0;
}