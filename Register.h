#ifndef REGISTER_H
#define REGISTER_H

#include <string>

class Register {
public:
    // 默认构造函数
    Register() : name(""), value(0.0) {}

    // 带参数的构造函数
    Register(std::string name) : name(name), value(0.0) {}

    std::string get_name() const;
    double get_value() const;
    void set_value(double value);

private:
    std::string name;
    double value;
};

#endif // REGISTER_H

