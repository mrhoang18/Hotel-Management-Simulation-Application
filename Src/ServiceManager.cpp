#include "ServiceManager.hpp"
#include "UI.hpp" // Để sử dụng giao diện hiển thị
#include <algorithm>
#include <iostream>

// Thêm dịch vụ mới
bool ServiceManager::addService(const std::string& id, const std::string& name, double price) {
    // Kiểm tra nếu dịch vụ đã tồn tại
    if (serviceExists(id)) {
        return false;
    }

    // Thêm dịch vụ mới vào danh sách
    services_.emplace_back(id, name, price);
    return true;
}

// Sửa thông tin dịch vụ
bool ServiceManager::editService(const std::string& id, const std::string& newName, double newPrice) {
    for (auto& service : services_) {
        if (service.getId() == id) {
            service.setName(newName);
            service.setPrice(newPrice);
            return true;
        }
    }
    return false; // Không tìm thấy dịch vụ
}

// Xóa dịch vụ
bool ServiceManager::deleteService(const std::string& id) {
    auto it = std::remove_if(services_.begin(), services_.end(), [&id](const Service& service) {
        return service.getId() == id;
    });

    if (it != services_.end()) {
        services_.erase(it, services_.end());
        return true;
    }

    return false; // Không tìm thấy dịch vụ để xóa
}

// Kiểm tra nếu dịch vụ đã tồn tại
bool ServiceManager::serviceExists(const std::string& id) const {
    for (const auto& service : services_) {
        if (service.getId() == id) {
            return true;
        }
    }
    return false;
}

// Liệt kê danh sách dịch vụ
void ServiceManager::listServices() const {
    if (services_.empty()) {
        UI::showMessage("Không có dịch vụ nào trong hệ thống.");
        return;
    }

    for (const auto& service : services_) {
        UI::showMessage("ID: " + service.getId() + 
                        ", Tên: " + service.getName() + 
                        ", Giá: " + std::to_string(service.getPrice()));
    }
}
