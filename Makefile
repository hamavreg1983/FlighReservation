# Yuval Hamberg
# yuval.hamberg@gmail.com
# 26/6/2017
# FRS

# File names
EXE_NAME = FRS
#SOURCES_FILES = $(wildcard $(SOURCE_PATH)/*.cpp)
SOURCES_FILES = $(shell find . -type f -name '*.cpp' ! -name '*test.cpp' ! -name 'main*')
SOURCES_TEST_FILES = $(shell find . -type f -name '*test.cpp')

OBJECTS_FILES = $(SOURCES_FILES:.cpp=.o)
#OBJECTS_FILES = $(wildcard $(OBJECT_PATH)/*.o)
OBJECTS_TEST_FILES = $(SOURCES_TEST_FILES:.cpp=.o)

OBJECT_MAIN = $(OBJECT_PATH)mainFlightReservationSys.o

HFILE = $(wildcard $(H_LOCAL_PATH)/*.h) 

LIB_NEEDED_PATH1 = ../googleTest/lib/
LIB_NEEDED1 = libgoogleTest.a

LIB_NEEDED_PATH2 = 
LIB_NEEDED2 = 

#LIBSCREATE = $(EXE_NAME).a
#LIB_CREATED_PATH = .

HPATH = inc/
H_LOCAL_PATH = src
SOURCE_PATH = src/
OBJECT_PATH = src/

CFLAGS = -g -ansi -pedantic -Wall -I $(HPATH) -I $(H_LOCAL_PATH)
CC = g++

.Phony : clean rebuild run unitTest

# Main target
$(EXE_NAME): $(OBJECTS_FILES) $(OBJECT_MAIN)
	$(CC) $(CFLAGS) $(OBJECTS_FILES) $(OBJECT_MAIN) -o $(EXE_NAME) 

unitTest: $(OBJECTS_FILES) $(OBJECTS_TEST_FILES) $(LIB_NEEDED1)
	$(CC) $(CFLAGS) $(OBJECTS_FILES) $(OBJECTS_TEST_FILES) -L$(LIB_NEEDED_PATH1) -lgoogleTest -o $(EXE_NAME)_unitTest -lpthread

# To obtain object files
$(OBJECT_PATH)/%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

# To obtain object files
%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

#$(LIB_CREATED_PATH)/$(LIBSCREATE) : $(OBJECTS_FILES)
#	ar -cvrs $(LIB_CREATED_PATH)/$(LIBSCREATE) $(OBJECTS_FILES)

$(LIB_NEEDED_PATH1)/$(LIB_NEEDED1) : 
	$(MAKE) $(LIB_NEEDED1) -C $(LIB_NEEDED_PATH1)../
	
$(LIB_NEEDED1) : $(LIB_NEEDED_PATH1)/$(LIB_NEEDED1)

run: ${EXE_NAME} 
	./${EXE_NAME}

clean:
	rm -f *.o
	rm -f $(OBJECT_PATH)/*.o
	rm -f $(OBJECTS_FILES)
	rm -f *~
	rm -f $(EXE_NAME)
	rm -f $(EXE_NAME)_unitTest
	rm -f a.out
	rm -f outputFile.txt
#	rm -f $(LIB_CREATED_PATH)/$(LIBSCREATE)
	rm -f $(LIB_NEEDED_PATH1)/$(LIB_NEEDED1)
	$(MAKE) clean -C $(LIB_NEEDED_PATH1)../

rebuild : clean $(EXE_NAME)


