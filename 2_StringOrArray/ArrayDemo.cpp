#include <string>
#include <iostream>
using std::string;
// 通过下列using声明, 可以在函数体内直接使用标准库的名字
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[]) {

        cout << "************************数组的初始化**************************************" << endl;
        //关于数组的初始化, 声明的数组大小, 必须是常量表达式, 如果数组的array[size]中使用了size那么size记得使用constexpr关键字修饰为常量
        //显示初始化数组
        const unsigned size = 5;
        int a1[size] = {1,3,5};           // 数组中有三个元素, 元素值分别为1,3,5
        int a2[] = {1,3,5};             // 长度是3的数组, 等价于上面
        int a3[5] = {1,3,5};            // 数组的长度为5, 等价于 = {1,3,5,0,0}

        //字符数组的特殊性
        char c1[] = "c++";                // 长度应该是4, 因为字符串包含着一个空字符等价于 = {'c','+','c','\0'}



    return 0;
}
