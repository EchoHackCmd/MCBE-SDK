#ifndef INCLUDES_MCBE_SDK_CLASSES_PLAYER
#define INCLUDES_MCBE_SDK_CLASSES_PLAYER

struct TextureUVCoordinateSet;
struct IMobMovementProxy;
class BodyControl;
struct ChunkSource;
struct Tick;
class ChunkPos;
enum CommandPermissionLevel;
class TextObjectRoot;
class ResolvedTextObject;
enum BedSleepingResult;
enum GameType { Survival = 0, Creative = 1, Adventure = 2, Default = 5 };
class IMinecraftEventing;
struct EventPacket;
class IContainerManager;
class Container;
class InventoryTransaction;
class ComplexInventoryTransaction;
class Packet;
class PlayerEventCoordinator;
class MoveInputHandler;
enum InputMode;
enum ClientPlayMode;
enum MovementEventType;

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
    virtual auto getMeleeWeaponDamageBonus(Mob*) -> __int64;
    virtual auto getMeleeKnockbackBonus(void) -> __int64;
    virtual auto travel(IMobMovementProxy*, float, float, float) -> void;
    virtual auto travel(float, float, float) -> void;
    virtual auto applyFinalFriction(float, bool) -> void;
    virtual auto updateWalkAnim(void) -> void;
    virtual auto aiStep(IMobMovementProxy*) -> void;
    virtual auto aiStep(void) -> void;
    virtual auto pushActors(void) -> void;
    virtual auto lookAt(Actor *, float, float) -> void;
    virtual auto isLookingAtAnEntity(void) -> bool;
    virtual auto checkSpawnRules(bool) -> bool;
    virtual auto checkSpawnObstruction(void) -> bool;
    virtual auto getAttackAnim(float) -> float;
    virtual auto getItemUseDuration(void) -> __int64;
    virtual auto getItemUseStartupProgress(void) -> float;
    virtual auto getItemUseIntervalProgress(void) -> float;
    virtual auto getItemUseIntervalAxis(void) -> __int64;
    virtual auto getTimeAlongSwing(void) -> __int64;
private:
    virtual auto Function305(void) -> void;
public:
    virtual auto getMaxHeadXRot(void) -> float;
private:
    virtual auto Function307(void) -> void;
public:
    virtual auto doHurtTarget(Actor*, ActorDamageCause*) -> void;
private:
    virtual auto Function309(void) -> void;
public:
    virtual auto leaveCaravan(void) -> void;
    virtual auto joinCaravan(Mob*) -> void;
    virtual auto hasCaravanTail(void) -> bool;
    virtual auto getCaravanHead(void) -> ActorUniqueID;
    virtual auto getArmorValue(void) -> __int64;
    virtual auto getArmorCoverPercentage(void) -> float;
    virtual auto hurtArmorSlots(ActorDamageSource*, int,std::bitset<4> const &) -> __int64;
    virtual auto setDamagedArmor(ArmorSlot, ItemStack*) -> void;
    virtual auto sendArmorDamage(std::bitset<4>*) -> __int64;
    virtual auto sendArmor(std::bitset<4>*) -> void;
    virtual auto containerChanged(int) -> void;
    virtual auto updateEquipment(void) -> void;
    virtual auto clearEquipment(void) -> void;
    virtual auto getAllArmor(void) -> std::vector<ItemStack*>;
    virtual auto getAllArmorID(void) -> __int64;
    virtual auto getAllHand(void) -> __int64;
    virtual auto getAllEquipment(void) -> __int64;
    virtual auto getArmorTypeHash(void) -> __int64;
    virtual auto dropEquipmentOnDeath(void) -> void;
    virtual auto dropEquipmentOnDeath(ActorDamageSource*, int) -> void;
    virtual auto clearVanishEnchantedItemsOnDeath(void) -> void;
    virtual auto sendInventory(bool) -> void;
    virtual auto getDamageAfterMagicAbsorb(ActorDamageSource*, int) -> void;
    virtual auto createAIGoals(void) -> bool;
private:
    virtual auto Function334(void) -> void;
public:
    virtual auto setItemSlot(EquipmentSlot, ItemStack*) -> bool;
    virtual auto setTransitioningSitting(bool) -> void;
    virtual auto attackAnimation(Actor*, float) -> void;
    virtual auto getAttackTime(void) -> int;
private:
    virtual auto Function339(void) -> void;
    virtual auto Function340(void) -> void;
    virtual auto Function341(void) -> void;
public:
    virtual auto ascendLadder(void) -> void;
    virtual auto ascendBlockByJumping(void) -> void;
    virtual auto descendBlockByCrouching(void) -> void;
    virtual auto dropContainer(void) -> void;
    virtual auto initBodyControl(void) -> std::unique_ptr<BodyControl, struct std::default_delete<BodyControl>>;
    virtual auto jumpFromGround(IMobMovementProxy*) -> void;
    virtual auto jumpFromGround(void) -> void;
    virtual auto updateAi(void) -> void;
    virtual auto newServerAiStep(void) -> void;
private:
    virtual auto Function351(void) -> void;
public:
    virtual auto getDamageAfterEnchantReduction(ActorDamageSource*, int) -> __int64;
    virtual auto getDamageAfterArmorAbsorb(ActorDamageSource*, int) -> int;
    virtual auto dropBags(void) -> void;
    virtual auto tickDeath(void) -> void;
    virtual auto updateGliding(void) -> void;
private:
    virtual auto Function357(void) -> void;
public:
    virtual auto prepareRegion(ChunkSource*) -> void;
    virtual auto destroyRegion(void) -> void;
    virtual auto suspendRegion(void) -> void;
    virtual auto resendAllChunks(void) -> void;
    virtual auto _fireWillChangeDimension(void) -> bool;
    virtual auto _fireDimensionChanged(void) -> void;
    virtual auto changeDimensionWithCredits(__int64) -> void;
    virtual auto tickWorld(Tick*) -> void;
private:
    virtual auto Function366(void) -> void;
public:
    virtual auto getTickingOffsets(void) -> std::vector<ChunkPos, class std::allocator<ChunkPos>>;
    virtual auto moveView(void) -> void;
    virtual auto setName(std::string*) -> void;
    virtual auto checkMovementStats(Vec3<float>*) -> void;
private:
    virtual auto Function371(void) -> void;
    virtual auto Function372(void) -> void;
public:
    virtual auto respawn(void) -> void;
    virtual auto resetRot(void) -> void;
    virtual auto resetPos(bool) -> void;
private:
    virtual auto Function376(void) -> void;
public:
    virtual auto hasResource(int) -> bool;
    virtual auto completeUsingItem(void) -> void;
    virtual auto setPermissions(CommandPermissionLevel) -> void;
    virtual auto startDestroying(void) -> void;
    virtual auto stopDestroying(void) -> void;
private:
    virtual auto Function382(void) -> void;
    virtual auto Function383(void) -> void;
public:
    virtual auto openTrading(ActorUniqueID*, bool) -> void;
    virtual auto canOpenContainerScreen(void) -> bool;
private:
    virtual auto Function386(void) -> void;
    virtual auto Function387(void) -> void;
public:
    virtual auto openInventory(void) -> void;
private:
    virtual auto Function389(void) -> void;
public:
    virtual auto displayClientMessage(std::string*) -> void;
    virtual auto displayTextObjectMessage(TextObjectRoot const &,std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &,std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &) -> void;
    virtual auto displayTextObjectWhisperMessage(ResolvedTextObject const &,std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &,std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &) -> void;
    virtual auto displayWhisperMessage(std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &,std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &,std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &,std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &) -> void;
    virtual auto startSleepInBed(Vec3<int*>) -> void;
    virtual auto stopSleepInBed(void) -> void;
    virtual auto canStartSleepInBed(void) -> bool;
    virtual auto getSleepTimer(void) -> int;
    virtual auto getPreviousTickSleepTimer(void) -> int;
private:
    virtual auto Function399(void) -> void;
    virtual auto Function400(void) -> void;
public:
    virtual auto isHostingPlayer(void) -> bool;
    virtual auto isLoading(void) -> bool;
    virtual auto isPlayerInitialized(void) -> bool;
private:
    virtual auto Function404(void) -> void;
public:
    virtual auto registerTrackedBoss(ActorUniqueID) -> void;
    virtual auto unregisterTrackedBoss(ActorUniqueID) -> void;
    virtual auto setPlayerGameType(GameType) -> void;
    virtual auto initHUDContainerManager(void) -> void;
    virtual auto _crit(Actor*) -> void;
    virtual auto getEventing(void) -> IMinecraftEventing*;
private:
    virtual auto Function411(void) -> void;
public:
    virtual auto sendEventPacket(EventPacket*) -> void;
    virtual auto addExperience(int) -> void;
    virtual auto addLevels(int) -> void;
    virtual auto setContainerData(IContainerManager*) -> void;
    virtual auto slotChanged(IContainerManager*, Container*, int, ItemStack*, ItemStack*, bool) -> void;
    virtual auto inventoryChanged(Container*, int, ItemStack*, ItemStack*) -> void;
    virtual auto refreshContainer(IContainerManager*) -> void;
    virtual auto deleteContainerManager(void) -> void;
    virtual auto setFieldOfViewModifier(float) -> void;
    virtual auto is2DPositionRelevant(__int64, Vec3<int>*) -> bool;
    virtual auto isEntityRelevant(Actor*) -> bool;
    virtual auto isTeacher(void) -> bool;
    virtual auto onSuspension(void) -> void;
    virtual auto onLinkedSlotsChanged(void) -> void;
    virtual auto startCooldown(Item*) -> void;
    virtual auto getItemCooldownLeft(unsigned __int64) -> int;
    virtual auto getItemCooldownLeft(HashedString*) -> int;
    virtual auto getMaxItemCooldownLeft(void) -> int;
    virtual auto isItemInCooldown(HashedString*) -> bool;
    virtual auto sendInventoryTransaction(InventoryTransaction*) -> void;
    virtual auto sendComplexInventoryTransaction(std::unique_ptr<ComplexInventoryTransaction,std::default_delete<ComplexInventoryTransaction>>) -> void;
    virtual auto sendNetworkPacket(Packet*) -> void;
    virtual auto getPlayerEventCoordinator(void) -> PlayerEventCoordinator*;
    virtual auto getMoveInputHandler(void) -> MoveInputHandler*;
    virtual auto getInputMode(void) -> InputMode;
    virtual auto getPlayMode(void) -> ClientPlayMode;
    virtual auto reportMovementTelemetry(MovementEventType) -> void;
    virtual auto onMovePlayerPacketNormal(Vec3<float>*, Vec2<float>*, float) -> void;
};

#endif /* INCLUDES_MCBE_SDK_CLASSES_PLAYER */
