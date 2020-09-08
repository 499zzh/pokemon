#ifndef MY_POKEMON_H
#define MY_POKEMON_H
#include<QObject>
#include<QPixmap>
#include"set.h"
class pokemon:public QObject{
    Q_OBJECT
public:
    pokemon();
    ~pokemon() {};

    int fight(pokemon* opponent);
    //战斗函数
    virtual int attack(pokemon* opponent);
    //攻击函数
    const double property_for_damage(pokemon* opponent);
    //对于属性进行伤害增减的判断
    const int att_crit_and_dodge(pokemon* opponent);
    //判断是否发生了暴击 闪避等事件 0代表闪避事件发生了 1代表正常 2代表暴击事件发生了 该返回值为一个伤害系数

    void exp_level(int new_exp);
    //管理经验值和等级， new_exp为新获得的经验值
    const int get_defense(){ return m_defense;};
    //读取防御力
    const int get_property(){ return m_property;};
    //读取精灵属性
    const int get_level(){ return m_level;};
    //读取精灵等级
    const int get_exp(){ return m_exp;};
    //读取精灵当前经验值
    const int get_HP(){ return m_HP;};
    //读取精灵HP
    const int get_att(){ return m_attack;};
    //读取攻击力
    const int get_type(){ return m_type;};
    //获取精灵类型
    const double get_dodge(){ return m_dodge;};
    //读取暴击率
    const double get_speed(){ return m_speed;};
    //读取速度
    const char* get_name(){ return m_name;};
    //读取精灵名字
    const QPixmap get_QPixmap(){ return pokemon_icon;};
    //读取精灵图标
    const char* format_output(int attrtbute, int type);
    //格式化输出精灵属性
    const int get_id(){ return pokemon_id;};
    //获取精灵id
    const int get_type_id(){ return type_id;};
    //获取精灵类型
    pokemon* recover(int level);
    //加载精灵
protected:
    char m_name[20];
    //名字长为20
    int m_type;
    //0代表力量型高攻击，1代表肉盾型高生命值，2代表防御性高防御，3代表敏捷型低攻击间隔
    int m_attack;
    //攻击力 力量 > 防御 = 肉盾 > 敏捷
    int m_defense;
    //防御力 防御 > 肉盾 > 力量 > 敏捷
    int m_HP;
    //生命值 肉盾 > 防御 = 力量 > 敏捷
    int m_speed;
    //速度 敏捷型 > 攻击型 = 防御型 > 肉盾型
    int m_property;
    //属性
    int m_growing_att;
    //成长对应不同精灵 45 50 55
    int m_growing_def;
    //成长对应不同精灵 20 25 30 35
    int m_growing_HP;
    //成长对应不同精灵 80 100 120
    int m_growing_speed;
    //成长对应不同精灵 15 12 8
    double m_dodge;
    //闪避几率 0.06 0.03 0.01
    double m_crit;
    //暴击几率 0.2 0.1 0.05
    int type_id;
    //精灵id
    int pokemon_id;
    //全局唯一精灵id
    QPixmap pokemon_icon;
    //精灵图标
private:
    int m_level;
    //等级 最大上限15级
    int m_exp;
    //经验值 每级上限初步设想是level*100 + 2^(level-1) 经验获取是level^2 + 2^等级差（奖励越级挑战） * （16 - 等级）*10
signals:
    void update(QString msg);
    //测试用途的发送战斗信息的信号
    void finish_fight(int result);
    //测试用途的发送战斗结束信息的信号
};

class fire_pokemon:virtual public pokemon
{
    //火属性精灵的特点是1.2倍伤害
public:
    fire_pokemon();
    ~fire_pokemon() {};
    int attack(pokemon *opponent);
};
//火属性精灵

class water_pokemon :virtual public pokemon
{
    //水属性精灵的效果是无视敌人自身等级*2的防御
public:
    water_pokemon();
    ~water_pokemon() {};
    int attack(pokemon* opponent);
};
//水属性精灵

class plant_pokemon :virtual public pokemon
{
    //草属性精灵的效果是攻击会附加自身等级*5的固定伤害
public:
    plant_pokemon();
    ~plant_pokemon() {};
    int attack(pokemon* opponent);
};
//草属性精灵

class dark_pokemon :virtual public pokemon
{
    //黑暗属性精灵的攻击不会被闪避，且闪避时造成4倍伤害
public:
    dark_pokemon();
    ~dark_pokemon() {};
    int attack(pokemon* opponent);
};
//黑暗属性精灵

class bright_pokemon :virtual public pokemon
{
    //光属性精灵的特点是暴击几率x2
public:
    bright_pokemon();
    ~bright_pokemon() {};
};
//光属性精灵

class wind_pokemon :virtual public pokemon
{
    //风属性精灵的速度属性会额外获得等级*3
public:
    wind_pokemon();
    ~wind_pokemon() {};
};
//风属性精灵

class earth_pokemon :virtual public pokemon
{
    //地属性精灵的效果是每级获得额外的15点生命值
public:
    earth_pokemon();
    ~earth_pokemon() {};
};
//地属性精灵

class thunder_pokemon :virtual public pokemon
{
    //雷属性精灵的效果是额外获得5点攻击力
public:
    thunder_pokemon();
    ~thunder_pokemon() {};
};
//雷电属性精灵

class machinery_pokemon :virtual public pokemon
{
    //机械属性精灵的效果是若伤害能被7整除则翻倍
public:
    machinery_pokemon();
    ~machinery_pokemon() {};
    int attack(pokemon* opponent);
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

class strong_fire_pokemon :public fire_pokemon, public strong_type
{
public:
    strong_fire_pokemon(int id) {   strcpy_s(m_name, "小火龙");
                                    pokemon_icon = QPixmap(":./Material/fire_1.png");
                                    type_id = 1;
                                    pokemon_id = id; };
    ~strong_fire_pokemon() {};
};
//力量型火属性精灵1
class shield_fire_pokemon :public fire_pokemon, public shield_type
{
public:
    shield_fire_pokemon(int id) { strcpy_s(m_name, "煤炭龟");
                          pokemon_icon = QPixmap(":./Material/fire_4.png");
                          type_id = 2;
                          pokemon_id = id; };
    ~shield_fire_pokemon() {};
};
//防御型火属性精灵2
class tank_fire_pokemon :public fire_pokemon, public tank_type
{
public:
    tank_fire_pokemon(int id) { strcpy_s(m_name, "六尾");
                        pokemon_icon = QPixmap(":./Material/fire_2.png");
                        type_id = 3;
                        pokemon_id = id; };
    ~tank_fire_pokemon() {};
};
//肉盾型火属性精灵3
class swift_fire_pokemon :public fire_pokemon, public swift_type
{
public:
    swift_fire_pokemon(int id) { strcpy_s(m_name, "小火马");
                         pokemon_icon = QPixmap(":./Material/fire_3.png");
                         type_id = 4;
                         pokemon_id = id; };
    ~swift_fire_pokemon() {};
};
//敏捷型火属性精灵4
class strong_water_pokemon :public water_pokemon, public strong_type
{
public:
    strong_water_pokemon(int id) {  strcpy_s(m_name, "杰尼龟");
                                    pokemon_icon = QPixmap(":./Material/water_1.png");
                                    type_id = 5;
                                    pokemon_id = id; };
    ~strong_water_pokemon() {};
};
//力量型水属性精灵5
class shield_water_pokemon :public water_pokemon, public shield_type
{
public:
    shield_water_pokemon(int id) {  strcpy_s(m_name, "可达鸭");
                                    pokemon_icon = QPixmap(":./Material/water_2.png");
                                    type_id = 6;
                                    pokemon_id = id; };
    ~shield_water_pokemon() {};
};
//防御型水属性精灵6
class tank_water_pokemon :public water_pokemon, public tank_type
{
public:
    tank_water_pokemon(int id) {    strcpy_s(m_name, "呆呆兽");
                                    pokemon_icon = QPixmap(":./Material/water_3.png");
                                    type_id = 7;
                                    pokemon_id = id; };
    ~tank_water_pokemon() {};
};
//肉盾型水属性精灵7
class swift_water_pokemon :public water_pokemon, public swift_type
{
public:
    swift_water_pokemon(int id) {   strcpy_s(m_name, "墨海马");
                                    pokemon_icon = QPixmap(":./Material/water_4.png");
                                    type_id = 8;
                                    pokemon_id = id; };
    ~swift_water_pokemon() {};
};
//敏捷型水属性精灵8
class strong_plant_pokemon :public plant_pokemon, public strong_type
{
public:
    strong_plant_pokemon(int id) {  strcpy_s(m_name, "菊草叶");
                                    pokemon_icon = QPixmap(":./Material/plant_3.png");
                                    type_id = 9;
                                    pokemon_id = id; };
    ~strong_plant_pokemon() {};
};
//力量型草属性精灵9
class shield_plant_pokemon :public plant_pokemon, public shield_type
{
public:
    shield_plant_pokemon(int id) {  strcpy_s(m_name, "毽子草");
                                    pokemon_icon = QPixmap(":./Material/plant_4.png");
                                    type_id = 10;
                                    pokemon_id = id; };
    ~shield_plant_pokemon() {};
};
//防御型草属性精灵10
class tank_plant_pokemon :public plant_pokemon, public tank_type
{
public:
    tank_plant_pokemon(int id) {    strcpy_s(m_name, "妙蛙种子");
                                    pokemon_icon = QPixmap(":./Material/plant_1.png");
                                    type_id = 11;
                                    pokemon_id = id; };
    ~tank_plant_pokemon() {};
};
//肉盾型草属性精灵11
class swift_plant_pokemon :public plant_pokemon, public swift_type
{
public:
    swift_plant_pokemon(int id) {   strcpy_s(m_name, "喇叭芽");
                                    pokemon_icon = QPixmap(":./Material/plant_2.png");
                                    type_id = 12;
                                    pokemon_id = id; };
    ~swift_plant_pokemon() {};
};
//敏捷型草属性精灵12
class strong_dark_pokemon :public dark_pokemon, public strong_type
{
public:
    strong_dark_pokemon(int id) {   strcpy_s(m_name, "小拉达");
                                    pokemon_icon = QPixmap(":./Material/dark_4.png");
                                    type_id = 13;
                                    pokemon_id = id; };
    ~strong_dark_pokemon() {};
};
//力量型暗属性精灵13
class tank_dark_pokemon :public dark_pokemon, public tank_type
{
public:
    tank_dark_pokemon(int id) {     strcpy_s(m_name, "戴卢比");
                                    pokemon_icon = QPixmap(":./Material/dark_1.png");
                                    type_id = 14;
                                    pokemon_id = id; };
    ~tank_dark_pokemon() {};
};
//肉盾型暗属性精灵14
class swift_dark_pokemon :public dark_pokemon, public swift_type
{
public:
    swift_dark_pokemon(int id) {    strcpy_s(m_name, "鬼斯");
                                    pokemon_icon = QPixmap(":./Material/dark_2.png");
                                    type_id = 15;
                                    pokemon_id = id; };
    ~swift_dark_pokemon() {};
};
//敏捷型暗属性精灵15
class strong_bright_pokemon :public bright_pokemon, public strong_type
{
public:
    strong_bright_pokemon(int id) {     strcpy_s(m_name, "凯西");
                                        pokemon_icon = QPixmap(":./Material/bright_1.png");
                                        type_id = 16;
                                        pokemon_id = id; };
    ~strong_bright_pokemon() {};
};
//力量型光属性精灵16
class swift_bright_pokemon :public bright_pokemon, public swift_type
{
public:
    swift_bright_pokemon(int id) {  strcpy_s(m_name, "麒麟奇");
                                    pokemon_icon = QPixmap(":./Material/bright_2.png");
                                    type_id = 17;
                                    pokemon_id = id; };
    ~swift_bright_pokemon() {};
};
//敏捷型光属性精灵17
class strong_wind_pokemon :public wind_pokemon, public strong_type
{
public:
    strong_wind_pokemon(int id) {   strcpy_s(m_name, "飞天螳螂");
                                    pokemon_icon = QPixmap(":./Material/wind_4.png");
                                    type_id = 18;
                                    pokemon_id = id; };
    ~strong_wind_pokemon() {};
};
//力量型风属性精灵18
class shield_wind_pokemon :public wind_pokemon, public shield_type
{
public:
    shield_wind_pokemon(int id) {   strcpy_s(m_name, "烈雀");
                                    pokemon_icon = QPixmap(":./Material/wind_2.png");
                                    type_id = 19;
                                    pokemon_id = id; };
    ~shield_wind_pokemon() {};
};
//防御型风属性精灵19
class tank_wind_pokemon :public wind_pokemon, public tank_type
{
public:
    tank_wind_pokemon(int id) {     strcpy_s(m_name, "波波");
                                    pokemon_icon = QPixmap(":./Material/wind_1.png");
                                    type_id = 20;
                                    pokemon_id = id; };
    ~tank_wind_pokemon() {};
};
//肉盾型风属性精灵20
class swift_wind_pokemon :public wind_pokemon, public swift_type
{
public:
    swift_wind_pokemon(int id) {    strcpy_s(m_name, "超音蝠");
                                    pokemon_icon = QPixmap(":./Material/wind_3.png");
                                    type_id = 21;
                                    pokemon_id = id; };
    ~swift_wind_pokemon() {};
};
//敏捷型风属性精灵21
class strong_earth_pokemon :public earth_pokemon, public strong_type
{
public:
    strong_earth_pokemon(int id) {  strcpy_s(m_name, "小拳石");
                                    pokemon_icon = QPixmap(":./Material/earth_3.png");
                                    type_id = 22;
                                    pokemon_id = id; };
    ~strong_earth_pokemon() {};
};
//力量型地属性精灵22
class shield_earth_pokemon :public earth_pokemon, public shield_type
{
public:
    shield_earth_pokemon(int id) {  strcpy_s(m_name, "穿山鼠");
                                    pokemon_icon = QPixmap(":./Material/earth_2.png");
                                    type_id = 23;
                                    pokemon_id = id; };
    ~shield_earth_pokemon() {};
};
//防御型地属性精灵23
class tank_earth_pokemon :public earth_pokemon, public tank_type
{
public:
    tank_earth_pokemon(int id) {    strcpy_s(m_name, "卡拉卡拉");
                                    pokemon_icon = QPixmap(":./Material/earth_4.png");
                                    type_id = 24;
                                    pokemon_id = id; };
    ~tank_earth_pokemon() {};
};
//肉盾型地属性精灵24
class swift_earth_pokemon :public earth_pokemon, public swift_type
{
public:
    swift_earth_pokemon(int id) {   strcpy_s(m_name, "拉达");
                                    pokemon_icon = QPixmap(":./Material/earth_1.png");
                                    type_id = 25;
                                    pokemon_id = id; };
    ~swift_earth_pokemon() {};
};
//敏捷型地属性精灵25
class strong_machinery_pokemon :public machinery_pokemon, public strong_type
{
public:
    strong_machinery_pokemon(int id) {  strcpy_s(m_name, "铜镜怪");
                                        pokemon_icon = QPixmap(":./Material/machinery_2.png");
                                        type_id = 26;
                                        pokemon_id = id; };
    ~strong_machinery_pokemon() {};
};
//力量型机械属性精灵26
class shield_machinery_pokemon :public machinery_pokemon, public shield_type
{
public:
    shield_machinery_pokemon(int id) {  strcpy_s(m_name, "雷吉斯奇鲁");
                                        pokemon_icon = QPixmap(":./Material/machinery_1.png");
                                        type_id = 27;
                                        pokemon_id = id; };
    ~shield_machinery_pokemon() {};
};
//防御型机械属性精灵27
class tank_machinery_pokemon :public machinery_pokemon, public tank_type
{
public:
    tank_machinery_pokemon(int id) {    strcpy_s(m_name, "自爆磁怪");
                                        pokemon_icon = QPixmap(":./Material/machinery_2.png");
                                        type_id = 28;
                                        pokemon_id = id; };
    ~tank_machinery_pokemon() {};
};
//肉盾型机械属性精灵28
class strong_thunder_pokemon :public thunder_pokemon, public strong_type
{
public:
    strong_thunder_pokemon(int id) {    strcpy_s(m_name, "皮卡丘");
                                        pokemon_icon = QPixmap(":./Material/thunder_1.png");
                                        type_id = 29;
                                        pokemon_id = id; };
    ~strong_thunder_pokemon() {};
};
//力量型雷属性精灵29
class tank_thunder_pokemon :public thunder_pokemon, public tank_type
{
public:
    tank_thunder_pokemon(int id) {  strcpy_s(m_name, "落雷兽");
                                    pokemon_icon = QPixmap(":./Material/thunder_3.png");
                                    type_id = 30;
                                    pokemon_id = id; };
    ~tank_thunder_pokemon() {};
};
//肉盾型雷属性精灵30
class swift_thunder_pokemon :public thunder_pokemon, public swift_type
{
public:
    swift_thunder_pokemon(int id) { strcpy_s(m_name, "霹雳电球");
                                    pokemon_icon = QPixmap(":./Material/thunder_2.png");
                                    type_id = 31;
                                    pokemon_id = id; };
    ~swift_thunder_pokemon() {};
};
//敏捷型雷属性精灵31

#endif // MY_POKEMON_H
