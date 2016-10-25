# include <vector>
using std::vector;

int main(int argc, char const *argv[]) {
    /* code */
    /*
        初始化 vector 对象的方法. 需要明确 vector是模板而非类型, 所以对应着vector是一个类模板

        // 普通初始化
        vector<T> v1        v1是一个空vector, 它潜在的元素是T类型的, 执行默认初始化
        vector<T> v2(v1)    v2中包含有v1所有元素的副本, 相当于把v1中的元素拷贝到v2
        vector<T> v2 = v1   等价于v2(v1), v2中包含有v1所有元素的副本

        // 创建指定数量的元素
        vector<T> v3(n, val)    v3包含了n个重复的元素val,

        // 值初始化, 如果元素是内置类型如int,那么元素初始值自动设为0. 如果元素是某种类类型如string,则元素由类默认初始化
        vector<T> v4(n)         v4包含了n个重复地执行了值初始化的对象

        // c++11 标准中,新添加的列表初始化vector对象
        vector<T> v5{a,b,c,...} v5包含了初始值个数的元素, 每个元素被赋予相应的初始值
        vector<T> v6 = {a,b,c...} 等价于v5{a,b,c...}
            // 注意区当使用花括号是也就是(list initialized)时, 如果花括号内提供的值不能用来列表初始化, 那么编译器会尝试用默认值初始化vector,如下
            vector<int> v7{10,11}       // 容器里面包含了两个元素, 10和11
            vector<string> v8{10,"hi"}  // 容器包含了10个值为"hi"的元素
    */





    return 0;
}
