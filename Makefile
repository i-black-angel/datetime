TARGET=main

OBJECTS=main.o

$(TARGET): $(OBJECTS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $<

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)
