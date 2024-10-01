#pragma once

#include <basis/seadTypes.h>

namespace al {
class HitSensor;
}
class IUsePlayerPuppet;
class PlayerBindableSensorList;

class PlayerBindKeeper {
public:
    PlayerBindKeeper(al::HitSensor* bodyHitSensor, IUsePlayerPuppet* puppet);

    al::HitSensor* getBindSensor() const { return mBindSensor; }

private:
    al::HitSensor* mBodyHitSensor;
    al::HitSensor* mBindSensor = nullptr;
    PlayerBindableSensorList* mSensorList = nullptr;
    const IUsePlayerPuppet* mPuppet;
    s32 mUnkTimer = 0;
    bool mUnkDemoFlag = 0;
};

static_assert(sizeof(PlayerBindKeeper) == 0x28);
