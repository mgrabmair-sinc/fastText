// TestUtil.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../fasttext_api.h"


int main()
{
	auto hPtr = CreateFastText();
	
	/*TrainingArgs args;
	args.Epochs = 25;
	args.LearningRate = 1.0;
	args.WordNGrams = 3;
	args.Verbose = 2;
	
	TrainSupervised(hPtr, "C:\\_Models\\cooking.train.txt", "C:\\_Models\\fasttext", args);
	*/
	
	
	LoadModel(hPtr, "C:\\_Models\\fasttext.bin");

	int maxLabelLen = GetMaxLabelLenght(hPtr);
	char* buff = new char[maxLabelLen + 1];
	
	float prob = PredictSingle(hPtr, "what is the difference between a new york strip and a bone-in new york cut sirloin ?", buff);
	delete[] buff;
	
	DestroyFastText(hPtr);
    return 0;
}

