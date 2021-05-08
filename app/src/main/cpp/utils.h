//
// Created by jet on 2021/5/6.
//

#ifndef TEST_DES_EDE3_CBC_UTILS_H
#define TEST_DES_EDE3_CBC_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif
void base64_encode(unsigned char *str ,long str_len , unsigned char *out );
void hexdump(unsigned char *buf, int num);
#ifdef __cplusplus
}
#endif


#endif //TEST_DES_EDE3_CBC_UTILS_H
