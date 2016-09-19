CC=g++ -std=c++11
#Debug FLAGS
DE=-D CLINES_LOG_ERROR
DD=-D CLINES_LOG_DEBUG
DV=-D CLINES_LOG_VERBOSE
DMO=-D CLINES_MIN_OUTPUT
DFLAGS= $(DE) $(DD) $(DV)

SRC=solution.cpp

testdebug:$(SRC)
	$(CC) $(SRC) -o problem $(DFLAGS)
