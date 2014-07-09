
#ifndef __FOODORDER_H
#define __FOODORDER_H

#define MENU_COL 22
#define AUSTRALIA_PROJECT

//-----------For Australiar order project----------------------------
/*

typedef struct 
{
	#ifdef AUSTRALIA_PROJECT
	char CategoryName[20];//specially for Australia pro
	#endif
	char FoodQuantiy[5];//ItemQuantity
	char FoodName[200];//ItEMTitle
	char FoodAmount[10];//ItemPrice
}FOOD;
*/
typedef struct 
{
	char RestaurantID[10];
	char OrderType[2];
	char OrderNumber[10];
	//FOOD OrderFood[10];
	char *OrderFood;
	char DeliveryCharge[10];//DeliveryCost
	char CC_HandelingFees[50];//Credit card fee + Handling fee
	char Discount[100];
	char Total[10];
	char CustomerType[2];//IsCustomerVerified
	char CustomerName[50];
	char CustomerAddress[150];
	char RequestTime[30];//DeliveryTime
	char PreviousNumberOfOrders[5];
	char PaymentStatus[2];
	char PaymentCardNo[50];
	char CustomerPhone[20];
	//char CustomerComments[100];
	char *CustomerComments;

}ORDER_STRUCT;


extern char DebugLock;

char SelfTest_GPRS(char *msg);

char Latest_Orders (char *msg);
//char Reject_Orders (char *msg);
char Confirm_Orders (char *msg);

void InitOrder(void);
void kmy_EnableDisableTime3(char OnOFF);//if OnOFF=1, GPRS_Thread(check order) is on; else is off.
void kmy_GPRSTimeSet(char init_flag);

// flag=1, just check if have receive an order
// flag=0, beep and lcd flash
// if BeepDuration=0, no beep
// if BeepDuration=1, beep until press a key 
unsigned char HaveReceiveOrder(char flag);

void GetRejectReason(char (*ReasonTable)[MENU_COL], char *Reason, char *RejectNum );
char CheckOrderFailWarn(void);
char CheckTimeFormat(char* buff);
char AutoPrintOrder(void);
void ReprintLastOrder(void);
#endif

