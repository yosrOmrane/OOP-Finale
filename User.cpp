#include "User.h"

User::User(const std::string& username, const std::string& hashedPassword, const std::string& salt)
    : username(username), hashedPassword(hashedPassword), salt(salt) {}

std::string User::getUsername() const { return username; }
std::string User::getHashedPassword() const { return hashedPassword; }
std::string User::getSalt() const { return salt; }

std::string User::toCSV() const {
    return username + "," + hashedPassword + "," + salt;
}

User User::fromCSV(const std::string& csvLine) {
    std::stringstream ss(csvLine);
    std::string username, hashedPassword, salt;

    std::getline(ss, username, ',');
    std::getline(ss, hashedPassword, ',');
    std::getline(ss, salt, ',');

    return User(username, hashedPassword, salt);
}
