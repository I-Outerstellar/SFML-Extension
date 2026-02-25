#include "ObjStorageControl.hpp"
#include "GameButton.hpp"
#include "GameShape.hpp"
#include <memory>
#include <algorithm>

void ObjectStorageControl::addButton(std::shared_ptr<GameButton>& button) {
	ObjectStorage::buttons.push_back(button);

	for (size_t i = ObjectStorage::buttons.size() - 1; i >= 1; i--) {
		if (ObjectStorage::buttons.at(i - 1)->getZIndex() < ObjectStorage::buttons.at(i)->getZIndex())
			std::swap(ObjectStorage::buttons.at(i - 1), ObjectStorage::buttons.at(i));
	}
}

void ObjectStorageControl::removeButton(std::shared_ptr<GameButton>& button) {
	auto iter = std::find(ObjectStorage::buttons.begin(), ObjectStorage::buttons.end(), button);
	if (iter != ObjectStorage::buttons.end())
		ObjectStorage::buttons.erase(iter);
}

void ObjectStorageControl::addShape(std::shared_ptr<GameShape>& shape) {
	ObjectStorage::shapes.push_back(shape);

	for (size_t i = ObjectStorage::shapes.size() - 1; i >= 1; i--) {
		if (ObjectStorage::shapes.at(i - 1)->getZIndex() < ObjectStorage::shapes.at(i)->getZIndex())
			std::swap(ObjectStorage::shapes.at(i - 1), ObjectStorage::shapes.at(i));
	}
}

void ObjectStorageControl::removeShape(std::shared_ptr<GameShape>& shape) {
	auto iter = std::find(ObjectStorage::shapes.begin(), ObjectStorage::shapes.end(), shape);
	if (iter != ObjectStorage::shapes.end())
		ObjectStorage::shapes.erase(iter);
}