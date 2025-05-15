#include "admin.h"

bool Admin::authenticate(std::string id, std::string pw) {
    return id == adminID && pw == adminPassword;
}
