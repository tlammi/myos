
CCFLAGS = --std=c++17 -I../include -I../arch/virtual/include
LDFLAGS = -lgtest -lpthread
objs = main.o tuple_test.o

all: run_tests
	

%.o: %.cpp
	g++ $(CCFLAGS) -o $@ -c $<

tests: $(objs)
	g++ -o $@ $^ $(LDFLAGS)

run_tests: tests
	./tests

clean:
	rm -f $(objs)
	rm -f tests
