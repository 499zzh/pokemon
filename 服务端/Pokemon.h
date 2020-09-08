#ifndef POKEMON_H
#define POKEMON_H
#include "pokemonset.h"

class pokemon
{
public:
    pokemon();
    ~pokemon() {};

    void fight(pokemon& opponent);							//战斗函数
    void reset_HP() { m_now_HP = m_HP; };					//恢复血量
    virtual int attack(pokemon& opponent);					//攻击函数 返回伤害值
    const double attribute_for_damage(pokemon& oppoent);		//为属性攻击进行计算
    const virtual int att_crit_and_dodge(pokemon& opponent);	//判断是否暴击和闪避 0代表闪避事件发生了 1代表正常 2代表暴击事件发生了 该返回值为一个伤害系数


    void exp_level(int new_exp);						//管理经验等级相关的函数

    const int get_defense() { return m_defense; };			//获取防御力
    const int get_attribute() { return m_attribute; };		//获取属性
    const int get_level() { return m_level; };				//获取等级
    const int get_HP() { return m_HP; };					//获取生命值
    const double get_dodge() { return m_dodge; };			//获取闪避几率
    const double get_interval(){ return m_interval; };		//获取闪避几率
    const char* get_name() { return m_name; };				//获取名
    const char* format_output(int attribute, int type);		//格式化输出
    void show();											//展示精灵属性

    //pokemon& operator=(const pokemon& self);
    virtual void dbg_pokemon_class();
    void dbg_delete_a_pokemon(pokemon& a_pokemon) {
        delete& a_pokemon;
    }
    pokemon* dbg_get_a_pokemon();
    //拓展
    //void distrubute_pro();							//分配属性点 暂时可以不实现
    //virtual void skills();							//技能

protected:
    char m_name[20];	//长为20
    int m_type;			//0代表力量型高攻击，1代表肉盾型高生命值，2代表防御性高防御，3代表敏捷型低攻击间隔
    int m_attack;		//攻击力 初步设想是 力量>防御=肉盾>敏捷			成长对应不同精灵 45 50 55
    int m_defense;		//防御力 初步设想是 防御>肉盾>力量>敏捷			成长对应不同精灵 20 25 30 35
    int m_HP;           //生命值 初步设想是 肉盾>防御=力量>敏捷			成长对应不同精灵 80 100 120
    int m_now_HP;		//当前生命值，用于战斗
    int m_growing_att; //成长对应不同精灵 45 50 55
    int m_growing_def;	//成长对应不同精灵 20 25 30 35
    int m_growing_HP;	//成长对应不同精灵 80 100 120
    double m_interval;  //攻击间隔 初步设想是敏捷>防御=力量>肉盾		0.79s 1.0s 1.26s
    double m_dodge;     //闪避几率 初步设想是敏捷>防御=力量>肉盾		0.06 0.03 0.01
    double m_crit;		//暴击几率 初步设想是 力量=敏捷>防御>肉盾		0.2 0.1 0.05
    int m_attribute;    //属性 对应表项待完成 水 火 草 土 电 风 机械 龙……
    pokemon* next_pokemon;  //链表指向该用户的下一个精灵
    //拓展
    //int m_rarity;       //普通 高级 稀有 神器 史诗 神话 挑战模式出现几率 60% 30% 6% 3% 0.7% 0.3%
private:
    int m_level;		//等级   最大是15级
    int m_exp;			//经验值 每级上限初步设想是level*100 + 2^(level-1) 经验获取是level^2 + 2^等级差（奖励越级挑战） * （16 - 等级）*10
    //拓展
    //int free_pro;       //用户自由培养的属性点
};
//精灵类

class fire_pokemon:virtual public pokemon
{
    //火属性精灵的特点是1.2倍伤害
public:
    fire_pokemon();
    ~fire_pokemon() {};
    int attack(pokemon& opponent);
};
//火属性精灵

class water_pokemon :virtual public pokemon
{
    //水属性精灵的效果是无视敌人自身等级*2的防御
public:
    water_pokemon();
    ~water_pokemon() {};
    int attack(pokemon& opponent);
};
//水属性精灵

class plant_pokemon :virtual public pokemon
{
    //草属性精灵的效果是攻击会附加自身等级*5的固定伤害
public:
    plant_pokemon();
    ~plant_pokemon() {};
    int attack(pokemon& opponent);
};
//草属性精灵

class dark_pokemon :virtual public pokemon
{
    //黑暗属性精灵的攻击不会被闪避，且闪避时造成4倍伤害
public:
    dark_pokemon();
    ~dark_pokemon() {};
    int attack(pokemon& opponent);
};
//黑暗属性精灵

class bright_pokemon :virtual public pokemon
{
    //光属性精灵的特点是暴击几率x2
public:
    bright_pokemon();
    ~bright_pokemon() {};
    int attack(pokemon& opponent);
    const int att_crit_and_dodge(pokemon& opponent);
    //特供版判断
};
//光属性精灵

class wind_pokemon :virtual public pokemon
{
    //风属性精灵的攻击时有一定几率攻击2次
public:
    wind_pokemon();
    ~wind_pokemon() {};
    int att_wind_pokemon();
};
//风属性精灵

class earth_pokemon :virtual public pokemon
{
    //地属性精灵的效果是一定几率返还本次伤害
public:
    earth_pokemon();
    ~earth_pokemon() {};
    int anti_damage();
};
//地属性精灵

class thunder_pokemon :virtual public pokemon
{
    //雷属性精灵的效果是暴击时对手下次无法攻击
public:
    thunder_pokemon();
    ~thunder_pokemon() {};
    //int attack(pokemon& opponent);
};
//雷电属性精灵

class machinery_pokemon :virtual public pokemon
{
    //机械属性精灵的效果是对手闪避时回复本次攻击的伤害*3给自身
public:
    machinery_pokemon();
    ~machinery_pokemon() {};
    int attack(pokemon& opponent);
};
//机械属性精灵

class strong_type :virtual public pokemon
{
public:
    strong_type();
    ~strong_type() {};
};
//力量型类

class shield_type :virtual public pokemon
{
public:
    shield_type();
    ~shield_type() {};
};
//防御型类

class tank_type :virtual public pokemon
{
public:
    tank_type();
    ~tank_type() {};
};
//肉盾型类

class swift_type :virtual public pokemon
{
public:
    swift_type();
    ~swift_type() {};
};
//敏捷型类


#endif // POKEMON_H
