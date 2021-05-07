#include <jni.h>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <tripleKeyDESCBCEncryption.h>
#include "android/log.h"

#include "utils.h"

#define TAG    "3DESC-CBC-lib" // 这个是自定义的LOG的标识
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__) // 定义LOGD类型


void hexdump(unsigned char *buf, int num) {
    int i;
    for (i = 0; i < num; i++) {
        LOGD("i = %d , v =  %02X ", i, buf[i]);
        if ((i + 1) % 8 == 0)
            LOGD("\n");
    }
    LOGD("\n");
}

int get_padding_length(int data_length) {
    return 8 - data_length % 8;
}


//PKCS#5 padding
char *padding_with_length(const char *src, int src_length) {
    int padding_length = get_padding_length(src_length);
    char *res = (char *) malloc(src_length + padding_length + 1);
    int i = 0;
    memcpy(res, src, src_length);
    for (; i < padding_length; i++) {
        res[src_length + i] = padding_length;
    }
    res[src_length + i] = '\0';
    return res;
}


//
void test_3DES_CBC_PKCS5() {
    const char buffer[] = "this is a 3des-cbd-PKCS#5 example2222";
//    LOGD("plain  text  = %s ,length = %d \n", buffer, strlen(buffer));
//    hexdump((unsigned char *) buffer, strlen(buffer) + 1 ) ;
    //after  PKCS#5 padding
    char *buffer2 = padding_with_length(buffer, strlen(buffer));
    //hexdump(reinterpret_cast<unsigned char *>(buffer2), strlen(buffer2) + 1);
    //LOGD("stop ======\n") ;
    int buffer_length = strlen(buffer2);
    //iv = thisthat
    char iv[] = {0X74, 0X68, 0X69, 0X73, 0X74, 0X68, 0X61, 0X74};
    LOGD("iv = %s \n", iv);
    //key = key1key2key3key4key5key6key7key8
    char key[] = {0X6B, 0X65, 0X79, 0X31, 0X6B, 0X65, 0X79, 0X32};
    char key2[] = {0X6B, 0X65, 0X79, 0X33, 0X6B, 0X65, 0X79, 0X34};
    char key3[] = {0X6B, 0X65, 0X79, 0X35, 0X6B, 0X65, 0X79, 0X36};
//    printf("key  = %s \n", iv);

    char out[1024] = {0};
    memset(out, 0x0, sizeof(out));
    tripleKeyDES_CBCEncryption(buffer2, key,
                               key2, key3, iv,
                               buffer_length,
                               out);

    //hex data
    int len = buffer_length;//strlen(out);
    LOGD("=======result  hex  ,length =%d \n", len);
    hexdump(reinterpret_cast<unsigned char *>(out), len + 1);
    LOGD(" \n");

    //base64
    unsigned char *buf = NULL;
    buf = base64_encode(reinterpret_cast<unsigned char *>(out) ,buffer_length);
    LOGD("base64 =%s ", buf);
    free(buf);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_test_1des_1ede3_1cbc_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello2 = "Hello from C++";


    test_3DES_CBC_PKCS5();

    return env->NewStringUTF(hello2.c_str());
}

