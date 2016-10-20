
int uninitializedVariableOutside ;
int reused = 20;    // reused变量具有全局作用域

int &refVal = reused;       // refVal 指向reused, 可以理解为引用即别名
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

    std::cout << "输出全局变量reused的值: " << reused << std::endl;
    int reused = 10;    // 会覆盖全局reused的变量
    std::cout << "输出局部变量创建后的reused的值: " << reused << std::endl;
    // refVal = 1000;        // 使用引用(别名)修改原始值, 会对全局reused指向的值触发影响
    std::cout << "显式的调用全局变量reused的值: " << ::reused << std::endl;


    /***********************指针*************************************************/
    std::cout << "\n*************************指针*************************************" << std::endl;

    // 利用指针访问对象
    int ival = 99;
    int *p = &ival;     // 使用取地址符(&)获取int对象的地址, 所以指针p存放着变量ival的地址
    std::cout << *p;    // 使用解引用符(*)来访问对象, 就是相当于有符号*得到指针p所指向的对象

    std::cout << "\n*************************生成空指针*************************************" << std::endl;
    int *p1 = nullptr;      // 最直接的方法, 使用字面值nullptr来初始化指针, 这是c++11中新引入的方法, nullptr是一种特殊的字面值, 可以转换任意其他的指针类型
    int *p2 = 0;            // 也可以通过将指针初始化为字面值0来生成空指针
    int *p3 = NULL;         // 使用预处理变量来给指针赋值, 这个扁郎在头文件cstdlib中, 不属于命名空间std, 它由预处理器负责管理, 所以无需加上std::

    std::cout << "\n************************* void*指针 *************************************" << std::endl;
    double obj = 3.14, *pd = &obj ,temp = 2.22 ,*ptemp = &temp;
    void *pv = &obj;
    pv = pd;        //pv可以存放任意类型的指针,

    /**
        对指针进行赋值
        当要赋值的指针带有*号的时候, 如   *pd = temp;
            *pd 代表指针指向的对象, 因为使用解引用符(*). 所以=右侧应该是一个相应的对象来对指针进行赋值
        当要赋值的指针无*号的时候, 如 pd=&temp;
            pd代表着指针指向的空间地址值, 所以=右侧应该是一个对象的地址值, 所以应该使用取地址符(&)获取对象的地址
    **/
    pd = &temp;
    *pd = temp;
    std::cout << "void*指针的值: " << *pd << "  obj"<<obj<< std::endl;

    return 0;
}
