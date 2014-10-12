#include "idxReader.h"
#include "nnetwork.h"
#include "trainingAlgorithm.h"

int main()
{
	IdxReader mnistTrainImageDataset, mnistTrainLabelDataset, mnistTestImageDataset, mnistTestLabelDataset;
	
	NNetwork nNetwork;
	
	TrainingAlgorithm trainingMethod;
	
	mnistTrainImageDataset.read("MNISTDataset/train-images.idx3-ubyte"); 
	
	mnistTrainLabelDataset.read("MNISTDataset/train-label.idx3-ubyte"); 
	
	mnistTestImageDataset.read("MNISTDataset/t10k-images.idx3-ubyte"); 
	
	mnistTestLabelDataset.read("MNISTDataset/t10k-label.idx3-ubyte"); 
	
	nNetwork.train(mnistTrainImageDataset, mnistTrainLabelDataset, trainingMethod); // reads parameters of type Dataset::IdxDataset, runs learning algorithm, saves estimated network parameters in a XML file
	
	nNetwork.predict(mnistTestImageDataset, mnistTestLabelDataset);	// reads parameters of type Dataset::IdxDataset, runs prediction procedure, saves estimated labels in a XML file
    
	return 0;
}