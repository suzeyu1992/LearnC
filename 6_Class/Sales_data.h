#ifndef SALES_DATA_H   //判断SALES_DATA_H变量是否未定义, 如果是未定义那么会顺序向下执行, 直到#endif
#define SALES_DATA_H   // 定义SALES_DATA_H变量
#include <string>

struct Sales_data{

        // 关于Sales_data的新成员
        std::string isbn() const {return bookName};             // 此函数声明和定义都在类的内部
        // 上面一句的函数体等价于 {return this->bookName;} // 因为this的目的总是指向这个对象, 所以this是一个常量指针, 不允许改变this中保存的地址
        // 而此函数另一个关键之处是紧随参数列表之后的const关键字, 这里const的作用是修改隐式this指针的类型

        Sales_data& combine(const Sales_data&);                 // 此函数类内部只有声明
        double avg_prince() const;                              // 此函数类内部只有声明

        std::string bookName;
        unsigned sold = 0;
        double revenue = 0.0;
};

// 作为接口组成部分的非成员函数, 定义和声明都在类的外部
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);


// 在类的外部定义成员函数
double Sales_data::avg_prince() const{
    if(sold)
        return revenue;
    else
        return 0;
}

#endif
