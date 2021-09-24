#include "Minecraft.h"

ClientInstance* Minecraft::cachedInstance = nullptr;

ClientInstance* Minecraft::getClientInstance(){
    return cachedInstance;
};

ClientInstance* Minecraft::getHardCodedInstancePtr(){ /* 1.17.30 */
    auto baseAddr = (uintptr_t)GetModuleHandleA("Minecraft.Windows.exe");
    auto ptr = (uintptr_t)(baseAddr) + 0x04112A48;
    return (ClientInstance*)Mem::findMultiLvlPtr(ptr, { 0x10, 0x50, 0x0 });
};