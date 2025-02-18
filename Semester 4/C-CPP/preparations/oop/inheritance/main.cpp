#include <iostream>

using namespace std;

class Animal {


    friend ostream& operator << (ostream& out, const Animal& rhs);
    friend istream& operator >> (istream& in,  Animal& rhs);
private:

    string type;
    double health_points;

public:

    Animal(string t ="", double hp =0.) : type(t), health_points(hp) {}
    Animal (const Animal& rhs) : Animal(rhs.type, rhs.health_points) {}
    Animal& operator=(const Animal& rhs) {
        this->type = rhs.type;
        this->health_points = rhs.health_points;
        return *this;
    }



    string getType() const {return type;}
    double getHP() const  {return health_points; }
    void setType(string t) { type = t;}
    void setHP(double hp) { health_points = hp;}

    void makeSound()
    {
        std::cout << this->getType() << " makes an animal sound.. :|\n";
    }



};


class Cat : public Animal {
    friend ostream& operator << (ostream& out, const Cat& rhs);
    friend istream& operator >> (istream& in,  Cat& rhs);
private:
    float speed;

public:

    Cat(string t ="", double hp =0., float s =2.) : Animal(t, hp), speed(s) {}
    Cat(const Cat& rhs) : Cat(rhs.getType(), rhs.getHP(), rhs.speed){}
    Cat& operator=(const Cat& rhs) {
        this->setType(rhs.getType());
        this->setHP(rhs.getHP());
        this->speed = rhs.speed;
        return *this;
    }


    float getSpeed() const { return speed; }
    void setSpeed(float s) { speed = s;}


     void makeSound(){
        std::cout << this->getType() << " says meow!\n";
    }
};

 ostream& operator << (ostream& out, const Animal& rhs) {

     out << "\n[ ANIMAL ]\nType: " << rhs.getType() << endl
         << "HP: " << rhs.getHP() << endl;

     return out;


 }
 istream& operator >> (istream& in, Animal& rhs) {
     std::cout << "Entering BASIC ANIMAL data:\n Type: ";
    string type;
     getline(cin, type);
     double hp;
     std::cout << "Health points: ";
     in >> hp;

     rhs.setType(type);
     rhs.setHP(hp);

     return in;

 }


ostream& operator << (ostream& out, const Cat& rhs) {

     out << "\n[ CAT ]\nType: " << rhs.getType() << endl
         << "HP: " << rhs.getHP() << endl
        << "Speed: " << rhs.getSpeed() << endl;

     return out;


 }
istream& operator >> (istream& in, Cat& rhs) {

     std::cout << "Entering CAT data:\n Type: ";
     string type;
     getline(cin, type);
     double hp;
     std::cout << "CAT Health points: ";
     float sp;
     in >> hp;
     std::cout << "CAT SPEED: ";
     in >> sp;

     rhs.setType(type);
     rhs.setHP(hp);
     rhs.setSpeed(sp);

     return in;

 }



int main()
{



     Animal a("lainom", 69);
     Animal e(a);
     Animal f = e;
     cout << a << endl;
     cout << e << endl;
     cout << f << endl;

     Cat c;
     cin >> c;
     cout << endl << c << endl;
     c.makeSound();

     Cat cc("MQU", 44, 32);
     Cat o(cc);
     Cat u = o;
     cout << cc << endl;
     cout << o << endl;
     cout << u << endl;


     std::cout << " ===Upcasting Cat -> Animal=== \n";
     Animal *cp = reinterpret_cast<Animal*>(&c); // котката правим във абстрактен тип животно upcasting
     std::cout << *cp << std::endl;
     cp->makeSound();

     std::cout << "===Downcasting Animal -> Cat=== \n";
     Cat *x = reinterpret_cast<Cat*>(cp);
     std::cout << *x << std::endl;
     x->makeSound();





}
