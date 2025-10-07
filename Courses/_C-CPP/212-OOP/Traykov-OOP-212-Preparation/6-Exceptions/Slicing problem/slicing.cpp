//
// Created by ADMIN on 07-Oct-25.
//

/**
 *
 *  Защо това е тук при темата за обработка на грешки, а не в предишната за полиморфизъм?
 *
 *  Въпреки, че е по-подходяща за там, слайсинга е засегнат тук защото в учебния
 *  материал се засяга момента, в който "хвърляме по стойност, а хващаме по (const) референция";
 *
 */

//  Пример:

   /**
            struct MyError { int code; std::string msg; };

            try {

                throw MyError{42, "boom"};

            } catch (const MyError& e) {
                // use e.code, e.msg
            }
    */

/**
 *  По този начин се запазва динамичния тип на обект от наследен клас;
 *  В противен случай се получава слайсинг (slicing), който "отрязва" допълнителните
 *  данни наследени и ги приравнява до тези актуални само в базовия тип.
 *
 *  В този файл показва пример за слайсинг.
 *
 */


#include <iostream>

struct Base {
    virtual std::string name() const { return "Base"; }
};

struct Derived : Base {
    int extra = 123;
    std::string name() const override { return "Derived"; }
};

void take_by_value(Base b) {           // <-- копие по стойност -> slicing
    std::cout << b.name() << "\n";     // печата "Base"
}

void take_by_reference(Base& b) {
    std::cout << b.name() << "\n";     // печата "Derived"
}

void take_by_ptr(Base* b) {             // подобно на Base&, но позволява null
    std::cout << b->name() << "\n";     // печата "Derived"
}


int main() {
    Derived d;
    take_by_value(d);                   // Derived -> Base (отрязва се extra)
    take_by_reference(d);
    take_by_ptr(&d);
}
