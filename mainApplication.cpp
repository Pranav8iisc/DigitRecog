#include <idxReader.h>
#include <nnetworkTrain.h>


int main()
{
	idxReader.read();
	nNNetwork.train();
	nNetwork.predict();
    return 0;
}