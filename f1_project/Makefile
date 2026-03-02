CXX = g++
CXXFLAGS = -std=c++11 -Wall -I./include

# Все исходные файлы
SRCS = main.cpp \
       src/person.cpp \
       src/driver.cpp \
       src/teamprincipal.cpp \
       src/technicaldirector.cpp \
       src/raceengineer.cpp \
       src/mechanic.cpp \
       src/team.cpp \
       src/track.cpp \
       src/streettrack.cpp \
       src/permanenttrack.cpp \
       src/highspeedtrack.cpp \
       src/historictrack.cpp

# Объектные файлы
OBJS = $(SRCS:.cpp=.o)

# Исполняемый файл
TARGET = f1_simulator

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Правило для src/%.o из src/%.cpp
src/%.o: src/%.cpp include/%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run