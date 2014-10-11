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
		readDataset(); 
		IdxDatasetReader(string)
		{}
};