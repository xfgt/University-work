//
// Created by ADMIN on 06-Oct-25.
//

class Shape {
public:
    virtual double area() = 0; // pure virtual function
    /*                                       ^
     * Клас, който съдържа поне една чисто виртуална функция се нарича "абстрактен клас".
     *
     */

}; // Класът Shape вече е абстрактен клас.


int main() {

    Shape s; // Не е възможно

    return 0;
}