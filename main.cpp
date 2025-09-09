/// вектор конечный, и содержит числа, надо найти вектор кратных чисел числу n в кубе
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <fstream>

const int N = 3;

class MyNumVec {
    private:
    std::vector<int> vtmp;
    int multiple_of_cube = 0;
    public:
    MyNumVec(std::vector<int> mylist) : vtmp(mylist) {
        multiple_of_cube = search_n_cube_in_vector();
    }

    void say(){
        switch (multiple_of_cube) {
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
    };
    void set_data(std::vector<int> v){
        for (int i: v){
            vtmp.push_back(i);
        }
        multiple_of_cube =  search_n_cube_in_vector();
    };
    int search_n_cube_in_vector(){
        int end_flag = 0;
        for (int i: vtmp){
                if (i%(N*N*N) == 0){
                end_flag = 1;
                break;
                };
            }
        return end_flag;
    }
};

template <typename T=std::vector<int>>
class FileReader {
    private:
    std::string FilePath;
    public:
    T tmp_vector;

    FileReader(std::string filepath) : FilePath(filepath) {

        std::fstream fd("numbers");

        if (fd.is_open()){
            std::string tmp;
            while (fd>>tmp){
                int tmpnum = std::stoi(tmp);
                tmp_vector.push_back(tmpnum);
            };
        }
    }


};



int main() {
    FileReader reader = {"numbers"};
    MyNumVec myOBJ{reader.tmp_vector};
    myOBJ.say();
    return 0;
}
