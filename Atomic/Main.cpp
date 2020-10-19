#include <iostream>
#include "Atomic/API/Rolimons.h"
#include "Atomic/API/Wrapper.h"
#include "Atomic/Config/Parser.h"
#include "Atomic/Conversion.h"
#include "Atomic/User.h"

std::string getItemStringDemand(atomic::Demand demand) {
	switch (demand) {
	case atomic::Demand::NotAssigned:
		return "Not Assigned";
	case atomic::Demand::Low:
		return "Low";
	case atomic::Demand::Normal:
		return "Normal";
	case atomic::Demand::High:
		return "High";
	case atomic::Demand::Amazing:
		return "Amazing";
	}
}

int main()
{
#ifndef VS_DEBUG
    try {
#endif
        std::cout << std::boolalpha;
        rolimons::ItemDB* items = new rolimons::ItemDB(rolimons::getRolimonItems());
        atomic::User r = { 1480997 };
        atomic::Inventory userInv = r.getInventory(*items);
		atomic::Item r2 = userInv.getRandomItem();
		std::cout << r2.name << " | " << getItemStringDemand(r2.demand);
#ifndef VS_DEBUG
    }
    catch (...) {
        std::cerr << "Unhandled exception occured, ignoring...\n";
    }
#endif
    return EXIT_SUCCESS;
}