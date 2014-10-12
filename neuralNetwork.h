/*
Classes defining generic structures for neural networks. These classes may later be specialized to instantiate different types of networks.
*/

// defines neuron class
template<class T>
class Neuron
{
	public:
	
		T *inputActivation;
		T outputResponse;
		Neuron *forwardNeighborNeurons;
		Neuron *backwardNeighborNeurons;
		
		void computeActivation();	
};

// defines the generic neural network
class NeuralNetwork
{
	public:
	
		Neuron *inputLayer;
		Neuron **hiddenLayer; // in general there may be arbitrary number of hidden layers
		Neuron *outputLayer;
		
		unsigned int nInputNeurons;
		unsigned int* nHiddenNeurons;
		unsigned int nOutputNeurons;
		unsigned int nHiddenLayers;
};