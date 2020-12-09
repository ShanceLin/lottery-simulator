#include "ticket.h"
#include <vector>

ticket::ticket(std::vector<int> inserted, int s){
	sort(inserted.begin(), inserted.end());
	set = inserted;
	special = s;
}

bool ticket::isJackpot(ticket winning, int s) {
	if (special != s) {
		return false;
	}
	if (set != winning.getSet()) { 
		return false;
	}
	return true;
}

std::vector<int> ticket::getSet(){ 
	return set;
}

void ticket::printTicket() {
	for (unsigned long i = 0; i < set.size(); i++) {
		std::cout << " " << set[i];
	}
	std::cout << " " << special << std::endl;
}

int ticket::checkMegaNumbers(ticket winning, int s) {
	bool specialMatch = (special == s);
	int numMatches = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (set[i] == winning.getSet()[j]) {
				numMatches++;
			}
		}
	}

	if(numMatches == 0 && specialMatch == true) return 2;
	if(specialMatch == true && numMatches == 1) return 4;
	if(specialMatch == true && numMatches == 2) return 10;
	if(specialMatch == false && numMatches == 3) return 10;
	if(specialMatch == true && numMatches == 3) return 200;
	if(specialMatch == false && numMatches == 4) return 500;
	if(specialMatch == true && numMatches == 4) return 10000;
	if(numMatches == 5) return 1000000;

	return 0;
}

int ticket::checkPowerNumbers(ticket winning, int s) {
	bool specialMatch = (special == s);
	int numMatches = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (set[i] == winning.getSet()[j]) {
				numMatches++;
			}
		}
	}

	if(numMatches == 0 && specialMatch == true) return 4;
	if(specialMatch == true && numMatches == 1) return 4;
	if(specialMatch == true && numMatches == 2) return 7;
	if(specialMatch == false && numMatches == 3) return 7;
	if(specialMatch == true && numMatches == 3) return 100;
	if(specialMatch == false && numMatches == 4) return 100;
	if(specialMatch == true && numMatches == 4) return 50000;
	if(numMatches == 5) return 1000000;

	return 0;
}


