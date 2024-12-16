#include "InstructionDefinitions.h"
#include "Register.h"
#include "DInstruction.h"
#include <unordered_map>

std::vector<DInstruction> define_instructions(
    std::unordered_map<std::string, Register>& registers
) {
    // 创建寄存器
    Register vReg1("vReg1");
    Register vReg2("vReg2");
    Register vReg3("vReg3");
    Register vReg0("vReg0");

    // 初始化寄存器值
    vReg1.set_value(5.0);
    vReg2.set_value(3.0);
    vReg3.set_value(2.0);

    // 将寄存器添加到寄存器字典
    registers = {
        {"vReg1", vReg1},
        {"vReg2", vReg2},
        {"vReg3", vReg3},
        {"vReg0", vReg0}
    };

    // 定义并返回指令
    return {
        DInstruction("fadd.d", "0000000", {"vReg2", "vReg1"}, {"vReg0"}, "frm", {{"NV", "Invalid Operation"}, {"OF", "Overflow"}}),
        DInstruction("fmsub.d", "0000001", {"vReg3", "vReg2", "vReg1"}, {"vReg0"}, "frm", {{"NV", "Invalid Operation"}}),
        DInstruction("fmul.d", "0000002", {"vReg2", "vReg1"}, {"vReg0"}, "frm", {{"OF", "Overflow"}}),
        DInstruction("fsqrt.d", "0000003", {"vReg1"}, {"vReg0"}, "frm", {{"NV", "NX"}})
    };
}

