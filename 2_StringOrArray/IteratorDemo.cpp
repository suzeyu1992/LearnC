#include <string>
#include <iostream>
using std::string;

int main(int argc, char const *argv[]) {

    // 利用迭代器改变字符串的第一个字符为大写
    string s("some person");
    if(s.begin() != s.end()){   // 确保s的非空
        auto it = s.begin();    // 一个指向元素的Iterator变量, 可以通过解引用运算符来获得指向的元素
        *it = toupper(*it);
    }
    std::cout << s << std::endl;

    // 利用迭代器的自增来实现字符串的转换大写
    // 转换空白符之前的所有字符为大写
    for(auto i = s.begin(); i!=s.end() && !isspace(*i) ; i++){
        *i = toupper(*i);
    }
    std::cout << s << std::endl;

    /*
        迭代器的类型
        vector<int> v1;
        const vector<int> v2;

        auto it1 = v1.begin();      // it1的类型是vector<int>::iterator
        auto it2 = v2.begin();      // it2的类型是vector<int>::const_iterator
        // 如果对象只需要读操作, 不需要写操作最好使用常量类型, c++11中新增的两个函数,就是此目的cbegin(), cend()
        auto it3 = v1.cbegin();     // it3的类型是vector<int>::const_iterator
    */



    // c++中的 箭头运算符 ->
    /*
        箭头运算符把解引用和成员访问两个操作结合在一起, 如下:
        it -> men   等价于     (*it).men
    */






    return 0;
}
