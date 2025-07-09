#include "vault.hpp"
#include <string>
#include <fstream>
#include <iostream>

std::string Vault::Encrypt(const std::string& orig) const {
    std::string result = orig;
    char key = 'U';
    for (char& i : result) {
        i ^=  key; // XOR encryption
    }
    return result;
}
    
std::string Vault::Decrypt(const std::string& encrypted) const {
    return Encrypt(encrypted);
}

void Vault::AddPassword(const std::string& Service, const std::string& Password) {
    Passwords[Service] = Password;
}

void Vault::DeletePassword(const std::string& Service) {
    Passwords.erase(Service);
}

std::string Vault::GetPassword(const std::string& Service) const {
    auto it = Passwords.find(Service);
    if (it != Passwords.end()) {
        return it->second;
    } 
    else {
        return " ";
    }
}

void Vault::ChangePassword (const std::string& service, const std::string& newPassword) {
    auto it = Passwords.find(service);
    if (it != Passwords.end()) {
        Passwords[service] = newPassword;
    }
    else {
        std::cout << "There is no such service.";
    }
}
    
void Vault::SaveToFile() const {
    std::ofstream file(Filename);
    for (const auto& pair : Passwords) {
        file << pair.first << "  " << Encrypt(pair.second) << std::endl;
    }
    file.close();
}

void Vault::LoadFromFile() {
    std::ifstream file(Filename);
    if (!file.is_open()) {
        std::cout << "Can't open a file" << std::endl;
        return;
    }
    std::string service, encrypted;
    while (file >> service >> encrypted) {
        Passwords[service] = Decrypt(encrypted);
    }
}