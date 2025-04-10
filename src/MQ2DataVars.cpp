/*****************************************************************************
MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License, version 2, as published by
the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
******************************************************************************/
#ifndef ISXEQ

#if !defined(CINTERFACE)
//#error /DCINTERFACE
#endif

#define DBG_SPEW


#include "MQ2Main.h"






map<string,PDATAVAR> VariableMap;

inline VOID DeleteMQ2DataVariable(PDATAVAR pVar)
{
    if (pVar->ppHead==&pMacroVariables || pVar->ppHead==&pGlobalVariables)
        VariableMap[pVar->szName]=0;
    if (pVar->pNext)
        pVar->pNext->pPrev=pVar->pPrev;
    if (pVar->pPrev)
        pVar->pPrev->pNext=pVar->pNext;
    else
        *pVar->ppHead=pVar->pNext;
    pVar->Var.Type->FreeVariable(pVar->Var.VarPtr);
    delete pVar;
}

inline PDATAVAR FindMQ2DataVariable(PCHAR Name)
{
    PDATAVAR pFind=VariableMap[Name];
    if (pFind)
        return pFind;
    // local?
    if (gMacroStack)
    {
        PDATAVAR pVar=gMacroStack->Parameters;
        while(pVar)
        {
            if (!strcmp(pVar->szName,Name))
                return pVar;
            pVar=pVar->pNext;
        }
        pVar=gMacroStack->LocalVariables;
        while(pVar)
        {
            if (!strcmp(pVar->szName,Name))
                return pVar;
            pVar=pVar->pNext;
        }
    }
    return 0;
}

BOOL AddMQ2DataEventVariable(PCHAR Name, PCHAR Index, MQ2Type *pType, PDATAVAR *ppHead, PCHAR Default)
{
    if (!ppHead || !Name[0])
        return FALSE;
    if (!Index)
        Index="";
    if (!Default)
        Default="";
    if (FindMQ2Data(Name) || FindMQ2DataType(Name))
        return FALSE; // name in use
    if (!pType)
        return FALSE;

    // create variable
    PDATAVAR pVar = new DATAVAR;
    pVar->ppHead=ppHead;
    pVar->pNext=*ppHead;
    *ppHead=pVar;
    pVar->pPrev=0;
    if (pVar->pNext)
        pVar->pNext->pPrev=pVar;
    strcpy(pVar->szName,Name);
    if (Index[0])
    {
        CDataArray *pArray=new CDataArray(pType,Index,Default);
        pVar->Var.Ptr=pArray;

    }
    else
    {
        pVar->Var.Type=pType;
        pType->InitVariable(pVar->Var.VarPtr);
        pType->FromString(pVar->Var.VarPtr,Default);
    }
    if (pVar->ppHead==&pMacroVariables || pVar->ppHead==&pGlobalVariables)
    {
        VariableMap[Name]=pVar;
    }
    return TRUE;
}


BOOL AddMQ2DataVariableBy(PCHAR Name, PCHAR Index, MQ2Type *pType, PDATAVAR *ppHead, PCHAR Default, BOOL ByData)
{
    if (!ppHead || !Name[0])
        return FALSE;
    if (!Index)
        Index="";
    if (!Default)
        Default="";
    if (FindMQ2DataVariable(Name) || FindMQ2Data(Name) || FindMQ2DataType(Name))
        return FALSE; // name in use
    if (!pType)
        return FALSE;

    // create variable
    PDATAVAR pVar = new DATAVAR;
    pVar->ppHead=ppHead;
    pVar->pNext=*ppHead;
    *ppHead=pVar;
    pVar->pPrev=0;
    if (pVar->pNext)
        pVar->pNext->pPrev=pVar;
    strcpy(pVar->szName,Name);
    if (Index[0])
    {
        CDataArray *pArray=new CDataArray(pType,Index,Default);
        pVar->Var.Ptr=pArray;
        pVar->Var.Type=pArrayType;
    }
    else
    {
        pVar->Var.Type=pType;
        pType->InitVariable(pVar->Var.VarPtr);
        if (ByData)
            pType->FromData(pVar->Var.VarPtr,*(MQ2TYPEVAR *)Default);
        else
            pType->FromString(pVar->Var.VarPtr,Default);
    }
    if (!(gMacroStack && (ppHead==&gMacroStack->LocalVariables || ppHead==&gMacroStack->Parameters)))
    {
        VariableMap[Name]=pVar;
    }
    return TRUE;
}

BOOL AddMQ2DataVariable(PCHAR Name, PCHAR Index, MQ2Type *pType, PDATAVAR *ppHead, PCHAR Default)
{
    return AddMQ2DataVariableBy(Name, Index, pType, ppHead, Default, 0);
}


BOOL AddMQ2DataVariableFromData(PCHAR Name, PCHAR Index, MQ2Type *pType, PDATAVAR *ppHead, MQ2TYPEVAR Default)
{
    return AddMQ2DataVariableBy(Name, Index, pType, ppHead, (PCHAR)&Default, 1);
}



PDATAVAR *FindVariableScope(PCHAR Name)
{
    if (!stricmp(Name,"global"))
        return &pGlobalVariables;
    if (!stricmp(Name,"outer"))
        return &pMacroVariables;
    if (gMacroStack && !stricmp(Name,"local"))
        return &gMacroStack->LocalVariables;
    return 0;
}

BOOL DeleteMQ2DataVariable(PCHAR Name)
{
    if (PDATAVAR pVar=FindMQ2DataVariable(Name))
    {
        DeleteMQ2DataVariable(pVar);
        return TRUE;
    }
    return FALSE;
}

VOID ClearMQ2DataVariables(PDATAVAR *ppHead)
{
    PDATAVAR pVar=*ppHead;
    while(pVar)
    {
        PDATAVAR pNext=pVar->pNext;
        DeleteMQ2DataVariable(pVar);
        pVar=pNext;
    }
    *ppHead=0;
}

VOID NewDeclareVar(PSPAWNINFO pChar, PCHAR szLine)
{
    if (!szLine[0])
    {
        SyntaxError("Usage: /declare <varname|varname[array extents]> [type] [global|outer|local] [default value]");
        return;
    }
    PDATAVAR *pScope=0;
    MQ2Type *pType=0;
    CHAR szIndex[MAX_STRING]={0};
    CHAR szName[MAX_STRING]={0};
    GetArg(szName,szLine,1);
    CHAR Arg[MAX_STRING]={0};
    GetArg(Arg,szLine,2);
    PCHAR pDefault;
    if (pScope=FindVariableScope(Arg))
    {
        // scope comes AFTER type, so next must be default
        pDefault=GetNextArg(szLine,2);
    }
    else if (pType=FindMQ2DataType(Arg))
    {
        // next is either scope or default
        GetArg(Arg,szLine,3);
        if (pScope=FindVariableScope(Arg))
        {
            // next is default
            pDefault=GetNextArg(szLine,3);
        }
        else
        {
            // this is default
            pDefault=GetNextArg(szLine,2);
        }
    }
    else
    {
        // this is default
        pDefault=GetNextArg(szLine);
    }
    if (!pScope)
    { 
        if (gMacroStack)
            pScope=&gMacroStack->LocalVariables;
        else
        {
            MacroError("/declare '%s' failed.  No macro in execution and no variable scope given",szName);
            return;
        }
    }
    if (!pType)
        pType=pStringType;
    if (pType==pArrayType)
    {
        MacroError("/declare array failed.  To declare an array use: /declare name[size] <type> <scope> <default element value>");
        MacroError("Example: /declare MyStringArray[25] string local ARRAY-UNDEFINED-ELEMENT");
        return;
    }

    if (PCHAR pBracket=strchr(szName,'['))
    {
        *pBracket=0;
        strcpy(szIndex,&pBracket[1]);
        szIndex[strlen(szIndex)-1]=0;
    }
    if (pType==pTimerType && szIndex[0])
    {
        MacroError("Cannot /declare an array of timers");
        return;
    }

    if (!AddMQ2DataVariable(szName,szIndex,pType,pScope,pDefault))
    {
        MacroError("/declare '%s' failed.  Name already in use.",szName);
    }
    else
    {
        if (pType==pTimerType)
        {
            PMQTIMER pTimer=(PMQTIMER)((*pScope)->Var.Ptr);
            strcpy(pTimer->szName,szName);
        }
    }
}

VOID NewDeleteVarCmd(PSPAWNINFO pChar, PCHAR szLine)
{
    if (szLine[0]==0) {
        SyntaxError("Usage: /deletevar <varname|* global>");
    } 
    else 
    {
        // destroy old variable
        if (!DeleteMQ2DataVariable(szLine))
        {
            if (!strnicmp(szLine,"* global",8))
            {
                ClearMQ2DataVariables(&pGlobalVariables);
            }
            else
                MacroError("Variable '%s' does not exist",szLine);
        }
    }
}

VOID NewVarset(PSPAWNINFO pChar, PCHAR szLine)
{
    if (!szLine[0])
    {
        SyntaxError("Usage: /varset <varname> <new value>");
        return;
    }
    CHAR szName[MAX_STRING]={0};
    GetArg(szName,szLine,1);
    PCHAR szRest=GetNextArg(szLine);
    CHAR szIndex[MAX_STRING]={0};
    if (PCHAR pBracket=strchr(szName,'['))
    {
        *pBracket=0;
        strcpy(szIndex,&pBracket[1]);
    }
    PDATAVAR pVar=FindMQ2DataVariable(szName);
    if (!pVar)
    {
        MacroError("/varset failed, variable '%s' not found",szName);
        return;
    }
    if (szIndex[0])
    {
        if (pVar->Var.Type!=pArrayType)
        {
            MacroError("/varset '%s' failed, array form on non-array",szName);
            return;
        }
        CDataArray *pArray=(CDataArray*)pVar->Var.Ptr;
        int N=pArray->GetElement(szIndex);
        if (N==-1)
        {
            MacroError("/varset '%s[%d]' failed, out of bounds on array",szName,N);
            return;
        }
        if (!pArray->pType->FromString(pArray->pData[N],szRest))
        {
            MacroError("/varset '%s[%d]' failed, array element type rejected new value",szName,N);
        }
    }
    else
    {
        if (!pVar->Var.Type->FromString(pVar->Var.VarPtr,szRest))
        {
            MacroError("/varset '%s' failed, variable type rejected new value",szName);
        }
    }
}

VOID NewVarcalc(PSPAWNINFO pChar, PCHAR szLine)
{
    if (!szLine[0])
    {
        SyntaxError("Usage: /varcalc <varname> <formula>");
        return;
    }
    CHAR szName[MAX_STRING]={0};
    GetArg(szName,szLine,1);
    PCHAR szRest=GetNextArg(szLine);
    if (!szRest || !szRest[0])
    {
        SyntaxError("Usage: /varcalc <varname> <formula>");
        return;
    }

    DOUBLE Result;
    if (!Calculate(szRest,Result))
    {
        MacroError("/varcalc '%s' failed.  Could not calculate '%s'",szName,szRest);
        return;
    }
    sprintf(szRest,"%f",Result);


    CHAR szIndex[MAX_STRING]={0};
    if (PCHAR pBracket=strchr(szName,'['))
    {
        *pBracket=0;
        strcpy(szIndex,&pBracket[1]);
    }
    PDATAVAR pVar=FindMQ2DataVariable(szName);
    if (!pVar)
    {
        MacroError("/varcalc failed, variable '%s' not found",szName);
        return;
    }
    if (szIndex[0])
    {
        if (pVar->Var.Type!=pArrayType)
        {
            MacroError("/varcalc '%s' failed, array form on non-array",szName);
            return;
        }
        CDataArray *pArray=(CDataArray*)pVar->Var.Ptr;
        int N=pArray->GetElement(szIndex);
        if (N==-1)
        {
            MacroError("/varcalc '%s[%d]' failed, out of bounds on array",szName,N);
            return;
        }
        if (!pArray->pType->FromString(pArray->pData[N],szRest))
        {
            MacroError("/varcalc '%s[%d]' failed, array element type rejected new value",szName,N);
        }
    }
    else
    {
        if (!pVar->Var.Type->FromString(pVar->Var.VarPtr,szRest))
        {
            MacroError("/varcalc '%s' failed, variable type rejected new value",szName);
        }
    }
}

VOID NewVardata(PSPAWNINFO pChar, PCHAR szLine)
{
    if (!szLine[0])
    {
        SyntaxError("Usage: /vardata <varname> <new mq2data value>");
        return;
    }
    CHAR szName[MAX_STRING]={0};
    GetArg(szName,szLine,1);
    PCHAR szRest=GetNextArg(szLine);
    if (!szRest || !szRest[0])
    {
        SyntaxError("Usage: /vardata <varname> <new mq2data value>");
        return;
    }
    CHAR szIndex[MAX_STRING]={0};
    if (PCHAR pBracket=strchr(szName,'['))
    {
        *pBracket=0;
        strcpy(szIndex,&pBracket[1]);
    }
    PDATAVAR pVar=FindMQ2DataVariable(szName);
    if (!pVar)
    {
        MacroError("/vardata '%s' failed, variable not found",szName);
        return;
    }
    MQ2TYPEVAR Result;
    if (!ParseMQ2DataPortion(szRest,Result))
    {
        MacroError("/vardata '%s' failed, MQ2Data portion '%s' unparsable",szName,szRest);
        return;
    }

    if (szIndex[0])
    {
        if (pVar->Var.Type!=pArrayType)
        {
            MacroError("/vardata '%s' failed, array form on non-array",szName);
            return;
        }
        CDataArray *pArray=(CDataArray*)pVar->Var.Ptr;
        int N=pArray->GetElement(szIndex);
        if (N==-1)
        {
            MacroError("/vardata '%s[%d]' failed, out of bounds on array",szName,N);
            return;
        }
        if (!pVar->Var.Type->FromData(pVar->Var.VarPtr,Result))
        {
            MacroError("/vardata '%s[%d]'failed, array element type rejected new value",szName,N);
        }
    }
    else
    {
        if (!pVar->Var.Type->FromData(pVar->Var.VarPtr,Result))
        {
            MacroError("/vardata '%s' failed, variable type rejected new value",szName);
        }
    }
}

#else
VOID AddCustomEvent(PEVENTLIST pEList, PCHAR szLine)
{
    PEVENTQUEUE pEvent = NULL;
    if (!pEList->pEventFunc) return;
    pEvent = (PEVENTQUEUE)malloc(sizeof(EVENTQUEUE));
    if (!pEvent) return;
    ZeroMemory(pEvent,sizeof(EVENTQUEUE));
    pEvent->Type = EVENT_CUSTOM;
    pEvent->pEventList = pEList;
    CHAR szParamName[MAX_STRING] = {0};
    CHAR szParamType[MAX_STRING] = {0};
    GetFuncParam(pEList->pEventFunc->Line,0,szParamName,szParamType);
    MQ2Type *pType = FindMQ2DataType(szParamType);
    if (!pType)
        pType=pStringType;

    AddMQ2DataEventVariable(szParamName,"",pType,&pEvent->Parameters,szLine);

    if (!gEventQueue) 
    {
        gEventQueue = pEvent;
    } 
    else 
    {
        PEVENTQUEUE pTemp;
        for (pTemp = gEventQueue;pTemp->pNext;pTemp=pTemp->pNext);
        pTemp->pNext = pEvent;
        pEvent->pPrev=pTemp;
    }
}
#endif
#ifndef SafeXLoc
#error 1
#endif
VOID CheckChatForEvent(PCHAR szMsg)
{
}

VOID DropTimers(VOID)
{
    PMQTIMER pTimer=gTimer;
    CHAR szOrig[MAX_STRING] = {0};
    while(pTimer)
    {
        if (pTimer->Current)
        {
            pTimer->Current--;
            if (!pTimer->Current)
            {
                itoa(pTimer->Original,szOrig,10);
            }
        }
        pTimer=pTimer->pNext;
    }
}
