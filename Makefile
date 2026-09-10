CXX = usr/bin/g++
CXXFLAGS = -std=c++17 -Wall -Wextra
BUILD_DIR = build

all: $(BUILD_DIR)/oss $(BUILD_DIR)/user

#Target-specific flags
debug: CXXFLAGS += -g -DDEBUG
debug: all

release: CXXFLAGS += -O3
release: all

#create build/ if it does not exist
$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)/oss: src/oss.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

$(BUILD_DIR)/user: src/user.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(BUILD_DIR)