#include "GameManager.h"


bool GameManager::GameEnding(PointCounter& Red, PointCounter& Green, PointCounter& Blue, PointCounter& Yellow)
{


	if (Red.GetScore() > 9 || Green.GetScore() > 9 || Blue.GetScore() > 9 || Yellow.GetScore() > 9)
	{
		if (Red.GetScore() > 9) {
			std::cout << "RED WON" << "\n";
		}
		if (Green.GetScore() > 9) {
			std::cout << "GREEN WON" << "\n";
		}
		if (Blue.GetScore() > 9) {
			std::cout << "BLUE WON" << "\n";
		}
		if (Yellow.GetScore() > 9) {
			std::cout << "YELLOW WON" << "\n";
		}
		//std::cout << Yellow.GetScore() << "\n";
		return true;

	}

	return false;


};