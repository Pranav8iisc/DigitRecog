/*
Specializes DatasetReader class for Idx files defined here(see at the bottom):
http://yann.lecun.com/exdb/mnist/
*/

#include "datasetReader.h"
#include <string>

using namespace std;

class IdxDatasetReader : public DatasetReader
{	
	public:
		
		unsigned magicNumber;
		unsigned *sizeOfDimension; // variable sizes array containing size for each of nDimensions
		unsigned *data; // n X 1 vector where 'n' = nDatasets*nDimensions*PROD(i){sizeOfDimension_{i}}, stored in row-major order
		unsigned nDatasets; // number of Datasets in the input idx file
				
		getDataset(string, unsigned); 
		
		
	protected:
	
		char getDatatype();
		unsigned getNumberOfDimensions();
		unsigned* getSizeOfDimension();	
		unsigned getTotalSizeData;
		bool hasValidFileSize(); 
};