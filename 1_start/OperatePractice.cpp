
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

    return 0;
}
