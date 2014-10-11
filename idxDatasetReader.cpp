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


idxDatasetReader::readDataset(string inputFileName, unsigned nInputDatasets)
{
	filename = inputFileName;
	nDatasets = nInputDatasets; // represents number of datasets inside input file
	
	if(this->file.open(fileName) == NULL)
		{
			cout << "Invalid filename. Please ensure correct filename is specified";
			exit(0);
		}
	
	// if file contains valid header
	
	// magic number
	unsigned magicNumber;
	bool isLittleEndian;
	
	this->file >> magicNumber;
		
	if (isLittleEndian() == true)
		{
			isLittleEndian = true;
			magicNumber = __builtin_bswap32(magicNumber);
		}
	
	
		
	// if file contains number of bytes as implied by file header
	
	// convert data to little-endian format
	
	
	
	
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

