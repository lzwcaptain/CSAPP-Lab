#include <stdio.h>
#include <stdlib.h>
#include "bits.h"
#define test3
void print_hex(int x);
#ifdef logical
int main()
{
    int x = 0xf0000000;
    printf_bin(x);
    int n = 4;
    printf_bin(logicalShift(x, n));
    return 1;
}
#endif
#ifdef test1
int main()
{
    printf_bin(1 << 31);
    printf_bin((1 << 31) >> 4);
    printf_bin(~((1 << 31) >> 4));
    return 0;
}
#endif
#ifdef test2
int main()
{
    printf_bin(0xff);
    printf_bin(~0xff);
    printf_bin(0xff + (~0xff));
}
#endif

#ifdef bitcount
int main()
{
    int a = 0b1111;
    printf_bin(a);
    int b = bitCount(a);
    printf_bin(b);
}
#endif
#ifdef BANG
int main()
{
    int a = 0b1000;
    printf_bin(a);
    printf_bin(bang(a));
}
#endif

#ifdef test3
int main()
{
    int x = 0b1000;
    printf_bin(x);
    x = x | (x >> 16);
    printf_bin(x);
    x = x | (x >> 8);
    x = x | (x >> 4);
    printf_bin(x);
    x = x | (x >> 2);
    printf_bin(x);
    x = x | (x >> 1);
    printf_bin(x);
    x = (~x) & 0x1;
    printf_bin(x);
}
#endif

void printf_bin(int num)
{
    printf("%d hex : ", num);
    int i, j, k;
    unsigned char *p = (unsigned char *)&num + 3; // p先指向num后面第3个字节的地址，即num的最高位字节地址

    for (i = 0; i < 4; i++) //依次处理4个字节(32位）
    {
        j = *(p - i);                //取每个字节的首地址，从高位字节到低位字节，即p p-1 p-2 p-3地址处
        for (int k = 7; k >= 0; k--) //处理每个字节的8个位，注意字节内部的二进制数是按照人的习惯存储！
        {
            if (j & (1 << k)) // 1左移k位，与单前的字节内容j进行或运算，如k=7时，00000000&10000000=0 ->该字节的最高位为0
                printf("1");
            else
                printf("0");
        }
        printf(" "); //每8位加个空格，方便查看
    }
    printf("\r\n");
}