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
		
		unsigned unsigned magicNumber;
		unsigned int *sizeOfDimension; // variable sizes array containing size for each of nDimensions
		unsigned int *data; // n X 1 vector where 'n' = nDatasets*nDimensions*PROD(i){sizeOfDimension_{i}}, stored in row-major order
		unsigned int nDatasets; // number of Datasets in the input idx file
				
		void getDataset(string, unsigned); 
		
		
	protected:
	
		unsigned int getMagicNumber
		char getDatatype();
		unsigned int getNumberOfDimensions();
		unsigned* int getSizeOfDimension();	
		unsigned int getNumberOfDatasets();
		unsigned int getTotalDatasetSize(unsigned int);		
};