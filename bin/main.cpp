#include <iostream>
#include <vector>

#include <lib/lr1.h>

int main() {
    std::vector<int> arr = { -100,-10,-2,2147483641,0,0,100 };//{10, 14, 15, 20, 21, 25, 30};
    Res output = countAndSum(arr);
    std::vector<int> result = output.result;
    for (int e : result) {
        std::cout << e << std::endl;
    }
    std::cout << std::endl<< output.min<<std::endl;
    for (std::string s : output.errors) {
        std::cout << s << std::endl;
    }
    return 0;
}