#include "FileUserRepository.h"

FileUserRepository::FileUserRepository(const std::string& filename) : filename(filename) {}

void FileUserRepository::saveUser(const User& user) {
    std::vector<User> users = loadUsers();

    auto it = std::find_if(users.begin(), users.end(), [&user](const User& existingUser) {
        return existingUser.getUsername() == user.getUsername();
    });

    if (it != users.end()) {
        users.erase(it);
    }

    users.push_back(user);

    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Erreur lors de l'ouverture du fichier : " + filename);
    }

    for (const auto& u : users) {
        file << u.toCSV() << "\n";
    }
}

std::vector<User> FileUserRepository::loadUsers() {
    std::vector<User> users;
    std::ifstream file(filename);

    if (!file.is_open()) {
        return users;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            try {
                users.push_back(User::fromCSV(line));
            } catch (...) {
                // Skip invalid line
            }
        }
    }
    return users;
}
