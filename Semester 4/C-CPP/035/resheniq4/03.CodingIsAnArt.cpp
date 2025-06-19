#include <iostream>
#include <cstring>


void solve (char* letters, std::string& msg, const int& sz){
    char largest = letters[0];

    for(int i = 0; i < sz; i++){
        if(letters[i] > largest)
            largest = letters[i];
    }

    /*
     * a -> s; b -> t, c -> u, d -> v, e -> w
     * A -> S; B -> T, C -> U, D -> V, E -> W
     *
     * Coding is an art!
     * Ugvafy ak sf sjl!
     */



    for(int i = 0; i < msg.length(); i++){
        if(msg[i] >= 'A' && msg[i] <= 'H' || msg[i] >= 'a' && msg[i] <= 'h' )
        {
            msg[i] += 18;
        } else if(msg[i] >= 'I' && msg[i] <= 'Z' || msg[i] >= 'i' && msg[i] <= 'z' ){
            msg[i] -=8;
        } else {
            continue;
        }

    }

}

int main(){


    char letters[4]{ 'e', 's' ,'i' ,'g' };
    std::string message = "Coding is an art!";

    solve(letters, message, 4);

    std::cout << message << std::endl;

    return 0;
}