#include <string>

// 为了演示 类的其他特性, 创建了两个相互关联的类Screen和Window
class Screen{
public:
    /*
        如果希望修改类的某个数据成员, 即使是在一个const成员函数内, 可以通过在变量的声明中加入mutable关键字做到这一点.
        例如: mutable size_t access_ctr;
    */

    typedef std::string::size_type pos; //设置类型别名
    // ==> using pos = std::string::size_type;

    // 为了使类更加使用, 还需要添加一个构造函数领用户能够定义屏幕的尺寸和内容, 或者其他成员
    Screen () = default;
    Screen (pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c){}

    char get() const {return contents[cursor];}         // 读取光标处的字符 隐式内联
    inline char get(pos ht, pos wd) const;              // 显示内联
    Screen &move (pos r, pos c);                        // 能在之后被设为内联
private:
    pos cursor = 0;
    pos height 0, width = 0;
    std::string contents;
}


// 令成员作为内联函数
inline                                                  // 可以在函数的定义出指定inline
Screen &Screen::move(pos r, pos c){
    pos row = r * width;        // 计算行的位置
    cursor = row + c;           // 在行内将光标移动到指定的列
    return *this;               // 以左值的形式返回对象
}

inline char Screen::get(pos ht, pos wd) const{                  // 在类的内部声明成inline
    pos row = r * width;
    return contents[row + c];   // 返回指定列的字符
}
