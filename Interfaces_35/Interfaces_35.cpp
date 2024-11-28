#include <iostream>
#include <vector>

using namespace std;

class IDevice
{
public:
    virtual void power() = 0;
    virtual void plus() = 0;
    virtual void minus() = 0;
    virtual void next() = 0;
    virtual void prev() = 0;
    virtual void showInfo() = 0;
};

class TV : public IDevice
{
private:
    bool isOn;
    int volume;
    int currentChannel;
    int maxVolume;
    int maxChannels;

public:
    TV(int maxVolume, int maxChannels)
        : isOn(false), volume(0), currentChannel(0), maxVolume(maxVolume), maxChannels(maxChannels)
    {
    }

    void power() override
    {
        isOn = !isOn;
        cout << "TV is " << (isOn ? "on" : "off") << endl;
    }

    void plus() override
    {
        if (isOn && volume < maxVolume)
        {
            volume++;
            cout << "Volume increased: " << volume << endl;
        }
    }

    void minus() override
    {
        if (isOn && volume > 0)
        {
            volume--;
            cout << "Volume decreased: " << volume << endl;
        }
    }

    void next() override
    {
        if (isOn && currentChannel < maxChannels)
        {
            currentChannel++;
            cout << "Switched to channel: " << currentChannel << endl;
        }
        if (isOn && currentChannel == maxChannels)
        {
            currentChannel = 0;
            cout << "Switched to channel: " << currentChannel << endl;
        }
    }

    void prev() override
    {
        if (isOn && currentChannel > 0)
        {
            currentChannel--;
            cout << "Switched to channel: " << currentChannel << endl;
        }
        if (isOn && currentChannel == 0)
        {
            currentChannel = maxChannels;
            cout << "Switched to channel: " << currentChannel << endl;
        }
    }

    void showInfo() override
    {
        cout << "TV Info: " << endl;
        cout << "Power: " << (isOn ? "On" : "Off") << endl;
        cout << "Volume: " << volume << endl;
        cout << "Channel: " << currentChannel << endl;
    }
};

class AirConditioner : public IDevice
{
private:
    bool isOn;
    int temperature;
    int mode;
    int minTemperature;
    int maxTemperature;
    int numModes;

public:
    enum Mode
    {
        Heating,
        Cooling,
        Turbo,
        Sleep
    };

    AirConditioner(int minTemperature, int maxTemperature, int numModes)
        : isOn(false), temperature(0), mode(0), minTemperature(minTemperature), maxTemperature(maxTemperature), numModes(numModes)
    {
    }

    void power() override
    {
        isOn = !isOn;
        cout << "Air Conditioner is " << (isOn ? "on" : "off") << endl;
    }

    void plus() override
    {
        if (isOn && temperature < maxTemperature)
        {
            temperature++;
            cout << "Temperature increased: " << temperature << endl;
        }
    }

    void minus() override
    {
        if (isOn && temperature > minTemperature)
        {
            temperature--;
            cout << "Temperature decreased: " << temperature << endl;
        }
    }

    void next() override
    {
        if (isOn)
        {
            mode = (mode + 1) % numModes;
            cout << "Switched to mode: " << mode << endl;
        }
    }

    void prev() override
    {
        if (isOn)
        {
            mode = (mode - 1 + numModes) % numModes;
            cout << "Switched to mode: " << mode << endl;
        }
    }

    void showInfo() override
    {
        cout << "Air Conditioner Info: " << endl;
        cout << "Power: " << (isOn ? "On" : "Off") << endl;
        cout << "Temperature: " << temperature << endl;
        cout << "Mode: " << mode << endl;
    }
};

class SmartRemote
{
private:
    vector<IDevice*> devices;
    IDevice* currentDevice;

public:
    SmartRemote()
        : currentDevice(nullptr)
    {
    }
    SmartRemote(IDevice* device)
        :currentDevice(device)
    {
        addDevice(device);
    }

    void addDevice(IDevice* device)
    {
        devices.push_back(device);
    }

    void removeDevice(IDevice* device)
    {
        size_t index = 0;
        for (auto& item : devices)
        {
            if (item == device)
            {
                if (item == currentDevice)
                {
                    currentDevice = *devices.begin();
                }
                devices.erase(devices.begin() + index);
            }
            index++;
        }
    }

    void showDevices()
    {
        cout << "Devices: " << endl;
        int index = 0;
        for (auto& item : devices)
        {
            cout << ++index << ". " << (item == currentDevice ? "Current\n" : "\n");
            item->showInfo();
            cout << endl;
        }

    }

    void changeDevice(int index)
    {
        if (index >= 0 && index < devices.size())
        {
            currentDevice = devices[index];
        }
    }

    void CurrentDevice()
    {
        showInfo();
    }

    void power()
    {
        if (currentDevice)
        {
            currentDevice->power();
        }
    }

    void plus()
    {
        if (currentDevice)
        {
            currentDevice->plus();
        }
    }

    void minus()
    {
        if (currentDevice)
        {
            currentDevice->minus();
        }
    }

    void next()
    {
        if (currentDevice)
        {
            currentDevice->next();
        }
    }

    void prev()
    {
        if (currentDevice)
        {
            currentDevice->prev();
        }
    }

    void showInfo()
    {
        if (currentDevice)
        {
            currentDevice->showInfo();
        }
    }
};


int main()
{
    TV tv(100, 3);
    AirConditioner ac(15, 30, 1);
    SmartRemote remote(&tv);

    remote.addDevice(&ac);

    remote.changeDevice(0);
    remote.power();
    remote.plus();
    remote.next();
    remote.showInfo();

    remote.changeDevice(1);
    remote.power();
    remote.plus();
    remote.next();
    remote.showInfo();

    remote.removeDevice(&ac);
    cout << "\n\n\n\n\n\n";
    remote.showDevices();
}