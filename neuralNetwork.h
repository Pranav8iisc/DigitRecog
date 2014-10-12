/*
Classes defining generic structures for neural networks. These classes may later be specialized to instantiate different types of networks.
*/

// defines neuron class
template<class T>
class neuron
{
	public:
	
		T *inputActivation;
		T outputResponse;
		neuron *forwardNeighborNeurons;
		neuron *backwardNeighborNeurons;
		
		void computeActivation();	
};

// defines the generic neural network
class neuralNetwork
{
	public:
	
		neuron *inputLayer;
		neuron **hiddenLayer; // in general there may be arbitrary number of hidden layers
		neuron *outputLayer;
		
		unsigned int nInputNeurons;
		unsigned int* nHiddenNeurons;
		unsigned int nOutputNeurons;
		unsigned int nHiddenLayers;
};