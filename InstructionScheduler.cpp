#include "InstructionScheduler.h"
#include <iostream>
#include <queue>
#include <unordered_map>
#include <cmath> 

void InstructionScheduler::execute() {
    // 执行指令调度
    while (!instructions.empty() || !waiting_instructions.empty()) {
        // 先检查已准备好的指令
        for (auto it = instructions.begin(); it != instructions.end();) {
            auto& ins = *it;

            bool ready_to_execute = true;
            
            // 检查指令的输入寄存器依赖是否已满足
            for (const auto& dep : ins.in_regs) {
                // 如果依赖寄存器尚未写入或正在等待
                if (registers.find(dep) == registers.end() || register_dependencies[dep] > 0) {
                    ready_to_execute = false;
                    break;
                }
            }

            if (ready_to_execute) {
                // 执行指令
                execute_instruction(ins);
                instructions.erase(it); // 执行完成后从待执行队列中移除
            } else {
                // 如果指令未准备好，加入等待队列
                waiting_instructions.push(ins);
                ++it;
            }
        }

        // 处理等待队列中的指令
        if (!waiting_instructions.empty()) {
            auto ins = waiting_instructions.front();
            waiting_instructions.pop();

            bool ready_to_execute = true;
            
            // 检查是否所有依赖寄存器已经满足
            for (const auto& dep : ins.in_regs) {
                if (register_dependencies[dep] > 0) {
                    ready_to_execute = false;
                    break;
                }
            }

            if (ready_to_execute) {
                execute_instruction(ins);
            } else {
                waiting_instructions.push(ins); // 如果未准备好，继续放回等待队列
            }
        }
    }
}

void InstructionScheduler::execute_instruction(const DInstruction& ins) {
    // 获取输入寄存器的值
    std::vector<double> input_values;
    for (const auto& reg : ins.in_regs) {
        input_values.push_back(registers[reg].get_value());
    }

    // 执行指令计算
    double result = 0;
    if (ins.generate_asm().find("fadd.d") != std::string::npos) {
        result = input_values[0] + input_values[1];
    } else if (ins.generate_asm().find("fmsub.d") != std::string::npos) {
        result = input_values[0] * input_values[1] - input_values[2];
    } else if (ins.generate_asm().find("fmul.d") != std::string::npos) {
        result = input_values[0] * input_values[1];
    } else if (ins.generate_asm().find("fsqrt.d") != std::string::npos) {
        result = std::sqrt(input_values[0]); // 计算平方根
    }

    // 存储到输出寄存器
    for (const auto& reg : ins.out_regs) {
        registers[reg].set_value(result);
    }

    // 更新依赖关系
    for (const auto& reg : ins.out_regs) {
        // 依赖计数器清除该寄存器的依赖
        register_dependencies[reg] = 0;  // 标记寄存器已经被写入，依赖已满足
        last_written_instructions[reg] = ins; // 记录写入该寄存器的最后一条指令
    }

    std::cout << "Executing: " << ins.generate_asm() << " with result " << result << std::endl;
}