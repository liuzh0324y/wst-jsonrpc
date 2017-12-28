CC = gcc 
CCFLAGS = 
CXX = g++
CXXFLAGS = -pipe -std=c++11 -fPIC -g -W 
LINK = g++
LDFLAGS = -shared
INCPATH = -I.
TARGET = bin/libjson.so
LIBS =
OBJS = objs/JsonObject.o


all: $(TARGET)

$(TARGET):	$(OBJS)	
	$(LINK) -o $(TARGET) $(LDFLAGS) \
		$(OBJS)	\
		$(LIBS)

objs/JsonObject.o: 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/JsonObject.o 		\
		src/JsonObject.cc
