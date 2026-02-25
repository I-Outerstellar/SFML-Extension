#pragma once
#include <vector>
#include <memory>

class GameButton;
class GameShape;

namespace ObjectStorage {
	extern std::vector<std::shared_ptr<GameButton>> buttons;
	extern std::vector<std::shared_ptr<GameShape>> shapes;
}
