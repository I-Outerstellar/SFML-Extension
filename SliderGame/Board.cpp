#include "Board.hpp"

Board::Board() noexcept { this->board.clear(); }

Board::Board(SlidingTilesEnums::Difficulty difficulty) noexcept {
	this->board.clear();
	int boardSize = static_cast<int>(difficulty);
	this->board.reserve(boardSize);

	for (int column = 0; column < boardSize; column++) {
		std::vector<size_t> columnVector{};
		columnVector.reserve(boardSize);
		for (int row = 0; row < boardSize; row++) {
			columnVector.push_back(boardSize * row + column + 1);
		}
		this->board.push_back(columnVector);
	}
}

bool Board::hasEmptyColumn() const noexcept {
	if (this->board.size() <= 0) return false;
	for (int i = 0; i < board.size(); i++) {
		if (board.at(i).size() <= 0) return false;
	}
	return true;
}

std::vector<size_t>& Board::access(size_t column) {
	return this->board.at(column);
}

size_t& Board::access(size_t column, size_t row) {
	return this->access(column).at(row);
}

bool Board::canAccess(size_t column) const noexcept {
	return (column >= 0 && column < this->board.size());
}

bool Board::canAccess(size_t column, size_t row) const noexcept {
	if (!canAccess(column)) return false;
	size_t size = this->board.at(column).size();
	return (row >= 0 && row < size);
}