all:
	@mkdir -p out
	@g++ -o out/solution.out \
	src/main.cpp \
	src/stringbase.cpp \
	src/stringhelper.cpp \
	-I./include \
	-std=gnu++14

run:
	@./solution.out

clean:
	@rm -rf out