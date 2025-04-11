#include "AuthService.h"
#include <algorithm>
AuthService::AuthService(std::shared_ptr<IUserRepository> userRepository,
                         std::shared_ptr<IHasher> hasher,
                         std::shared_ptr<IValidator> validator)
    : userRepository(userRepository), hasher(hasher), validator(validator) {}

bool AuthService::registerUser(const std::string &username, const std::string &password)
{
    if (!validator->isValidUsername(username) || !validator->isValidPassword(password))
    {
        return false;
    }

    auto users = userRepository->loadUsers();
    auto it = std::find_if(users.begin(), users.end(), [&username](const User &user)
                           { return user.getUsername() == username; });

    if (it != users.end())
        return false;

    std::string salt = hasher->generateSalt();
    std::string hashedPassword = hasher->hashPassword(password, salt);

    User newUser(username, hashedPassword, salt);
    userRepository->saveUser(newUser);

    return true;
}

bool AuthService::loginUser(const std::string &username, const std::string &password)
{
    auto users = userRepository->loadUsers();
    auto it = std::find_if(users.begin(), users.end(), [&username](const User &user)
                           { return user.getUsername() == username; });

    if (it == users.end())
        return false;

    const User &user = *it;
    std::string hashed = hasher->hashPassword(password, user.getSalt());

    return hashed == user.getHashedPassword();
}
