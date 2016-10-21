
#ifndef SALES_DATA_H   //判断SALES_DATA_H变量是否未定义, 如果是未定义那么会顺序向下执行, 直到#endif
#define SALES_DATA_H   // 定义SALES_DATA_H变量
#include <string>

struct SalesData{
        std::string bookName;
        unsigned sold = 0;
        double revenue = 0.0;
};

#endif
