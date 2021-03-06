#include <string>
#include <vector>
// 为了演示 类的其他特性, 创建了两个相互关联的类Screen和Window

class Window{

public:
    // 创建类的静态成员
    static double size;         // 使用作用域运算符访问静态成员   double temp = Window::size;

    // 静态成员的类内初始化
    static constexpr int prieds = 20;       // 要想实现静态成员的类内初始化, 那么成员必须是constexpr字面值常量类型
                                            // 并且初始值也为常量表达式
    /*
        静态成员和非静态成员某些区别
        静态数据成员可以是不完全类型,  而非静态成员受到了限制, 只能声明成它所属类的指针或引用,
        例如:
            static Window win;      // ok, 静态成员可以是不完全类型
            Window *win2;           // ok, 指针成员可以是不完全类型
            Window win;             // err, 数据成员必须是完全类型

        还有一点, 可以使用静态成员作为默认实参.  因为非静态数据成员它的值本身属于对象的一部分.
        Screen &clear(char = bk);       //bk表示一个在类中稍后定义的静态成员
        static const char bk;
    */

private:
    // window追踪的Screen
    // 默认情况下, 一个window包含一个标准尺寸的空白Screen
    std::vector<Screen> screens{Screen(24, 80, ' ')};       // 类内初始化值必须使用=的初始化形式或者花括号括起来的直接初始化形式
    explicit  // 抑制构造函数定义的隐式转换, 只能针对一个参数的构造函数, 并且只能在类中定义.

    string bar;                // 默认初始化成空的string对象
    bar = "Hi";                // 为bar赋一个值
    string foo = "hi";         // 定义并初始化

    // 演示错误的构造函数初始化
    const string tempInt;          // 成员是const常量
    string &tempDou;               // 成员是引用



}

// 创建一个构造函数, 但是不编写 初始值列表, 值对成员变量在函数体内进行赋值
 Window::Window(string &s){
    bar = s;        // 因为没有在构造函数的参数列表之后使用 : ...{} 进行函数的初始值列表中
                    // 显式地初始化成员, 则该成员将在构造函数体之前执行默认初始化, 并在函数体内进行赋值动作.
            // 注意 : 所以如果数据成员是是const或者引用的话唯一的初始化机会就是通过构造函数的初始值, 必须使用初始化列表进行初始化, 否则会发生错误,
            // 例如: 在函数体内进行 tempInt = s; tempDou = s;  将会引发错误, const不能被赋值修改, 引用还没被初始化
            // 正确方式: Window::Window(string &s):tempInt(s), tempDou(s){...}
}

// 委托构造函数函数     相当于java中 通过this调用本类的其他构造函数
Window::Window():Window::Window(""){}

/*
    聚合类:
        1. 所有成员都是public
        2. 没有定义任何构造函数
        3. 没有了类内初始值
        4. 没有基类, 没有virtual函数
*/
struct Data{
    int iVal;
    string s;
}
// 可以使用 列表赋值法初始化.    Data call = {0, "su"}; // 要保证初始值与生命的顺序一致.
