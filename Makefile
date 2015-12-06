CXX = $(shell fltk-config --cxx)
DEBUG = -g

CXXFLAGS = -std=c++11 $(shell fltk-config --use-gl --use-images --cxxflags ) -I.
LDFLAGS = $(shell fltk-config --use-gl --use-images --ldflags )
LDSTATIC = $(shell fltk-config --use-gl --use-images --ldstaticflags )
LINK = $(CXX)

TARGET = main 
OBJS = main.o visualize.o trapezoid.o segment_node.o point_node.o trapezoid_node.o search.o
SRCS = visualize.cpp trapezoid.cpp segment_node.cpp point_node.cpp trapezoid_node.cpp search.cpp main.cpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LINK) -o $(TARGET) $(OBJS) $(LDFLAGS)

clean:
	rm -f *.o 
	rm -f $(TARGET) 
