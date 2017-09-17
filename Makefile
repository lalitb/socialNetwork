CC = g++
CFLAGS = -c -Wall -DDEBUG -g -std=c++11
LDFLAGS =
COMMON_SOURCES = LinkedIn.cpp LinkedInException.cpp
TARGET_SOURCES = automated_test.cpp
#TEST_SOURCES = 
COMMON_OBJECTS = $(COMMON_SOURCES:.cpp=.o)
TARGET_OBJECTS = $(TARGET_SOURCES:.cpp=.o)
EXECUTABLE =	automated 
#TEST_EXECUTABLE = mytestprogram

.PHONY: all target #tests

all: target #tests

target: $(EXECUTABLE)

#tests: $(TEST_EXECUTABLE)

$(EXECUTABLE): $(COMMON_OBJECTS) $(TARGET_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

#$(TEST_EXECUTABLE): $(COMMON_OBJECTS) $(TEST_OBJECTS)
#    $(CC) $(LDFLAGS) $^ -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
