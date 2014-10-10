#include <iostream>
#include <fstream>
#include <opencv/highgui.h>


using namespace std;

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
// file location : MNISTDataset/train-images.idx3-ubyte	
	ifstream trainImageFile("MNISTDataset/train-images.idx3-ubyte", ios::binary);
	char magicNumber[4];
	for (unsigned i = 0; i < 4; i++)
		trainImageFile.get(magicNumber[i]); 

	char numberOfImages[4];
	for (unsigned i = 0; i < 4; i++)
		trainImageFile.get(numberOfImages[i]);
	
			
	trainImageFile.close();
}

// reads training label data
void readTrainingSetLabelFile()
{
// file location : MNISTDataset/train-label.idx3-ubyte

}

// reads test image data
void readTestSetImageFile()
{
// file location : MNISTDataset/t10k-images.idx3-ubyte

}

// reads test label data
void readTestSetLabelFile()
{
// file location : MNISTDataset/t10k-label.idx3-ubyte

}

// used only for Debugging purpose so as to be sure about the read training and testing image data.
void saveImages()
{

}
