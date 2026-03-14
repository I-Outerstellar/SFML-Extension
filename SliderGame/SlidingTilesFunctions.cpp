#include "SlidingTilesFunctions.hpp"
#include "SlidingTilesData.hpp"
#include <random>
#include <limits>

static SlidingTilesEnums::Direction getRandomDirection() {
	std::random_device randomDevice;
	std::mt19937 generator(randomDevice());
	std::uniform_int_distribution<int> dist(1, 4);
	int randomNumber = dist(generator);

	switch (randomNumber) {
	using namespace SlidingTilesEnums;
	case 1: return Direction::DOWN;
	case 2: return Direction::UP;
	case 3: return Direction::LEFT;
	case 4: return Direction::RIGHT;
	default: return Direction::UP;
	}
}

namespace SlidingTilesFunctions {

	void startGame(SlidingTilesEnums::Difficulty difficulty) {
		SlidingTilesData::board = Board(difficulty);
		SlidingTilesData::boardSize = static_cast<int>(difficulty);
		SlidingTilesData::currentColumn = SlidingTilesData::currentRow = static_cast<int>(difficulty) - 1;
		SlidingTilesData::slides = 0;
	}

	bool slide(SlidingTilesEnums::Direction direction) {
		using namespace SlidingTilesData;
		bool canSlide = false;

		//Determine if a slide can occur in the desired direction
		switch (direction) {
		case SlidingTilesEnums::Direction::DOWN:
			canSlide = board.canAccess(currentColumn, currentRow + 1);
			break;
		case SlidingTilesEnums::Direction::UP:
			canSlide = board.canAccess(currentColumn, currentRow - 1);
			break;
		case SlidingTilesEnums::Direction::LEFT:
			canSlide = board.canAccess(currentColumn - 1, currentRow);
			break;
		case SlidingTilesEnums::Direction::RIGHT:
			canSlide = board.canAccess(currentColumn + 1, currentRow);
			break;
		}

		if (!canSlide) return false;

		//Slide the desired square to the empty square
		switch (direction) {
		case SlidingTilesEnums::Direction::DOWN:
			std::swap(board.access(currentColumn, currentRow), board.access(currentColumn, currentRow + 1));
			currentRow += 1;
			break;
		case SlidingTilesEnums::Direction::UP:
			std::swap(board.access(currentColumn, currentRow), board.access(currentColumn, currentRow - 1));
			currentRow -= 1;
			break;
		case SlidingTilesEnums::Direction::LEFT:
			std::swap(board.access(currentColumn, currentRow), board.access(currentColumn - 1, currentRow));
			currentColumn -= 1;
			break;
		case SlidingTilesEnums::Direction::RIGHT:
			std::swap(board.access(currentColumn, currentRow), board.access(currentColumn + 1, currentRow));
			currentColumn += 1;
			break;
		}
		return true;
	}

	void shuffle() {
		size_t totalSlides = SlidingTilesData::boardSize * std::pow(10, static_cast<int>(SlidingTilesData::boardSize / 2));

		SlidingTilesEnums::Direction direction = SlidingTilesEnums::Direction::RIGHT;
		while (totalSlides >= 0) {
			SlidingTilesEnums::Direction next = getRandomDirection();
			if (next == direction) continue;
			if (!slide(next)) continue;
			direction = next;
			totalSlides--;
		}

		while (SlidingTilesData::currentColumn != SlidingTilesData::boardSize - 1) slide(SlidingTilesEnums::Direction::DOWN);
		while (SlidingTilesData::currentRow != SlidingTilesData::boardSize - 1) slide(SlidingTilesEnums::Direction::RIGHT);
	}

	bool isBoardOrdered() {
		for (size_t column = 0; column < SlidingTilesData::boardSize; column++) {
			for (size_t row = 0; row < SlidingTilesData::boardSize; row++) {
				if (SlidingTilesData::board.access(column, row) != SlidingTilesData::boardSize * row + column + 1)
					return false;
			}
		}
		return true;
	}

	
}