#ifndef VOLUME_SETTINGS_HPP
#define VOLUME_SETTINGS_HPP

#include <opencv2/core/cvstd.hpp>

namespace cv
{

class VolumeSettings
{
public:
	VolumeSettings();
	~VolumeSettings();

	class Impl;
private:
	Ptr<Impl> impl;
};

}

#endif // !VOLUME_SETTINGS_HPP
