#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include "ticket.cpp"
#include <time.h>

std::vector<int> generateMega() {
	//populate the pool of possible numbers
	std::vector<int> megaPool;
	for (int i = 1; i < 71; i++) {
		megaPool.push_back(i); 
	}

	//generate random vector of numbers into generated
	std::vector<int> generated;
	int totalMega = 69;
	//srand(time(0));
	for (int i = 0; i < 5; i++) {
		int randIndex = rand() % totalMega;
		generated.push_back(megaPool[randIndex]);
		std::swap(megaPool[randIndex], megaPool.back());
		megaPool.pop_back();
		totalMega--;
	}

	return generated;
}

std::vector<int> generatePower() {
	//populate the pool of possible numbers
	std::vector<int> powerPool;
	for (int i = 1; i < 70; i++) {
		powerPool.push_back(i); 
	}

	//generate random vector of numbers into generated
	std::vector<int> generated;
	int totalPower = 68;
	//srand(time(0));
	for (int i = 0; i < 5; i++) {
		int randIndex = rand() % totalPower;
		generated.push_back(powerPool[randIndex]);
		std::swap(powerPool[randIndex], powerPool.back());
		powerPool.pop_back();
		totalPower--;
	}

	return generated;
}

int main() {
	bool end = false;
	int eachPlay = 1; 

	while (end == false) {
		//Accepting commands from command line, saving to command. 
		std::string commandLine; 
		getline(std::cin, commandLine);
		std::stringstream ss(commandLine);
		std::string command;
		ss >> command;
		transform(command.begin(), command.end(), command.begin(), ::tolower);
		//checks if commands are mega/power/end 
		if (command == "megamillions" || command == "mega") {
			//storage variables
			long plays = 0;
			long money = 0;
			long millionCounter = 1;
			bool jackpot = false;
			while (jackpot == false) {
				if (plays % 100000 == 0) {
					std::cout << "Play #" << plays << std::endl << "Money Earned: $" << money << std::endl; 
				}
				if (money > millionCounter * (1000000)) {
					std::cout << "Money: $" << money << std::endl << "Money Spent: $" << plays*2 << std::endl;
					millionCounter++;
				}

				std::vector<int> winning = generateMega();
				srand(time(0));
				int winningSpecial = (rand() % 25) + 1;

				ticket *winningTicket = new ticket(winning, winningSpecial);

				for (int i = 0; i < eachPlay; i++) {
					plays++;
					std::vector<int> generated = generateMega();
					//srand(time(0));
					int randSpecial = (rand() % 25) + 1;

					ticket *played = new ticket(generated, randSpecial);


					//played->printTicket();
					//winningTicket->printTicket();


					if (played->isJackpot(*winningTicket, winningSpecial) == true) {
						jackpot = true;
						std::cout << "You hit the jackpot!" << std::endl << "Tickets: " << plays << std::endl << "Money: $" << money << std::endl << "Money Spent: $" << plays*2 << std::endl << "Winning numbers: ";
						winningTicket->printTicket();
						std::cout << std::endl;

					} else {
						money += played->checkMegaNumbers(*winningTicket, winningSpecial);
					}

					delete(played);
				}
				delete(winningTicket);
			}

		} else if (command == "powerball" || command == "power") {
			long plays = 0;
			long money = 0;
			long millionCounter = 1;
			bool jackpot = false;
			while (jackpot == false) {
				if (plays % 100000 == 0) {
					std::cout << "Play #" << plays << std::endl << "Money Earned: $" << money << std::endl; 
				}
				if (money > millionCounter * (1000000)) {
					std::cout << "Money: $" << money << std::endl << "Money Spent: $" << plays*2 << std::endl;
					millionCounter++;
				}
				std::vector<int> winning = generatePower();
				srand(time(0));
				int winningSpecial = (rand() % 25) + 1;

				ticket *winningTicket = new ticket(winning, winningSpecial);
				for (int i = 0; i < eachPlay; i++) {
					std::vector<int> generated = generatePower();
					//srand(time(0));
					int randSpecial = (rand() % 25) + 1;

					ticket *played = new ticket(generated, randSpecial);


					//played->printTicket();
					//winningTicket->printTicket();


					if (played->isJackpot(*winningTicket, winningSpecial) == true) {
						plays++;
						jackpot = true;
						std::cout << "You hit the jackpot!" << std::endl << "Tickets: " << plays << std::endl << "Money: $" << money << std::endl << "Money Spent: $" << plays*2 << std::endl << "Winning numbers: ";
						winningTicket->printTicket();
						std::cout << std::endl;

					} else {
						money += played->checkPowerNumbers(*winningTicket, winningSpecial);
					}

					delete(played);
				}
				delete(winningTicket);

			}
		} else if(command == "plays") {
			std::cout << "How many plays each drawing?: ";
			std::cin >> eachPlay;
			std::cout << "Each drawing there will be " << eachPlay << " plays." << std::endl;
		} else if(command == "end" || command == "exit") {
			std::cout << "Exiting program" << std::endl;
			end = true; 
		}

	}
}