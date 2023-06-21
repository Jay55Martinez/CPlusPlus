// Jay Martinez -- Assignment 6 -- 6/19/23
/*
Enum Class Status:

States: received, preparing, in_transit, delivered
*/
enum class Status {
    received,
    preparing,
    in_transit,
    delivered
};

void updateStatus(Status& currentStatus, Status newStatus);