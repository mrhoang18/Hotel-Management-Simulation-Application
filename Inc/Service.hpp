#ifndef SERVICE_HPP
#define SERVICE_HPP

#include <vector>
#include <string>

// Lớp Service đại diện cho một dịch vụ
class Service {
private:
    std::string id_;       // ID dịch vụ
    std::string name_;     // Tên dịch vụ
    double price_;         // Giá dịch vụ

public:
    // Constructor
    Service(const std::string& id, const std::string& name, double price)
        : id_(id), name_(name), price_(price) {}

    // Getter
    std::string getId() const { return id_; }
    std::string getName() const { return name_; }
    double getPrice() const { return price_; }

    // Setter
    void setName(const std::string& name) { name_ = name; }
    void setPrice(double price) { price_ = price; }
};

#endif // SERVICE_HPP
