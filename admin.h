#ifndef ADMIN_H
#define ADMIN_H

#include <string>

class Admin {
private:
    const std::string adminID = "ZC2024";
    const std::string adminPassword = "ad123";

public:
    bool authenticate(std::string id, std::string pw);
};

#endif // ADMIN_H
