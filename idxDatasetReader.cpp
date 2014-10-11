#include <iostream>
#include <fstream>
#include <opencv/highgui.h>

#define MAX_FILENAME_CHAR 255

using namespace std;

unsigned nImages;
unsigned char trainImageData;
unsigned char trainLabelData;
unsigned char testImageData;
unsigned char testLabelData;

/*
-----------------------------
-----------------------------
MNIST Image data format:

Magic number(4 bytes, Big endian)
Number of images(4 bytes)
Number of rows
Number of columns
Pixel
Pixel
..
..
Pixel
------------------------------
------------------------------

------------------------------
------------------------------
MNIST Image label format:

Magic number(4 bytes, Big endian)
Number of items(4)
Label
Label
..
..
Label
-----------------------------
-----------------------------
*/


// reads training image data
void readTrainingSetImageFile()
{
	ifstream trainImageFile("MNISTDataset/train-images.idx3-ubyte", ios::binary);
	
	char magicNumber[4];
	
	for (unsigned i = 0; i < 4; i++)
		trainImageFile.get(magicNumber[i]); 

	char nImages[4];
	
	for (unsigned i = 0; i < 4; i++)
		trainImageFile.get(nImages[i]);
	
	unsigned nRows, nColumns, totalPixels;

	totalPixels = nRows * nColumns;

	trainImageData = new char[totalPixels];
	
	for (unsigned i = 0; i < totalPixels; i++)
		trainImageFile.get(trainImageData[i]);
			
	trainImageFile.close();
}

// reads training label data
void readTrainingSetLabelFile()
{
	ifstream trainLabelFile("MNISTDataset/train-label.idx3-ubyte", ios::binary);
	
	char magicNumber[4];
	
	for (unsigned i = 0; i < 4; i++)
		trainLabelFile.get(magicNumber[i]); 

	char nLabels[4];
	
	for (unsigned i = 0; i < 4; i++)
		trainLabelFile.get(nLabels[i]);
	
	char labelData = new char[nLabels];
	
	for (unsigned i = 0; i < nLabels; i++)
		trainLabelFile.get(labelData[i]);
			
	trainLabelFile.close();
}

// reads test image data
void readTestSetImageFile()
{
	ifstream trainImageFile("MNISTDataset/t10k-images.idx3-ubyte", ios::binary);
	
	char magicNumber[4];
	
	for (unsigned i = 0; i < 4; i++)
		testImageFile.get(magicNumber[i]); 

	char nImages[4];
	
	for (unsigned i = 0; i < 4; i++)
		testImageFile.get(nImages[i]);
	
	unsigned nRows, nColumns, totalPixels;

	totalPixels = nRows * nColumns;

	char imageData = new char[totalPixels];
	
	for (unsigned i = 0; i < totalPixels; i++)
		testImageFile.get(imageData[i]);
			
	testImageFile.close();

}

// reads test label data
void readTestSetLabelFile()
{
	ifstream trainLabelFile("MNISTDataset/t10k-label.idx3-ubyte", ios::binary);
	
	char magicNumber[4];
	
	for (unsigned i = 0; i < 4; i++)
		testLabelFile.get(magicNumber[i]); 

	char nLabels[4];
	
	for (unsigned i = 0; i < 4; i++)
		testLabelFile.get(nLabels[i]);
	
	char labelData = new char[nLabels];
	
	for (unsigned i = 0; i < nLabels; i++)
		testLabelFile.get(labelData[i]);
			
	testLabelFile.close();

}

// for Debugging pupose
void saveImages()
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


int main()
{
	cout << "Please enter number of images"; 
	return 0;
}
