#pragma once
#include <vector>
#include <utility>
#include <map>

namespace App1 {
	public enum class GameSide { White, Brown };
	public enum class ChipType {Regular, Queen};
	ref struct Chip {
	internal:
		ChipType type;
		GameSide colour;
	};
	ref struct Cell {
	internal:
		Chip^ chip = nullptr;
	};
	ref struct Move {
	internal:
		std::pair<int, int> fromXY;
		bool isCutting = false;
		Chip^ cuttedChip = nullptr;
		std::pair<int, int> toXY;
	};
	ref class Board sealed
	{
	internal:
		void move(std::vector<Move^>* moves);
		void moveFromJson(Windows::Data::Json::JsonObject^ jsonMove);
		static Board^ getInstance();
		void populateBoard(GameSide side);
		void moveAvailibilityPass();
	internal:
		std::vector<Move^>* findMovesForCurrentChip(std::pair<int, int> chip, std::pair<int,int> exclude, ChipType type);
		std::map<std::pair<int, int>, std::vector<Move^>*>* getMoveAvailibilityPassMap();
		std::vector<std::vector<Cell^>*>* getCellBoard();
	private:
		Board();
		GameSide mGameSide;
		static Board^ mInstance;
		std::map<std::pair<int, int>, std::vector<Move^>*>* mMoveAvailibilityPassMap;
		std::vector<std::vector<Cell^>*>* mCellBoard;
	};
}

