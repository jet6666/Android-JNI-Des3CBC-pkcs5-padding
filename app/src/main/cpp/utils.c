//
// Created by jet on 2021/5/6.
//
#include "utils.h"
#include <string.h>
#include "stdio.h"
#include "stdlib.h"


unsigned char *base64_encode(unsigned char *str ,int len2) {
    long len;
    long str_len;
    unsigned char *res;
    int i, j;
//定义base64编码表
    unsigned char *base64_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
//计算经过base64编码后的字符串长度
    str_len = len2;//strlen(str);
    if (str_len % 3 == 0)
        len = str_len / 3 * 4;
    else
        len = (str_len / 3 + 1) * 4;
    res = malloc(len + 1);
    res[len] = '\0';
//以3个8位字符为一组进行编码
    for (i = 0, j = 0; i < len - 2; j += 3, i += 4) {
        res[i] = base64_table[str[j] >> 2]; //取出第一个字符的前6位并找出对应的结果字符
        res[i + 1] = base64_table[(str[j] & 0x3) << 4 |
                                  (str[j + 1] >> 4)]; //将第一个字符的后位与第二个字符的前4位进行组合并找到对应的结果字符
        res[i + 2] = base64_table[(str[j + 1] & 0xf) << 2 |
                                  (str[j + 2] >> 6)]; //将第二个字符的后4位与第三个字符的前2位组合并找出对应的结果字符
        res[i + 3] = base64_table[str[j + 2] & 0x3f]; //取出第三个字符的后6位并找出结果字符
    }

    switch (str_len % 3) {
        case 1:
            res[i - 2] = '=';
            res[i - 1] = '=';
            break;
        case 2:
            res[i - 1] = '=';
            break;
    }

    return res;
}

