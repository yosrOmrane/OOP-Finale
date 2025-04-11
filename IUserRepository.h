#ifndef IUSERREPOSITORY_H
#define IUSERREPOSITORY_H

#include <vector>
#include "User.h"

class IUserRepository {
public:
    virtual ~IUserRepository() = default;
    virtual void saveUser(const User& user) = 0;
    virtual std::vector<User> loadUsers() = 0;
};

#endif // IUSERREPOSITORY_H
