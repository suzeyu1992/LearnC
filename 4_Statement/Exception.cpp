
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(int argc, char const *argv[]) {

    try{
        throw std::runtime_error("手动抛出异常");

    }catch(std::runtime_error err){
        cout << "捕获到错误  " << err.what() << endl;
    }

    return 0;
}
