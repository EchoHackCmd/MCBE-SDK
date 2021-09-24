#ifndef CLASSES_CLIENTINSTANCE
#define CLASSES_CLIENTINSTANCE

#include "../Math/Math.h"
#include "../Mem/Mem.h"

#include "Player.h"
#include "BlockSource.h"
#include "Block.h"

class ClientInstance {
private:
    uintptr_t* VTable;
public:
    auto getPlayer() -> Player*;
public:
    auto grabMouse() -> void;
    auto releaseMouse() -> void;
};

#endif /* CLASSES_CLIENTINSTANCE */