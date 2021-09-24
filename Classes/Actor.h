#ifndef INCLUDES_SDK_CLASSES_ACTOR
#define INCLUDES_SDK_CLASSES_ACTOR

class Player;
class Actor;

enum InitializationMethod;
class VariantParameterList;
enum ActorType;
struct PredictedMovementValues;
enum ActorLocation;
struct IActorMovementProxy;
struct ActorDamageSource;
enum InputMode;
struct UIProfanityContext;
enum MaterialType;
enum ActorDamageCause;
struct ActorUniqueID;
enum LevelSoundEvent;
enum ActorEvent;
struct HashedString;
enum ArmorSlot;
enum ArmorMaterialType;
enum ArmorTextureType;
enum EquipmentSlot;
struct CompoundTag;
class DataLoadHelper;
struct ActorLink;
enum CommandPermissionLevel;
struct AttributeInstance;
struct Attribute;
struct MobEffectInstance;
struct AnimationComponent;
enum ItemUseMethod;
struct ActorInteraction;
struct EquipmentTableDefinition;
struct PlayerSnapshotComponent;
struct LootTable;
struct RenderParams;
enum AnimationComponentGroup;

#include "Mob.h"

#include "BlockSource.h"
#include "Block.h"
#include "ItemStack.h"

class Actor {
public:
    void setFlightSpeed(float speed){
        static unsigned int offset = NULL;

        if(offset == NULL)
            offset = *reinterpret_cast<int*>(Mem::findSig("F3 0F 11 88 ? ? ? ? C3 CC CC CC 48 8B 41 10 F3 0F 10 80 ? ? ? ? C3 CC CC CC 48 83") + 4);
        
        if(offset > 10)
            *(float*)((uintptr_t)(this) + offset) = speed;
    };
private:
    virtual auto Constructor(void) -> void;
public:
    virtual auto getLastHurtByMob(void) -> Mob*;
    virtual auto setLastHurtByMob(Mob*) -> void;
    virtual auto getLastHurtByPlayer(void) -> Player*;
    virtual auto setLastHurtByPlayer(Player*) -> void;
    virtual auto getLastHurtMob(void) -> Mob*;
    virtual auto setLastHurtMob(Actor*) -> void;
    virtual auto outOfWorld(void) -> bool;
    virtual auto reloadHardcoded(InitializationMethod, VariantParameterList const &) -> void;
    virtual auto reloadHardcodedClient(InitializationMethod, VariantParameterList const &) -> void;
    virtual auto initializeComponents(InitializationMethod, VariantParameterList const &) -> void;
    virtual auto reloadComponents(InitializationMethod, VariantParameterList const &) -> void;
    virtual auto _serverInitItemStackIds(void) -> void;
    virtual auto _doInitialMove(void) -> void;
private:
    virtual auto Function13(void) -> void;
public:
    virtual auto reset(void) -> void;
    virtual auto getOnDeathExperience(void) -> __int64;
    virtual auto getOwnerEntityType(void) -> ActorType;
    virtual auto remove(void) -> void;
    virtual auto setPos(Vec3<float>*) -> void;
private:
    virtual auto Function19(void) -> void;
public:
    virtual auto getPredictedMovementValues(void) -> PredictedMovementValues*;
    virtual auto getPos(void) -> Vec3<float>*;
    virtual auto getPosOld(void) -> Vec3<float>*;
    virtual auto getPosExtrapolated(float) -> Vec3<float>*;
    virtual auto getAttachPos(ActorLocation, float) -> Vec3<float>*;
    virtual auto getFiringPos(void) -> Vec3<float>*;
    virtual auto setRot(Vec2<float>*) -> void;
    virtual auto move(IActorMovementProxy*, Vec3<float>*) -> void;
    virtual auto move(Vec3<float>*) -> void;
    virtual auto getInterpolatedRidingPosition(float) -> Vec3<float>*;
    virtual auto getInterpolatedBodyRot(float) -> float;
    virtual auto getInterpolatedHeadRot(float) -> float;
    virtual auto getInterpolatedBodyYaw(float) -> float;
    virtual auto getYawSpeedInDegreesPerSecond(void) -> float;
    virtual auto getInterpolatedWalkAnimSpeed(float) -> float;
    virtual auto getWorldPosition(void) -> Vec3<float>*;
    virtual auto checkBlockCollisions(AABB<float> const &, std::function<void (BlockSource &, Block const &, Vec3<int> const &, Actor &)>) -> void;
    virtual auto updateEntityInside(void) -> void;
    virtual auto updateEntityInside(AABB<float>*) -> void;
    virtual auto isFireImmune(void) -> bool;
private:
    virtual auto Function40(void) -> void;
public:
    virtual auto blockedByShield(ActorDamageSource*, Actor*) -> void;
    virtual auto teleportTo(Vec3<float>*, bool, int, int) -> void;
    virtual auto tryTeleportTo(Vec3<float>*, bool, bool, int, int) -> void;
    virtual auto chorusFruitTeleport(Vec3<float>*) -> void;
    virtual auto lerpTo(Vec3<float>*, Vec2<float>*, int) -> void;
    virtual auto lerpMotion(Vec3<float>*) -> void;
    virtual auto tryCreateAddActorPacket(void) -> __int64;
    virtual auto normalTick(void) -> void;
    virtual auto baseTick(void) -> void;
    virtual auto rideTick(void) -> void;
    virtual auto positionRider(Actor*,float) -> void;
    virtual auto getDuration(void) -> float;
    virtual auto startRiding(Actor*) -> void;
    virtual auto addRider(Actor*) -> void;
    virtual auto flagRiderToRemove(Actor*) -> void;
    virtual auto getExitTip(std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &, InputMode) -> std::string*;
    virtual auto intersects(Vec3<float>*, Vec3<float>*) -> bool;
    virtual auto isInWall(void) -> bool;
    virtual auto isInvisible(void) -> bool;
    virtual auto canShowNameTag(void) -> bool;
private:
    virtual auto Function61(void) -> void;
public:
    virtual auto setNameTagVisible(bool) -> void;
    virtual auto getNameTag(void) -> std::string*;
    virtual auto getNameTagAsHash(void) -> unsigned __int64;
    virtual auto getFormattedNameTag(void) -> std::string*;
    virtual auto filterFormattedNameTag(UIProfanityContext*) -> void;
    virtual auto setNameTag(std::string*) -> void;
private:
    virtual auto Function68(void) -> void;
public:
    virtual auto setScoreTag(std::string*) -> void;
    virtual auto getScoreTag(void) -> std::string*;
    virtual auto isInWater(void) -> bool;
    virtual auto hasEnteredWater(void) -> bool;
    virtual auto isInLava(void) -> bool;
    virtual auto isUnderLiquid(MaterialType) -> bool;
    virtual auto isOverWater(void) -> bool;
    virtual auto setBlockMovementSlowdownMultiplier(Vec3<float>*) -> bool;
    virtual auto resetBlockMovementSlowdownMultiplier(void) -> void;
private:
    virtual auto Function78(void) -> void;
public:
    virtual auto getShadowHeightOffs(void) -> float;
    virtual auto getShadowRadius(void) -> float;
    virtual auto getHeadLookVector(float) -> Vec3<float>*;
private:
    virtual auto Function82(void) -> void;
public:
    virtual auto canSee(Vec3<float>*) -> bool;
    virtual auto canSee(Actor*) -> bool;
    virtual auto isSkyLit(float) -> bool;
    virtual auto getBrightness(float) -> float;
private:
    virtual auto Function87(void) -> void;
    virtual auto Function88(void) -> void;
public:
    virtual auto onAboveBubbleColumn(bool) -> void;
    virtual auto onInsideBubbleColumn(bool) -> void;
    virtual auto isImmobile(void) -> bool;
    virtual auto isSilent(void) -> bool;
    virtual auto isPickable(void) -> bool;
private:
    virtual auto Function94(void) -> void;
public:
    virtual auto isSleeping(void) -> bool;
    virtual auto setSleeping(bool) -> void;
private:
    virtual auto Function97(void) -> void;
public:
    virtual auto setSneaking(bool) -> void;
    virtual auto isBlocking(void) -> void;
private:
    virtual auto Function100(void) -> void;
public: 
    virtual auto isAlive(void) -> bool;
    virtual auto isOnFire(void) -> bool;
    virtual auto isOnHotBlock(void) -> bool;
private:
    virtual auto Function104(void) -> void;
public:
    virtual auto isSurfaceMob(void) -> bool;
private:
    virtual auto Function106(void) -> void;
    virtual auto Function107(void) -> void;
    virtual auto Function108(void) -> void;
public:
    virtual auto isAffectedByWaterBottle(void) -> bool;
    virtual auto canAttack(Actor*, bool) -> bool;
    virtual auto setTarget(Actor*) -> void;
private:
    virtual auto Function112(void) -> void;
public:
    virtual auto isValidTarget(Actor*) -> bool;
    virtual auto attack(Actor*, ActorDamageCause*) -> void;
    virtual auto performRangedAttack(Actor*, float) -> void;
    virtual auto adjustDamageAmount(int*) -> void;
    virtual auto getEquipmentCount(void) -> __int64;
    virtual auto setOwner(ActorUniqueID) -> void;
    virtual auto setSitting(bool) -> void;
private:
    virtual auto Function120(void) -> void;
    virtual auto Function121(void) -> void;
public:
    virtual auto getInventorySize(void) -> __int64;
    virtual auto getEquipSlots(void) -> __int64;
    virtual auto getChestSlots(void) -> __int64;
    virtual auto setStanding(bool) -> void;
    virtual auto canPowerJump(void) -> bool;
    virtual auto setCanPowerJump(bool) -> void;
    virtual auto isJumping(void) -> bool;
    virtual auto isEnchanted(void) -> bool;
private:
    virtual auto Function130() -> void;
    virtual auto Function131() -> void;
public:
    virtual auto shouldRender(void) -> bool;
    virtual auto playAmbientSound(void) -> void;
    virtual auto getAmbientSound(void) -> LevelSoundEvent;
    virtual auto isInvulnerableTo(ActorDamageSource*) -> bool;
    virtual auto getBlockDamageCause(Block const &) -> ActorDamageCause;
    virtual auto actuallyHurt(int, ActorDamageSource*, bool) -> void;
    virtual auto animateHurt(void) -> void;
    virtual auto doFireHurt(int) -> void;
    virtual auto onLightningHit(void) -> void;
    virtual auto onBounceStarted(Vec3<int>*, Block*) -> void;
    virtual auto feed(int) -> void;
    virtual auto handleEntityEvent(ActorEvent, int) -> void;
    virtual auto getPickRadius(void) -> float;
    virtual auto getActorRendererId(void) -> HashedString*;
    virtual auto spawnAtLocation(ItemStack*, float) -> ItemActor*;
    virtual auto spawnAtLocation(Block*, int, float) -> ItemActor*;
    virtual auto spawnAtLocation(Block*, int) -> ItemActor*;
    virtual auto spawnAtLocation(int, int, float) -> ItemActor*;
    virtual auto spawnAtLocation(int, int) -> ItemActor*;
    virtual auto despawn(void) -> void;
    virtual auto killed(Actor*) -> void;
    virtual auto awardKillScore(Actor*, int) -> void;
    virtual auto setArmor(ArmorSlot, ItemStack*) -> void;
    virtual auto getArmor(ArmorSlot) -> ItemStack*;
    virtual auto getArmorMaterialTypeInSlot(ArmorSlot) -> ArmorMaterialType;
    virtual auto getArmorMaterialTextureTypeInSlot(ArmorSlot) -> ArmorTextureType;
    virtual auto getArmorColorInSlot(ArmorSlot, int) -> float;
    virtual auto getEquippedSlot(EquipmentSlot) -> ItemStack*;
    virtual auto setEquippedSlot(EquipmentSlot, ItemStack const &) -> void;
    virtual auto getCarriedItem(void) -> ItemStack*;
    virtual auto setCarriedItem(ItemStack*) -> void;
    virtual auto setOffhandSlot(ItemStack*) -> void;
    virtual auto getEquippedTotem(void) -> ItemStack*;
    virtual auto consumeTotem(void) -> void;
    virtual auto save(CompoundTag*) -> bool;
    virtual auto saveWithoutId(CompoundTag*) -> void;
    virtual auto load(CompoundTag*, DataLoadHelper*) -> bool;
    virtual auto loadLinks(CompoundTag const &, std::vector<ActorLink,std::allocator<ActorLink>> &, DataLoadHelper &) -> void;
    virtual auto getEntityTypeId(void) -> uint8_t;
private:
    virtual auto Function171(void) -> void;
public:
    virtual auto getSourceUniqueID(void) -> ActorUniqueID;
    virtual auto setOnFire(int) -> void;
    virtual auto extinguishFire(void) -> void;
    virtual auto thawFreezeEffect(void) -> void;
    virtual auto canFreeze(void) -> bool;
    virtual auto isWearingLeatherArmor(void) -> bool;
    virtual auto getLiquidAABB(MaterialType) -> AABB<float>;
    virtual auto handleInsidePortal(Vec3<int>*) -> void;
private:
    virtual auto Function180(void) -> void;
public:
    virtual auto getPortalWaitTime(void) -> __int64;
    virtual auto getDimensionId(void) -> int*;
    virtual auto canChangeDimensions(void) -> bool;
private:
    virtual auto Function184(void) -> void;
public:
    virtual auto changeDimension(__int64) -> void;
    virtual auto getControllingPlayer(void) -> ActorUniqueID;
    virtual auto checkFallDamage(float, bool) -> void;
    virtual auto causeFallDamage(float, float, ActorDamageSource) -> void;
    virtual auto handleFallDistanceOnServer(float, float, bool) -> void;
    virtual auto playSynchronizedSound(LevelSoundEvent, Vec3<float>*, int, bool) -> void;
    virtual auto playSynchronizedSound(LevelSoundEvent, Vec3<float>*, Block*, bool) -> void;
    virtual auto onSynchedDataUpdate(int) -> void;
    virtual auto canAddRider(Actor*) -> bool;
private:
    virtual auto Function194(void) -> void;
    virtual auto Function195(void) -> void;
public:
    virtual auto inCaravan(void) -> bool;
private:
    virtual auto Function198(void) -> void;
public:
    virtual auto tickLeash(void) -> void;
    virtual auto sendMotionPacketIfNeeded(void) -> void;
private:
    virtual auto Function201(void) -> void;
public:
    virtual auto stopRiding(bool, bool, bool) -> void;
    virtual auto startSwimming(void) -> void;
    virtual auto stopSwimming(void) -> void;
private:
    virtual auto Function205(void) -> void;
public:
    virtual auto getCommandPermissionLevel(void) -> CommandPermissionLevel;
    virtual auto isClientSide(void) -> bool;
    virtual auto getMutableAttribute(Attribute*) -> AttributeInstance*;
    virtual auto getAttribute(Attribute*) -> AttributeInstance*;
    virtual auto getDeathTime(void) -> __int64;
    virtual auto heal(int) -> void;
    virtual auto isInvertedHealAndHarm(void) -> bool;
    virtual auto canBeAffected(MobEffectInstance*) -> bool;
    virtual auto canBeAffected(int) -> bool;
    virtual auto canBeAffectedByArrow(MobEffectInstance*) -> bool;
    virtual auto onEffectAdded(MobEffectInstance*) -> void;
    virtual auto onEffectUpdated(MobEffectInstance*) -> void;
    virtual auto onEffectRemoved(MobEffectInstance*) -> void;
    virtual auto getAnimationComponent(void) -> AnimationComponent*;
    virtual auto openContainerComponent(Player*) -> void;
    virtual auto swing(void) -> void;
    virtual auto useItem(ItemStackBase &, ItemUseMethod, bool) -> void;
private:
    virtual auto Function223(void) -> void;
    virtual auto Function224(void) -> void;
    virtual auto Function225(void) -> void;
public:
    virtual auto getMapDecorationRotation(void) -> float;
    virtual auto getRiderYRotation(Actor*) -> float;
    virtual auto getYHeadRot(void) -> float;
    virtual auto isWorldBuilder(void) -> bool;
    virtual auto isInCreativeMode(void) -> bool;
    virtual auto isAdventure(void) -> bool;
    virtual auto add(ItemStack*) -> bool;
    virtual auto drop(ItemStack*, bool) -> bool;
    virtual auto getInteraction(Player*, ActorInteraction*, Vec3<float>*) -> bool;
private:
    virtual auto Function235(void) -> void;
    virtual auto Function236(void) -> void;
public:
    virtual auto setSize(float, float) -> void;
    virtual auto onOrphan(void) -> void;
    virtual auto wobble(void) -> void;
    virtual auto wasHurt(void) -> bool;
    virtual auto startSpinAttack(void) -> void;
    virtual auto stopSpinAttack(void) -> void;
    virtual auto setDamageNearbyMobs(bool) -> void;
private:
    virtual auto Function244(void) -> void;
public:
    virtual auto reloadLootTable(EquipmentTableDefinition*) -> void;
    virtual auto reloadLootTable(void) -> void;
private:
    virtual auto Function247(void) -> void;
public:
    virtual auto kill(void) -> void;
    virtual auto die(ActorDamageSource*) -> void;
    virtual auto shouldDropDeathLoot(void) -> bool;
    virtual auto shouldTick(void) -> bool;
    virtual auto extractSnapshot(PlayerSnapshotComponent*) -> void;
    virtual auto applySnapshot(PlayerSnapshotComponent*, PlayerSnapshotComponent*) -> void;
    virtual auto getNextStep(float) -> float;
    virtual auto getLootTable(void) -> LootTable*;
    virtual auto updateEntitySpecificMolangVariables(RenderParams*) -> void;
    virtual auto shouldTryMakeStepSound(void) -> bool;
private:
    virtual auto Function258(void) -> void;
public:
    virtual auto _hurt(ActorDamageSource*, int, bool, bool) -> void;
    virtual auto markHurt(void) -> void;
    virtual auto _getAnimationComponent(std::shared_ptr<AnimationComponent> &, AnimationComponentGroup) -> AnimationComponent;
    virtual auto readAdditionalSaveData(CompoundTag*, DataLoadHelper*) -> void;
    virtual auto addAdditionalSaveData(CompoundTag*) -> void;
    virtual auto _playStepSound(Vec3<int>*, Block*) -> void;
    virtual auto _playFlySound(Vec3<int>*, Block*) -> void;
private:
    virtual auto Function266(void) -> void;
public:
    virtual auto checkInsideBlocks(float) -> void;
    virtual auto pushOutOfBlocks(Vec3<float>*) -> void;
    virtual auto updateWaterState(void) -> void;
    virtual auto doWaterSplashEffect(void) -> void;
    virtual auto spawnTrailBubbles(void) -> void;
    virtual auto updateInsideBlock(void) -> void;
    virtual auto _removeRider(ActorUniqueID*, bool, bool, bool) -> void;
    virtual auto _onSizeUpdated(void) -> void;
};

#endif /* INCLUDES_SDK_CLASSES_ACTOR */