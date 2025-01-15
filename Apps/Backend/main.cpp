//#include <iostream>
//#include <string>
//#include <curl/curl.h>
//#include <openssl/aes.h>
//#include <openssl/rand.h>
//#include <nlohmann/json.hpp> // Для работы с JSON
//
//using json = nlohmann::json;
//
//class AESCipher {
//private:
//    unsigned char key[32]; // 256-битный ключ
//    unsigned char iv[AES_BLOCK_SIZE]; // Вектор инициализации
//
//public:
//    AESCipher(const std::string &keyStr) {
//        if (keyStr.size() < 32) {
//            throw std::runtime_error("Ключ должен быть длиной 32 байта");
//        }
//        memcpy(key, keyStr.data(), 32);
//        RAND_bytes(iv, AES_BLOCK_SIZE); // Генерация случайного IV
//    }
//
//    std::string encrypt(const std::string &plaintext) {
//        AES_KEY encryptKey;
//        AES_set_encrypt_key(key, 256, &encryptKey);
//
//        unsigned char ciphertext[plaintext.size() + AES_BLOCK_SIZE];
//        int outlen = 0;
//        AES_cfb128_encrypt(
//            (unsigned char *)plaintext.data(),
//            ciphertext,
//            plaintext.size(),
//            &encryptKey,
//            iv,
//            &outlen,
//            AES_ENCRYPT
//        );
//
//        return std::string((char *)ciphertext, plaintext.size());
//    }
//
//    std::string decrypt(const std::string &ciphertext) {
//        AES_KEY decryptKey;
//        AES_set_decrypt_key(key, 256, &decryptKey);
//
//        unsigned char plaintext[ciphertext.size()];
//        int outlen = 0;
//        AES_cfb128_encrypt(
//            (unsigned char *)ciphertext.data(),
//            plaintext,
//            ciphertext.size(),
//            &decryptKey,
//            iv,
//            &outlen,
//            AES_DECRYPT
//        );
//
//        return std::string((char *)plaintext, ciphertext.size());
//    }
//};
//
//class FirebaseHandler {
//private:
//    std::string firebaseURL;
//    std::string authToken;
//
//public:
//    FirebaseHandler(const std::string &url, const std::string &token) : firebaseURL(url), authToken(token) {}
//
//    // Отправка POST-запроса в Firebase
//    void sendPostRequest(const std::string &path, const json &data) {
//        CURL *curl;
//        CURLcode res;
//
//        curl = curl_easy_init();
//        if (curl) {
//            std::string url = firebaseURL + path + ".json?auth=" + authToken;
//            std::string jsonData = data.dump();
//
//            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
//            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonData.c_str());
//
//            struct curl_slist *headers = nullptr;
//            headers = curl_slist_append(headers, "Content-Type: application/json");
//            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
//
//            res = curl_easy_perform(curl);
//            if (res != CURLE_OK) {
//                std::cerr << "Ошибка запроса: " << curl_easy_strerror(res) << std::endl;
//            }
//
//            curl_easy_cleanup(curl);
//        }
//    }
//};
//
//int main() {
//    // Инициализация шифратора
//    AESCipher cipher("my_super_secret_32_byte_key");
//
//    // Данные для отправки
//    json userData = {
//        {"name", cipher.encrypt("John Doe")},
//        {"email", cipher.encrypt("john.doe@example.com")},
//        {"created_at", "2025-01-15"}
//    };
//
//    // Инициализация Firebase
//    FirebaseHandler firebase("https://your-project-id.firebaseio.com", "YOUR_FIREBASE_AUTH_TOKEN");
//
//    // Отправка данных
//    firebase.sendPostRequest("/users", userData);
//
//    std::cout << "Данные успешно отправлены!" << std::endl;
//
//    return 0;
//}
