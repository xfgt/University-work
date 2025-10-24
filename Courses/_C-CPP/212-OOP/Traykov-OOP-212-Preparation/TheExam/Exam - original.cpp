#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
#include <fstream>


class Shape {

    friend std::ostream& operator<<(std::ostream& out, const Shape& obj);
    friend std::istream& operator>>(std::istream& in, Shape& obj);

private:
    double _height;
    double _width;


public:

    virtual double calculateSurface();

     Shape(double h =0., double w=0.) :
        _height(h), _width(w) { }


    virtual ~Shape();
    Shape(const Shape& obj) {
        this->_height = obj._height;
        this->_width = obj._width;// bad
    }

    virtual double getHeight() const {
        return _height;
    }

    virtual double getWidth() const {
        return _width;
    }


    virtual char* getZaglavie()  {
        return "NoZaglavie";
    }
    virtual int getID();

    virtual void setHeight(double h) {
        this->_height = h;
    }

    virtual void setWidth(double w) {
        this->_width =w;
    }




};




class Triangle : public Shape {
    friend std::ostream& operator<<(std::ostream& out, const Triangle& obj);
    friend std::istream& operator>>(std::istream& in, Triangle& obj);

private:
    int _id;
    char* _zaglavie;

public:
    explicit Triangle(double h =0., double w=0., int id=100, char* zagl ="") : Shape(h, w) {

        this->_id = id;
        _zaglavie = new char[strlen(zagl) + 1];
        assert(_zaglavie != nullptr);

        // ima problem s tova ako po malko strlen();
        strcpy(_zaglavie, zagl);
    }


    virtual ~Triangle() {
        delete[] _zaglavie;
    }

    Triangle(const Triangle& obj) {
        this->_id = obj._id;

        delete[] this->_zaglavie;
        this->_zaglavie = new char[strlen(obj.getZaglavie()) + 1];
        assert(_zaglavie != nullptr);

        // ima problem s tova ako po malko strlen();
        strcpy(_zaglavie, obj.getZaglavie());

    }


    virtual char* getZaglavie() const {
        return _zaglavie;
    }

    int getID() override {
        return _id;
    }

    virtual void setZaglavie(const char* str) {
        delete[] this->_zaglavie;

        this->_zaglavie = new char[strlen(str) + 1];
        assert(this->_zaglavie != nullptr);
        strcpy(this->_zaglavie, str);
    }

    double calculateSurface() override {
        return (this->getHeight() * this->getWidth()) / 2;
    }
};



class Rectangle : public Shape {
    friend std::ostream& operator<<(std::ostream& out, const Rectangle& obj);
    friend std::istream& operator>>(std::istream& in, Rectangle& obj);

private:
    int _id;
    char* _zaglavie;

public:
    explicit Rectangle(double h =0., double w=0., int id = 100, char* zagl ="") : Shape(h, w) {

        this->_id = id;
        _zaglavie = new char[strlen(zagl) + 1];
        assert(_zaglavie != nullptr);

        // ima problem s tova ako po malko strlen();
        strcpy(_zaglavie, zagl);
    }


    virtual ~Rectangle() {
        delete[] _zaglavie;
    }

    Rectangle(const Rectangle& obj) {
        this->_id = obj._id;

        delete[] this->_zaglavie;
        this->_zaglavie = new char[strlen(obj.getZaglavie()) + 1];
        assert(_zaglavie != nullptr);

        // ima problem s tova ako po malko strlen();
        strcpy(_zaglavie, obj.getZaglavie());

    }


     char* getZaglavie() const{
        return _zaglavie;
    }

    int getID() override {
        return _id;
    }

    virtual void setZaglavie(const char* str) {
        delete[] this->_zaglavie;

        this->_zaglavie = new char[strlen(str) + 1];
        assert(this->_zaglavie != nullptr);
        strcpy(this->_zaglavie, str);
    }

    double calculateSurface() override {
        return this->getHeight() * this->getWidth();
    }
};


std::ostream& operator << (std::ostream& out, const Shape& obj) {

    out <<  obj.getHeight() << ' ' << obj.getWidth() << ' ';
    return out;
}

std::istream& operator>>(std::istream& in, Shape& obj) {

    double h{}, w{};

    in >> h >> w;

    obj.setHeight(h);
    obj.setWidth(w);

    return in;
}



std::ostream& operator << (std::ostream& out, const Triangle& obj) {

    out << "Zaglavie: " << obj.getZaglavie() << " id= " << obj._id << ' ' <<  obj.getHeight() << ' ' << obj.getWidth() << ' ';
    return out;
}

std::istream& operator>>(std::istream& in, Triangle& obj) {

    double h{}, w{};
    std::string str;
    std::getline(std::cin, str);
    std::cin.ignore(); // \n
    in >> h >> w;

    obj.setHeight(h);
    obj.setWidth(w);
    obj.setZaglavie(str.c_str());

    return in;
}



int main() {

    std::fstream file;

    std::vector<Shape*> v_shapes;
    Shape* shape;

    shape = new Triangle(15.6, 33.547, 150, "Triangle 1");
    v_shapes.push_back(shape);

    shape = new Triangle(22.3, 5,  141,"imATriangle");
    v_shapes.push_back(shape);

    shape = new Rectangle(40, 8,  55, "I'm a Rectangle");
    v_shapes.push_back(shape);




    file.open("figures.txt", std::ios::out | std::ios::app);
    if (!file)
        return -1;


    for (auto i : v_shapes) {
        file << "Zaglavie: " << *i->getZaglavie() << " ID=" << i->getID() << " height = " << i->getHeight() << " width = " << i->getWidth() << '\n';
    }


    file.close();



    return 0;
}