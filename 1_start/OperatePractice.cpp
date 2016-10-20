
int uninitializedVariableOutside ;


int main(){

    // 无符号类型相减的时候注意 出现负数的情况
    unsigned  u1 = 42, u2 = 10;
    std::cout << u1 - u2 << std::endl;  // 可以执行, 输出32
    std::cout << u2 - u1 << std::endl;  // 可以执行, 不过结果是取模后的值

    // 当算术表达式中即有无符号又有int值时, 那个int值会转换成无符号数
    unsigned u = 10;
    int i = -42;
    std::cout << i + i << std::endl;    // 输出-84
    std::cout << u + i << std::endl;    // 如果int占32位, 输出4294967264


    /******************************字面值常量****************************************/
    /*
        十进制 普通数字 字面值默认是十进制带符号数
        八进制 0开头 字面值可能是无符号或者有符号
        十六进制 0x开头 字面值可能是无符号或者有符号
        浮点型 默认为double类型
    */
    std::cout << "我是八进制10 输出结果: " <<  010 << std::endl;
    std::cout << "我是十进制10 输出结果: " <<  10 << std::endl;
    std::cout << "我是十六进制进制10 输出结果: " <<  0x10 << std::endl;

    /***********************变量*************************************************/
    std::cout << "\n*************************变量*************************************" << std::endl;
    int uninitializedVariableInternal ;
    std::cout << "未被初始化的变量--函数体之内int值:   " << uninitializedVariableInternal << std::endl;
    std::cout << "未被初始化的变量--函数体之外int值:   " << uninitializedVariableOutside << std::endl;

    extern int declarationInt ;      // 声明一个变量而非定义 , 如果在函数体内部用extern声明的时候试图初始化那么会crash
    int definitionInt;              // 声明一个变量并定义


    return 0;
}
