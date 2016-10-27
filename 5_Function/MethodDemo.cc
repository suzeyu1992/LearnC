
#include <iostream>
#include <string>
#include <initializer_list>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;

size_t callCountAdd(){
    static size_t ctr = 0;
    return ++ctr;
}

/*定义可变参数  initializer_list*/

/*利用列表初始化返回值*/
std::vector<string>  process(){
    return {"列表", "初始化", "返回值"};
}


int main(int argc, char const *argv[]) {
    std::vector<char> v('1');
    // 局部静态对象
    for (size_t i = 0; i < 10; i++) {
        cout << "调用" << i <<"次方法后的ctr值: " << callCountAdd() << endl;
    }

    // 关于函数的声明和函数的定义非常相似, 区别是声明不需要函数体, 也就县当于不需要返回值.
    // 可以这么说函数的三要素是(返回类型, 函数名, 形参类型)  函数声明也称作函数原型.


    // 显示利用列表初始化的返回值
    auto vec = process();
    for(auto v = vec.begin() ; v !=vec.end(); v++){
        cout << *v << " ";
    }
    cout << endl;
    return 0;
}
