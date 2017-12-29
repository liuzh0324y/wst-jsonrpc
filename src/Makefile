CC = gcc 
CCFLAGS = 
CXX = g++
CXXFLAGS = -pipe -std=c++11 -fPIC -g -W 
LINK = g++
LDFLAGS = -shared
INCPATH = -I.
TARGET = bin/libjson.so
LIBS =
OBJS =	\
	objs/JsonDocument.o \
	objs/JsonValue.o 	\
	objs/JsonArray.o 	\
	objs/JsonObject.o 	\
	objs/JsonParseError.o 	


all: $(TARGET)

$(TARGET):	$(OBJS)	
	$(LINK) -o $(TARGET) $(LDFLAGS) \
		$(OBJS)	\
		$(LIBS)

objs/JsonDocument.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/JsonDocument.o 	\
		src/JsonDocument.cc

objs/JsonValue.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/JsonValue.o 		\
		src/JsonValue.cc

objs/JsonArray.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/JsonArray.o 		\
		src/JsonArray.cc

objs/JsonObject.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/JsonObject.o 		\
		src/JsonObject.cc 

objs/JsonParseError.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/JsonParseError.o 	\
		src/JsonParseError.cc