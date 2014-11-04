#include "LinearNeuronPerceptronNetwork.h"

int main()
{

	LinearNeuronPerceptronNetwork mnistNetwork;

	mnistNetwork.readTrainingData();

	mnistNetwork.extractFeatures();

	mnistNetwork.trainNetwork();

	mnistNetwork.testNetwork();

	return 0;
}
