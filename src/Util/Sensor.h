#pragma once

namespace al {
class HitSensor;
class SensorMsg;
}  // namespace al

namespace rs {

bool sendMsgBindCollidedGround(al::HitSensor* source, al::HitSensor* target);
bool sendMsgBindKeepDemoStart(al::HitSensor* source, al::HitSensor* target);
bool sendMsgBindKeepDemoExecute(al::HitSensor* source, al::HitSensor* target);
bool sendMsgBindKeepDemoEnd(al::HitSensor* source, al::HitSensor* target);
bool sendMsgBindRecoveryLife(al::HitSensor* source, al::HitSensor* target);
bool sendMsgEnableMapCheckPointWarp(al::HitSensor* source, al::HitSensor* target);
bool sendMsgEnemyAttack2D(al::HitSensor* source, al::HitSensor* target);
bool sendMsgNoticePlayerDamage(al::HitSensor* source, al::HitSensor* target);
bool sendMsgTouchFireDrum2D(al::HitSensor* source, al::HitSensor* target);
bool sendMsgItemAmiiboKoopa(al::HitSensor* source, al::HitSensor* target);

bool isMsgCapTouchWall(const al::SensorMsg*);

}  // namespace rs
