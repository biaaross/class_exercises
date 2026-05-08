#include <iostream>
#include <string>

class employee {
    private:
    std::string name;
    std::string department;
    double wage;

    public:
    employee(std::string n,std::string d,double w) {
        name = n.empty() ? "Unknow" : n;
        department = d.empty() ? "Unknow" : d;
        wage  = w<0 ? 0 : w;
    }

    std::string getName() const;
    std::string getDepartment() const;
    double getWage() const;

    void raise(double ratio);

    void showInformation();
};

std::string employee::getName() const {
    return name;
}


std::string employee::getDepartment() const {
    return department;
}


double employee::getWage() const {
    return wage;
}

void employee::raise(double ratio) {
    if(ratio<0) {
        std::cerr<<"[INVALİD RATIO]"<<std::endl;
        return;
    }
    else {
        wage = wage + (wage * ratio / 100);
    }
}

void employee::showInformation() {
    std::cout<<"Name: "<<name
             <<" | Department: "<<department
             <<" | Wage: "<<wage<<std::endl;

}

int main() {
    
        employee staff[3] = {
        employee("Emre", "Software", 45000),
        employee("Selin", "Design", 38000),
        employee("Can", "Marketing", 32000)
    };

    
    std::cout << "--- Salary List After 15% Raise ---" << std::endl;
    for (int i = 0; i < 3; i++) {
        staff[i].raise(15);
        staff[i].showInformation();
    }


    employee highestPaid = staff[0]; 
    for (int i = 1; i < 3; i++) {
        if (staff[i].getWage() > highestPaid.getWage()) {
            highestPaid = staff[i];
        }
    }
    std::cout << "\nHighest Paid Employee: " << highestPaid.getName() 
              << " (" << highestPaid.getWage() << " TL)" << std::endl;

    std::cout << "\n--- Software Department Filter ---" << std::endl;
    bool found = false;
    for (int i = 0; i < 3; i++) {
        if (staff[i].getDepartment() == "Software") {
            staff[i].showInformation();
            found = true;
        }
    }
    
    if (!found) {
        std::cout << "No employees found in this department." << std::endl;
    }

    return 0;
}
