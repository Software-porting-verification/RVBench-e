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
    Register vReg4("vReg4");
    Register vReg0("vReg0");

    // 初始化寄存器值
    vReg1.set_value(5.0);
    vReg2.set_value(3.0);
    vReg3.set_value(2.0);
    vReg4.set_value(-4.0);

    // 将寄存器添加到寄存器字典
    registers = {
        {"vReg1", vReg1},
        {"vReg2", vReg2},
        {"vReg3", vReg3},
        {"vReg4", vReg4},
        {"vReg0", vReg0}
    };

    // 创建DInstruction对象的vector
    std::vector<DInstruction> instructions = {
        DInstruction(
            "fadd.d", "0000000", 
            {"vReg2", "vReg1"}, // operands
            {"vReg0"},          // destRegs
            "frm", 
            {{"NV", "Invalid Operation"}, {"OF", "Overflow"}}, 
            ""
        ),
        DInstruction(
            "fmsub.d", "0000001", 
            {"vReg3", "vReg2", "vReg1"}, // operands
            {"vReg0"},                  // destRegs
            "frm", 
            {{"NV", "Invalid Operation"}}, 
            ""
        ),
        DInstruction(
            "fmul.d", "0000002", 
            {"vReg2", "vReg1"}, // operands
            {"vReg0"},          // destRegs
            "frm", 
            {{"OF", "Overflow"}}, 
            ""
        ),
        DInstruction(
            "fsqrt.d", "0000003", 
            {"vReg1"},           // operands
            {"vReg0"},           // destRegs
            "frm", 
            {{"NV", "Invalid Operation"},
             {"NX", "Non-existent"}}, 
            ""
        ),
        DInstruction(
            "fdiv.d", "0000004", 
            {"vReg2", "vReg1"}, // operands
            {"vReg0"},          // destRegs
            "frm", 
            {{"NV", "Invalid Operation"}, {"DZ", "Divide by Zero"}, 
             {"OF", "Overflow"}, {"UF", "Underflow"}, {"NX", "Non-existent"}},
            ""
        ),
        DInstruction(
            "feq.d", "0000005", 
            {"vReg2", "vReg1"}, // operands
            {"vReg0"},          // destRegs
            "", 
            {{"NV", "Invalid Operation"}},
            ""
        ),
        DInstruction(
            "fsgnjn.d", "0000006", 
            {"vReg4", "vReg1"}, // operands
            {"vReg0"},          // destRegs
            "", 
            {},
            ""
        ),
        DInstruction(
            "fcvt.wu.d", "0000007", 
            {"vReg1"}, // operands
            {"vReg0"},          // destRegs
            "frm", 
            {{"NV", "Invalid Operation"}, {"NX", "Non-existent"}},
            ""
        ),

    };

    return instructions;
}

