// 通过下列using声明, 可以在函数体内直接使用标准库的名字
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string

int main(){
    cout << "使用using声明, 省略标准的 命名空间::变量 的方式" << endl;

    // 初始化stirng常用的方式
    string s1 ;             // 默认初始化, s1是一个空字符串
    string s2 = s1;         // s2是s1的副本     等价于     string s2(s1);
    string s3 = "hello";    // s3是该字符串字面值的副本  等价于   string s3("hello");
    string s4(10, 'c');     // s4的内容是ccccccccccc


    // 直接初始化和拷贝初始化  使用 = 号初始化一二变量, 实际上执行的是拷贝初始化, 与之相反那么就是直接初始化
    string s5 = "copy_initialization";       // 拷贝初始化
    string s6("direct_initialization");      // 直接初始化




}
