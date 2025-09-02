/// вектор конечный, и содержит числа, надо найти вектор кратных чисел числу n в кубе
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <fstream>

int main() {

    int n;
    std::cout << "input your n: ";
    std::cin >> n;
    std::fstream fd("numbers");
    std::vector<int> rezlist;
    if (fd.is_open()){
        std::string tmp;
        while (fd>>tmp){
            int tmpnum = std::stoi(tmp);
            if (tmpnum%(n*n*n) == 0){
                rezlist.push_back(tmpnum);
            };
        }
    } else {
        std::cout << "File not found" << std::endl;
        std::cerr << "File don`t open" << std::endl;
    }
    if (!rezlist.empty()){
    std::cout << "The number increases by n³ : " << n*n*n << std::endl;
    for (int i : rezlist){
    std::cout << i << std::endl;
    }
    } else {
        std::cout << "massive is empty" << std::endl;
    }
    return 0;
}
