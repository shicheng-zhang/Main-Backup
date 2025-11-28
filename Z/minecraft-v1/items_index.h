#include <string.h>
#define max_itms 10
//Define item structure and basis
typedef enum {
    UTILITY,
    FOOD,
    RESOURCES,
    P_RESOURCES,
    TOOLS,
    MISC
} lv_1_category;
//Define Item Classification index
typedef enum {
    //Utility
    MELEE = 1 << 0,
    RANGED = 1 << 1,
    ARMOR = 1 << 2,
    //Food
    BAKED = 1 << 3,
    MEATS = 1 << 4,
    F_V = 1 << 5, //Fruits and Vegetables
    UNPROCESSED = 1 << 6,
    //Resources
    WOODS = 1 << 7,
    STONES = 1 << 8,
    ORES = 1 << 9,
    NSB = 1 << 10, //Non-Solid Blocks
    //Processed Resources
    P_WOODS = 1 << 11,
    P_STONES = 1 << 12,
    P_ORES = 1 << 13,
    P_NSB = 1 << 14, //Processed Non-Solid Blocks
    C_WOODS = 1 << 15, //Cut Woods
    C_STONES = 1 << 16, //Cut Stones
    //Tools
} lv_2_category;
typedef struct {
    char itm_names [50];
    lv_1_category itm_lv_1;
    int itm_lv_2; 
} OBJS;


