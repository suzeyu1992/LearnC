// 告诉编译器我们要使用iostream库
#include <iostream> // 括号内的内容指向了一个头文件

int main(){

    // std作用是为命名空间,防止一些名字的冲突, 标准库定义的所有名字都在命名空间std中
    // :: 作用域运算符 , 可以指出使用定义在命名空间的字段
    // << 表示输出运算符
    std::cout << "请输入两个数字: " ;
    // endl, 这是一个操作符的特殊值, 效果为结束当前行, 并将于设备关联的缓冲区中的内容刷新到设备
    std::cout << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "数字为: " << v1 << " + " << v2 << " = "<< v1+v2 << std::endl;
    printf("%s\n", "嘿嘿");
    return 0;
}
