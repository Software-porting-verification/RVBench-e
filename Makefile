# Makefile for Instruction Scheduler project

# C++ 编译器设置
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

# C 编译器设置（如果有需要 C 编译的部分）
CC = gcc
CFLAGS = -O3 -Wall -march=native -ftree-vectorize
CFLAGS += -mavx -mfma  # 启用 AVX 和 FMA 指令集

# 目标可执行文件
TARGET = instruction_scheduler

# 源文件
SRCS = main.cpp Register.cpp DInstruction.cpp InstructionScheduler.cpp InstructionDefinitions.cpp

# 头文件目录
INCLUDES = -I.

# 目标文件
OBJS = $(SRCS:.cpp=.o)

# 编译和链接规则
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# 编译 .cpp 文件为 .o 文件
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# 清理生成的文件
clean:
	rm -f $(OBJS) $(TARGET)

# 运行目标
check: $(TARGET)
	./$(TARGET)

