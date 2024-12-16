#include "DInstruction.h"
#include <stdexcept>
#include <iostream>

DInstruction::DInstruction(std::string name, std::string opcode, 
                           std::vector<std::string> in_regs, 
                           std::vector<std::string> out_regs, 
                           std::string rounding_mode,
                           std::unordered_map<std::string, std::string> exceptions, 
                           std::string vRegS)
    : name(name), opcode(opcode), in_regs(in_regs), out_regs(out_regs),
      rounding_mode(rounding_mode), exceptions(exceptions), vRegS(vRegS) {}

std::string DInstruction::get_name() const {
    return name;
}

std::vector<std::string> DInstruction::get_in_regs() const {
    return in_regs;
}

std::vector<std::string> DInstruction::get_out_regs() const {
    return out_regs;
}

std::string DInstruction::generate_asm() const {
    std::string asm_code;
    if (name == "fadd.d") {
        asm_code = "fadd.d " + out_regs[0] + ", " + in_regs[0] + ", " + in_regs[1];
    } else if (name == "fmsub.d") {
        asm_code = "fmsub.d " + out_regs[0] + ", " + in_regs[0] + ", " + in_regs[1] + ", " + in_regs[2];
    } else if (name == "fmul.d") {
        asm_code = "fmul.d " + out_regs[0] + ", " + in_regs[0] + ", " + in_regs[1];
    } else if (name == "fsqrt.d") {
        asm_code = "fsqrt.d " + out_regs[0] + ", " + in_regs[0];
    } else {
        throw std::invalid_argument("不支持的指令：" + name);
    }

    if (!vRegS.empty()) {
        asm_code += "  // vRegS: " + vRegS;
    }

    return asm_code;
}

std::string DInstruction::handle_exceptions() const {
    std::string exception_code;
    for (const auto& exception : exceptions) {
        exception_code += "if (" + exception.first + ") {\n";
        exception_code += "    // 处理异常: " + exception.second + "\n";
        exception_code += "    return -1;\n";
        exception_code += "}\n";
    }
    return exception_code;
}

