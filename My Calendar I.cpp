#include <set>

class MyCalendar {
    std::set<std::pair<int, int>> bookings;

public:
    MyCalendar() {}

    bool book(int start, int end) {
        // Check for overlaps with existing bookings
        for (const auto& booking : bookings) {
            // If the new booking overlaps with any existing booking
            if (start < booking.second && end > booking.first) {
                return false;
            }
        }
        // If no overlap, add the new booking
        bookings.insert({start, end});
        return true;
    }
};