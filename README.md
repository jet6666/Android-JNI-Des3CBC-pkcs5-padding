# Android-JNI-Des3CBC-pkcs5-padding
Android des-ede3-cbc  PKCS#5 C  JNI project


simple and light    C/C++  des3 cbc pkcs5 padding algorithm

```
const char buffer[] = "this is a 3des-cbd-PKCS#5 example2222";
    char *buffer2 = padding_with_length(buffer, strlen(buffer));
    int buffer_length = strlen(buffer2);
    //iv = thisthat
    char iv[] = {0X74, 0X68, 0X69, 0X73, 0X74, 0X68, 0X61, 0X74};
    LOGD("iv = %s \n", iv);
    //key = key1key2key3key4key5key6key7key8
    char key[] = {0X6B, 0X65, 0X79, 0X31, 0X6B, 0X65, 0X79, 0X32};
    char key2[] = {0X6B, 0X65, 0X79, 0X33, 0X6B, 0X65, 0X79, 0X34};
    char key3[] = {0X6B, 0X65, 0X79, 0X35, 0X6B, 0X65, 0X79, 0X36};

    char out[1024] = {0};
    memset(out, 0x0, sizeof(out));
    tripleKeyDES_CBCEncryption(buffer2, key,
                               key2, key3, iv,
                               buffer_length,
                               out);

    //hex data
    int len = strlen(out);
    LOGD("=======result  hex  ,length =%d \n", len);
    hexdump(reinterpret_cast<unsigned char *>(out), len + 1);
    LOGD(" \n");
```


# why not use openssl library  ( [static libary](https://github.com/AsteriskZuo/openssl_for_ios_and_android))

## 1. support api 23 above 
## 2.size too big (5MB)



# use openssl  library example

```
EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
        FILE *out2;

        EVP_CIPHER_CTX_init(ctx);
        EVP_EncryptInit_ex(ctx, EVP_des_ede3_cbc(), NULL, key, iv);
        if (!EVP_EncryptUpdate(ctx, outbuf, &outlen,
                               reinterpret_cast<const unsigned char *>(intext), sizeof(intext))) {
            LOGD("failed");
        } else {
            /* Buffer passed to EVP_EncryptFinal() must be after data just
         * encrypted to avoid overwriting it.
         */
            if (!EVP_EncryptFinal_ex(ctx, outbuf + outlen, &tmplen)) {
                /* Error */
                LOGD("failed2");
            } else {
                outlen += tmplen;
                EVP_CIPHER_CTX_cleanup(ctx);
                print_data("\n New \n", outbuf, outlen);

                //Encode To Base64
                char *enc_output = Base64Encode(reinterpret_cast<const char *>(outbuf), outlen);
                LOGD("base64 = %s\n", enc_output);
            }
        }
```

 
