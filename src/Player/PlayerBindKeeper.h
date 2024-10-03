#pragma once

#include <basis/seadTypes.h>

namespace al {
class HitSensor;
class SensorMsg;
}  // namespace al
class IUsePlayerPuppet;
class PlayerBindableSensorList;

class PlayerBindKeeper {
public:
    PlayerBindKeeper(al::HitSensor* bodyHitSensor, IUsePlayerPuppet* puppet);

    bool receiveRequestDamage();

    al::HitSensor* getBindSensor() const { return mBindSensor; }

private:
    void clearBindImpl();

    al::HitSensor* mBodyHitSensor;
    al::HitSensor* mBindSensor = nullptr;
    PlayerBindableSensorList* mSensorList = nullptr;
    IUsePlayerPuppet* mPuppet;
    s32 mUnkTimer = 0;
    bool mUnkDemoFlag = 0;
};

static_assert(sizeof(PlayerBindKeeper) == 0x28);
