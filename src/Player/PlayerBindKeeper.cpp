#include "Player/PlayerBindKeeper.h"

#include "Player/PlayerBindableSensorList.h"

PlayerBindKeeper::PlayerBindKeeper(al::HitSensor* bodyHitSensor, IUsePlayerPuppet* puppet)
    : mBodyHitSensor(bodyHitSensor), mPuppet(puppet) {
    mSensorList = new PlayerBindableSensorList();
}
