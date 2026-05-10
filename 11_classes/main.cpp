#include "appointmen.h"
#include <iostream>

int main() {
    Patient* p1 = new Patient("Ali Veli", "Bas agrisi");
    Doctor* d1 = new Doctor("Dr. Ayse", "Noroloji");

    Appointment* app = new Appointment(p1, d1, "15/05/2026");

    app->showAppointmentInfo();

    delete app; 
    delete p1;
    delete d1;

    return 0;
}