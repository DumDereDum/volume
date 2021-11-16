#include <iostream>
#include <fstream>
#include <chrono>

#include "include/volume.hpp"

using namespace cv;

int main(int argc, char** argv)
{

	if (true)
	{
		VolumeSettings settings;
		Volume volume(VolumeType::TSDF, settings);
		volume.integrate();
		volume.raycast();
	}

	if (true)
	{
		VolumeSettings settings;
		Volume volume(VolumeType::HashTSDF, settings);
		volume.integrate();
		volume.raycast();
	}

	if (true)
	{
		VolumeSettings settings;
		Volume volume(VolumeType::ColorTSDF, settings);
		volume.integrate();
		volume.raycast();
	}

	return 0;
}