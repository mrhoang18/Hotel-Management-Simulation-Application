#include "RoomManager.hpp"
#include "UI.hpp" // Sử dụng UI để hiển thị thông tin
#include <algorithm>

// Thêm phòng mới
bool RoomManager::addRoom(const std::string& roomId, const std::string& roomType, const std::string& roomStatus) {
    // Kiểm tra nếu phòng đã tồn tại
    if (roomExists(roomId)) {
        return false; // Không thể thêm nếu ID phòng đã tồn tại
    }

    // Thêm phòng mới
    rooms_.emplace_back(roomId, roomType, roomStatus);
    return true;
}

// Sửa thông tin phòng
bool RoomManager::editRoom(const std::string& roomId, const std::string& newRoomType, const std::string& newRoomStatus) {
    for (auto& room : rooms_) {
        if (room.getId() == roomId) {
            room.setType(newRoomType);
            room.setStatus(newRoomStatus);
            return true; // Cập nhật thành công
        }
    }
    return false; // Không tìm thấy phòng
}

// Kiểm tra nếu phòng tồn tại
bool RoomManager::roomExists(const std::string& roomId) const {
    for (const auto& room : rooms_) {
        if (room.getId() == roomId) {
            return true; // Phòng tồn tại
        }
    }
    return false; // Phòng không tồn tại
}

// Liệt kê danh sách phòng
void RoomManager::listRooms() const {
    if (rooms_.empty()) {
        UI::showMessage("Không có phòng nào trong hệ thống.");
        return;
    }

    for (const auto& room : rooms_) {
        UI::showMessage("ID: " + room.getId() + 
                        ", Loại: " + room.getType() + 
                        ", Trạng thái: " + room.getStatus());
    }
}

// Xóa phòng
bool RoomManager::deleteRoom(const std::string& roomId) {
    auto it = std::remove_if(rooms_.begin(), rooms_.end(), [&roomId](const Room& room) {
        return room.getId() == roomId;
    });

    if (it != rooms_.end()) {
        rooms_.erase(it, rooms_.end());
        return true; // Xóa thành công
    }

    return false; // Không tìm thấy phòng để xóa
}
