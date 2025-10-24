#include <cassert>
#include <cstring>
#include <iostream>
#include <fstream>


class MyClass {


private:
    int a;
    char* b;


public:
    explicit MyClass(int a=0, const char* x="")
        : a(a) {

        b = new char[strlen(x)+1];
        assert(b != nullptr);
        strcpy(b, x);


    }

    ~MyClass() {
        delete[] b; // RAII
    }

    int get_a() const {
        return a;
    }

    char* get_b() const {
        return b;
    }


	// NOTE: std::ostream&
    void Serialize(std::ostream& fileObject) const {
        fileObject.write(reinterpret_cast<const char *>(&a), sizeof(a));
		
		// first we write all member-varialbes seperately

		// the best example for ser_and_deserl. is with char* array;
        const char* str = this->get_b();
        int n = strlen(this->get_b()) + 1;

		// First we write the size in the binary file.
        fileObject.write(reinterpret_cast<const char *>(&n), sizeof(n));

		// Then we write the string contents of char*.
        fileObject.write(str, n);
    }

	// return a referance for the empty class object (modified after procedure)
	// NOTE: std::istream&
    MyClass& Deserialize(std::istream& fileObject){

        fileObject.read(reinterpret_cast<char*>(&this->a), sizeof(a));
        
		// After the member-variables we read the second byte standing for
		// the size of the comming array (char[])
		int n;
        fileObject.read(reinterpret_cast<char *>(&n), sizeof(n)); // write the size of char[]
		
		

        delete[] this->b;
        this->b = new char[n];

		// we read the bytes, storing them into temp char[];
        char* temp = new char[n];
        fileObject.read(reinterpret_cast<char *>(temp), n);

		// we copy the contents to THIS->member-varialbe of char*.
        strcpy(this->b, temp);
        delete[] temp; // memory-leak precautions.

        return *this; // we return the modified original object.
    }






};

std::ostream& operator << (std::ostream& out, const MyClass& obj) {

    out << obj.get_a() << ' ' << obj.get_b() << '\n';

    return out;
}

int main() {

    std::fstream fileObj;


    {
        fileObj.open("Sample_file.bin", std::ios::out | std::ios::binary | std::ios::ate);
    
        if (!fileObj)
            return -1;
    
        MyClass mc(158, "Hello world! :)");
        MyClass ld(256, "Hello world! :) How are you doing today? <3");
        MyClass yt(300, "YEETXD");
    
        mc.Serialize(fileObj);
        ld.Serialize(fileObj);
        yt.Serialize(fileObj);
    
        fileObj.close();
    }



    {
        fileObj.open("Sample_file.bin", std::ios::in | std::ios::binary);
        if (!fileObj)
            return -1;

        MyClass x, y, z;
        x.Deserialize(fileObj);
        y.Deserialize(fileObj);
        z.Deserialize(fileObj);

        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    }

    return 0;
}
