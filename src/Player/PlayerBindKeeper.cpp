#include "Player/PlayerBindKeeper.h"

#include "Library/LiveActor/ActorSensorMsgFunction.h"
#include "Player/IUsePlayerPuppet.h"
#include "Player/PlayerBindableSensorList.h"
#include "Util/Sensor.h"

const s32 UnkTimerDuration = 30;

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

bool PlayerBindKeeper::sendMsgBindKeepDemoStart() {
    bool handled = rs::sendMsgBindKeepDemoStart(mBindSensor, mBodyHitSensor);

    if (handled) {
        mUnkDemoFlag = true;
        return handled;
    }

    return false;
}

bool PlayerBindKeeper::sendMsgBindKeepDemoExecute() {
    rs::sendMsgBindKeepDemoExecute(mBindSensor, mBodyHitSensor);
    return true;
}

bool PlayerBindKeeper::sendMsgBindKeepDemoEnd() {
    bool handled = rs::sendMsgBindKeepDemoEnd(mBindSensor, mBodyHitSensor);

    if (handled) {
        mUnkDemoFlag = false;
        return handled;
    }

    return false;
}

bool PlayerBindKeeper::sendMsgBindDamage() {
    if (!mBindSensor)
        return false;
    return al::sendMsgBindDamage(mBindSensor, mBodyHitSensor);
}

bool PlayerBindKeeper::sendMsgBindRecoveryLife() const {
    return rs::sendMsgBindRecoveryLife(mBindSensor, mBodyHitSensor);
}

bool PlayerBindKeeper::sendMsgCollidedGround() {
    return rs::sendMsgBindCollidedGround(mBindSensor, mBodyHitSensor);
}

bool PlayerBindKeeper::sendMsgEnableMapCheckPointWarp() {
    return rs::sendMsgEnableMapCheckPointWarp(mBindSensor, mBodyHitSensor);
}

void PlayerBindKeeper::clearBindImpl() {
    mBindSensor = nullptr;
    mUnkDemoFlag = 0;
    mPuppet->cancel();
    mUnkTimer = UnkTimerDuration;
}
