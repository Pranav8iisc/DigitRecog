#include <ifstream>
#include "idxDatasetReader.h"

using namespace std;

idxDatasetReader::idxDatasetReader()
{	
	
}

~idxDatasetReader::idxDatasetReader()
{
	
}

// I suspect this is not portable :(
// http://stackoverflow.com/questions/280162/is-there-a-way-to-do-a-c-style-compile-time-assertion-to-determine-machines-e
idxDatasetReader::isLittleEndian()
{
	union {
	char c[sizeof(int)];
	int n;
	} isLittle = 1;
	
	if (isLittle[0] == 0x00)
		return true;
	else
		return false;		
}


idxDatasetReader::getDataset(string inputFileName, unsigned nInputDatasets)
{
	filename = inputFileName;
	nDatasets = nInputDatasets; 
	
	if(this->file.open(fileName) == NULL)
		{
			cout << "Invalid filename. Please ensure correct filename is specified";
			exit(0);
		}
	
	// extract magic number
	bool isLittleEndian;
	
	file >> magicNumber;
		
	if (isLittleEndian() == true)
		{
			isLittleEndian = true;
			magicNumber = __builtin_bswap32(magicNumber);
		}
	
	// get datatype
	char datatypeId; 
	datatypeId = getDatatype();
	
	// get number of dimensions
	char nDimensions;
	nDimensions = getNumberOfDimension();
	
	// get size of dimensions
	sizeOfDimension = getSizeOfDimension();
	
	unsigned totalSize = getTotalDatasetSize();
		
	// check if file contains number of bytes as implied by file header
	if (hasValidFileSize() == false)
		{
			cout << "Actual data < data size implied by the header :(";
			exit(0);			
		}
		
	// read dataset
	switch(datypeId)
	{
		case 0x08:
		data = new unsigned char[totalDatasetSize];
		for (unsigned byteId = 0; byteId < totalDatasetSize; byteId++)
			file.get(data[byteId]); 
		break;
		
		case 0x09: 
		data = new char[totalDatasetSize];
		for (unsigned byteId = 0; byteId < totalDatasetSize; byteId++)
			file.get(data[byteId]); 
		break;
		
		case 0x0B: 
		data = new short[totalDatasetSize]; 
		for (unsigned byteId = 0; byteId < totalDatasetSize; byteId++)
			{
				file.get(data[byteId]); 
				data[byteId] = __builtin_bswap16(magicNumber);
			}
		break;
		
		case 0x0C: 
		data = new int[totalDatasetSize];
		for (unsigned byteId = 0; byteId < totalDatasetSize; byteId++)
			{
				file.get(data[byteId]); 
				data[byteId] = __builtin_bswap32(magicNumber);
			}
		break;
		
		case 0x0D: 
		data = new float[totalDatasetSize];
		for (unsigned byteId = 0; byteId < totalDatasetSize; byteId++)
			{
				file.get(data[byteId]); 
				data[byteId] = __builtin_bswap32(magicNumber);
			}
		break;
		
		case 0x0E: 
		data = new double[totalDatasetSize];
		for (unsigned byteId = 0; byteId < totalDatasetSize; byteId++)
			{
				file.get(data[byteId]); 
				data[byteId] = __builtin_bswap64(magicNumber);
			}
		break;
		
		defualt:
		cout << "Invalid dataset type specified";
		exit(0);
	}	
	
	file.close();
}


// saves dataset in JPEG form
void idxDatsetReader::saveJPEG()
{
	// save training images
	char fileName[MAX_FILENAME_CHAR];
	
	Iplimage opencvImage = cvCreateImage(cvSize(nRows, nColumns), IPL_DEPTH_8U, 1);
	
	for (unsigned imageId = 0; imageId < nImages; imageId++)
	{
		sprintf(fileName, "MNISTDataset/trainImages/%i.jpg", imageId);
			for (unsigned i = 0; i < nPixels; i++)
				opencvImage->ImageData[i] = trainImageData[imageId][i];
	}
}
*/

