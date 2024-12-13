#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>

class Room {
private:
    std::string id_;     // Mã phòng
    std::string type_;   // Loại phòng (Đơn, Đôi, Suite)
    std::string status_; // Trạng thái phòng (Trống, Đang thuê, Bảo trì)

public:
    Room(const std::string& id, const std::string& type, const std::string& status)
        : id_(id), type_(type), status_(status) {}

    // Getter
    std::string getId() const { return id_; }
    std::string getType() const { return type_; }
    std::string getStatus() const { return status_; }

    // Setter
    void setType(const std::string& type) { type_ = type; }
    void setStatus(const std::string& status) { status_ = status; }
};

#endif // ROOM_HPP
