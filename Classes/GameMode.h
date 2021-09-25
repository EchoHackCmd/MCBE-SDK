#ifndef INCLUDES_MCBE_SDK_CLASSES_GAMEMODE
#define INCLUDES_MCBE_SDK_CLASSES_GAMEMODE

class GameMode {
public:
    Player* player;
private:
    virtual ~GameMode();
public:
    virtual auto startDestroyBlock(Vec3<int>*, UCHAR, bool*) -> bool;
    virtual auto destroyBlock(Vec3<int>*, UCHAR) -> bool;
    virtual auto continueDestroyBlock(Vec3<int>*, UCHAR, Vec3<float>*, bool*) -> bool;
    virtual auto stopDestroyBlock(Vec3<int>*) -> void;
    virtual auto startBuildBlock(Vec3<int>*, UCHAR) -> void;
    virtual auto buildBlock(Vec3<int>*, UCHAR, bool) -> bool;
    virtual auto continueBuildBlock(Vec3<int>*, UCHAR) -> void;
    virtual auto stopBuildBlock(void) -> void;
    virtual auto tick(void) -> void;
    virtual auto getPickRange(InputMode*, bool) -> float;
    virtual auto useItem(ItemStack*) -> bool;
    virtual auto useItemOn(ItemStack*, Vec3<int>*, UCHAR, Vec3<float>*, Block*) -> bool;
    virtual auto interact(Actor*, Vec3<float>*) -> bool;
    virtual auto attack(Actor*) -> bool;
    virtual auto releaseUsingItem(void) -> void;
};

#endif /* INCLUDES_MCBE_SDK_CLASSES_GAMEMODE */
