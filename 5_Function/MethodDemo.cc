
#include <iostream>
#include <string>
#include <initializer_list>
#include <vector>
#include <sstream>
#include <cassert>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using namespace std;

size_t callCountAdd(){
    static size_t ctr = 0;
    return ++ctr;
}

/*定义可变参数  initializer_list*/

/*利用列表初始化返回值*/
// std::vector<string>  process(){
//     return {"列表", "初始化", "返回值"};
// }


// 默认实参
typedef string::size_type sz;
string screen(sz h = 24, sz w = 24){
    // 使用标准库
    stringstream  ss;
    ss << "高:" << h << "    宽:" << w;
    return ss.str() ;
}

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

    /*
        重载函数
        如果同一个作用域内的几个函数名字相同但形参列表不同, 称为 overloaded function, 返回值不参与评判重载的标准


        // 利用引用形参构建两个重载函数
        Record lookup(const Account&);
        Record lookup(const Phone&);            // 属于重载函数

        // 重载和const形参
        // 顶层的const不影响传入函数的对象, 一个拥有顶层const的形参无法和另外一个没有顶层const的形参区分开来
        Record lookup(Phone);
        Record lookup(const Phone);  // 第二条错误, 重复声明了函数

        Record lookup(Phone*);
        Record lookup(Phone* const);  // 第二条错误, phone* 代表着 phone是一个指针, 然后const修饰这个指针是一个常量指针, 也就是顶层const

        但是如果传入形参是指针, 指针的顶层const不同那么就可以作为重载
        Record lookup(Phone*);         // 指针指向的是一个非常量对象
        Record lookup(const Phone*);   // 属于重载, const 修饰的效果指针指向的对象是常量, 这是一个底层const. 表明对象是一个常量对象



    */

    // 调用默认实参
    string result_1 = screen();
    cout << "调用默认实参函数(不传参数)结果: " << result_1 << endl;
    result_1 = screen(1);
    cout << "调用默认实参函数(传第一个参数)结果: " << result_1 << endl;
    result_1 = screen(1,1);
    cout << "调用默认实参函数(传第两参数)结果: " << result_1 << endl;
    // 注意对于没有实参的函数和有实参的函数是可以共存的, 例如函数
    // void add(int a){}
    // Void add(int a = 1){}



    // 调试帮助 -- assert预处理宏
    /*
        assert是一种预处理宏, 所谓预处理宏其实是一个预处理变量, 它的行为有点类似于内联函数. assert宏是用一个表达式作为他的条件.
        assert宏定义在cassert头文件中, 预处理名字由预处理器而非编译器管理, 因此, 可以直接使用预处理名字而无需提供using声明.
        表示式的结果如果是0那么断言失败, 系统终止执行, 反之非0, 程序继续向下执行.
    */
    assert(1);
    cout << "断言成功可以继续执行" << endl;



    // 主函数的返回值, 如果控制到达结尾处没有return语句, 编译器将隐式地插入一条返回0的return语句
    // 0表示执行成功, 非0表示执行失败, 非0值的具体含义依机器而定, 为了是返回与机器无关, cstdlib头文件定义了两个预处理变量
    bool resolve = true;
    if (resolve) {
        return EXIT_FAILURE;
    }else{
        return EXIT_SUCCESS;
    }
}
