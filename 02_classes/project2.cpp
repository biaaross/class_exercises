#include <iostream>
#include <string>
#include <algorithm>

class  device {
    protected:
    bool turnOn;
    
    public:
    std::string marka;
    void showState() const;
};

void device::showState() const {
    std::cout<<"State: "<<(turnOn ? "open" : "closed")
             <<" | Marka: "<<marka<<std::endl;
}


class smartphone :  public device {
    private:
    int batteryLevel;

    public:
  smartphone(std::string m, int battery) {
        marka = m.empty() ? "bilinmiyor" : m;
        batteryLevel = (battery >= 0) ? battery : 0;
    }

    void open();
    void showState() const;
};

void smartphone::open() {
    turnOn = true;
}

void smartphone::showState() const {
    std::cout << "--- Telefon Durumu ---" << std::endl;

        std::cout << "Marka: " << marka 
                  << " | State: " << (turnOn ? "YES" : "NO")
                  << " | Battery: %" << batteryLevel << std::endl;
}


class smartLamp : public device {
    private:
    std::string color;

    public:
    smartLamp(std::string m, std::string c) {
        marka = m.empty() ? "bilinmiyor" : m;
        color = c.empty() ? "bilinmiyor" : c;
    }

    void showState() const;
};

void smartLamp::showState() const {
    std::cout << "--- Lamp State ---" << std::endl;
        std::cout << "Marka: " << marka 
                  << " | Color: " << color 
                  << " | State: " << (turnOn ? "Open" : "Close") << std::endl;
    }



int main() {
    smartphone myPhone("Apple", 85);
    smartLamp myLamp("Xiaomi", "Mavi");

    myPhone.open();
    
    myPhone.showState();
    myLamp.showState();

    return 0;
}