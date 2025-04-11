#include "UserValidator.h"

bool UserValidator::isValidUsername(const std::string& username) {
    if (username.length() < 3) return false;
    std::regex pattern("^[a-zA-Z0-9_]+$");
    return std::regex_match(username, pattern);
}

bool UserValidator::isValidPassword(const std::string& password) {
    if (password.length() < 8) return false;

    bool hasUpper = false, hasLower = false, hasDigit = false;
    for (char c : password) {
        if (isupper(c)) hasUpper = true;
        if (islower(c)) hasLower = true;
        if (isdigit(c)) hasDigit = true;
    }

    return hasUpper && hasLower && hasDigit;
}
