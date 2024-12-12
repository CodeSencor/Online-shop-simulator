#include <utility>

#include "../../Enums/ServiceType.h"
#include "../../Headers/Core/Service.h"

ServiceType Service::GetType() {
    return servicetype;
}

Service &Service::operator=(const Service &other) {
    if (this == &other) {
        return *this;
    }

    this->id = other.id;
    this->name = other.name;
    this->description = other.description;
    this->image = other.image;
    this->price = other.price;
    this->servicetype = other.servicetype;

    return *this;
}

Service::Service()
    : servicetype(ServiceType::OTHER) {
}

Service::Service(std::string id, std::string name, std::string description, std::string image,
                 std::shared_ptr<Price> &price, ServiceType type) : Buyable(id, name, description, image, price) {
    this->id = id;
    this->name = name;
    this->description = description;
    this->image = image;
    this->price = price;
    this->servicetype = type;
}

nlohmann::json Service::toJSON() const {
    return nlohmann::json{
        {"id", id},
        {"name", name},
        {"description", description},
        {"image", image},
        {"price", price->toJSON()},
        {"servicetype", servicetype}
    };
}

void Service::fromJSON(const nlohmann::json &json) {
    id = json.at("id").get<std::string>();
    name = json.at("name").get<std::string>();
    description = json.at("description").get<std::string>();
    image = json.at("image").get<std::string>();
    price = std::make_shared<Price>(json.at("price"));
    servicetype = json.at("servicetype").get<ServiceType>();
}

Service::Service(const nlohmann::json &json) {
    this->Service::fromJSON(json);
}
