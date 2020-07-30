
CCFLAGS = --std=c++17 -lgtest -I../include -I../arch/x86/include

objs = main.o tuple_test.o

all: run_tests
	

%.o: %.cpp
	g++ $(CCFLAGS) -o $@ -c $<

tests: $(objs)
	g++ $(CCFLAGS) -o $@ $^ 

run_tests: tests
	./tests

clean:
	rm -f $(objs)
	rm -f tests
