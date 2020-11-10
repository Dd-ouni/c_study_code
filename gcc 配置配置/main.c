int main(int argc, char const *argv[])
{
    /* 
        gcc main.c -o a -std=c11 -W -Wall -Werror -fsanitize=address

        -fsanitize=address ： 打印段错误
        http://www.cppblog.com/markqian86/archive/2018/04/17/215594.html
     */

    /*
        -Wall -Werror -Wextra -pedantic -Wconversion
        兔兔推荐的五大佬
        -Wextra  打印一些额外的警告信息。
        -ansi ：告诉编译器实现ANSI语言选项。这将打开
            海湾合作委员会的关某些"特点"，这
            都与ANSI不兼容
            标准的。

        -pedantic ：配合使用 -ansi ，这告诉编译器要严格遵守ANSI标准，
        拒绝任何code这是不
        兼容。
        
        -Wconversion
        size_t到int的隐式转换会有警告  防止内存截断
    */

    // -W -Wall -Werror -Wextra -pedantic -ansi -Wconversion -std=c11 -fsanitize=address
    return 0;
}
