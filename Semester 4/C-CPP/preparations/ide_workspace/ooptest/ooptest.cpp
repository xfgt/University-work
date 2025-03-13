// 04_1440 (130325)
#if 0// turn on/off
#include <iostream>
#include <cstdlib>
using namespace std;

class RegTasks {
    int n;
    char* name;
    int* level;
    double* paid;

public:
    RegTasks(const char* nme="NoName") : n(0), level(nullptr), paid(nullptr) {
        name = new char[strlen(nme) + 1];
        strcpy_s(name, strlen(nme) + 1, nme);
    }
    ~RegTasks() {
        // for the pointers
        if (n != 0) {
            delete[] name;
            delete[] level;
            delete[] paid;
            
        }
    }
    // copy constructor
#if 1
    RegTasks(const RegTasks& rhs) { // void report(RegTasks p)
        n = rhs.n;
        
        name = new char[strlen(rhs.name) + 1];
        strcpy_s(name, strlen(rhs.name) + 1, rhs.name);

        level = new int[n];
        paid = new double[n];


        for (int i = 0; i < n; i++) {
            level[i] = rhs.level[i];
            paid[i] = rhs.paid[i];
        }
    }
    
#endif


    // copy assignment operator
    // dyasno asociativen
    // y = x = k = l;
    // k <- l
    // x <- k
    // y <- x


#if 1
    RegTasks& operator=(const RegTasks& rhs) {
        if (this != &rhs) {
            if (n != 0) {
                delete[] name;
                delete[] level;
                delete[] paid;
            }
            n = rhs.n;

            name = new char[strlen(rhs.name) + 1];
            strcpy_s(name, strlen(rhs.name) + 1, rhs.name);

            level = new int[n];
            paid = new double[n];


            for (int i = 0; i < n; i++) {
                level[i] = rhs.level[i];
                paid[i] = rhs.paid[i];
            }
            // ne e prieto v chlen funkcii v daden v klas da se izvikva susthiq klas.
        }
        return *this;
    }
#endif


    char* getName() const { return name;  }
    int getN() const { return n; }
    void addTask(int rank, double sum) {
        n++;
        int* k = new int[n];
        double* t = new double[n];

        for (int i = 0; i < n - 1; i++) {
            k[i] = level[i];
            t[i] = paid[i];
        }

        k[n - 1] = rank;
        t[n - 1] = sum;

        if (n != 1) {
            
            delete[] level;
            delete[] paid;
        }

        level = k;
        paid = t;
    }
    
    double total() const {
        double sum = 0;
        for (int i = 0; i < n - 1; i++) {
            sum += paid[i];
        }
        return sum;
    }

    double average() const { return n == 0 ? 0. : total() / n; }

    int maxPaidRank() const {
        if (n == 0) return -1;

        int ind = 0;
        double max = paid[0];

        for (int i = 0; i < n; i++) {
            if (paid[i] > max) {
                ind = i;
                max = paid[i];
            }
        }

        return level[ind];
    }
};


void report(RegTasks p) {
    printf("Name: %s\nRecords: %d\nTotal paid: %f\n Average paid: %f\n Max paid task of rank: %d\n\n",p.getName(), p.getN(), p.total(), p.average(), p.maxPaidRank());
}

int main()
{
    // constructors and operator= overload
#if 0
    for (int i = 0; i < 10; i++) {
        RegTasks x;

        for (int j = 0; j < 5; j++) {
            x.addTask(1 + rand() % 10, 1.25 + rand() % 2000);
        }



        report(x);
    }
#endif
    RegTasks x;

    for (int j = 0; j < 5; j++) {
        x.addTask(1 + rand() % 10, 1.25 + rand() % 2000);
    }
    report(x);

    cout << "Y";
    // On one line works with copy constructor
    // RegTasks y = x; // kopirasht konstruktor zashtoto e na edin red ( ekvivalent: RegTasks y(x) )

    // On seperate lines copies but appears an error;
    RegTasks y;
    y = x; // obrushtame se kum operator za prisvoqvane
   

    report(y);



    return 0;
}
#endif