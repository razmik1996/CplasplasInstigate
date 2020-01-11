SOURCESWITHMAIN := $(wildcard *.cpp)
SOURCES := $(patsubst shape.cpp, , $(SOURCESWITHMAIN))
OBJECTS := $(patsubst %.cpp, obj/%.o, $(SOURCES))
DEPENDS := $(patsubst %.cpp, obj/%.dep, $(SOURCESWITHMAIN))

bin/program: ./bin lib/libStat.a shape.cpp
	@g++ shape.cpp -L lib -l Stat -o bin/program
	@echo "Succesfully..."
./bin:
	@mkdir -p bin
	@echo "bin folder created..."
lib/libStat.a: ./lib $(OBJECTS)
	@ar rc lib/libStat.a $(OBJECTS)
	@echo "static lib created..."
./lib:
	@mkdir -p lib
	@echo "lib folder created..."
obj/%.o: %.cpp
	@mkdir -p obj
	@g++ -c $< -o $@
obj/%.dep: %.cpp
	@mkdir -p obj
	@g++ -MM $< -MT "$@ $(patsubst %.dep, %.o, $@)" -o $@
-include $(DEPENDS)

.PHONY: clean
clean:
	@rm -rf bin/ lib/ obj/
	@echo "Cleaning..."

.PHONY: push
push:
	@git add .
	@git commit -m"some changes"
	@git push origin master

