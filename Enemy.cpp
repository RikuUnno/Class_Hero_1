#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Enemy.h"
#include "Hero.h"

using namespace std;

class Hero; //‘O•ûéŒ¾

//```````````EnemyClass```````````

Enemy::Enemy(const char* enemyName, int enemyHp, int enemyAtk, int enemyDef)
{
    name = new(nothrow) char[strlen(enemyName) + 1];

    strcpy(name, enemyName);

    hp = enemyHp;

    atk = enemyAtk;

    def = enemyDef;

    cout << "name > " << name << endl
        << "Hp > " << hp << endl
        << "ak > " << atk << endl
        << "def > " << def << endl;
}

Enemy::~Enemy()
{
    if (name != nullptr)
    {
        delete[] name;
        name = nullptr;
    }
}

void Enemy::attack(Hero* hero)
{
    int damage = atk - hero->DefGetter();

    cout << hero->NameGetter() << "‚Ö" << damage << "‚Ìƒ_ƒ[ƒW‚ğ—^‚¦‚½" << endl;

    hero->TakeDamage(damage);
}

void Enemy::heal(int recovery)
{
    hp += recovery;
}

int Enemy::HpGetter()
{
    return hp;
}

int Enemy::DefGetter()
{
    return def;
}

char* Enemy::NameGetter()
{
    return name;
}

void Enemy::TakeDamage(int damage)
{
    hp -= damage;
    cout << name << "‚Íc‚è " << hp << endl;
}

//```````````EnemyClass```````````