#pragma once
#include <set>
#include <memory>

class GameButton;
class GameShape;

struct CompareButtonZIndex {
	bool operator()(const std::shared_ptr<GameButton>& button1, const std::shared_ptr<GameButton>& button2) const;
};

struct CompareShapeZIndex {
	bool operator()(const std::shared_ptr<GameShape>& shape1, const std::shared_ptr<GameShape>& shape2) const;
};

namespace ObjectStorage {
	extern std::set<std::shared_ptr<GameButton>, CompareButtonZIndex> buttons;
	extern std::set<std::shared_ptr<GameShape>, CompareShapeZIndex> shapes;
}
