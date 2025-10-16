//
// Created by jeff on 16.10.25 г..
//
// credit to: Mike Shah

// to binary!

#include <iostream>
#include <fstream>

struct GameObject {


    int field1;
    short field2;
    bool active;
    char padding[1];

    GameObject(int _field1, short _field2, bool _active) : field1(_field1), field2(_field2), active(_active) {}

    void Serialize(std::ostream& os) {
        os.write(reinterpret_cast<const char*>(&field1), sizeof(field1));
        os.write(reinterpret_cast<const char*>(&field2), sizeof(field2));
        os.write(reinterpret_cast<const char*>(&active), sizeof(active));
        os.write(padding, sizeof(padding));
    }

    void Deserialize(std::istream& is) {
        is.read(reinterpret_cast<char*>(&field1), sizeof(field1));
        is.read(reinterpret_cast<char*>(&field2), sizeof(field2));
        is.read(reinterpret_cast<char*>(&active), sizeof(active));
        is.read(padding, sizeof(padding));
    }
    friend std::ostream& operator<<(std::ostream& out, const GameObject& obj);
};

std::ostream& operator<<(std::ostream& out, const GameObject& obj){

    out << obj.field1 << " " << obj.field2 << " " << std::boolalpha << obj.active;

    return out;
}



int main() {

    // Start a new scope -- that way our std::ofstream will .close().
    {
        std::cout << "Sizeof GameObject: " << sizeof(GameObject) << std::endl;
        GameObject go(50, 23, 1);
        std::cout << go << std::endl; // Test operator << overlaod

        // Write out our text version
        std::ofstream text_file("text.txt");
        text_file << go << std::endl;

        // Write out our binary version
        std::ofstream binary_file("text.bin", std::ios::binary);
        go.Serialize(binary_file);
    }

    // Second experiment, reading our binary data, and populating and empty game object
    {
        GameObject go(0,0,0);
        std::ifstream input_binary_file("text.bin", std::ios::binary);
        go.Deserialize(input_binary_file);
        std::cout << "Deserialized: " << go << std::endl;
    }

    return 0;
}