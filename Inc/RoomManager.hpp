#ifndef ROOM_MANAGER_HPP
#define ROOM_MANAGER_HPP

#include <vector>
#include <string>
#include "Room.hpp" // Định nghĩa lớp Room

class RoomManager {
private:
    std::vector<Room> rooms_; // Danh sách các phòng

public:
    // Phương thức thêm phòng
    bool addRoom(const std::string& roomId, const std::string& roomType, const std::string& roomStatus);

    // Phương thức sửa thông tin phòng
    bool editRoom(const std::string& roomId, const std::string& newRoomType, const std::string& newRoomStatus);

    // Phương thức kiểm tra nếu phòng tồn tại
    bool roomExists(const std::string& roomId) const;

    // Phương thức liệt kê danh sách phòng
    void listRooms() const;

    // Phương thức xóa phòng
    bool deleteRoom(const std::string& roomId);
};

#endif // ROOM_MANAGER_HPP
