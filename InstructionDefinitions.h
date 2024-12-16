#ifndef INSTRUCTION_DEFINITIONS_H
#define INSTRUCTION_DEFINITIONS_H

#include "DInstruction.h"
#include <vector>
#include <unordered_map>
#include "Register.h"

std::vector<DInstruction> define_instructions(
    std::unordered_map<std::string, Register>& registers
);

#endif // INSTRUCTION_DEFINITIONS_H

