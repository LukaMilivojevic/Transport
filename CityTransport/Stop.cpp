#include "Stop.h"
#include <ostream>

int Stop::getId() const
{
    return stop_id_;
}

std::string Stop::getName() const
{
    return stop_name_;
}

bool Stop::getImportance() const
{
    return important_;
}

std::ostream& operator<<(std::ostream& os, const Stop& stop)
{
    os << stop.stop_id_ << " " << stop.stop_name_;
    if (stop.important_)
        os << "[!]";
    return os;
}
