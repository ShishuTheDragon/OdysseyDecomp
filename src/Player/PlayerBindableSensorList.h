#pragma once

class PlayerBindableSensorList {
public:
    PlayerBindableSensorList();

private:
    char padding[0x20];
};

static_assert(sizeof(PlayerBindableSensorList) == 0x20);
