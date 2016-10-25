#include <string>
#include <iostream>
using std::string;
// 通过下列using声明, 可以在函数体内直接使用标准库的名字
using std::cout;
using std::cin;
using std::endl;

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

    // 使用getline()读取一行
    /*
    string lineStr ;
    while(getline(cin, lineStr)){
        cout << "我是复制输出" << lineStr << endl;
    }
    */

    // 测试字符串的长度和判空
    // 注意如果一条表达式中使用了 size() 那么就不要再使用int了, 这样可以避免int和unsigned混用的问题
    string emptyStr = "";
    cout << "emptyStr字符串是否为空: " << emptyStr.empty()
         << "\nHello字符串的长度: "<< s3.size() << endl;


    // 字符串对象相加
    string addStr = s3 + s4;
    cout << "字符串对象相加:" << addStr << endl;
    s3 = "hhello";
    cout << "改变之前相加字符串的某一个值并打印, s3=" << s3 << "     相加数addStr=" << addStr <<endl;

    // 使用+连接字符串字面值常量和字符串对象的时候要注意,  不允许两个字面值常量字符串进行 + 连接
    // 还有切记字符串字面值与string是不同类型

    cout << "\n******************************开始练习操作字符串*************************************" << endl;

    string operatorStr("some one!!");
    // 向打印每行输出一个, 最后统计一个字符串中标点符号的个数
    // 声明一个标记个数的变量 , 变量类型使用decltype()获取和size()返回的类型一样的对象类型
    decltype(operatorStr.size()) strCount = 0;
    for(auto c : operatorStr){
        if (ispunct(c)) {   // 判断单个字符是否是标点
            ++strCount;
        }
        cout << c << endl;
    }
    cout << "字符串operator中标点符号个数为: " << strCount  << endl;



    cout << "\n******************************使用for循环改变字符串中的字符*************************************" << endl;
    // 转成大写
    for(auto &c : operatorStr){     // 这里c代表了一个字符引用
        c = toupper(c);             // 只要把转换后的字符, 赋值给原始字符串中的引用, 即可改变对象
    }

    cout << "改变后的字符串: "<< operatorStr << endl;

    cout << "\n******************************字符串的下标操作*************************************" << endl;
    // 替换字符串的最后一个字符为空串
    if(!operatorStr.empty()){
        operatorStr[operatorStr.size()-1] = ' ';
    }
    cout << "去掉最后一个字符后的字符串: "<< operatorStr << endl;

















}
