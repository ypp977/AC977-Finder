# 定义编译器和编译选项
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude -g
LDFLAGS = -llog4cplus

# 项目结构
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include
LOG_DIR = logs/search_logs

# 目标文件
TARGET = $(BUILD_DIR)/ac977_finder

# 源文件
SRCS = $(wildcard $(SRC_DIR)/*.cc)
OBJS = $(patsubst $(SRC_DIR)/%.cc, $(BUILD_DIR)/%.o, $(SRCS))

# 默认目标
all: $(TARGET)

# 链接目标
$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

# 编译规则
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理目标
clean:
	rm -rf $(BUILD_DIR)/* $(LOG_DIR)/*

# 伪目标
.PHONY: all clean