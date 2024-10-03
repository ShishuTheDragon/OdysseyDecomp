#include "Player/PlayerBindKeeper.h"

#include "Player/IUsePlayerPuppet.h"
#include "Player/PlayerBindableSensorList.h"

const u32 UnkTimerDuration = 0x1e;

PlayerBindKeeper::PlayerBindKeeper(al::HitSensor* bodyHitSensor, IUsePlayerPuppet* puppet)
    : mBodyHitSensor(bodyHitSensor), mPuppet(puppet) {
    mSensorList = new PlayerBindableSensorList();
}

bool PlayerBindKeeper::receiveRequestDamage() {
    if (!mBindSensor)
        return false;

    if (!mPuppet->isRequestDamage())
        return false;

    mPuppet->clearRequestDamage();
    return true;
}

void PlayerBindKeeper::clearBindImpl() {
    mBindSensor = nullptr;
    mUnkDemoFlag = 0;
    mPuppet->cancel();
    mUnkTimer = UnkTimerDuration;
}
