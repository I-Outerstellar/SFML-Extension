#pragma once
#include <unordered_set>
#include <memory>

class GameButton;
class GameShape;

namespace ObjectStorage {
	extern std::unordered_set<std::shared_ptr<GameButton>> buttons;
	extern std::unordered_set<std::shared_ptr<GameShape>> shapes;
}
