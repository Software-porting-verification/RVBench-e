#include <iostream>
#include "DInstruction.h"
#include "Register.h"
#include "InstructionScheduler.h"
#include "InstructionDefinitions.h"

int main() {
    // 创建寄存器字典
    std::unordered_map<std::string, Register> registers;

    // 获取定义好的指令
    std::vector<DInstruction> instructions = define_instructions(registers);

    // 创建指令调度器并执行
    InstructionScheduler scheduler(instructions, registers);
    scheduler.execute();

    return 0;
}

