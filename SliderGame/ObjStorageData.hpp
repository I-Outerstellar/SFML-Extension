#pragma once
#include <unordered_set>
#include <memory>
#include "GameButton.hpp"

namespace ObjectStorage {
	extern std::unordered_set<std::shared_ptr<GameButton>> buttons;
}
