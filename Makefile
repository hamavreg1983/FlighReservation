# Yuval Hamberg
# yuval.hamberg@gmail.com
# 26/6/2017
# FRS

# File names
EXE_NAME = FRS
#SOURCES_FILES = $(wildcard $(SOURCE_PATH)/*.cpp)
SOURCES_FILES = $(shell find . -type f -name '*.cpp' ! -name '*test.cpp')

OBJECTS_FILES = $(SOURCES_FILES:.cpp=.o)
#OBJECTS_FILES = $(wildcard $(OBJECT_PATH)/*.o)

HFILE = $(wildcard $(H_LOCAL_PATH)/*.h) 

LIB_NEEDED_PATH1 = 
LIB_NEEDED1 = 

LIB_NEEDED_PATH2 = 
LIB_NEEDED2 = 

#LIBSCREATE = $(EXE_NAME).a
#LIB_CREATED_PATH = .

HPATH = /src/
H_LOCAL_PATH = /src/
SOURCE_PATH = /src/
OBJECT_PATH = /src/

CFLAGS = -g -ansi -pedantic -Wall -I $(HPATH) -I $(H_LOCAL_PATH) 
#<enter> -I $(LIB_NEEDED_PATH1)/../inc/
CC = g++

DYN_LIB_PATH = 

.Phony : clean rebuild run

# Main target
$(EXE_NAME): $(OBJECTS_FILES) # $(LIB_CREATED_PATH)/$(LIBSCREATE)
	$(CC) $(CFLAGS) $(OBJECTS_FILES) -o $(EXE_NAME) 
#<enter> $(LIB_NEEDED_PATH1)/$(LIB_NEEDED1) $(LIB_NEEDED_PATH2)/$(LIB_NEEDED2) -lm -lpthread


# To obtain object files
$(OBJECT_PATH)/%.o: %.c $(HFILE)
	$(CC) -c $(CFLAGS) $< -o $@

# To obtain object files
%.o: %.c $(HFILE)
	$(CC) -c $(CFLAGS) $< -o $@

#$(LIB_CREATED_PATH)/$(LIBSCREATE) : $(OBJECTS_FILES)
#	ar -cvrs $(LIB_CREATED_PATH)/$(LIBSCREATE) $(OBJECTS_FILES)

#$(LIB_NEEDED_PATH1)/$(LIB_NEEDED1) : 
#	$(MAKE) $(LIB_NEEDED1) -C $(LIB_NEEDED_PATH1)/../
	
#$(LIB_NEEDED1) : $(LIB_NEEDED_PATH1)/$(LIB_NEEDED1)

#$(LIB_NEEDED_PATH2)/$(LIB_NEEDED2) : 
#	$(MAKE) $(LIB_NEEDED2) -C $(LIB_NEEDED_PATH2)/../source
	
#$(LIB_NEEDED2) : $(LIB_NEEDED_PATH2)/$(LIB_NEEDED2)

run: ${EXE_NAME} 
	./${EXE_NAME}

clean:
	rm -f *.o
	rm -f $(OBJECT_PATH)/*.o
	rm -f $(OBJECTS_FILES)
	rm -f *~
	rm -f $(EXE_NAME)
	rm -f a.out
	rm -f outputFile.txt
#	rm -f $(LIB_CREATED_PATH)/$(LIBSCREATE)
#	rm -f $(LIB_NEEDED_PATH1)/$(LIB_NEEDED1)
#	$(MAKE) clean -C outputsModuls

rebuild : clean $(EXE_NAME)


