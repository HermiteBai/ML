HR = ../bin/HandwritingRecognition
DR = ../bin/DatingRecommend

handwriting:../bin
	clang++ -o $(HR) -Wno-c++11-extensions handRecog.cpp img2vec.cpp kNN.cpp
datingrecommend:../bin
	clang++ -o $(DR) -Wno-c++11-extensions predict.cpp kNN.cpp
../bin:
	mkdir ../bin

	
