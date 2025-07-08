#pragma once

#include <string>
#include <map>

class Vault {

    private:
    std::map<std::string, std::string> Passwords;
    std::string Filename;
    //methods
    std::string Encrypt(const std::string& orig) const;
    std::string Decrypt(const std::string& encrypted) const;
    public:

    Vault(std::string& Filename): Filename(Filename) {};
    void AddPassword(const std::string& Service, const std::string& Password);
    void DeletePassword(const std::string& Service);
    std::string GetPassword(const std::string& Service) const;
    void ChangePassword (const std::string& service, const std::string& newPassword);
    void SaveToFile() const;
    void LoadFromFile();
};