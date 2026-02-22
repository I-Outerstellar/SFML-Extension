#include "ObjStorageControl.hpp"
#include <memory>

void ObjectStorageControl::addButton(std::shared_ptr<GameButton>& button) {
	ObjectStorage::buttons.insert(button);
}

void ObjectStorageControl::removeButton(std::shared_ptr<GameButton>& button) {
	ObjectStorage::buttons.erase(button);
}

void ObjectStorageControl::addShape(std::shared_ptr<GameShape>& shape) {
	ObjectStorage::shapes.insert(shape);
}

void ObjectStorageControl::removeShape(std::shared_ptr<GameShape>& shape) {
	ObjectStorage::shapes.erase(shape);
}