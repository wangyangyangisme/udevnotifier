#ifndef UDEVNOTIFIER__DEVICE_H
#define UDEVNOTIFIER__DEVICE_H

#include "udevnotifier_global.h"
#include <QtCore/QMetaType>

class udev_device;

namespace UdevNotifier {

class DevicePrivate;


/**
 * @class Device
 * @brief The UdevNotifier Device class
 * @author Francesco Nwokeka <francesco.nwokeka@gmail.com>
 *
 * This class describes a device on the system detected by the UdevNotifier
 */
class UDEVNOTIFIERSHARED_EXPORT Device
{
public:

    enum TYPE{

        MONITOR,
        WEBCAM,
        USBDEVICE
    };
    TYPE typeD;

    Device(udev_device *device = nullptr, TYPE n  = USBDEVICE);
    Device(const Device &other);
    ~Device();
    Device::TYPE typeDevice();

    QString node() const;
    QString subsystem() const;
    QString type() const;

private:
    DevicePrivate * const d;
};

}

Q_DECLARE_METATYPE(UdevNotifier::Device)

#endif  // UDEVNOTIFIER__DEVICE_H
