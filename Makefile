# Yuval Hamberg
# yuval.hamberg@gmail.com
# 26/6/2017
# FRS

# excutable name
TARGET = FRS

MAIN_SOURCE = $(shell find . -type f -name 'main*.cpp')
TEST_SOURCE = $(shell find . -type f -name '*_test.cpp' ! -name 'main*')
SOURCES = $(shell find . -type f -name '*.cpp' ! -name '*test.cpp' ! -name 'main*')

REQ_LIB = googleTest
REQ_LIB_NAME = lib$(REQ_LIB).a
REQ_LIB_PATH = ../googleTest/lib/

OBJECTS = $(SOURCES:.cpp=.o) $(MAIN_SOURCE:.cpp=.o)

CCFLAGS = -IUI -Isrc -Igtest -IFRS_manger -Icontroler
LDFLAGS = 
CC = g++

.Phony : all clean rebuild run unitTest

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $(notdir $^) $(LDFLAGS) 

%.o: %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $<

unitTest: $(SOURCES:.cpp=.o) $(TEST_SOURCE:.cpp=.o) $(REQ_LIB_NAME)
	$(CC) -o $(TARGET)_test $(notdir $(SOURCES:.cpp=.o) $(TEST_SOURCE:.cpp=.o)) $(LDFLAGS) $(REQ_LIB_PATH)$(REQ_LIB_NAME) -pthread

$(REQ_LIB_NAME):
	$(MAKE) -C $(REQ_LIB_PATH)../

clean:
	rm -f *.o $(TARGET) $(TARGET)_test
	$(MAKE) clean -C $(REQ_LIB_PATH)../

rebuild : clean $(TARGET)

run: $(TARGET)
	./$(TARGET)