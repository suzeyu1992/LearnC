#include <iostream>
#include <string>

using std::string;

int main(int argc, char const *argv[]) {

    // 算术运算符 (-) 操作布尔值
    bool b = true;
    bool b2 = -b;
    std::cout << "b2的布尔值" << b2 << std::endl;

    // boolean的关系运算时的比较
    int i = 1;
    int j = 2;
    int k = 3;
    if(i < j < k){                      // 此比较首先是i<j, 得到的是true, 当于k整数型比较的时候, true转变为1进行比较 1 < k的条件表达式
        std::cout << "条件成立" << std::endl;
    }

    // 点运算符 和 箭头运算符
    string s1 = "hungry", *pStr = &s1;
    int num_1 = s1.size();
    int num_2 = pStr -> size();        // 等价于 (*pStr).size();  指针(*pStr)中的括号是必须的, 如果没有那么, 点运算会优先执行
    if (num_2 == num_1) {
        std::cout << "使用点运算和箭头运算的字符串大小相等!!!" << std::endl;
    }

    // 条件运算符(三目运算符) 在输出表达式的使用
    std::cout << ((3 < 4) ? "fail" : "pass" ) << std::endl;
    //  比较有歧义的三木表达式
    //std::cout << (3 < 4) ? "fail" : "pass"  ;
    /*
        上面的语句等价于 ==>
        cout << (3 < 4);               // 输出1
        std::cout << ? "fail" : "pass" << std::endl;  // 根据cout的值是true还是false产生对应的字面值
    */


    // sizeof运算符    返回一条表达式或者一个类型 所占的字节数. 所得的是一个size_t类型常量表达式
    int z = 1, *pz = &z;
    std::cout << "int的占用空间字节数: "<< sizeof(z) << std::endl;
    std::cout << "int类型指针的占用空间字节数: "<< sizeof(pz) << std::endl;

    char c = '1', *pc = &c;
    std::cout << "char的占用空间字节数: "<< sizeof(c) << std::endl;
    std::cout << "char类型指针的占用空间字节数: "<< sizeof(pc) << std::endl;

    return 0;
}
