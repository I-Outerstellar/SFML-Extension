#include "ObjStorageControl.hpp"
#include "ObjStorageData.hpp"
#include <memory>

void ObjectStorageControl::addButton(std::shared_ptr<GameButton>& button) {
	ObjectStorage::buttons.insert(button);
}

void ObjectStorageControl::removeButton(std::shared_ptr<GameButton>& button) {
	ObjectStorage::buttons.erase(button);
}