Sources= main.cpp Vector.cpp
Tests=vectorTest.cpp
Executable=Versuch4

CXXFLAGS = -g -Wall -Wextra -pthread -Iinc
CPPFLAGS = -isystem $(GTEST_DIR)/include

GTEST_DIR = ../googletest
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

ObjectDir=obj/
TestObjectDir=testObj/
SourceDir=source/
TestSourceDir=tests/
BinDir=bin/

CC=g++
RM=rm -f

Objects=$(Sources:.cpp=.o)
TestObjects=$(Tests:.cpp=.o)

CSources=$(addprefix $(SourceDir),$(Sources))
CTestSources=$(addprefix $(TestSourceDir),$(Tests))

CObjects=$(addprefix $(ObjectDir),$(Objects))
CTestObjects=$(addprefix $(TestObjectDir),$(TestObjects))

CExecutable=$(addprefix $(BinDir),$(Executable))

clean:
	$(RM) $(CObjects) $(CTestObjects) gtest.a $(CExecutable)

all: $(CSources) $(CExecutable)

$(CExecutable): $(CObjects) $(CTestObjects) gtest.a
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

$(ObjectDir)%.o: $(SourceDir)%.cpp $(GTEST_HEADERS)
	$(CC) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@

$(TestObjectDir)%.o: $(TestSourceDir)%.cpp $(GTEST_HEADERS)
	$(CC) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@
	
	
#GTest
gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^