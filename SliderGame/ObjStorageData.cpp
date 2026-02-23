#include "ObjStorageData.hpp"
#include "GameShape.hpp"
#include "GameButton.hpp"

bool CompareButtonZIndex::operator()(const std::shared_ptr<GameButton>& button1, const std::shared_ptr<GameButton>& button2) const {
	return button1->getZIndex() < button2->getZIndex();
}

bool CompareShapeZIndex::operator()(const std::shared_ptr<GameShape>& shape1, const std::shared_ptr<GameShape>& shape2) const {
	return shape1->getZIndex() < shape2->getZIndex();
}

std::set<std::shared_ptr<GameButton>, CompareButtonZIndex> ObjectStorage::buttons{};
std::set<std::shared_ptr<GameShape>, CompareShapeZIndex> ObjectStorage::shapes{};