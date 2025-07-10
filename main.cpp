#include "vault.hpp"
#include <iostream>
#include <string>

int main() {
    Vault vault("vault.txt");
    vault.LoadFromFile();
    std::string command;
    std::cout << "Print one of the commands: add, delete, get, change, exit\n";

    while (true) {
        std::cin >> command;

        if (command == "add") {
            std::string service, password;
            std::cout << "Print the name of the service: ";
            std::cin >> service;
            std::cout << "Print your password: ";
            std::cin >> password;
            vault.AddPassword(service, password);
            vault.SaveToFile();
            std::cout << "Password added successfully. Enter new command: ";
        }
        else if (command == "delete") {
            std::string service;
            std::cout << "Print the name of the service: ";
            std::cin >> service;
            vault.DeletePassword(service);
            vault.SaveToFile();
            std::cout << "Password deleted successfully. Enter new command: ";
        }
        else if (command == "get") {
            std::string service;
            std::cout << "Print the name of the service: ";
            std::cin >> service;
            std::string password = vault.GetPassword(service);
            if (password != " ") {
                std::cout << "Your password: " << password << ". Enter a new command: \n";
            }
            else {
                std::cout << "No password found for that service.";
            }

        }
        else if (command == "change") {
            std::string service, oldPassword, newPassword;
            std::cout << "Print the name of the service: ";
            std::cin >> service;
            bool result = false;
            int attempts = 3;
            while (attempts > 0) {
                std::cout << "Print your current password: ";
                std::cin >> oldPassword;

                if (vault.GetPassword(service) == oldPassword) {
                    std::cout << "Print new password: ";
                    std::cin >> newPassword;
                    vault.ChangePassword(service, newPassword);
                    vault.SaveToFile();
                    std::cout << "Password changed successfully. Enter new command: ";
                    result = true;
                    break;
                }
                else {
                    attempts--;
                    std::cout << "Incorrect password. Attempts left: " << attempts << "\n";
                }
            }
            if (!result) {
                std::cout << "Too many attempts. Failed to change the password.";
            }
        }
        else if (command == "exit") {
            break;
        }
        else {
            std::cout << "Invalid command. Try again.";
        }
    }
    return 0;
}