#include <string>
#include <vector>
// 为了演示 类的其他特性, 创建了两个相互关联的类Screen和Window

class Window{
private:
    // window追踪的Screen
    // 默认情况下, 一个window包含一个标准尺寸的空白Screen
    std::vector<Screen> screens{Screen(24, 80, ' ')};       // 类内初始化值必须使用=的初始化形式或者花括号括起来的直接初始化形式
}
