CXX = g++
CXXFLAGS = -std=c++20 -O3 -flto -funroll-loops -ffast-math -fomit-frame-pointer \
           -finline-functions -fno-signed-zeros -fno-trapping-math \
           -fipa-pta -fipa-cp -fipa-bit-cp -fdevirtualize -fdevirtualize-at-ltrans \
           -Wall -Wextra

TARGET = batcheck
SRC = main.cpp

all: $(TARGET)
	./$(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

install: $(TARGET)
	sudo install -m 755 $(TARGET) /usr/bin/$(TARGET)

clean:
	rm -f $(TARGET)