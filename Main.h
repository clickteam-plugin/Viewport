// Object identifier "ViPo"
#define IDENTIFIER	MAKEID(V,i,P,o)

// ------------------------------
// DEFINITION OF CONDITIONS CODES
// ------------------------------
#define	CND_CONDITION				0
#define	CND_LAST					0

// ---------------------------
// DEFINITION OF ACTIONS CODES
// ---------------------------
#define	ACT_ACTION					0
#define	ACT_LAST					10

// -------------------------------
// DEFINITION OF EXPRESSIONS CODES
// -------------------------------
#define	EXP_EXPRESSION				0
#define	EXP_LAST                    0

// --------------------------------
// EDITION OF OBJECT DATA STRUCTURE
// --------------------------------
// These values let you store data in your extension that will be saved in the CCA.
// You would use these with a dialog...

typedef struct tagEDATA_V1
{
	extHeader		eHeader;
	short			sx;
	short			sy;
	short			swidth;
	short			sheight;
	bool			rotationAA;

} EDITDATA;
typedef EDITDATA _far *			LPEDATA;

// Object versions
#define	KCX_CURRENT_VERSION			1

// --------------------------------
// RUNNING OBJECT DATA STRUCTURE
// --------------------------------
// If you want to store anything between actions/conditions/expressions
// you should store it here. Also, some OEFLAGS require you to add
// structures to this structure.

typedef struct tagRDATA
{
	headerObject	rHo;					// Header
	rCom			roc;
	rSpr			rs;
	rMvt			rm;
	rVal			rv;
	bool			FlipHoz;
	bool			FlipVer;
	double			Angle;
	bool			RotationAA;
	long			SourceX;
	long			SourceY;
	long			SourceWidth;
	long			SourceHeight;

} RUNDATA;
typedef	RUNDATA	_far *			LPRDATA;

// Size when editing the object under level editor
// -----------------------------------------------
#define	MAX_EDITSIZE			sizeof(EDITDATA)

// Default flags
// -------------
#define	OEFLAGS		OEFLAG_SPRITES|OEFLAG_MOVEMENTS|OEFLAG_VALUES|OEFLAG_BACKSAVE|OEFLAG_SCROLLINGINDEPENDANT
#define	OEPREFS		OEPREFS_BACKSAVE|OEPREFS_SCROLLINGINDEPENDANT|OEPREFS_LOADONCALL|OEPREFS_BACKEFFECTS|OEPREFS_KILL

/* See OEFLAGS.txt for more info on these useful things! */


// If to handle message, specify the priority of the handling procedure
// 0= low, 255= very high. You should use 100 as normal.                                                
// --------------------------------------------------------------------
#define	WINDOWPROC_PRIORITY		100
