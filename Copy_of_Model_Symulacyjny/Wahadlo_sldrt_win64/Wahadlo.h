/*
 * Wahadlo.h
 *
 * Code generation for model "Wahadlo".
 *
 * Model version              : 1.289
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Tue Nov 07 13:04:42 2017
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Wahadlo_h_
#define RTW_HEADER_Wahadlo_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Wahadlo_COMMON_INCLUDES_
# define Wahadlo_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "sldrtdef.h"
#endif                                 /* Wahadlo_COMMON_INCLUDES_ */

#include "Wahadlo_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ()
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ()
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ()
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ()
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ()
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->ModelData.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->ModelData.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->ModelData.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->ModelData.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define Wahadlo_rtModel                RT_MODEL_Wahadlo_T

/* Block signals (auto storage) */
typedef struct {
  real_T Encoder[5];                   /* '<S3>/Encoder' */
  real_T Sum;                          /* '<S3>/Sum' */
  real_T Cart_pos;                     /* '<S9>/Gain3' */
  real_T AngleScale;                   /* '<S3>/Angle Scale' */
  real_T PendPosOut;                   /* '<S2>/angle normalization' */
  real_T Pend_vel;                     /* '<S9>/Gain2' */
  real_T Cart_vel;                     /* '<S9>/Gain4' */
  real_T Cart_acc;                     /* '<S1>/Gain4' */
  real_T Gain2;                        /* '<Root>/Gain2' */
  real_T Gain3;                        /* '<Root>/Gain3' */
  real_T Gain4;                        /* '<Root>/Gain4' */
  real_T Gain5;                        /* '<Root>/Gain5' */
  real_T Subtract;                     /* '<Root>/Subtract' */
  real_T Gain6;                        /* '<Root>/Gain6' */
  real_T Abs;                          /* '<Root>/Abs' */
  real_T Add1;                         /* '<Root>/Add1' */
  real_T PWM[3];                       /* '<S3>/PWM' */
  real_T SliderGain;                   /* '<S11>/Slider Gain' */
  real_T Switch3;                      /* '<Root>/Switch3' */
  real_T Saturation[3];                /* '<S3>/Saturation' */
  real_T ResetEncoder[5];              /* '<S3>/ResetEncoder' */
  real_T ResetSource[3];               /* '<S3>/ResetSource' */
  real_T LimitFlag[3];                 /* '<S3>/LimitFlag' */
  real_T LimitFlagSource[3];           /* '<S3>/LimitFlagSource' */
  real_T LimitSource[3];               /* '<S3>/LimitSource' */
  real_T SetLimit[3];                  /* '<S3>/SetLimit' */
  real_T LimitSwitch[3];               /* '<S3>/LimitSwitch' */
  real_T PWMPrescaler;                 /* '<S3>/PWMPrescaler' */
  real_T PWMPrescalerSource;           /* '<S3>/PWMPrescalerSource' */
  real_T ResetSwitchFlag[3];           /* '<S3>/ResetSwitchFlag ' */
  real_T ResetSwitchFlagSource[3];     /* '<S3>/ResetSwitchFlagSource' */
  real_T ThermFlag[3];                 /* '<S3>/ThermFlag ' */
  real_T ThermFlagSource[3];           /* '<S3>/ThermFlagSource' */
  real_T ResetEncoders;                /* '<Root>/Reset Encoders' */
  real_T In;                           /* '<S8>/In' */
  boolean_T Logic[2];                  /* '<S7>/Logic' */
} B_Wahadlo_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T TmpLatchAtSampleandHoldInport1_;/* synthesized block */
  real_T Memory_PreviousInput;         /* '<S9>/Memory' */
  real_T Memory1_PreviousInput;        /* '<S9>/Memory1' */
  real_T Memory1_PreviousInput_m;      /* '<S1>/Memory1' */
  struct {
    void *LoggedData;
  } PendulumControlandStatesExperim;   /* '<Root>/Pendulum  Control and States (Experiment)' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWs_PWORK;                      /* '<S10>/FromWs' */

  struct {
    int_T PrevIndex;
  } FromWs_IWORK;                      /* '<S10>/FromWs' */

  int8_T SampleandHold_SubsysRanBC;    /* '<Root>/Sample and Hold' */
  boolean_T Memory_PreviousInput_b;    /* '<S7>/Memory' */
} DW_Wahadlo_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState SampleandHold_Trig_ZCE;   /* '<Root>/Sample and Hold' */
} PrevZCX_Wahadlo_T;

/* Backward compatible GRT Identifiers */
#define rtB                            Wahadlo_B
#define BlockIO                        B_Wahadlo_T
#define rtP                            Wahadlo_P
#define Parameters                     P_Wahadlo_T
#define rtDWork                        Wahadlo_DW
#define D_Work                         DW_Wahadlo_T
#define rtPrevZCSigState               Wahadlo_PrevZCX
#define PrevZCSigStates                PrevZCX_Wahadlo_T

/* Parameters (auto storage) */
struct P_Wahadlo_T_ {
  real_T E;                            /* Variable: E
                                        * Referenced by:
                                        *   '<Root>/Gain10'
                                        *   '<S4>/Constant'
                                        */
  real_T Jr;                           /* Variable: Jr
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T K[4];                         /* Variable: K
                                        * Referenced by:
                                        *   '<Root>/Gain2'
                                        *   '<Root>/Gain3'
                                        *   '<Root>/Gain4'
                                        *   '<Root>/Gain5'
                                        */
  real_T Sensors_T0;                   /* Mask Parameter: Sensors_T0
                                        * Referenced by:
                                        *   '<S9>/Gain2'
                                        *   '<S9>/Gain4'
                                        */
  real_T Acceleration_T0;              /* Mask Parameter: Acceleration_T0
                                        * Referenced by: '<S1>/Gain4'
                                        */
  real_T CompareToConstant1_const;     /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T SliderGain_gain;              /* Mask Parameter: SliderGain_gain
                                        * Referenced by: '<S11>/Slider Gain'
                                        */
  real_T AlfaNormalization_pos;        /* Mask Parameter: AlfaNormalization_pos
                                        * Referenced by: '<S2>/pos'
                                        */
  boolean_T SRFlipFlop_initial_condition;/* Mask Parameter: SRFlipFlop_initial_condition
                                          * Referenced by: '<S7>/Memory'
                                          */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Gain9_Gain;                   /* Expression: 0.5
                                        * Referenced by: '<Root>/Gain9'
                                        */
  real_T Gain8_Gain;                   /* Expression: 0.1
                                        * Referenced by: '<Root>/Gain8'
                                        */
  real_T Normal_Value;                 /* Expression: 0
                                        * Referenced by: '<Root>/Normal'
                                        */
  real_T Reset_Value;                  /* Expression: 1
                                        * Referenced by: '<Root>/Reset'
                                        */
  real_T _Y0;                          /* Expression: initCond
                                        * Referenced by: '<S8>/ '
                                        */
  real_T Encoder_P1_Size[2];           /* Computed Parameter: Encoder_P1_Size
                                        * Referenced by: '<S3>/Encoder'
                                        */
  real_T Encoder_P1;                   /* Expression: BaseAddress
                                        * Referenced by: '<S3>/Encoder'
                                        */
  real_T Encoder_P2_Size[2];           /* Computed Parameter: Encoder_P2_Size
                                        * Referenced by: '<S3>/Encoder'
                                        */
  real_T Encoder_P2;                   /* Expression: T0
                                        * Referenced by: '<S3>/Encoder'
                                        */
  real_T Encoder1024PPR_Gain;          /* Expression: 1
                                        * Referenced by: '<S3>/Encoder 1024 PPR'
                                        */
  real_T PosCartScale_Gain;            /* Expression: 5.7053e-005
                                        * Referenced by: '<S3>/PosCart Scale'
                                        */
  real_T CartOffset_Value;             /* Expression: -1.86/2
                                        * Referenced by: '<S3>/Cart Offset'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1
                                        * Referenced by: '<S9>/Gain3'
                                        */
  real_T TmpLatchAtSampleandHoldInport1_;/* Expression: 0
                                          * Referenced by: synthesized block
                                          */
  real_T pi_Value;                     /* Expression: pi
                                        * Referenced by: '<S2>/pi'
                                        */
  real_T AngleScale_Gain;              /* Expression: 2*pi/4096
                                        * Referenced by: '<S3>/Angle Scale'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S9>/Memory'
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<S9>/Memory1'
                                        */
  real_T Memory1_X0_b;                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory1'
                                        */
  real_T Constant1_Value;              /* Expression: pi/2
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Gain6_Gain;                   /* Expression: -0.35
                                        * Referenced by: '<Root>/Gain6'
                                        */
  real_T Gain_Gain;                    /* Expression: 5
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Gain7_Gain;                   /* Expression: 10
                                        * Referenced by: '<Root>/Gain7'
                                        */
  real_T PWM_P1_Size[2];               /* Computed Parameter: PWM_P1_Size
                                        * Referenced by: '<S3>/PWM'
                                        */
  real_T PWM_P1;                       /* Expression: BaseAddress
                                        * Referenced by: '<S3>/PWM'
                                        */
  real_T PWM_P2_Size[2];               /* Computed Parameter: PWM_P2_Size
                                        * Referenced by: '<S3>/PWM'
                                        */
  real_T PWM_P2;                       /* Expression: T0
                                        * Referenced by: '<S3>/PWM'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.7
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 0.5
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -0.5
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T ResetEncoder_P1_Size[2];      /* Computed Parameter: ResetEncoder_P1_Size
                                        * Referenced by: '<S3>/ResetEncoder'
                                        */
  real_T ResetEncoder_P1;              /* Expression: BaseAddress
                                        * Referenced by: '<S3>/ResetEncoder'
                                        */
  real_T ResetEncoder_P2_Size[2];      /* Computed Parameter: ResetEncoder_P2_Size
                                        * Referenced by: '<S3>/ResetEncoder'
                                        */
  real_T ResetEncoder_P2;              /* Expression: T0
                                        * Referenced by: '<S3>/ResetEncoder'
                                        */
  real_T ResetSource_Value[3];         /* Expression: [1 1 1 ]
                                        * Referenced by: '<S3>/ResetSource'
                                        */
  real_T LimitFlag_P1_Size[2];         /* Computed Parameter: LimitFlag_P1_Size
                                        * Referenced by: '<S3>/LimitFlag'
                                        */
  real_T LimitFlag_P1;                 /* Expression: BaseAddress
                                        * Referenced by: '<S3>/LimitFlag'
                                        */
  real_T LimitFlag_P2_Size[2];         /* Computed Parameter: LimitFlag_P2_Size
                                        * Referenced by: '<S3>/LimitFlag'
                                        */
  real_T LimitFlag_P2;                 /* Expression: T0
                                        * Referenced by: '<S3>/LimitFlag'
                                        */
  real_T LimitFlagSource_Value[3];     /* Expression: [0 0 0]
                                        * Referenced by: '<S3>/LimitFlagSource'
                                        */
  real_T LimitSource_Value[3];         /* Expression: [129 116 300]
                                        * Referenced by: '<S3>/LimitSource'
                                        */
  real_T SetLimit_P1_Size[2];          /* Computed Parameter: SetLimit_P1_Size
                                        * Referenced by: '<S3>/SetLimit'
                                        */
  real_T SetLimit_P1;                  /* Expression: BaseAddress
                                        * Referenced by: '<S3>/SetLimit'
                                        */
  real_T SetLimit_P2_Size[2];          /* Computed Parameter: SetLimit_P2_Size
                                        * Referenced by: '<S3>/SetLimit'
                                        */
  real_T SetLimit_P2;                  /* Expression: T0
                                        * Referenced by: '<S3>/SetLimit'
                                        */
  real_T LimitSwitch_P1_Size[2];       /* Computed Parameter: LimitSwitch_P1_Size
                                        * Referenced by: '<S3>/LimitSwitch'
                                        */
  real_T LimitSwitch_P1;               /* Expression: BaseAddress
                                        * Referenced by: '<S3>/LimitSwitch'
                                        */
  real_T LimitSwitch_P2_Size[2];       /* Computed Parameter: LimitSwitch_P2_Size
                                        * Referenced by: '<S3>/LimitSwitch'
                                        */
  real_T LimitSwitch_P2;               /* Expression: T0
                                        * Referenced by: '<S3>/LimitSwitch'
                                        */
  real_T PWMPrescaler_P1_Size[2];      /* Computed Parameter: PWMPrescaler_P1_Size
                                        * Referenced by: '<S3>/PWMPrescaler'
                                        */
  real_T PWMPrescaler_P1;              /* Expression: BaseAddress
                                        * Referenced by: '<S3>/PWMPrescaler'
                                        */
  real_T PWMPrescaler_P2_Size[2];      /* Computed Parameter: PWMPrescaler_P2_Size
                                        * Referenced by: '<S3>/PWMPrescaler'
                                        */
  real_T PWMPrescaler_P2;              /* Expression: T0
                                        * Referenced by: '<S3>/PWMPrescaler'
                                        */
  real_T PWMPrescalerSource_Value;     /* Expression: 0
                                        * Referenced by: '<S3>/PWMPrescalerSource'
                                        */
  real_T ResetSwitchFlag_P1_Size[2];   /* Computed Parameter: ResetSwitchFlag_P1_Size
                                        * Referenced by: '<S3>/ResetSwitchFlag '
                                        */
  real_T ResetSwitchFlag_P1;           /* Expression: BaseAddress
                                        * Referenced by: '<S3>/ResetSwitchFlag '
                                        */
  real_T ResetSwitchFlag_P2_Size[2];   /* Computed Parameter: ResetSwitchFlag_P2_Size
                                        * Referenced by: '<S3>/ResetSwitchFlag '
                                        */
  real_T ResetSwitchFlag_P2;           /* Expression: T0
                                        * Referenced by: '<S3>/ResetSwitchFlag '
                                        */
  real_T ResetSwitchFlagSource_Value[3];/* Expression: [ 0 0 0 ]
                                         * Referenced by: '<S3>/ResetSwitchFlagSource'
                                         */
  real_T ThermFlag_P1_Size[2];         /* Computed Parameter: ThermFlag_P1_Size
                                        * Referenced by: '<S3>/ThermFlag '
                                        */
  real_T ThermFlag_P1;                 /* Expression: BaseAddress
                                        * Referenced by: '<S3>/ThermFlag '
                                        */
  real_T ThermFlag_P2_Size[2];         /* Computed Parameter: ThermFlag_P2_Size
                                        * Referenced by: '<S3>/ThermFlag '
                                        */
  real_T ThermFlag_P2;                 /* Expression: T0
                                        * Referenced by: '<S3>/ThermFlag '
                                        */
  real_T ThermFlagSource_Value[3];     /* Expression: [1 1 1]
                                        * Referenced by: '<S3>/ThermFlagSource'
                                        */
  uint8_T ManualSwitch_CurrentSetting; /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  uint8_T ManualSwitch1_CurrentSetting;/* Computed Parameter: ManualSwitch1_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch1'
                                        */
  uint8_T ResetEncoders_CurrentSetting;/* Computed Parameter: ResetEncoders_CurrentSetting
                                        * Referenced by: '<Root>/Reset Encoders'
                                        */
  boolean_T Logic_table[16];           /* Computed Parameter: Logic_table
                                        * Referenced by: '<S7>/Logic'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Wahadlo_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[2];
    SimStruct childSFunctions[9];
    SimStruct *childSFunctionPtrs[9];
    struct _ssBlkInfo2 blkInfo2[9];
    struct _ssSFcnModelMethods2 methods2[9];
    struct _ssSFcnModelMethods3 methods3[9];
    struct _ssStatesInfo2 statesInfo2[9];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[3];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[5];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[3];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn3;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[3];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn4;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn5;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn6;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[3];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn7;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[3];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn8;
  } NonInlinedSFcns;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    void *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    void *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    void *dwork;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Wahadlo_T Wahadlo_P;

/* Block signals (auto storage) */
extern B_Wahadlo_T Wahadlo_B;

/* Block states (auto storage) */
extern DW_Wahadlo_T Wahadlo_DW;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_Wahadlo_T Wahadlo_PrevZCX;

/* Model entry point functions */
extern void Wahadlo_initialize(void);
extern void Wahadlo_output(void);
extern void Wahadlo_update(void);
extern void Wahadlo_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern Wahadlo_rtModel *Wahadlo(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_Wahadlo_T *const Wahadlo_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/LimitFlagGain' : Unused code path elimination
 * Block '<S3>/LimitSwitchGain' : Unused code path elimination
 * Block '<S3>/PWMGain' : Unused code path elimination
 * Block '<S3>/PWMPrescalerGain' : Unused code path elimination
 * Block '<S3>/ResetEncoderGain' : Unused code path elimination
 * Block '<S3>/ResetSwitchFlagGain' : Unused code path elimination
 * Block '<S3>/SetLimitGain' : Unused code path elimination
 * Block '<S3>/ThermFlagGain' : Unused code path elimination
 * Block '<S6>/Gain' : Unused code path elimination
 * Block '<S6>/Gain1' : Unused code path elimination
 * Block '<S6>/Sign' : Unused code path elimination
 * Block '<S6>/Sum' : Unused code path elimination
 * Block '<Root>/Gain1' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Wahadlo'
 * '<S1>'   : 'Wahadlo/Acceleration'
 * '<S2>'   : 'Wahadlo/Alfa Normalization'
 * '<S3>'   : 'Wahadlo/Cart-Pendulum System'
 * '<S4>'   : 'Wahadlo/Compare To Constant'
 * '<S5>'   : 'Wahadlo/Compare To Constant1'
 * '<S6>'   : 'Wahadlo/Coulomb & Viscous Friction'
 * '<S7>'   : 'Wahadlo/S-R Flip-Flop'
 * '<S8>'   : 'Wahadlo/Sample and Hold'
 * '<S9>'   : 'Wahadlo/Sensors'
 * '<S10>'  : 'Wahadlo/Signal Builder'
 * '<S11>'  : 'Wahadlo/Slider Gain'
 */
#endif                                 /* RTW_HEADER_Wahadlo_h_ */
