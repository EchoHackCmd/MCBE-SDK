#include "ClientInstance.h"

Player* ClientInstance::getPlayer(){
    static unsigned int offset = NULL;
    
    if(offset == NULL)
        offset = *reinterpret_cast<int*>(Mem::findSig("48 ? ? ? ? ? ? 48 85 C0 ? ? 48 81 C1 ? ? ? ? B2 ? E9") + 3) + 8;
    
    return *reinterpret_cast<Player**>((uintptr_t)(this) + offset);
};

void ClientInstance::grabMouse(){
    using GrabMouse = void (__thiscall*)(ClientInstance*);
    static GrabMouse _GrabMouse = reinterpret_cast<GrabMouse>(VTable[270]);
    _GrabMouse(this);
};

void ClientInstance::releaseMouse(){
    using ReleaseMouse = void (__thiscall*)(ClientInstance*);
    static ReleaseMouse _ReleaseMouse = reinterpret_cast<ReleaseMouse>(VTable[271]);
    _ReleaseMouse(this);
};