//
// Created by User on 030-30.6.2024 г..
//


// input 1: 10x10 matrix
// input 2: unit time
// . healty
// # rust-resistant
// ! began to rust


#include <iostream>
#define ROWS 10
#define COLS 10


class RustMaker{

private:
    char** m_matrix;
    int m_rows,
        m_cols;
    int m_unitTime;


    // hardenRust -> scan matrix and make all 'x' to '!'
    void hardenRust(){
        for (int i = 0; i < m_rows; i++){
            for (int j = 0; j < m_cols; j++){
                if(m_matrix[i][j] ==  'x'){
                    m_matrix[i][j] = '!';
                }
            }
        }

    }

    // create side points of rust from given point; moves one unit
    void makeTempRustFromPoint(int x, int y){ // filling X

        // toLeft
        if(y > 0){
            if(m_matrix[x][y-1] != '#'){
                if(m_matrix[x][y-1] != '!'){
                    m_matrix[x][y-1] = 'x';
                }
            }

        }
        // toRight
        if(y < m_cols-1){
            if(m_matrix[x][y+1] != '#'){
                if(m_matrix[x][y+1] != '!'){
                    m_matrix[x][y+1] = 'x';
                }
            }

        }

        // toBottom
        if(x < m_rows-1){
            if(m_matrix[x+1][y] != '#'){
                if(m_matrix[x+1][y] != '!'){
                    m_matrix[x+1][y] = 'x';
                }
            }

        }

        // toTop
        if(x > 0){
            if(m_matrix[x-1][y] != '#'){
                if(m_matrix[x-1][y] != '!'){
                    m_matrix[x-1][y] = 'x';
                }
            }
        }


    }

    void workPoints(int m){

        for (int i = 0; i < m_rows; i++){
            for (int j = 0; j < m_cols; j++){
                if(m_matrix[i][j] ==  '!'){
                    makeTempRustFromPoint(i, j); // assign with 'x'
                }
            }
        }
        hardenRust();
        if(m_unitTime == 1) return;
        workPoints(m_unitTime--);

    }




public:
    RustMaker(char** mtrx =nullptr, int r =0, int c =0, int x =0){
        m_matrix = mtrx;
        m_rows = r;
        m_cols = c;
        m_unitTime = x;
    }

    void getSchema(){
        workPoints(m_unitTime);

    }

    void printResult(){
        for (int i = 0; i < m_rows; ++i) {
            for (int j = 0; j < m_cols; ++j) {
                std::cout << m_matrix[i][j];
            }
            std::cout << std::endl;
        }

    }



};

int main(){


    char** matrix = new char*[ROWS];
        for(int r = 0; r < ROWS; r++){
            matrix[r] = new char[COLS];
            for(int c = 0; c < COLS; c++){
                std::cin >> matrix[r][c];
            }
        }
        std::cin.clear();

        int unitTime{};
        std::cin >> unitTime;
        std::cin.clear();


        RustMaker r(matrix, ROWS, COLS, unitTime);
        r.getSchema();
        r.printResult();







// Memory management
    for(int i = 0; i < ROWS; i++){
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}