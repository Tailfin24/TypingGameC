#include "GameData.h"



/*变量*/
int choice = 0;
unsigned score = 0; //分数
unsigned gameTime = 0; //时间
Key key[26];
Block block[10][4];
Letter letterSaved[100], letterCurrent[100]; //分别表示未出现在屏幕上的字母、已出现在屏幕上的字母
int sizeSaved = 0, sizeCurrent = 0; //表示letterSaved和letterCurrent数组的大小

/*文本数据*/
char text1[] = "includestdiohintmainprintfHelloWorldnreturn";
char text2[] = "includestdiohintmainintijkprintfniiiforjjjforkkkifikijjkprintfdddnijk";
char text3[] = "includestdiohintmainprintfCnprintfnprintfnprintfnprintfn";
char text4[] = "YouCanUsuallyDoBetterByApplyingATrigIdentityOrComputingAVectorDotProduct.";
char text5[] = "AllocateFourDigitsForTheYearPartOfADateANewMillenniumIsComming";
char text6[] = "InOrderToUnderstandRecursionOneMustFirstUnderstandRecursion";
char text7[] = "NinePeopleCantMakeABabyInAMonth";
