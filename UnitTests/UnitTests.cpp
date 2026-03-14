#include "pch.h"
#include "CppUnitTest.h"

#include "../SliderGame/Board.hpp"
#include "../SliderGame/SlidingTilesData.hpp"
#include "../SliderGame/SlidingTilesEnums.hpp"
#include "../SliderGame/SlidingTilesFunctions.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace SlidingTilesEnums;
using namespace SlidingTilesData;

namespace UnitTests
{
	TEST_CLASS(StartGame) {
	public:
		
		TEST_METHOD(EasyDifficulty) {
			size_t size = 3;
			SlidingTilesFunctions::startGame(Difficulty::EASY);
			Assert::AreEqual(boardSize, size);
			Assert::AreEqual(currentColumn, currentRow);
			Assert::AreEqual(currentColumn, size - 1);
			Assert::AreEqual(slides, 0);
		}

		TEST_METHOD(MediumDifficulty) {
			size_t size = 4;
			SlidingTilesFunctions::startGame(Difficulty::MEDIUM);
			Assert::AreEqual(boardSize, size);
			Assert::AreEqual(currentColumn, currentRow);
			Assert::AreEqual(currentColumn, size - 1);
			Assert::AreEqual(slides, 0);
		}

		TEST_METHOD(HardDifficulty) {
			size_t size = 6;
			SlidingTilesFunctions::startGame(Difficulty::HARD);
			Assert::AreEqual(boardSize, size);
			Assert::AreEqual(currentColumn, currentRow);
			Assert::AreEqual(currentColumn, size - 1);
			Assert::AreEqual(slides, 0);
		}

		TEST_METHOD(InsaneDifficulty) {
			size_t size = 9;
			SlidingTilesFunctions::startGame(Difficulty::INSANE);
			Assert::AreEqual(boardSize, size);
			Assert::AreEqual(currentColumn, currentRow);
			Assert::AreEqual(currentColumn, size - 1);
			Assert::AreEqual(slides, 0);
		}

	};

	TEST_CLASS(Slide) {
		
		TEST_METHOD(UpDirection) {
			SlidingTilesFunctions::startGame(Difficulty::EASY);
			bool pass1 = SlidingTilesFunctions::slide(Direction::UP);
			bool pass2 = SlidingTilesFunctions::slide(Direction::UP);

			Assert::IsTrue(pass1);
			Assert::IsTrue(pass2);

			Assert::AreEqual(static_cast<size_t>(6), board.access(2, 2));
			Assert::AreEqual(static_cast<size_t>(3), board.access(2, 1));
			Assert::AreEqual(static_cast<size_t>(9), board.access(2, 0));
		}

		TEST_METHOD(LeftDirection) {
			SlidingTilesFunctions::startGame(Difficulty::EASY);
			bool pass1 = SlidingTilesFunctions::slide(Direction::LEFT);
			bool pass2 = SlidingTilesFunctions::slide(Direction::LEFT);

			Assert::IsTrue(pass1);
			Assert::IsTrue(pass2);

			Assert::AreEqual(static_cast<size_t>(8), board.access(2, 2));
			Assert::AreEqual(static_cast<size_t>(7), board.access(1, 2));
			Assert::AreEqual(static_cast<size_t>(9), board.access(0, 2));
		}

		TEST_METHOD(DownDirection) {
			SlidingTilesFunctions::startGame(Difficulty::EASY);
			currentColumn = currentRow = 0; //This would be a logical error under normal circumstances
			bool pass1 = SlidingTilesFunctions::slide(Direction::DOWN);
			bool pass2 = SlidingTilesFunctions::slide(Direction::DOWN);

			Assert::IsTrue(pass1);
			Assert::IsTrue(pass2);

			Assert::AreEqual(static_cast<size_t>(4), board.access(0, 0));
			Assert::AreEqual(static_cast<size_t>(7), board.access(0, 1));
			Assert::AreEqual(static_cast<size_t>(1), board.access(0, 2));
		}

		TEST_METHOD(RightDirection) {
			SlidingTilesFunctions::startGame(Difficulty::EASY);
			currentColumn = currentRow = 0; //This would be a logical error under normal circumstances
			bool pass1 = SlidingTilesFunctions::slide(Direction::RIGHT);
			bool pass2 = SlidingTilesFunctions::slide(Direction::RIGHT);

			Assert::IsTrue(pass1);
			Assert::IsTrue(pass2);

			Assert::AreEqual(static_cast<size_t>(2), board.access(0, 0));
			Assert::AreEqual(static_cast<size_t>(3), board.access(1, 0));
			Assert::AreEqual(static_cast<size_t>(1), board.access(2, 0));
		}

	};

	TEST_CLASS(IsBoardOrdered) {

		TEST_METHOD(Easy_True) {
			SlidingTilesFunctions::startGame(Difficulty::EASY);
			Assert::IsTrue(SlidingTilesFunctions::isBoardOrdered());
		}

		TEST_METHOD(Easy_False) {
			SlidingTilesFunctions::startGame(Difficulty::EASY);
			SlidingTilesFunctions::slide(Direction::UP);
			SlidingTilesFunctions::slide(Direction::LEFT);
			SlidingTilesFunctions::slide(Direction::DOWN);
			SlidingTilesFunctions::slide(Direction::RIGHT);
			Assert::IsFalse(SlidingTilesFunctions::isBoardOrdered());
		}

		TEST_METHOD(Medium_True) {
			SlidingTilesFunctions::startGame(Difficulty::MEDIUM);
			Assert::IsTrue(SlidingTilesFunctions::isBoardOrdered());
		}

		TEST_METHOD(Medium_False) {
			SlidingTilesFunctions::startGame(Difficulty::MEDIUM);
			SlidingTilesFunctions::slide(Direction::UP);
			SlidingTilesFunctions::slide(Direction::LEFT);
			SlidingTilesFunctions::slide(Direction::DOWN);
			SlidingTilesFunctions::slide(Direction::RIGHT);
			Assert::IsFalse(SlidingTilesFunctions::isBoardOrdered());
		}

		TEST_METHOD(Hard_True) {
			SlidingTilesFunctions::startGame(Difficulty::HARD);
			Assert::IsTrue(SlidingTilesFunctions::isBoardOrdered());
		}

		TEST_METHOD(Hard_False) {
			SlidingTilesFunctions::startGame(Difficulty::HARD);
			SlidingTilesFunctions::slide(Direction::UP);
			SlidingTilesFunctions::slide(Direction::LEFT);
			SlidingTilesFunctions::slide(Direction::DOWN);
			SlidingTilesFunctions::slide(Direction::RIGHT);
			Assert::IsFalse(SlidingTilesFunctions::isBoardOrdered());
		}

		TEST_METHOD(Insane_True) {
			SlidingTilesFunctions::startGame(Difficulty::INSANE);
			Assert::IsTrue(SlidingTilesFunctions::isBoardOrdered());
		}

		TEST_METHOD(Insane_False) {
			SlidingTilesFunctions::startGame(Difficulty::INSANE);
			SlidingTilesFunctions::slide(Direction::UP);
			SlidingTilesFunctions::slide(Direction::LEFT);
			SlidingTilesFunctions::slide(Direction::DOWN);
			SlidingTilesFunctions::slide(Direction::RIGHT);
			Assert::IsFalse(SlidingTilesFunctions::isBoardOrdered());
		}

	};
}
