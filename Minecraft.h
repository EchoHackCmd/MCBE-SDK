#ifndef MINECRAFT
#define MINECRAFT

#include "Classes/ClientInstance.h"
#include "Math/Math.h"
#include "Mem/Mem.h"

class Minecraft {
private:
    static ClientInstance* cachedInstance;
public:
    static auto getClientInstance() -> ClientInstance*;
    static auto getHardCodedInstancePtr() -> ClientInstance*;
};

#endif /* MINECRAFT */