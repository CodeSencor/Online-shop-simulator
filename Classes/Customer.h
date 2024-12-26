#ifndef OOP_PROJECT_CUSTOMER_H
#define OOP_PROJECT_CUSTOMER_H

#include <memory>
#include <string>

#include "Wallet.h"

class Customer
{
    std::string             id;
    std::string             name;
    std::string             surname;
    std::string             email;
    std::string             phone;
    std::shared_ptr<Wallet> wallet;

  public:
    std::string             GetId();
    std::string             GetName();
    std::string             GetSurname();
    std::string             GetEmail();
    std::string             GetPhone();
    std::shared_ptr<Wallet> GetWallet();

    Customer& operator=(const Customer& other);

    Customer(std::string id, std::string name, std::string surname, std::string email, std::string phone);
    Customer(std::string             id,
             std::string             name,
             std::string             surname,
             std::string             email,
             std::string             phone,
             std::shared_ptr<Wallet> wallet);
};

#endif // OOP_PROJECT_CUSTOMER_H
