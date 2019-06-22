CXX = g++
CXXFLAGS = -Wall -std=c++14
exec = madlibs
objs = *.o
src = *.cpp

$(exec): $(objs)
	$(CXX) $(CXXFLAGS) -o $(exec) $(objs)

$(objs): $(src) *.h
	$(CXX) $(CXXFLAGS) -c $(src)

clean:
	rm $(exec) $(objs)
