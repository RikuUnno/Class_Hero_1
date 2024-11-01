#include <iostream>
#include "Enemy.h"
#include "Hero.h"

using namespace std;

int main()
{
    Hero hero1("Hero1", 200);
    Enemy enemy1("Enemy1", 200);

    cout << endl;

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
