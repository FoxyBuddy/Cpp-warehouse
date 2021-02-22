/* 引用自定义头文件 calc.h 的原因是：
1、在多个源代码文件中使用函数（如果代码中有涉及）；
2、避免因函数名称重定义导致的错误发生。
头文件中只写外部源文件的函数原型，不写函数的主体部分，也不写main函数。
*/

void calc(int init);
void exponent(int exp);
void xlcThousands(double thousands);