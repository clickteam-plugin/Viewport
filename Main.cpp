// ============================================================================
//
// This file are where the Conditions/Actions/Expressions are defined.
// You can manually enter these, or use CICK (recommended)
// See the Extension FAQ in this SDK for more info and where to download it
//
// ============================================================================

// Common Include
#include	"common.h"

// Quick memo: content of the eventInformations arrays
// ---------------------------------------------------
// Menu ID
// String ID
// Code
// Flags
// Number_of_parameters
// Parameter_type [Number_of_parameters]
// Parameter_TitleString [Number_of_parameters]

// Definitions of parameters for each condition
short conditionsInfos[]=
		{
		0,
		};

// Definitions of parameters for each action
short actionsInfos[]=
	{ 
	AID_actSetWidth,	AID_actSetWidth,	0,	0,	1,	PARAM_EXPRESSION,	AP0ID_actSetWidth,
	AID_actSetHeight,	AID_actSetHeight,	1,	0,	1,	PARAM_EXPRESSION,	AP0ID_actSetHeight,
	AID_actSetSourceRegion,	AID_actSetSourceRegion,	2,	0,	4,	PARAM_EXPRESSION,	PARAM_EXPRESSION,	PARAM_EXPRESSION,	PARAM_EXPRESSION,	AP0ID_actSetSourceRegion,	AP1ID_actSetSourceRegion,	AP2ID_actSetSourceRegion,	AP3ID_actSetSourceRegion,
	AID_actSetSourceRegionCenter,	AID_actSetSourceRegionCenter,	3,	0,	4,	PARAM_EXPRESSION,	PARAM_EXPRESSION,	PARAM_EXPRESSION,	PARAM_EXPRESSION,	AP0ID_actSetSourceRegionCenter,	AP1ID_actSetSourceRegionCenter,	AP2ID_actSetSourceRegionCenter,	AP3ID_actSetSourceRegionCenter,
	AID_actHorizontalFlipOn,	AID_actHorizontalFlipOn,	4,	0,	0,
	AID_actHorizontalFlipOff,	AID_actHorizontalFlipOff,	5,	0,	0,
	AID_actVerticalFlipOn,	AID_actVerticalFlipOn,	6,	0,	0,
	AID_actVerticalFlipOff,	AID_actVerticalFlipOff,	7,	0,	0,
	AID_actRotate,	AID_actRotate,	8,	0,	1,	PARAM_EXPRESSION,	AP0ID_actRotate,
	AID_actUpdate,	AID_actUpdate,	9,	0,	0,
	0 };

// Definitions of parameters for each expression
short expressionsInfos[]=
		{
		0
		};



// ============================================================================
//
// CONDITION ROUTINES
// 
// ============================================================================

// -----------------
// Sample Condition
// -----------------
// Returns TRUE when the two values are equal!
// 

long WINAPI DLLExport Condition(LPRDATA rdPtr, long param1, long param2)
{

//  **** Still use this method for 1 or 2 parameters ****	
//	if (param1==param2)	
//		return TRUE;

	long p1 = CNC_GetParameter(rdPtr);
	long p2 = CNC_GetParameter(rdPtr);
	long p3 = CNC_GetParameter(rdPtr);

	if ((p1 + p2)==p3)
		return TRUE;
		 
	return FALSE;
}


// ============================================================================
//
// ACTIONS ROUTINES
// 
// ============================================================================

short WINAPI DLLExport actSetWidth(LPRDATA rdPtr, long param1, long param2)
{
	rdPtr->rHo.hoImgWidth = max((short)param1,1);
	rdPtr->roc.rcChanged = true;
	return 0;
}

short WINAPI DLLExport actSetHeight(LPRDATA rdPtr, long param1, long param2)
{
	rdPtr->rHo.hoImgHeight = max((short)param1,1);
	rdPtr->roc.rcChanged = true;
	return 0;
}

short WINAPI DLLExport actSetSourceRegion(LPRDATA rdPtr, long param1, long param2)
{
	long p1=CNC_GetIntParameter(rdPtr);
	long p2=CNC_GetIntParameter(rdPtr);
	long p3=CNC_GetIntParameter(rdPtr);
	long p4=CNC_GetIntParameter(rdPtr);

	rdPtr->SourceX = p1;
	rdPtr->SourceY = p2;
	rdPtr->SourceWidth = max(p3,1);
	rdPtr->SourceHeight = max(p4,1);
	rdPtr->roc.rcChanged = true;

	return 0;
}

short WINAPI DLLExport actSetSourceRegionCenter(LPRDATA rdPtr, long param1, long param2)
{
	long p1=CNC_GetIntParameter(rdPtr);
	long p2=CNC_GetIntParameter(rdPtr);
	long p3=CNC_GetIntParameter(rdPtr);
	long p4=CNC_GetIntParameter(rdPtr);

	rdPtr->SourceX = p1-(p3/2);
	rdPtr->SourceY = p2-(p4/2);
	rdPtr->SourceWidth = max(p3,1);
	rdPtr->SourceHeight = max(p4,1);

	rdPtr->roc.rcChanged = true;

	return 0;
}

short WINAPI DLLExport actHorizontalFlipOn(LPRDATA rdPtr, long param1, long param2)
{
	rdPtr->FlipHoz = true;
	rdPtr->roc.rcChanged = true;
	return 0;
}

short WINAPI DLLExport actHorizontalFlipOff(LPRDATA rdPtr, long param1, long param2)
{
	rdPtr->FlipHoz = false;
	rdPtr->roc.rcChanged = true;
	return 0;
}

short WINAPI DLLExport actVerticalFlipOn(LPRDATA rdPtr, long param1, long param2)
{
	rdPtr->FlipVer = true;
	rdPtr->roc.rcChanged = true;
	return 0;
}

short WINAPI DLLExport actVerticalFlipOff(LPRDATA rdPtr, long param1, long param2)
{
	rdPtr->FlipVer = false;
	rdPtr->roc.rcChanged = true;
	return 0;
}

short WINAPI DLLExport actRotate(LPRDATA rdPtr, long param1, long param2)
{
	long tmpf=CNC_GetFloatValue(rdPtr, 0 ); float p1=*(float *)&tmpf;
	rdPtr->Angle = p1 * ( PI / 180.0);
	rdPtr->roc.rcChanged = true;
	return 0;
}

short WINAPI DLLExport actUpdate(LPRDATA rdPtr, long param1, long param2)
{
	rdPtr->roc.rcChanged = true;
	return 0;
}


// ============================================================================
//
// EXPRESSIONS ROUTINES
// 
// ============================================================================



// ----------------------------------------------------------
// Condition / Action / Expression jump table
// ----------------------------------------------------------
// Contains the address inside the extension of the different
// routines that handle the action, conditions and expressions.
// Located at the end of the source for convinience
// Must finish with a 0
//
long (WINAPI * ConditionJumps[])(LPRDATA rdPtr, long param1, long param2) = 
	{ 
	0
	};
	
short (WINAPI * ActionJumps[])(LPRDATA rdPtr, long param1, long param2) =
	{
	actSetWidth,
	actSetHeight,
	actSetSourceRegion,
	actSetSourceRegionCenter,
	actHorizontalFlipOn,
	actHorizontalFlipOff,
	actVerticalFlipOn,
	actVerticalFlipOff,
	actRotate,
	actUpdate,
	0
	};

long (WINAPI * ExpressionJumps[])(LPRDATA rdPtr, long param) = 
	{     
	0
	};