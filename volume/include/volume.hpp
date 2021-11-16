#ifndef VOLUME_HPP
#define VOLUME_HPP

#include <opencv2/core/cvstd.hpp>

#include "volume_settings.hpp"

namespace cv
{

enum class VolumeType
{
	TSDF = 0,
	HashTSDF = 1,
	ColorTSDF = 2
};


class Volume
{
public:
	Volume();
	Volume(VolumeType vtype, VolumeSettings settings);
	~Volume();

	void integrate();
	void raycast() const;

	void fetchNormals() const;
	void fetchPointsNormals() const;

	void reset();
	int getVisibleBlocks() const;
	size_t getTotalVolumeUnits() const;


	class Impl;
private:
	Ptr<Impl> impl;
};

}
#endif // !VOLUME_HPP
