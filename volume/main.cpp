#include <iostream>
#include <fstream>
#include <chrono>

#include "include/volume.hpp"

using namespace cv;

class Volume
{
	public:
		Volume(...);
		~Volume();
		void fun();

		class Impl;

	private:
		Impl* pimpl;
}


class Volume::Impl
{
	public:
		Impl(...);
		virtual ~Impl();
		virtual void fun() = 0;
}

class Volume1
{
	public:
		Impl(...);
		virtual ~Impl();
		virtual void fun() override;
}


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
