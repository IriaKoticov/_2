/// вектор конечный, и содержит числа, надо найти вектор кратных чисел числу n в кубе
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <fstream>

const int N = 3;

int search_n_cube_in_vector(std::vector<int> vtmp, int n){
    int end_flag = 0;
    for (int i: vtmp){
            if (i%(n*n*n) == 0){
               end_flag = 1;
               break;
            };
        }
    return end_flag;
}



int main() {

    std::fstream fd("numbers");
    std::vector<int> tmp_vector;

    if (fd.is_open()){
        std::string tmp;
        while (fd>>tmp){
            int tmpnum = std::stoi(tmp);
            tmp_vector.push_back(tmpnum);
        };
    }

    switch (search_n_cube_in_vector(tmp_vector, N)) {
        case 1: {

            std::cout<< "Есть кратное кубу числа: " << N << std::endl ;
            break;
        }
        case 0: {

            std::cout<< "Нет кратного кубу числа: " << N << std::endl ;

            break;

        }
        default:{
            break;
        }
    }

    return 0;
}
