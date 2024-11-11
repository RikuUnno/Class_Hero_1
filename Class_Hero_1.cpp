#include <iostream>
#include "Enemy.h"
#include "Hero.h"

using namespace std;

void showStatus(const Hero hero, const Enemy enemy);

void showStatus(const Hero hero, const Enemy enemy)
{
    cout << "~~~Hero~~~" << endl
        << "名前：" << hero.NameGetter() << endl
        << "HP：" << hero.HpGetter() << endl
        << "攻撃力：" << hero.AtkGetter() << endl
        << "防御力：" << hero.DefGetter() << endl
        << "~~~Enemy~~~" << endl
        << "名前：" << enemy.NameGetter() << endl
        << "HP：" << enemy.HpGetter() << endl
        << "攻撃力：" << enemy.AtkGetter() << endl
        << "防御力：" << enemy.DefGetter() << endl;
}

int main()
{
    Hero hero1("Hero1", 200);
    Enemy enemy1("Enemy1", 200);

    cout << endl;

    showStatus(hero1, enemy1);

    while (hero1.HpGetter() > 0 && enemy1.HpGetter() > 0) {
        hero1.attack(&enemy1);
        if (enemy1.HpGetter() <= 0) {
            cout << hero1.NameGetter() << "の勝ち" << endl;
            break;
        }

        enemy1.attack(&hero1);
        if (hero1.HpGetter() <= 0) {
            cout << enemy1.NameGetter() << "の勝ち" << endl;
            break;
        }
    }
}
