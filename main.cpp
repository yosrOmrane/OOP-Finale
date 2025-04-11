#include <iostream>
#include <memory>
#include "FileUserRepository.h"
#include "SHA256Hasher.h"
#include "UserValidator.h"
#include "AuthService.h"

void displayMenu() {
    std::cout << "\n===== Système d'authentification =====\n";
    std::cout << "1. S'inscrire\n";
    std::cout << "2. Se connecter\n";
    std::cout << "3. Quitter\n";
    std::cout << "Choix : ";
}

int main() {
    auto userRepository = std::make_shared<FileUserRepository>("users.csv");
    auto hasher = std::make_shared<SHA256Hasher>();
    auto validator = std::make_shared<UserValidator>();
    AuthService authService(userRepository, hasher, validator);

    int choice;
    std::string username, password;

    while (true) {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                std::cout << "Entrez le nom d'utilisateur : ";
                std::getline(std::cin, username);
                std::cout << "Entrez le mot de passe : ";
                std::getline(std::cin, password);

                if (authService.registerUser(username, password)) {
                    std::cout << "Inscription réussie !\n";
                } else {
                    std::cout << "Échec de l'inscription. Vérifiez le nom d'utilisateur ou le mot de passe.\n";
                }
                break;

            case 2:
                std::cout << "Entrez le nom d'utilisateur : ";
                std::getline(std::cin, username);
                std::cout << "Entrez le mot de passe : ";
                std::getline(std::cin, password);

                if (authService.loginUser(username, password)) {
                    std::cout << "Connexion réussie !\n";
                } else {
                    std::cout << "Nom d'utilisateur ou mot de passe incorrect.\n";
                }
                break;

            case 3:
                std::cout << "Au revoir !\n";
                return 0;

            default:
                std::cout << "Choix invalide.\n";
        }
    }

    return 0;
}
