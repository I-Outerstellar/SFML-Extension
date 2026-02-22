#include <memory>
#include "ObjStorageData.hpp"

namespace ObjectStorageControl {
	void addButton(std::shared_ptr<GameButton>& button);
	void removeButton(std::shared_ptr<GameButton>& button);
	void addShape(std::shared_ptr<GameShape>& shape);
	void removeShape(std::shared_ptr<GameShape>& shape);
}