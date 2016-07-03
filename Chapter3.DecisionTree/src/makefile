WalOpt =  -Wno-c++11-extensions -Wno-c++11-compat-deprecated-writable-strings
dst = ../bin/testTree
src =  *.cpp 
lib = ../lib/ ../lib/libjson.a 

all:
	clang++ $(WalOpt) -o $(dst) $(src) -I $(lib)
