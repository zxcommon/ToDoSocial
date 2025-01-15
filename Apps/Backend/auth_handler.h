#ifndef AUTH_HANDLER_H
#define AUTH_HANDLER_H

#include <string>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class AuthHandler {
public:
    static std::string getAuthToken(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            throw std::runtime_error("Не удалось открыть JSON-файл конфигурации.");
        }

        json config;
        file >> config;
        file.close();

        if (config.contains("firebase_auth_token")) {
            return config["firebase_auth_token"].get<std::string>();
        } else {
            throw std::runtime_error("Поле 'firebase_auth_token' отсутствует в JSON-файле.");
        }
    }

    static std::string getDatabaseURL(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            throw std::runtime_error("Не удалось открыть JSON-файл конфигурации.");
        }

        json config;
        file >> config;
        file.close();

        if (config.contains("database_url")) {
            return config["database_url"].get<std::string>();
        } else {
            throw std::runtime_error("Поле 'database_url' отсутствует в JSON-файле.");
        }
    }
};

#endif // AUTH_HANDLER_H
