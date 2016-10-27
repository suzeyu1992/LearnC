
#include <iostream>
#include <string>
#include <initializer_list>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;

size_t callCountAdd(){
    static size_t ctr = 0;
    return ++ctr;
}

/*定义可变参数  initializer_list*/

/*利用列表初始化返回值*/
// std::vector<string>  process(){
//     return {"列表", "初始化", "返回值"};
// }


int main(int argc, char const *argv[]) {
    std::vector<char> v('1');
    // 局部静态对象
    for (size_t i = 0; i < 10; i++) {
        cout << "调用" << i <<"次方法后的ctr值: " << callCountAdd() << endl;
    }

    // 关于函数的声明和函数的定义非常相似, 区别是声明不需要函数体, 也就县当于不需要返回值.
    // 可以这么说函数的三要素是(返回类型, 函数名, 形参类型)  函数声明也称作函数原型.


    // 显示利用列表初始化的返回值
    /*
    auto vec = process();
    for(auto v = vec.begin() ; v !=vec.end(); v++){
        cout << *v << " ";
    }
    cout << endl;
    */


    /*
        返回数组指针
        因为数组不能拷贝, 所以函数不能返回数组, 不过可以返回数组的指针或者引用. 如下比较简单的方法就是利用类型别名
        typedef int arrT[10];   //arrT 是一个类型别名, 表示类型是 含有10个整数的数组
        using arrT = int[10];   //等价于上面使用typedef声明的类型别名
        arrT* func(int i);      // func返回一个指向10个整型数组的 指针.

        不使用别名  实现声明一个返回数组指针的函数
        int (*func(int i))[10];
        // func(int i)函数声明, 表示需要一个int类型的实参, 加上(*func(int i))表明返回的是一个指针, 可以解引用
        // (*func(int i))[10]表示返回结果进行解引用将得到一个大小为10的数组,  最后的int说明数组内的元素类型

        使用尾置返回法  此方法是c++11中出现的
        auto func(int i) -> int (*)[10]
        可以看出在参数列表之后使用-> 来指定返回类型.
        首先(*)返回的是一个指针, int (*)[10] 然后其余部分标出指针指向对象的类型为一个大小为10的整数型数组
    */



    // 主函数的返回值, 如果控制到达结尾处没有return语句, 编译器将隐式地插入一条返回0的return语句
    // 0表示执行成功, 非0表示执行失败, 非0值的具体含义依机器而定, 为了是返回与机器无关, cstdlib头文件定义了两个预处理变量
    bool resolve = true;
    if (resolve) {
        return EXIT_FAILURE;
    }else{
        return EXIT_SUCCESS;
    }
}
