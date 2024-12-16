#ifndef D_INSTRUCTION_H
#define D_INSTRUCTION_H

#include <string>
#include <vector>
#include <unordered_map>

class DInstruction {
public:
    DInstruction() {}
    DInstruction(std::string name, std::string opcode, 
                 std::vector<std::string> in_regs, 
                 std::vector<std::string> out_regs, 
                 std::string rounding_mode,
                 std::unordered_map<std::string, std::string> exceptions,
                 std::string vRegS = "");

    std::string get_name() const;
    std::vector<std::string> get_in_regs() const;
    std::vector<std::string> get_out_regs() const;
    std::string generate_asm() const;
    std::string handle_exceptions() const;

public:
    std::string name;
    std::string opcode;
    std::vector<std::string> in_regs;
    std::vector<std::string> out_regs;
    std::string rounding_mode;
    std::unordered_map<std::string, std::string> exceptions;
    std::string vRegS;
};

#endif // D_INSTRUCTION_H

