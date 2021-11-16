#include <iostream>

#include "../include/volume.hpp"

namespace cv
{

class Volume::Impl
{
private:

public:
    Impl() {};
	virtual ~Impl() {};

	virtual void integrate() = 0;
	virtual void raycast() const = 0;

	virtual void fetchNormals() const = 0;
	virtual void fetchPointsNormals() const = 0;

	virtual void reset() = 0;
	virtual int getVisibleBlocks() const = 0;
	virtual size_t getTotalVolumeUnits() const = 0;
};


class TsdfVolume : public Volume::Impl
{
public:
	TsdfVolume(VolumeSettings settings);
	~TsdfVolume();

	virtual void integrate() override;
	virtual void raycast() const override;

	virtual void fetchNormals() const override;
	virtual void fetchPointsNormals() const override;

	virtual void reset() override;
	virtual int getVisibleBlocks() const override;
	virtual size_t getTotalVolumeUnits() const override;
private:
	VolumeSettings settings;
};

TsdfVolume::TsdfVolume(VolumeSettings settings) { this->settings = settings; }
TsdfVolume::~TsdfVolume() {}

void TsdfVolume::integrate() { std::cout << "TsdfVolume::integrate()" << std::endl; }
void TsdfVolume::raycast() const { std::cout << "TsdfVolume::raycast()" << std::endl; }

void TsdfVolume::fetchNormals() const {}
void TsdfVolume::fetchPointsNormals() const{}

void TsdfVolume::reset() {}
int TsdfVolume::getVisibleBlocks() const { return 1; }
size_t TsdfVolume::getTotalVolumeUnits() const { return 1; }


class HashTsdfVolume : public Volume::Impl
{
public:
	HashTsdfVolume(VolumeSettings settings);
	~HashTsdfVolume();

	virtual void integrate() override;
	virtual void raycast() const override;

	virtual void fetchNormals() const override;
	virtual void fetchPointsNormals() const override;

	virtual void reset() override;
	virtual int getVisibleBlocks() const override;
	virtual size_t getTotalVolumeUnits() const override;
private:
	VolumeSettings settings;
};

HashTsdfVolume::HashTsdfVolume(VolumeSettings settings) { this->settings = settings; }
HashTsdfVolume::~HashTsdfVolume() {}

void HashTsdfVolume::integrate() { std::cout << "HashTsdfVolume::integrate()" << std::endl; }
void HashTsdfVolume::raycast() const { std::cout << "HashTsdfVolume::raycast()" << std::endl; }

void HashTsdfVolume::fetchNormals() const {}
void HashTsdfVolume::fetchPointsNormals() const{}

void HashTsdfVolume::reset() {}
int HashTsdfVolume::getVisibleBlocks() const { return 1; }
size_t HashTsdfVolume::getTotalVolumeUnits() const { return 1; }


class ColorTsdfVolume : public Volume::Impl
{
public:
	ColorTsdfVolume(VolumeSettings settings);
	~ColorTsdfVolume();

	virtual void integrate() override;
	virtual void raycast() const override;

	virtual void fetchNormals() const override;
	virtual void fetchPointsNormals() const override;

	virtual void reset() override;
	virtual int getVisibleBlocks() const override;
	virtual size_t getTotalVolumeUnits() const override;
private:
	VolumeSettings settings;
};

ColorTsdfVolume::ColorTsdfVolume(VolumeSettings settings) { this->settings = settings; }
ColorTsdfVolume::~ColorTsdfVolume() {}

void ColorTsdfVolume::integrate() { std::cout << "ColorTsdfVolume::integrate()" << std::endl; }
void ColorTsdfVolume::raycast() const { std::cout << "ColorTsdfVolume::raycast()" << std::endl; }

void ColorTsdfVolume::fetchNormals() const {}
void ColorTsdfVolume::fetchPointsNormals() const{}

void ColorTsdfVolume::reset() {}
int ColorTsdfVolume::getVisibleBlocks() const { return 1; }
size_t ColorTsdfVolume::getTotalVolumeUnits() const { return 1; }


Volume::Volume()
{
	VolumeSettings settings;
	this->impl = makePtr<TsdfVolume>(settings);
}
Volume::Volume(VolumeType vtype, VolumeSettings settings)
{
	switch (vtype)
	{
	case VolumeType::TSDF:
		this->impl = makePtr<TsdfVolume>(settings);
		break;
	case VolumeType::HashTSDF:
		this->impl = makePtr<HashTsdfVolume>(settings);
		break;
	case VolumeType::ColorTSDF:
		this->impl = makePtr<ColorTsdfVolume>(settings);
		break;
	default:
		//CV_Error(Error::StsInternal,
		//	"Incorrect OdometryType, you are able to use only { ICP, RGB, RGBD }");
		break;
	}
}
Volume::~Volume() {}

void Volume::integrate() { this->impl->integrate(); }
void Volume::raycast() const { this->impl->raycast(); }
void Volume::fetchNormals() const { this->impl->fetchNormals(); }
void Volume::fetchPointsNormals() const { this->impl->fetchPointsNormals(); }
void Volume::reset() { this->impl->reset(); }
int Volume::getVisibleBlocks() const { return this->impl->getVisibleBlocks(); }
size_t Volume::getTotalVolumeUnits() const { return this->impl->getTotalVolumeUnits(); }


}