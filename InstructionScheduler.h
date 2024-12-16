#ifndef INSTRUCTION_SCHEDULER_H
#define INSTRUCTION_SCHEDULER_H

#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include "DInstruction.h"  // 假设 Instruction 类已定义在该头文件中
#include "Register.h"     // 假设 Register 类已定义在该头文件中

class InstructionScheduler {
public:
    // 修改构造函数，允许传递寄存器映射
    InstructionScheduler(const std::vector<DInstruction>& instructions,
                         const std::unordered_map<std::string, Register>& registers)
        : instructions(instructions), registers(registers) {}

    // 执行指令调度
    void execute();

private:
    // 执行单条指令
    void execute_instruction(const DInstruction& ins);

    // 指令队列
    std::vector<DInstruction> instructions;

    // 寄存器值映射
    std::unordered_map<std::string, Register> registers;  // Register 类假设已定义

    // 等待队列：存储依赖未满足的指令
    std::queue<DInstruction> waiting_instructions;

    // 寄存器依赖计数器：用于跟踪每个寄存器的依赖情况
    std::unordered_map<std::string, int> register_dependencies;

    // 最后写入某个寄存器的指令：记录每个寄存器最后被哪条指令写入
    std::unordered_map<std::string, DInstruction> last_written_instructions;
};

#endif // INSTRUCTION_SCHEDULER_H
