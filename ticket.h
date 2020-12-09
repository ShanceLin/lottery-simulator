#ifndef TICKET
#define TICKET
#include <vector>

class ticket {
	public:
		ticket(std::vector<int> insert, int s); //Constructor with all the digits passed in
		bool isJackpot(ticket winning, int s);
		int checkMegaNumbers(ticket winning, int s);
		int checkPowerNumbers(ticket winning, int s);
		std::vector<int> getSet();
		void printTicket();

	private:
		std::vector<int> set; //All ints for storage
		int special;
};


#endif