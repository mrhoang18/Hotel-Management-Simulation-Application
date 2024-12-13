#include "Manager.hpp"

// Hiển thị menu quản lý chính
void Manager::showManagementMenu() {
    Menu mainMenu("Quản lý khách sạn", {
        {1, "Quản lý nhân viên", [this]() { manageEmployees(); }},
        {2, "Quản lý phòng", [this]() { manageRooms(); }},
        {3, "Dịch vụ", [this]() { manageServices(); }},
        {0, "Quay lại", []() { UI::showMessage("Quay lại menu chính..."); }}
    });

    mainMenu.showMenu();  // Hiển thị menu quản lý chính
}

// Quản lý nhân viên
void Manager::manageEmployees() {
    Menu employeeMenu("Quản lý nhân viên", {
        {1, "Thêm nhân viên", [this]() { addEmployee(); }},
        {2, "Sửa thông tin nhân viên", [this]() { editEmployee(); }},
        {3, "Xóa nhân viên", [this]() { deleteEmployee(); }},
        {4, "Xem danh sách nhân viên", [this]() { listEmployees(); }},
        {0, "Quay lại", []() { UI::showMessage("Quay lại menu quản lý..."); }}
    });

    employeeMenu.showMenu();  // Hiển thị menu quản lý nhân viên
}

void Manager::addEmployee() {
   
    while (true) {
        UI::showMessage("=== Thêm Nhân Viên ===");

        // Nhập thông tin từ người dùng
        std::string name = UI::getInputString("Nhập tên nhân viên: ");
        std::string phoneNumber = UI::getInputString("Nhập số điện thoại: ");

        // Kiểm tra vị trí công việc hợp lệ
        std::string position;
        while (true) {
            position = UI::getInputString("Nhập vị trí công việc (Tạp vụ (TV)/Bảo vệ (BV)/Đầu bếp (DB)/Lễ Tân (LT)): ");
            if (position == "TV" || position == "BV" || position == "DB" || position == "LT") {
                break; // Thoát vòng lặp nếu nhập hợp lệ
            } else {
                UI::showMessage("Vị trí không hợp lệ. Vui lòng nhập lại!");
            }
        }
        // Thêm nhân viên mới vào danh sách
        employeeManager.addEmployee(accountList, name, phoneNumber, position);

        // Hiển thị tùy chọn để thêm nhân viên khác
        int choice = UI::getUserChoice("Thêm nhân viên khác (1) hoặc quay lại (0): ");
        
        if (choice == 0) {
            break;  // Quay lại nếu người dùng chọn 0
        }
    }
}

void Manager::editEmployee() {
    UI::showMessage("Sửa thông tin nhân viên...");
    // Danh sách nhân viên
    employeeManager.listEmployees();

    UI::showMessage("Vui lòng nhập tên của nhân viên muốn sửa thông tin:");

    std::string id = UI::getInputString("Nhập ID: ");

    // employeeManager.findEmployeeById(id);

}

void Manager::deleteEmployee() {
    UI::showMessage("=== Xóa Nhân Viên ===");

    // Hiển thị danh sách nhân viên để người dùng biết ID
    employeeManager.listEmployees();

    // Yêu cầu người dùng nhập ID nhân viên cần xóa
    std::string id = UI::getInputString("Nhập ID của nhân viên cần xóa: ");

    // Gọi phương thức xóa trong EmployeeManager
    employeeManager.deleteEmployeeById(id);
}

void Manager::listEmployees() {
    UI::showMessage("=== Danh Sách Nhân Viên ===");

    employeeManager.listEmployees();

    UI::showMessage("------------------");
}

// Quản lý phòng
void Manager::manageRooms() {
    Menu roomMenu("Quản lý phòng", {
        {1, "Thêm phòng", [this]() { addRoom(); }},
        {2, "Sửa thông tin phòng", [this]() { editRoom(); }},
        {3, "Xóa phòng", [this]() { deleteRoom(); }},
        {4, "Xem danh sách phòng", [this]() { listRooms(); }},
        {0, "Quay lại", []() { UI::showMessage("Quay lại menu quản lý..."); }}
    });

    roomMenu.showMenu();  // Hiển thị menu quản lý phòng
}

void Manager::addRoom() {
    while (true) {
        UI::showMessage("=== Thêm Phòng ===");

        // Nhập ID phòng và kiểm tra tính hợp lệ
        std::string roomId;
        while (true) {
            roomId = UI::getInputString("Nhập ID phòng: ");
            if (!roomManager.roomExists(roomId)) {
                break;
            } else {
                UI::showMessage("ID phòng đã tồn tại. Vui lòng nhập lại!");
            }
        }

        // Nhập loại phòng và kiểm tra tính hợp lệ
        std::string roomType;
        while (true) {
            roomType = UI::getInputString("Nhập loại phòng (Đơn, Đôi, Suite): ");
            if (roomType == "Đơn" || roomType == "Đôi" || roomType == "Suite") {
                break;
            } else {
                UI::showMessage("Loại phòng không hợp lệ. Vui lòng nhập lại (Đơn, Đôi, Suite)!");
            }
        }

        // Nhập trạng thái phòng và kiểm tra tính hợp lệ
        std::string roomStatus;
        while (true) {
            roomStatus = UI::getInputString("Nhập trạng thái phòng (Trống, Bận, Sửa): ");
            if (roomStatus == "Trống" || roomStatus == "Bận" || roomStatus == "Sửa") {
                break;
            } else {
                UI::showMessage("Trạng thái phòng không hợp lệ. Vui lòng nhập lại (Trống, Bận, Sửa)!");
            }
        }

        // Thêm phòng mới vào danh sách
        bool success = roomManager.addRoom(roomId, roomType, roomStatus);

        if (success) {
            UI::showMessage("Phòng với ID " + roomId + " đã được thêm thành công.");
        } else {
            UI::showMessage("Không thể thêm phòng. Có lỗi xảy ra.");
        }

        // Tùy chọn thêm phòng khác hoặc quay lại
        int choice = UI::getUserChoice("Chọn 0 để thêm phòng khác, chọn 1 để quay lại: ");
        if (choice == 1) {
            break; // Quay lại menu quản lý phòng nếu người dùng chọn 1
        }
    }
}

void Manager::editRoom() {
    UI::showMessage("=== Sửa Thông Tin Phòng ===");

    // Nhập ID phòng cần sửa
    std::string roomId = UI::getInputString("Nhập ID phòng cần sửa: ");

    // Kiểm tra phòng có tồn tại không
    if (!roomManager.roomExists(roomId)) {
        UI::showMessage("Không tìm thấy phòng với ID: " + roomId);
        return;
    }

    // Nhập thông tin mới
    std::string newRoomType = UI::getInputString("Nhập loại phòng mới (Đơn, Đôi, Suite): ");
    std::string newRoomStatus = UI::getInputString("Nhập trạng thái phòng mới (Trống, Đang thuê, Bảo trì): ");

    // Cập nhật thông tin phòng
    bool success = roomManager.editRoom(roomId, newRoomType, newRoomStatus);

    if (success) {
        UI::showMessage("Thông tin phòng với ID " + roomId + " đã được cập nhật.");
    } else {
        UI::showMessage("Cập nhật thông tin phòng thất bại.");
    }
}

void Manager::deleteRoom() {
    UI::showMessage("=== Xóa Phòng ===");

    // Hiển thị danh sách phòng để người dùng biết ID
    roomManager.listRooms();

    // Nhập ID phòng cần xóa
    std::string roomId = UI::getInputString("Nhập ID phòng cần xóa: ");

    // Gọi phương thức xóa phòng
    bool success = roomManager.deleteRoom(roomId);

    if (success) {
        UI::showMessage("Phòng với ID " + roomId + " đã được xóa thành công.");
    } else {
        UI::showMessage("Không tìm thấy phòng với ID: " + roomId);
    }
}

void Manager::listRooms() {
    UI::showMessage("=== Danh Sách Phòng ===");

    // Gọi phương thức liệt kê danh sách phòng từ RoomManager
    roomManager.listRooms();

    UI::showMessage("------------------");
}

// Quản lý dịch vụ
void Manager::manageServices() {
    Menu serviceMenu("Quản lý dịch vụ", {
        {1, "Thêm dịch vụ", [this]() { addService(); }},
        {2, "Sửa thông tin dịch vụ", [this]() { editService(); }},
        {3, "Xóa dịch vụ", [this]() { deleteService(); }},
        {4, "Xem danh sách dịch vụ", [this]() { listServices(); }},
        {0, "Quay lại", []() { UI::showMessage("Quay lại menu quản lý..."); }}
    });

    serviceMenu.showMenu();  // Hiển thị menu quản lý dịch vụ
}

void Manager::addService() {
    while (true) {
        UI::showMessage("=== Thêm Dịch Vụ ===");

        // Nhập ID dịch vụ và kiểm tra trùng lặp
        std::string serviceId;
        while (true) {
            serviceId = UI::getInputString("Nhập ID dịch vụ: ");
            if (!serviceManager.serviceExists(serviceId)) {
                break;
            } else {
                UI::showMessage("ID dịch vụ đã tồn tại. Vui lòng nhập lại!");
            }
        }

        // Nhập tên dịch vụ
        std::string serviceName = UI::getInputString("Nhập tên dịch vụ: ");

        // Nhập giá dịch vụ
        double servicePrice;
        while (true) {
            try {
                servicePrice = std::stod(UI::getInputString("Nhập giá dịch vụ: "));
                if (servicePrice >= 0) break; // Giá phải là số dương
                else UI::showMessage("Giá không thể âm. Vui lòng nhập lại!");
            } catch (...) {
                UI::showMessage("Giá không hợp lệ. Vui lòng nhập lại!");
            }
        }

        // Thêm dịch vụ vào danh sách
        bool success = serviceManager.addService(serviceId, serviceName, servicePrice);

        if (success) {
            UI::showMessage("Dịch vụ với ID " + serviceId + " đã được thêm thành công.");
        } else {
            UI::showMessage("Không thể thêm dịch vụ. Có lỗi xảy ra.");
        }

        // Tùy chọn thêm dịch vụ khác hoặc quay lại
        int choice = UI::getUserChoice("Chọn 0 để thêm dịch vụ khác, chọn 1 để quay lại: ");
        if (choice == 1) {
            break;
        }
    }
}

void Manager::editService() {
    UI::showMessage("=== Sửa Thông Tin Dịch Vụ ===");

    // Nhập ID dịch vụ cần sửa
    std::string serviceId = UI::getInputString("Nhập ID dịch vụ cần sửa: ");

    // Kiểm tra dịch vụ có tồn tại không
    if (!serviceManager.serviceExists(serviceId)) {
        UI::showMessage("Không tìm thấy dịch vụ với ID: " + serviceId);
        return;
    }

    // Nhập tên mới cho dịch vụ
    std::string newName = UI::getInputString("Nhập tên mới cho dịch vụ: ");

    // Nhập giá mới cho dịch vụ
    double newPrice;
    while (true) {
        try {
            newPrice = std::stod(UI::getInputString("Nhập giá mới cho dịch vụ: "));
            if (newPrice >= 0) break; // Giá phải là số dương
            else UI::showMessage("Giá không thể âm. Vui lòng nhập lại!");
        } catch (...) {
            UI::showMessage("Giá không hợp lệ. Vui lòng nhập lại!");
        }
    }

    // Cập nhật thông tin dịch vụ
    bool success = serviceManager.editService(serviceId, newName, newPrice);

    if (success) {
        UI::showMessage("Thông tin dịch vụ với ID " + serviceId + " đã được cập nhật.");
    } else {
        UI::showMessage("Không thể cập nhật thông tin dịch vụ. Có lỗi xảy ra.");
    }
}

void Manager::deleteService() {
    UI::showMessage("=== Xóa Dịch Vụ ===");

    // Hiển thị danh sách dịch vụ trước khi xóa
    serviceManager.listServices();

    // Nhập ID dịch vụ cần xóa
    std::string serviceId = UI::getInputString("Nhập ID dịch vụ cần xóa: ");

    // Gọi phương thức xóa dịch vụ
    bool success = serviceManager.deleteService(serviceId);

    if (success) {
        UI::showMessage("Dịch vụ với ID " + serviceId + " đã được xóa thành công.");
    } else {
        UI::showMessage("Không tìm thấy dịch vụ với ID: " + serviceId);
    }
}

void Manager::listServices() {
    UI::showMessage("=== Danh Sách Dịch Vụ ===");

    // Gọi phương thức liệt kê dịch vụ từ ServiceManager
    serviceManager.listServices();

    UI::showMessage("------------------");
}
