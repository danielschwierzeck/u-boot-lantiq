/*spec file for ETRON EM6AA1608TSA*/

/*total address lines*/
#define TOTAL_ADDR_LINE  25 

/*nmuber of row address pin*/
#define ROW_ADDR_NUM     13

/*number of column address pin*/
#define COLUMN_ADDR_NUM  9

/*Number of banks*/
#define BANK_NUM         4

/*CAS Latency in cycles*/
#define CAS_LATENCY     2.5

/*CAS Latency in mode register*/
#define CASLTY 6

/*burst length*/
#define BURST_LENGTH 8

/*A0-A8 with A10 defining Auto Precharge*/ 
#define AUTO_PRECHARGE_BIT  10

/*write recovery time*/
#define Twr      15    

/*Power down exit command period*/
#define Tpdex   1 

/*Activate delay for different memory bank*/
#define Trrd     10

/*Period between active command of the same bank*/
/*or row cycle time*/
#define Trc      60

/*Minimum row active time.*/
#define Trasmin     40

/*Pre-charge command time*/
#define Trp      20

/*Extended mode register set time*/
#define Temrs    10

/*Mode register set time*/
#define Tmrd     10

/*Refresh command time*/
#define Trfc     72

/*Write to read command delay*/
#define Twtr     2

/*clock cycles to lock the DLL*/
#define Tdll     200

/*Self refresh exit time (to read command)*/
#define Txsr     200

/*Exit self refresh to non read command*/
#define Txsnr    75

/*Active to read or write delay*/
#define Trcd     20

/*Minimum CKE pulse width, clock cycle time*/
#define Tcke     6

/*Cycles between refresh command*/
#define Tref     7.8

/*Maximum row active time*/
#define Trasmax 120000

/*Initialize time, from clock start to stable time, in us*/
#define Tinit  200 

/*Refresh commands from init that is needed*/
#define init_refresh 2

