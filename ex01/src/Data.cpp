#include "Data.hpp"

Data::Data()
: id_(0), message_(""), value_(0.0) {}

Data::Data(int i, const std::string& m, double v)
: id_(i), message_(m), value_(v) {}