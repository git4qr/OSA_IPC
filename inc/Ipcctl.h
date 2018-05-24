#ifndef __IPCCTL_H_
#define __IPCCTL_H_

#define _PATH0_ "/"
#define _PATH1_ "/"
#define _PATH2_ "/"
#define _PATH3_ "/"
#define _PATH4_ "/"

#define SHMEMSTATUSSIZE 200
#define SHMEMFRAMESIZE 10485760
#define MMTNUM 10
#define PARAMLEN 12


typedef enum 
{
    sensor,  /*0*/
    pinp, /*1*/
    trk, /*2*/
    sectrk, /*3*/
    enh, /*4*/
    mtd, /*5*/
    trkdoor, /*6*/
    posmove, /*7*/
    zoom, /*8*/
    autocheck, /*9*/
    mmt,/*10*/
    mmtselect,/*11*/
    axismove,/*12*/
    read_shm_trkpos,/*13*/
    exit_img,
    invalid
}CMD_ID;


typedef enum 
{
	shm_rdonly,
	shm_rdwr
}shm_perms;

typedef enum
{
    TRK_MODE,
    LOCK_MODE,
    SCAN_MODE,
    SMALL_AREA_MODE,
    FOLLOW_MODE,
    SEARCH_TRK_MODE
}to_osd_work_mode_enum;

typedef enum
{
    SINGLE_RANGE_MODE,
    CONTINUE_RANGE_MODE,
    MARK_RANGE_MODE,
    EXPOSURE_MODE
}to_osd_laser_work_mode_enum;

typedef enum 
{
    IPC_TOIMG_MSG,  		// SERVER TO CLIENT
    IPC_FRIMG_MSG,		// CLIENT TO SERCER
    IPC_SHA,
    IPC_OSD_SHA,
    IPC_SEM,
    IPC_MAX
}IPC_MTYPE;

typedef enum 
{
    IPC_Class_MSG,  
    IPC_Class_SHA,
    IPC_Class_SEM,
    IPC_ClassMAX
}IPC_Class;

typedef enum {
        ipc_eSen_CH0 = 0x00,
        ipc_eSen_CH1 = 0x01,
        ipc_eSen_CH2 = 0x02,
        ipc_eSen_CH3 = 0x03,
        ipc_eSen_CH4 = 0x04,
        ipc_eSen_Max = 0x05
}ipc_eSenserStat;

typedef enum img_zoom
{
    zoom_0 = 0x00,
    zoom_2 = 0x02,
    zoom_4 = 0x04,
    zoom_8 = 0x08
}ipc_img_zoom;

typedef enum ipc_Dram_TrkAim
{
	IPC_AIM_NO1		= 0x00,
	IPC_AIM_NO2		= 0x01,
	IPC_AIM_NO3		= 0x02,
	IPC_AIM_NO4		= 0x03,
	IPC_AIM_NO5		= 0x04,
	IPC_AIM_MAX		= 0x05,
} ipc_eTrkAim;

typedef enum {
	ipc_ePicp_top_left = 0x00,
	ipc_ePicp_top_right = 0x01,
	ipc_ePicp_bot_left = 0x02,
	ipc_ePicp_bot_right = 0x03,
}ipc_ePicpPosStat;

typedef enum ipc_Dram_SysMode
{
	IPC_INIT_MODE           = 0x00,
	IPC_CHECK_MODE      = 0x01,
	IPC_AXIS_MODE           = 0x02,
	IPC_NORMAL_MODE     = 0x03,
} ipc_eSysMode;

typedef enum ipc_Dram_TrkType
{
	IPC_AUTO_MODE		= 0x00,
	IPC_CONTRAST_MODE	= 0x01,
	IPC_CENTRE_MODE		= 0x02,
} ipc_eTrkType;

typedef enum ipc_Dram_zoomCtrl
{
	ipc_eZoom_Ctrl_Pause    = 0x00,
	ipc_eZoom_Ctrl_SCAL2    = 0x01,
	ipc_eZoom_Ctrl_SCAL4    = 0x02,
	ipc_eZoom_Ctrl_ADD      = 0x01,
	ipc_eZoom_Ctrl_SUB      = 0x02,
} ipc_eZoomCtrl;

typedef enum ipc_Dram_ImgAlg
{
	ipc_eImgAlg_Disable     = 0x00,
	ipc_eImgAlg_Enable      = 0x01,
} ipc_eImgAlgStat;  // use by img zoom/enh/stb/mtd/rst

typedef enum ipc_Dram_MMTSelect
{
	ipc_eMMT_No     = 0x00,
	ipc_eMMT_Next       = 0x01,
	ipc_eMMT_Prev       = 0x02,
	ipc_eMMT_Select = 0x03,
} ipc_eMMTSelect;

typedef enum ipc_Dram_DispGradeStat
{
	ipc_eDisp_hide      = 0x00,
	ipc_eDisp_show_rect     = 0x01,
	ipc_eDisp_show_text     = 0x02,
	ipc_eDisp_show_dbg      = 0x04,
} ipc_eDispGrade;

typedef enum ipc_Dram_DispGradeColor
{
	ipc_ecolor_Default  = 0x0,
	ipc_ecolor_Black = 0x1,
	ipc_ecolor_White    = 0x2,
	ipc_ecolor_Red = 0x03,
	ipc_ecolor_Yellow = 0x04,
	ipc_ecolor_Blue = 0x05,
	ipc_ecolor_Green = 0x06,
} ipc_eOSDColor;

typedef enum
{
	ipc_eTrk_Acq        = 0x00,
	ipc_eTrk_Normal = 0x01,
	ipc_eTrk_Assi       = 0x02,
	ipc_eTrk_Lost       = 0x03,
} ipc_eTrkStat;

typedef enum ipc_Dram_trkMode
{
	// mode cmd
	ipc_eTrk_mode_acq       = 0x00,
	ipc_eTrk_mode_target    = 0x01,
	ipc_eTrk_mode_mtd       = 0x02,
	ipc_eTrk_mode_sectrk    = 0x03,
	ipc_eTrk_mode_search    = 0x04,
} ipc_eTrkMode;

typedef enum ipc_Dram_trkRefine
{
	ipc_eTrk_ref_no     = 0x00,
	ipc_eTrk_ref_left   = 0x01,
	ipc_eTrk_ref_right  = 0x02,
	ipc_eTrk_ref_up     = 0x01,
	ipc_eTrk_ref_down   = 0x02,
} ipc_eTrkRefine;

typedef enum ipc_Dram_saveMode
{
	ipc_eSave_Disable       = 0x00,
	ipc_eSave_Enable        = 0x01,
	ipc_eSave_Cancel        = 0x02,
} ipc_eSaveMode;

typedef struct{
	char *name;
	int Identify;
	int Class;
	int IPCID;
}IPC_Handl;

typedef struct{
    volatile unsigned char unitFaultStat;/*0:FR ok,TV ok; 1:FR ok,TV err; 2:FR err,TV ok; 3:FR err,TV err*/
    volatile unsigned char ComStat;/*主通信状态，0正常，1故障*/
    volatile unsigned char RomdeviceStat;/*存储设备状态：0正常，1故障*/
    volatile unsigned char GPUStat;/*GPU状态：0正常，1故障*/
}CMD_AUTOCHECK;


typedef struct{
	volatile unsigned char SensorStat;
}CMD_SENSOR;

typedef struct{
	volatile unsigned char ImgPicp;
	volatile unsigned char PicpSensorStat;
	volatile unsigned char PicpZoomStat;//pinp zoom
}CMD_PinP;

typedef struct{
	volatile unsigned char AvtTrkStat;// eTrkMode 
    	volatile unsigned char TrkCmd;//only for ack trk mod
}CMD_TRK;
	
typedef struct{
	volatile unsigned char SecAcqStat;// eSecTrkMode
	volatile  int ImgPixelX; //SecTrk X
	volatile  int ImgPixelY; //SecTrk Y
}CMD_SECTRK;

typedef struct{
    volatile unsigned char ImgEnhStat;// eImgAlgStat enh 0:close 1:open
}CMD_ENH;

typedef struct{
	volatile unsigned char ImgMmtStat;// eImgAlgStat mtd 0:close 1:open
}CMD_MMT;

typedef struct{
	volatile unsigned char ImgMtdStat;// eImgAlgStat mtd 0:close 1:open
}CMD_MTD;

typedef struct{
	volatile unsigned char ImgMmtSelect;// eMMTSelect or range 0-MTD_TARGET_NUM
}CMD_MMTSELECT;

typedef struct{
	volatile unsigned char unitMtdValid;//mmt  0-disable 1-valid 2-unvalid
	volatile unsigned char unitMtdPixelX1;//report mmt x1
	volatile unsigned char unitMtdPixelX2;//report mmt x2
	volatile unsigned char unitMtdPixelY1;//report mmt y1
	volatile unsigned char unitMtdPixelY2;//report mmt y2
}CMD_sMTD;

typedef struct{
	volatile unsigned char unitAimW;//aim w
	volatile unsigned char unitAimH;//aim h
}CMD_AIMWH;

typedef struct{
	volatile unsigned char unitAimX1; //aim x1
	volatile unsigned char unitAimX2; //aim x2
	volatile unsigned char unitAimY1; //aim y1
	volatile unsigned char unitAimY2; //aim y2
}CMD_AIMXY;

typedef struct{
	volatile unsigned char AvtTrkAimSize;
}CMD_TRKDOOR;

typedef struct{
	volatile unsigned char UartSpeedSelect;//sync422 rate
}CMD_SYNC422;

typedef struct{
	volatile unsigned char AvtMoveX;// eTrkRefine (axis or aim) x
	volatile unsigned char AvtMoveY;// eTrkRefine (axis or aim) y
}CMD_POSMOVE;

typedef struct{
	volatile unsigned char unitTrkX1;// for report and osd text x1
	volatile unsigned char unitTrkX2;// for report and osd text x2
	volatile unsigned char unitTrkY1;// for report and osd text y1
	volatile unsigned char unitTrkY2;// for report and osd text y2
}CMD_sTRKXY;

typedef struct{
	volatile unsigned char unitAxisX1;//cross x1
	volatile unsigned char unitAxisX2;//cross x2
	volatile unsigned char unitAxisY1;//cross y1
	volatile unsigned char unitAxisY2;//cross y2
}CMD_CROSSXY;

typedef struct{
    volatile unsigned char ImgZoomStat;
}CMD_ZOOM;

typedef struct{
    volatile unsigned char screenshot;//1:enable 2:disable
    volatile unsigned char g_record;//1:enable record  2:disable record
}CMD_SCREENSHOT;

typedef struct{
    volatile unsigned char screenh265;//1:enable 2:disable
    volatile unsigned char g_record;//1:enable record  2:disable record
}CMD_SCREENH265;

typedef struct{
    volatile unsigned int framerate;
}CMD_FRAMERATE;

typedef struct{
    volatile unsigned int datastream;
}CMD_DATASTREAM;

typedef struct{
    unsigned char cmd_ID;
	unsigned char param[PARAMLEN];
}SENDST;



/** universal status **/
typedef struct
{
	/***** new status *****/
	volatile int axisMoveStepX;
	volatile int axisMoveStepY;
	volatile int aimRectMoveStepX;
	volatile int aimRectMoveStepY;
	volatile int validChId;
	volatile int opticAxisPosX[ipc_eSen_Max];	//may be same to unitAxisX[eSen_Max]
	volatile int opticAxisPosY[ipc_eSen_Max];
	volatile int AxisPosX[ipc_eSen_Max];	
	volatile int AxisPosY[ipc_eSen_Max];
	volatile int AvtPosX[ipc_eSen_Max];	//target avt x,y for each channel
	volatile int AvtPosY[ipc_eSen_Max];
	

	/***** old status ,remaining tidy*****/	
	volatile unsigned int  unitVerNum;      	// 1.23=>0x0123
	volatile unsigned int  unitFaultStat;   		// bit0:tv input bit1:fr input bit2:avt21
	volatile unsigned int  unitFaultStatpri;   	// bit0:tv input bit1:fr input bit2:avt21
	volatile unsigned char  SysMode; 		// 0 --- init ; 1 ---normal  2---settiing
	volatile unsigned char  FovCtrl; 
	volatile unsigned char  FovStat;       /* 1 byte ext-input fov:0 Large fov ,1 midle fov,2 small fov,3 electric x2 fov */
	volatile float  unitFovAngle[ipc_eSen_Max];
	
	volatile unsigned int TrkStatpri;
	volatile unsigned int TrkStat;     // acp/trk/assi/lost

	volatile int  unitAimW;      // aim size
	volatile int  unitAimH;      // aim size
	volatile int  unitAimX;
	volatile int  unitAimY;
	
	volatile float TrkX;    		// for report and osd text 	what
	volatile float TrkY;    		// for report and osd text
	volatile float TrkXtmp;    	// for report and osd text
	volatile float TrkYtmp;    	// for report and osd text

	volatile unsigned int  AvtTrkStat;      		// eTrkMode 
	volatile unsigned int  AvtTrkAimSize;   	// 0-4
	volatile unsigned int  AvtCfgSave;      	// eSaveMode
	volatile unsigned int  AvtTrkCoast;
	volatile unsigned int  TrkErrFeedback;  	// eTrkMode 

	volatile int  trkerrx;
	volatile int  trkerry;	

	/***** cmd stat part *****/
	volatile unsigned int  SensorStat;      		
	volatile unsigned int  changeSensorFlag;
	volatile unsigned int  PicpSensorStat;  		
	volatile unsigned int  PicpSensorStatpri; 		
	volatile unsigned int  PicpPosStat;			
	volatile unsigned int  ImgZoomStat[ipc_eSen_Max];   	
	volatile unsigned int  ImgEnhStat[ipc_eSen_Max];    	
	volatile unsigned int  ImgBlobDetect[ipc_eSen_Max];    
	volatile unsigned int  ImgFrezzStat[ipc_eSen_Max];    	
	volatile unsigned int  ImgVideoTrans[ipc_eSen_Max]; 
	volatile unsigned int  ImgPicp[ipc_eSen_Max];   	

	volatile unsigned int  MmtValid;    			
	volatile unsigned int  MmtPixelX;
	volatile unsigned int  MmtPixelY;
	volatile unsigned int  MmtStat[ipc_eSen_Max];    	
	volatile unsigned int  MmtSelect[ipc_eSen_Max];

	volatile unsigned char  MMTTempStat;		//ack mmt stat
	volatile unsigned char  Mmttargetnum; 			

	volatile unsigned char  MtdState[ipc_eSen_Max];	//record moving obj detect state of each channel

	/***** cmd osd part *****/
	volatile unsigned int  DispGrp[ipc_eSen_Max];       	// eDispGrade
	volatile unsigned int  DispColor[ipc_eSen_Max];  	// eOSDColor or eGRPColor
	
	//don't know the usage
	volatile unsigned int  TrkCoastCount;
	volatile unsigned int  FreezeresetCount;

	//may be not useful
	volatile unsigned int  TvCollimation;   //dianshi zhunzhi   not understanding
	volatile unsigned int  FrCollimation;   //rexiang zhunzhi
	
	volatile unsigned int  	ImgMmtshow[ipc_eSen_Max];	//not sure show what
	volatile unsigned char 	MmtOffsetXY[20]; 		//not sure the func
	
} IMGSTATUS;

typedef struct {
	int MAIN_Sensor;	//13--0
	int Timedisp_9;
	bool OSD_text_show;
	int OSD_text_color;
	int OSD_text_alpha;
	int OSD_text_font;
	int OSD_text_size;
	bool OSD_draw_show;
	int OSD_draw_color;
	int CROSS_AXIS_WIDTH;
	int CROSS_AXIS_HEIGHT;
	int Picp_CROSS_AXIS_WIDTH;
	int Picp_CROSS_AXIS_HEIGHT;
	int ch0_acqRect_width;
	int ch1_acqRect_width;
	int ch2_acqRect_width;	//13--15
	int ch3_acqRect_width;	// 14 -- 0
	int ch4_acqRect_width;
	int ch5_acqRect_width;
	int ch0_acqRect_height;
	int ch1_acqRect_height;
	int ch2_acqRect_height;
	int ch3_acqRect_height;
	int ch4_acqRect_height;
	int ch5_acqRect_height;
	int bomen1_width;
	int bomen2_width;
	int bomen3_width;
	int bomen4_width;
	int bomen5_width;
	int bomen1_height;
	int bomen2_height;	// 14 -- 15
	int bomen3_height;	// 15 -- 0
	int bomen4_height;
	int bomen5_height;
}OSDSTATUS;

typedef struct out_frame_angle
{
    volatile unsigned char out_frame_angle_a[3];
    volatile unsigned char out_frame_angle_e[3];
}out_frame_angle_t;

typedef struct in_frame_angle
{
    volatile unsigned char  in_frame_angle_a[3];
    volatile unsigned char  in_frame_angle_e[3];
}in_frame_angle_t;

typedef struct to_osd_time
{
    volatile unsigned char year[2];
    volatile unsigned char month;
    volatile unsigned char day;
    volatile unsigned char hour;
    volatile unsigned char min;
    volatile unsigned char sec;
    volatile unsigned char msec;
}to_osd_time_t;

typedef struct work_mode
{
    volatile unsigned char mode;
}work_mode_t;

typedef struct laser_work_mode
{
    volatile unsigned char laser_mode;
}laser_work_mode_t;

typedef struct laser_range
{
    volatile unsigned char range[2];
}laser_range_t;

typedef struct man_focal_length
{
    volatile unsigned char length[2];
}man_focal_length_t;

typedef struct photo_dect_temp
{
    volatile  char temp;
}photo_dect_temp_t;

typedef struct prevent_jam
{
    volatile unsigned char stat;
    volatile unsigned char level;
}prevent_jam_t;


int ipc_settrack(unsigned int trackstatus, int trackposx, int trackposy);
int ipc_gettrack(unsigned int* trackstatus, int* trackposx, int* trackposy);
int ipc_setSensorstat(unsigned int unitFaultStat);
int ipc_getSensorstat(unsigned int* unitFaultStat);
int ipc_sendmsg(SENDST* Param,int Mesgthe );
int ipc_recvmsg(SENDST* Param,int Mesgthe );
void* recv_msg(SENDST *RS422);
int send_msg(SENDST *RS422);
int  send_msgpth(SENDST * RS422);
void Ipc_init();
void Ipc_create(int *shm_perm);
void Ipc_uninit();
void  ipc_status_P();
void  ipc_status_V();
IMGSTATUS *ipc_getimgstatus_p();
IMGSTATUS ipc_getimgstatus();
OSDSTATUS *ipc_getosdstatus_p();


#endif
