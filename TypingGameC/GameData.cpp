#include "GameData.h"



/*����*/
int choice = 0;
unsigned score = 0; //����
unsigned gameTime = 0; //ʱ��
Key key[26];
Block block[10][4];
Letter letterSaved[100], letterCurrent[100]; //�ֱ��ʾδ��������Ļ�ϵ���ĸ���ѳ�������Ļ�ϵ���ĸ
int sizeSaved = 0, sizeCurrent = 0; //��ʾletterSaved��letterCurrent����Ĵ�С

/*�ı�����*/
char text1[] = "includestdiohintmainprintfHelloWorldnreturn";
char text2[] = "includestdiohintmainintijkprintfniiiforjjjforkkkifikijjkprintfdddnijk";
char text3[] = "includestdiohintmainprintfCnprintfnprintfnprintfnprintfn";
char text4[] = "YouCanUsuallyDoBetterByApplyingATrigIdentityOrComputingAVectorDotProduct.";
char text5[] = "AllocateFourDigitsForTheYearPartOfADateANewMillenniumIsComming";
char text6[] = "InOrderToUnderstandRecursionOneMustFirstUnderstandRecursion";
char text7[] = "NinePeopleCantMakeABabyInAMonth";
