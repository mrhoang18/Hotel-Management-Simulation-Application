#ifndef SERVICE_MANAGER_HPP
#define SERVICE_MANAGER_HPP

#include <vector>
#include <string>
#include "Service.hpp" // Định nghĩa lớp Service

// Lớp ServiceManager để quản lý danh sách dịch vụ
class ServiceManager {
private:
    std::vector<Service> services_; // Danh sách dịch vụ

public:
    // Thêm dịch vụ
    bool addService(const std::string& id, const std::string& name, double price);

    // Sửa thông tin dịch vụ
    bool editService(const std::string& id, const std::string& newName, double newPrice);

    // Xóa dịch vụ
    bool deleteService(const std::string& id);

    // Kiểm tra dịch vụ có tồn tại hay không
    bool serviceExists(const std::string& id) const;

    // Liệt kê tất cả các dịch vụ
    void listServices() const;
};

#endif // SERVICE_MANAGER_HPP
