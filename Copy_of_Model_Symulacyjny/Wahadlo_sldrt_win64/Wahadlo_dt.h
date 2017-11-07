/*
 * Wahadlo_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Wahadlo_B.Encoder[0]), 0, 0, 67 },

  { (char_T *)(&Wahadlo_B.Logic[0]), 8, 0, 2 }
  ,

  { (char_T *)(&Wahadlo_DW.TmpLatchAtSampleandHoldInport1_), 0, 0, 4 },

  { (char_T *)(&Wahadlo_DW.PendulumControlandStatesExperim.LoggedData), 11, 0, 4
  },

  { (char_T *)(&Wahadlo_DW.FromWs_IWORK.PrevIndex), 10, 0, 1 },

  { (char_T *)(&Wahadlo_DW.SampleandHold_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&Wahadlo_DW.Memory_PreviousInput_b), 8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  7U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Wahadlo_P.E), 0, 0, 11 },

  { (char_T *)(&Wahadlo_P.SRFlipFlop_initial_condition), 8, 0, 1 },

  { (char_T *)(&Wahadlo_P.Constant3_Value), 0, 0, 95 },

  { (char_T *)(&Wahadlo_P.ManualSwitch_CurrentSetting), 3, 0, 3 },

  { (char_T *)(&Wahadlo_P.Logic_table[0]), 8, 0, 16 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

/* [EOF] Wahadlo_dt.h */
