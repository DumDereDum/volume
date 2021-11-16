#include "../include/volume_settings.hpp"

namespace cv
{
class VolumeSettings::Impl
{
public:
	Impl() {};
	virtual ~Impl() {};

private:

};

class VolumeSettingsImpl : public VolumeSettings::Impl
{
public:
	VolumeSettingsImpl();
	~VolumeSettingsImpl();

private:

};

VolumeSettingsImpl::VolumeSettingsImpl() {}
VolumeSettingsImpl::~VolumeSettingsImpl() {}


VolumeSettings::VolumeSettings()
{
	this->impl = makePtr<VolumeSettingsImpl>();
}

VolumeSettings::~VolumeSettings()
{
}

}