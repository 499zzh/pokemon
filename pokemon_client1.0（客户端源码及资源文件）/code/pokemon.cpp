#include "Pokemon.h"
#include<string.h>
#include<time.h>

pokemon::pokemon(){
    strcpy_s(m_name, "pokemon");
    m_attack = 40;
    m_defense = 20;
    m_HP = 200;
    m_level = 1;
    m_exp = 0;
    m_crit = 0;
    m_attribute = -1;
    m_type = -1;
    m_dodge = 0;
    m_interval = 0;
    m_growing_att = 0;
    m_growing_def = 0;
    m_growing_HP = 0;
    m_now_HP = 0;
    next_pokemon = NULL;
}
//精灵类的构造函数

fire_pokemon::fire_pokemon(){
    m_attribute = FIRE;
    m_growing_att += 15;
    m_growing_def += 10;
    m_growing_HP += 25;
}
//火属性精灵的构造函数

water_pokemon::water_pokemon() {
    m_attribute = WATER;
    m_growing_att += 10;
    m_growing_def += 15;
    m_growing_HP += 25;
}
//水属性精灵的构造函数

plant_pokemon::plant_pokemon() {
    m_attribute = PLANT;
    m_growing_att += 10;
    m_growing_def += 20;
    m_growing_HP += 30;
}
//草属性精灵的构造函数

dark_pokemon::dark_pokemon() {
    m_attribute = DARK;
    m_growing_att += 25;
    m_growing_def += 5;
    m_growing_HP += 20;
}
//黑暗属性精灵的构造函数

bright_pokemon::bright_pokemon() {
    m_attribute = BRIGHT;
    m_growing_att += 20;
    m_growing_def += 5;
    m_growing_HP += 25;
}
//光属性精灵的构造函数

wind_pokemon::wind_pokemon() {
    m_attribute = WIND;
    m_growing_att += 15;
    m_growing_def += 10;
    m_growing_HP += 20;
}
//风属性精灵的构造函数

earth_pokemon::earth_pokemon() {
    m_attribute = EARTH;
    m_growing_att += 5;
    m_growing_def += 25;
    m_growing_HP += 30;
}
//地属性精灵的构造函数

thunder_pokemon::thunder_pokemon() {
    m_attribute = THUNDER;
    m_growing_att += 20;
    m_growing_def += 5;
    m_growing_HP += 20;
}
//雷电属性精灵的构造函数

machinery_pokemon::machinery_pokemon() {
    m_attribute = MACHINERY;
    m_growing_att += 5;
    m_growing_def += 1;
    m_growing_HP += 25;
}
//机械属性精灵的构造函数

strong_type::strong_type()
{
    m_type = STRONG;
    m_interval = 1.0;
    m_dodge = 0.03;
    m_crit = 0.2;
    m_growing_att += 55;
    m_growing_def += 25;
    m_growing_HP += 100;
    //设定初始化
}
//力量型构造函数

shield_type::shield_type()
{
    m_type = SHIELD;
    m_interval = 1.0;
    m_dodge = 0.03;
    m_crit = 0.1;
    m_growing_att += 50;
    m_growing_def += 35;
    m_growing_HP += 100;
    //设定初始化
}
//防御型构造函数

swift_type::swift_type()
{
    m_type = SWIFT;
    m_interval = 0.79;
    m_dodge = 0.06;
    m_crit = 0.2;
    m_growing_att += 45;
    m_growing_def += 20;
    m_growing_HP += 80;
}
//敏捷类构造函数

tank_type::tank_type()
{
    m_type = TANK;
    m_interval = 1.26;
    m_dodge = 0.01;
    m_crit = 0.05;
    m_growing_att += 50;
    m_growing_def += 30;
    m_growing_HP += 120;
}
//肉盾类构造函数

class strong_fire_pokemon :public fire_pokemon, public strong_type
{
public:
    strong_fire_pokemon() { strcpy_s(m_name, "strong_fire_pokemon"); };
    ~strong_fire_pokemon() {};
};
//力量型火属性精灵
class shield_fire_pokemon :public fire_pokemon, public shield_type
{
public:
    shield_fire_pokemon() { strcpy_s(m_name, "shield_fire_pokemon"); };
    ~shield_fire_pokemon() {};
};
//防御型火属性精灵
class tank_fire_pokemon :public fire_pokemon, public tank_type
{
public:
    tank_fire_pokemon() { strcpy_s(m_name, "tank_fire_pokemon"); };
    ~tank_fire_pokemon() {};
};
//肉盾型火属性精灵
class swift_fire_pokemon :public fire_pokemon, public swift_type
{
public:
    swift_fire_pokemon() { strcpy_s(m_name, "swift_fire_pokemon"); };
    ~swift_fire_pokemon() {};
};
//敏捷型火属性精灵

class strong_water_pokemon :public water_pokemon, public strong_type
{
public:
    strong_water_pokemon() { strcpy_s(m_name, "strong_water_pokemon"); };
    ~strong_water_pokemon() {};
};
//力量型水属性精灵
class shield_water_pokemon :public water_pokemon, public shield_type
{
public:
    shield_water_pokemon() { strcpy_s(m_name, "shield_water_pokemon"); };
    ~shield_water_pokemon() {};
};
//防御型水属性精灵
class tank_water_pokemon :public water_pokemon, public tank_type
{
public:
    tank_water_pokemon() { strcpy_s(m_name, "tank_water_pokemon"); };
    ~tank_water_pokemon() {};
};
//肉盾型水属性精灵
class swift_water_pokemon :public water_pokemon, public swift_type
{
public:
    swift_water_pokemon() { strcpy_s(m_name, "swift_water_pokemon"); };
    ~swift_water_pokemon() {};
};
//敏捷型水属性精灵

class strong_plant_pokemon :public plant_pokemon, public strong_type
{
public:
    strong_plant_pokemon() { strcpy_s(m_name, "strong_plant_pokemon"); };
    ~strong_plant_pokemon() {};
};
//力量型草属性精灵
class shield_plant_pokemon :public plant_pokemon, public shield_type
{
public:
    shield_plant_pokemon() { strcpy_s(m_name, "shield_plant_pokemon"); };
    ~shield_plant_pokemon() {};
};
//防御型草属性精灵
class tank_plant_pokemon :public plant_pokemon, public tank_type
{
public:
    tank_plant_pokemon() { strcpy_s(m_name, "tank_plant_pokemon"); };
    ~tank_plant_pokemon() {};
};
//肉盾型草属性精灵
class swift_plant_pokemon :public plant_pokemon, public swift_type
{
public:
    swift_plant_pokemon() { strcpy_s(m_name, "swift_plant_pokemon"); };
    ~swift_plant_pokemon() {};
};
//敏捷型草属性精灵

class strong_dark_pokemon :public dark_pokemon, public strong_type
{
public:
    strong_dark_pokemon() { strcpy_s(m_name, "strong_dark_pokemon"); };
    ~strong_dark_pokemon() {};
};
//力量型暗属性精灵
class shield_dark_pokemon :public dark_pokemon, public shield_type
{
public:
    shield_dark_pokemon() { strcpy_s(m_name, "shield_dark_pokemon"); };
    ~shield_dark_pokemon() {};
};
//防御型暗属性精灵
class tank_dark_pokemon :public dark_pokemon, public tank_type
{
public:
    tank_dark_pokemon() { strcpy_s(m_name, "tank_dark_pokemon"); };
    ~tank_dark_pokemon() {};
};
//肉盾型暗属性精灵
class swift_dark_pokemon :public dark_pokemon, public swift_type
{
public:
    swift_dark_pokemon() { strcpy_s(m_name, "swift_dark_pokemon"); };
    ~swift_dark_pokemon() {};
};
//敏捷型暗属性精灵

class strong_bright_pokemon :public bright_pokemon, public strong_type
{
public:
    strong_bright_pokemon() { strcpy_s(m_name, "strong_bright_pokemon"); };
    ~strong_bright_pokemon() {};
};
//力量型光属性精灵
class shield_bright_pokemon :public bright_pokemon, public shield_type
{
public:
    shield_bright_pokemon() { strcpy_s(m_name, "shield_bright_pokemon"); };
    ~shield_bright_pokemon() {};
};
//防御型光属性精灵
class tank_bright_pokemon :public bright_pokemon, public tank_type
{
public:
    tank_bright_pokemon() { strcpy_s(m_name, "tank_bright_pokemon"); };
    ~tank_bright_pokemon() {};
};
//肉盾型光属性精灵
class swift_bright_pokemon :public bright_pokemon, public swift_type
{
public:
    swift_bright_pokemon() { strcpy_s(m_name, "swift_bright_pokemon"); };
    ~swift_bright_pokemon() {};
};
//敏捷型光属性精灵

class strong_wind_pokemon :public wind_pokemon, public strong_type
{
public:
    strong_wind_pokemon() { strcpy_s(m_name, "strong_wind_pokemon"); };
    ~strong_wind_pokemon() {};
};
//力量型风属性精灵
class shield_wind_pokemon :public wind_pokemon, public shield_type
{
public:
    shield_wind_pokemon() { strcpy_s(m_name, "shield_wind_pokemon"); };
    ~shield_wind_pokemon() {};
};
//防御型风属性精灵
class tank_wind_pokemon :public wind_pokemon, public tank_type
{
public:
    tank_wind_pokemon() { strcpy_s(m_name, "tank_wind_pokemon"); };
    ~tank_wind_pokemon() {};
};
//肉盾型风属性精灵
class swift_wind_pokemon :public wind_pokemon, public swift_type
{
public:
    swift_wind_pokemon() { strcpy_s(m_name, "swift_wind_pokemon"); };
    ~swift_wind_pokemon() {};
};
//敏捷型风属性精灵

class strong_earth_pokemon :public earth_pokemon, public strong_type
{
public:
    strong_earth_pokemon() { strcpy_s(m_name, "strong_earth_pokemon"); };
    ~strong_earth_pokemon() {};
};
//力量型地属性精灵
class shield_earth_pokemon :public earth_pokemon, public shield_type
{
public:
    shield_earth_pokemon() { strcpy_s(m_name, "shield_earth_pokemon"); };
    ~shield_earth_pokemon() {};
};
//防御型地属性精灵
class tank_earth_pokemon :public earth_pokemon, public tank_type
{
public:
    tank_earth_pokemon() { strcpy_s(m_name, "tank_earth_pokemon"); };
    ~tank_earth_pokemon() {};
};
//肉盾型地属性精灵
class swift_earth_pokemon :public earth_pokemon, public swift_type
{
public:
    swift_earth_pokemon() { strcpy_s(m_name, "swift_earth_pokemon"); };
    ~swift_earth_pokemon() {};
};
//敏捷型地属性精灵

class strong_machinery_pokemon :public machinery_pokemon, public strong_type
{
public:
    strong_machinery_pokemon() { strcpy_s(m_name, "strong_machinery_pokemon"); };
    ~strong_machinery_pokemon() {};
};
//力量型机械属性精灵
class shield_machinery_pokemon :public machinery_pokemon, public shield_type
{
public:
    shield_machinery_pokemon() { strcpy_s(m_name, "shield_machinery_pokemon"); };
    ~shield_machinery_pokemon() {};
};
//防御型机械属性精灵
class tank_machinery_pokemon :public machinery_pokemon, public tank_type
{
public:
    tank_machinery_pokemon() { strcpy_s(m_name, "tank_machinery_pokemon"); };
    ~tank_machinery_pokemon() {};
};
//肉盾型机械属性精灵
class swift_machinery_pokemon :public machinery_pokemon, public swift_type
{
public:
    swift_machinery_pokemon() { strcpy_s(m_name, "swift_machinery_pokemon"); };
    ~swift_machinery_pokemon() {};
};
//敏捷型机械属性精灵

class strong_thunder_pokemon :public thunder_pokemon, public strong_type
{
public:
    strong_thunder_pokemon() { strcpy_s(m_name, "strong_thunder_pokemon"); };
    ~strong_thunder_pokemon() {};
};
//力量型雷属性精灵
class shield_thunder_pokemon :public thunder_pokemon, public shield_type
{
public:
    shield_thunder_pokemon() { strcpy_s(m_name, "shield_thunder_pokemon"); };
    ~shield_thunder_pokemon() {};
};
//防御型雷属性精灵
class tank_thunder_pokemon :public thunder_pokemon, public tank_type
{
public:
    tank_thunder_pokemon() { strcpy_s(m_name, "tank_thunder_pokemon"); };
    ~tank_thunder_pokemon() {};
};
//肉盾型雷属性精灵
class swift_thunder_pokemon :public thunder_pokemon, public swift_type
{
public:
    swift_thunder_pokemon() { strcpy_s(m_name, "swift_thunder_pokemon"); };
    ~swift_thunder_pokemon() {};
};
//敏捷型雷属性精灵

void pokemon::fight(pokemon& opponent) {
    this->reset_HP();
    opponent.reset_HP();
    //为双方补满血量
    int your_interval = (int)(m_interval * 1000);
    int opponent_interval = (int)(opponent.m_interval * 1000);
    //取出攻击间隔
    clock_t start_time = clock(); //获取起始时间
    clock_t now_time;
    cout << "战斗开始！" << endl;
    while (1) {
        Sleep(1);
        now_time = clock() + 1;
        //获取当前时间
        if ((now_time - start_time) % your_interval == 0) {
            int temp_demage = this->attack(opponent);
            opponent.m_now_HP -= temp_demage;
            cout << "您造成了 " << temp_demage << " 点伤害" <<endl;
        }
        //用户攻击
        if ((now_time - start_time) % opponent_interval == 0) {
            int temp_demage = opponent.attack(*this);
            this->m_now_HP -= temp_demage;
            cout << "对手造成了 " << temp_demage << " 点伤害"<<endl;
        }
        //对手攻击
        //双方HP均大于0时
        if (this->m_now_HP <= 0) {
            cout << "您失败了！" << endl;
            break;
        }
        else if (opponent.m_now_HP <= 0) {
            int reward = m_level < opponent.get_level();
            //越级挑战奖励，相差太多减少
            int exp = 0;
            if (reward <= 0)
                exp = m_level * m_level + pow(2, reward) + (16 - m_level) * 10;
            else
                exp = m_level * opponent.get_level() - reward + (16 - m_level) * 10;
            cout << "您胜利了！" << endl;
            exp_level(exp);
            break;
        }
    }
}
//战斗函数
