#include "SHA256Hasher.h"

std::string SHA256Hasher::hashPassword(const std::string& password, const std::string& salt) {
    return sha256(password + salt);
}

std::string SHA256Hasher::generateSalt() {
    static std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<int> dist(0, 15);
    const char* hex_chars = "0123456789abcdef";
    std::string salt;

    for (int i = 0; i < 16; ++i) {
        salt += hex_chars[dist(rng)];
    }
    return salt;
}

std::string SHA256Hasher::sha256(const std::string& input) {
    std::hash<std::string> hasher;
    size_t hash = hasher(input);

    std::stringstream ss;
    ss << std::hex << std::setw(16) << std::setfill('0') << hash;

    std::string result = ss.str();
    while (result.length() < 64) {
        result += result;
    }

    return result.substr(0, 64);
}
