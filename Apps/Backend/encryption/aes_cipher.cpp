#include "aes_cipher.h"
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <stdexcept>
#include <cstring>

AESCipher::AESCipher(const std::string &keyStr) {
    if (keyStr.size() < 32) {
        throw std::runtime_error("Ключ должен быть длиной 32 байта");
    }
    memcpy(key, keyStr.data(), 32);
}

std::string AESCipher::encrypt(const std::string &plaintext) {
    AES_KEY encryptKey;
    AES_set_encrypt_key(key, 256, &encryptKey);

    unsigned char localIV[AES_BLOCK_SIZE];
    RAND_bytes(localIV, AES_BLOCK_SIZE);

    unsigned char ciphertext[plaintext.size() + AES_BLOCK_SIZE];
    int outlen = 0;

    AES_cfb128_encrypt(
        (unsigned char *)plaintext.data(),
        ciphertext,
        plaintext.size(),
        &encryptKey,
        localIV,
        &outlen,
        AES_ENCRYPT
    );

    std::string result((char *)localIV, AES_BLOCK_SIZE);
    result += std::string((char *)ciphertext, plaintext.size());
    return result;
}

std::string AESCipher::decrypt(const std::string &ciphertext) {
    AES_KEY decryptKey;
    AES_set_decrypt_key(key, 256, &decryptKey);

    unsigned char localIV[AES_BLOCK_SIZE];
    memcpy(localIV, ciphertext.data(), AES_BLOCK_SIZE);

    unsigned char plaintext[ciphertext.size() - AES_BLOCK_SIZE];
    int outlen = 0;

    AES_cfb128_encrypt(
        (unsigned char *)(ciphertext.data() + AES_BLOCK_SIZE),
        plaintext,
        ciphertext.size() - AES_BLOCK_SIZE,
        &decryptKey,
        localIV,
        &outlen,
        AES_DECRYPT
    );

    return std::string((char *)plaintext, ciphertext.size() - AES_BLOCK_SIZE);
}
