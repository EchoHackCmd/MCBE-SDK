#ifndef CLASSES_PLAYER
#define CLASSES_PLAYER

struct TextureUVCoordinateSet;

#include "Actor.h"

class Player : public Actor {
private:
    virtual auto Function275(void) -> void;
public:
    virtual auto knockback(Actor*, int, float, float, float, float, float) -> void;
private:
    virtual auto Function277(void) -> void;
public:
    virtual auto setSprinting(bool) -> void;
    virtual auto getHurtSound(void) -> LevelSoundEvent;
    virtual auto getDeathSound(void) -> LevelSoundEvent;
    virtual auto getItemInHandIcon(ItemStack*, int) -> TextureUVCoordinateSet;
    virtual auto getSpeed(void) -> float;
    virtual auto setSpeed(float) -> void;
    virtual auto getJumpPower(void) -> float;
    virtual auto hurtEffects(ActorDamageSource*, int, bool, bool) -> bool;
};

#endif /* CLASSES_PLAYER */