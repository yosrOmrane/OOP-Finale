#ifndef USER_H
#define USER_H

#include <string>
#include <sstream>

class User {
private:
    std::string username;
    std::string hashedPassword;
    std::string salt;

public:
    User(const std::string& username, const std::string& hashedPassword, const std::string& salt);

    std::string getUsername() const;
    std::string getHashedPassword() const;
    std::string getSalt() const;

    std::string toCSV() const;
    static User fromCSV(const std::string& csvLine);
};

#endif // USER_H
