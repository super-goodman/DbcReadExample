#pragma once
#include "windows.h"
enum ObjectType : int {
    Unit = 5,
    Players = 6,
    Dynamic = 8
};

enum SpellBookClassType : int {
    DeathKight = 5,

};

enum MovementType : int {
    Normal = 0,
    Up = 0x10,
    Down = 0x20,
    Left = 0x40,
    Right = 0x80,
    Camerat_Left = 0x100,
    Camerat_Right = 0x200,
};

enum AuraFlags : BYTE {
    Active = 0x80,
    Passive = 0x10,
    Harmful = 0x20
};

enum TeamID : UINT8 {
    Horde,
    Alliance,
    INVALID,
};

enum WoWClass : UINT8
{
    None = 0,
    Warrior = 1,
    Paladin = 2,
    Hunter = 3,
    Rogue = 4,
    Priest = 5,
    DeathKnight = 6,
    Shaman = 7,
    Mage = 8,
    Warlock = 9,
    Druid = 11,
};

enum WoWRace : UINT8
{
    Human = 1,
    Orc,
    Dwarf,
    NightElf,
    Undead,
    Tauren,
    Gnome = 115,
    TrollFemale = 116,
    Troll = 158,
    Goblin = 8,
    BloodElf,
    Draenei,
    FelOrc,
    Naga,
    Broken,
    Skeleton = 15,
    Draeneis = 1629,
    BloodElfs = 1610,
};