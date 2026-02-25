#include "ObjStorageData.hpp"
#include "GameShape.hpp"
#include "GameButton.hpp"

std::vector<std::shared_ptr<GameButton>> ObjectStorage::buttons{};
std::vector<std::shared_ptr<GameShape>> ObjectStorage::shapes{};