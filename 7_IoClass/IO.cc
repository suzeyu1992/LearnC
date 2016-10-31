#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char const *argv[]) {
    /* IO对象不可拷贝或者赋值
        就如之前的代码中一样
        ofstream out1, out2;
        out1 = out2;                    // 不能对流对象赋值
        ofstream print (ofstream);      // 不能初始化ofstream参数
        out2 = print(out2);             // 不能拷贝流对象

        总结下来就是, 不能将形参和返回类型设置为流类型. 进行IO操作的函数通常以引用的方式传递和返回流
        读写一个io对象会改变其状态, 因此传递和返回的引用不能是const的.
    */

    // 操作流状态可能会伴随着失败, 例如cin >> ival;  ival是一个int类型, 但是我们键入了B. 这是cin就会进入错误状态,
    // 一旦一个流发生错误, 其上后续的io操作都会失败. 通常通过将其作为一个当做一个条件来使用如: while(cin >> word){}

    /*
        io库定义了一个与机器无关的iostate类型, 用其提供表达流状态的完整功能
        流的状态有四种:
            1. badbit: 表示系统级错误
            2. failbit: 期望读取发生错误, 可以修复, 流也可以继续使用
            3. eofbit: 当到达文件结束位置, eofbit和failbit将被置位
            4. goobit: 流未发生错误可以使用

        流对象的 rdstate成员返回一个iostate的值, 对应流的当前状态, 而setstate操作将给定条件位置为.
        clear是一个重载的成员包括无参合接受一个iostate类型的版本. 使用参考如下:
            auto old_state = cin.rdstate();     // 记住cin的当前状态
            cin.clear();                        // 使cin有效
            process_input(cin);                 // 使用cin
            cin.setstate(old_state);            // 将cin置为原有状态

            如下代码, 表示复位failbit和badbit. eofbit不变
            cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit);


    */

    // 刷新输出缓冲区
    std::cout << "hi!" << std::endl;      // 输出一个hi和一个换行, 然后刷新缓冲区
    std::cout << "hi!" << std::flush;     // 输出hi, 然后刷新缓冲区, 不附加任何额外字符
    std::cout << "hi!" << std::ends;      // 输出hi和一个空字符, 然后刷新缓冲区


    // unitbuf操纵符
    // 如果需要每次输出操作后都刷新缓冲区,, 可以使用unitbuf操纵符. 它告诉流接下来每次写操作之后都进行一次flush操作.
    std::cout << std::unitbuf;       // 所有输出操作后都会立即刷新缓冲区
    // ....  这段区域的任何输出都立即刷新, 无缓冲
    std::cout << std::nounitbuf;     // 回到正常的缓冲方式

    std::string ifile= "/Users/suzeyu/Documents/workspace/c/LearnC/7_IoClass/Test.txt";
    std::ifstream in(ifile);
    in.open() >> ifile ;
    std::cout << ifile << std::endl;
    // std::ofstream out;
    // out.open(ifile);
    // out << "嘿嘿" << std::endl;


    /*
        文件的模式
        in      以读方式打开
        out     以写方式打开
        app     每次写操作前均定位到文件末尾
        ate     打开文件后立即定位到文件末尾
        trunc   截断文件
        binary  以二进制方式进行IO
    */


















    return 0;
}
