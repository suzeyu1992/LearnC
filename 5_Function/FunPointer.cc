# include <iostream>

using namespace std;

bool numCompare(const int & a, const int & b){
    return (a > b);
}

int main(int argc, char const *argv[]) {

    /*
        函数指针
        所谓函数指针就是指向的是函数而非对象. 函数的类型有返回值和形参决定, 和函数名无关
        例如 如下函数
        bool lenCompare(const string &, const string &);
        如果要声明对应的指针指向该函数, 只需要用指针替换函数名即可
        bool (*pf)(const string &, const string &); // 未初始化

        分析上面个的语句, 首先(*pf) 说明了pf是一个指针; 右侧是形参列表, 表示pf指向的是函数; 在观察左侧, 发现
        函数的返回类型是布尔值. 因此, pf就是一个指向函数的指针, 其中该函数的参数是两个const string引用, 返回值是bool类型

        在说明一遍(*p)的括号是必不可少的, 如果没有括号表示的意义就是pf是一个函数, 而这个函数的返回值就是bool指针
    */

    // 声明一个函数指针  名字为指针的名字为num
    bool (*numC)(const int & a, const int & b);
    // 为num指针定义一个值, 直接把一个函数名当做一个值使用的时候, 该函数会自动转换成指针
    numC = numCompare;      // 等价于 numC = &numCompare

    // 开始利用指针函数调用
    numC(1,2);         // 相当于调用numCompare()函数
    (*numC)(2,3);      //一个等价调用  也可以使用原始函数调用


    // 清空指针指向, 可以利用nullptr, 或者赋值一个值为0的整型常量表达式
    numC = nullptr;
    numC = 0;

    return 0;
}
