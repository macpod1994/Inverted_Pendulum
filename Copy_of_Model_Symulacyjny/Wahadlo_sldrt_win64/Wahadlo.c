/*
 * Wahadlo.c
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

#include "Wahadlo.h"
#include "Wahadlo_private.h"
#include "Wahadlo_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.01, 0.0,
};

/* Block signals (auto storage) */
B_Wahadlo_T Wahadlo_B;

/* Block states (auto storage) */
DW_Wahadlo_T Wahadlo_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Wahadlo_T Wahadlo_PrevZCX;

/* Real-time model */
RT_MODEL_Wahadlo_T Wahadlo_M_;
RT_MODEL_Wahadlo_T *const Wahadlo_M = &Wahadlo_M_;
real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Model output function */
void Wahadlo_output(void)
{
  /* local block i/o variables */
  real_T rtb_FromWs;
  real_T rtb_Encoder1024PPR[5];
  real_T rtb_Product_n;
  int32_T i;
  real_T rtb_Product_d;

  /* Reset subsysRan breadcrumbs */
  srClearBC(Wahadlo_DW.SampleandHold_SubsysRanBC);

  /* Level2 S-Function Block: '<S3>/Encoder' (P1_Encoder) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[0];
    sfcnOutputs(rts, 1);
  }

  /* Gain: '<S3>/Encoder 1024 PPR' */
  for (i = 0; i < 5; i++) {
    rtb_Encoder1024PPR[i] = Wahadlo_P.Encoder1024PPR_Gain * Wahadlo_B.Encoder[i];
  }

  /* End of Gain: '<S3>/Encoder 1024 PPR' */

  /* Sum: '<S3>/Sum' incorporates:
   *  Constant: '<S3>/Cart Offset'
   *  Gain: '<S3>/PosCart Scale'
   */
  Wahadlo_B.Sum = Wahadlo_P.PosCartScale_Gain * rtb_Encoder1024PPR[4] +
    Wahadlo_P.CartOffset_Value;

  /* Gain: '<S9>/Gain3' */
  Wahadlo_B.Cart_pos = Wahadlo_P.Gain3_Gain * Wahadlo_B.Sum;

  /* Gain: '<S3>/Angle Scale' */
  Wahadlo_B.AngleScale = Wahadlo_P.AngleScale_Gain * rtb_Encoder1024PPR[3];

  /* Sum: '<S2>/Sum' incorporates:
   *  Constant: '<S2>/pi'
   *  Constant: '<S2>/pos'
   *  Gain: '<S9>/Gain1'
   *  Product: '<S2>/Product'
   */
  rtb_Product_n = Wahadlo_P.pi_Value * Wahadlo_P.AlfaNormalization_pos +
    Wahadlo_P.Gain1_Gain * Wahadlo_B.AngleScale;

  /* Fcn: '<S2>/angle normalization' */
  Wahadlo_B.PendPosOut = rt_atan2d_snf(sin(rtb_Product_n), cos(rtb_Product_n));

  /* CombinatorialLogic: '<S7>/Logic' incorporates:
   *  Abs: '<Root>/Abs3'
   *  Constant: '<S5>/Constant'
   *  Memory: '<S7>/Memory'
   *  RelationalOperator: '<S5>/Compare'
   */
  i = (int32_T)(((((uint32_T)(fabs(Wahadlo_B.PendPosOut) <=
    Wahadlo_P.CompareToConstant1_const) << 1) + false) << 1) +
                Wahadlo_DW.Memory_PreviousInput_b);
  Wahadlo_B.Logic[0U] = Wahadlo_P.Logic_table[(uint32_T)i];
  Wahadlo_B.Logic[1U] = Wahadlo_P.Logic_table[i + 8U];

  /* Outputs for Triggered SubSystem: '<Root>/Sample and Hold' incorporates:
   *  TriggerPort: '<S8>/Trigger'
   */
  if (Wahadlo_B.Logic[0] && (Wahadlo_PrevZCX.SampleandHold_Trig_ZCE != POS_ZCSIG))
  {
    /* Inport: '<S8>/In' incorporates:
     *  Memory: '<Root>/TmpLatchAtSample and HoldInport1'
     */
    Wahadlo_B.In = Wahadlo_DW.TmpLatchAtSampleandHoldInport1_;
    Wahadlo_DW.SampleandHold_SubsysRanBC = 4;
  }

  Wahadlo_PrevZCX.SampleandHold_Trig_ZCE = Wahadlo_B.Logic[0];

  /* End of Outputs for SubSystem: '<Root>/Sample and Hold' */

  /* Gain: '<S9>/Gain2' incorporates:
   *  Memory: '<S9>/Memory'
   *  Sum: '<S9>/Sum'
   */
  Wahadlo_B.Pend_vel = 1.0 / Wahadlo_P.Sensors_T0 * (Wahadlo_B.AngleScale -
    Wahadlo_DW.Memory_PreviousInput);

  /* Gain: '<S9>/Gain4' incorporates:
   *  Memory: '<S9>/Memory1'
   *  Sum: '<S9>/Sum1'
   */
  Wahadlo_B.Cart_vel = 1.0 / Wahadlo_P.Sensors_T0 * (Wahadlo_B.Sum -
    Wahadlo_DW.Memory1_PreviousInput);

  /* Gain: '<S1>/Gain4' incorporates:
   *  Memory: '<S1>/Memory1'
   *  Sum: '<S1>/Sum1'
   */
  Wahadlo_B.Cart_acc = 1.0 / Wahadlo_P.Acceleration_T0 * (Wahadlo_B.Cart_vel -
    Wahadlo_DW.Memory1_PreviousInput_m);

  /* Gain: '<Root>/Gain2' */
  Wahadlo_B.Gain2 = -Wahadlo_P.K[0] * Wahadlo_B.PendPosOut;

  /* Gain: '<Root>/Gain3' */
  Wahadlo_B.Gain3 = -Wahadlo_P.K[1] * Wahadlo_B.Pend_vel;

  /* Gain: '<Root>/Gain4' incorporates:
   *  Sum: '<Root>/Subtract1'
   */
  Wahadlo_B.Gain4 = (Wahadlo_B.Cart_pos - Wahadlo_B.In) * -Wahadlo_P.K[2];

  /* Gain: '<Root>/Gain5' */
  Wahadlo_B.Gain5 = -Wahadlo_P.K[3] * Wahadlo_B.Cart_vel;

  /* Sum: '<Root>/Subtract' incorporates:
   *  Abs: '<Root>/Abs1'
   *  Constant: '<Root>/Constant1'
   */
  Wahadlo_B.Subtract = fabs(Wahadlo_B.PendPosOut) - Wahadlo_P.Constant1_Value;

  /* Product: '<Root>/Product' */
  rtb_Product_n = Wahadlo_B.Pend_vel * Wahadlo_B.Subtract;

  /* Signum: '<Root>/Sign' */
  if (rtb_Product_n < 0.0) {
    rtb_Product_n = -1.0;
  } else if (rtb_Product_n > 0.0) {
    rtb_Product_n = 1.0;
  } else {
    if (rtb_Product_n == 0.0) {
      rtb_Product_n = 0.0;
    }
  }

  /* Gain: '<Root>/Gain6' incorporates:
   *  Signum: '<Root>/Sign'
   */
  Wahadlo_B.Gain6 = Wahadlo_P.Gain6_Gain * rtb_Product_n;

  /* Abs: '<Root>/Abs' */
  Wahadlo_B.Abs = fabs(Wahadlo_B.Cart_pos);

  /* Sum: '<Root>/Add1' incorporates:
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/Gain7'
   */
  Wahadlo_B.Add1 = Wahadlo_P.Gain_Gain * Wahadlo_B.Cart_pos +
    Wahadlo_P.Gain7_Gain * Wahadlo_B.Cart_vel;

  /* Level2 S-Function Block: '<S3>/PWM' (P1_PWM) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[1];
    sfcnOutputs(rts, 1);
  }

  /* Gain: '<S11>/Slider Gain' incorporates:
   *  Constant: '<Root>/Constant'
   */
  Wahadlo_B.SliderGain = Wahadlo_P.SliderGain_gain * Wahadlo_P.Constant_Value;

  /* FromWorkspace: '<S10>/FromWs' */
  {
    real_T *pDataValues = (real_T *) Wahadlo_DW.FromWs_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) Wahadlo_DW.FromWs_PWORK.TimePtr;
    int_T currTimeIndex = Wahadlo_DW.FromWs_IWORK.PrevIndex;
    real_T t = Wahadlo_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[35]) {
      currTimeIndex = 34;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    Wahadlo_DW.FromWs_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          rtb_FromWs = pDataValues[currTimeIndex];
        } else {
          rtb_FromWs = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_FromWs = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 36;
      }
    }
  }

  /* Switch: '<Root>/Switch3' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Constant: '<S4>/Constant'
   *  Fcn: '<Root>/Fcn'
   *  Fcn: '<Root>/Fcn1'
   *  Gain: '<Root>/Gain10'
   *  Gain: '<Root>/Gain8'
   *  Gain: '<Root>/Gain9'
   *  Product: '<Root>/Product1'
   *  RelationalOperator: '<S4>/Compare'
   *  Signum: '<Root>/Sign1'
   *  Sum: '<Root>/Add2'
   *  Sum: '<Root>/Sum'
   *  Switch: '<Root>/Switch2'
   */
  if (Wahadlo_B.Logic[0]) {
    /* Sum: '<Root>/Add' */
    rtb_Product_n = ((Wahadlo_B.Gain2 + Wahadlo_B.Gain3) + Wahadlo_B.Gain4) +
      Wahadlo_B.Gain5;

    /* Signum: '<Root>/Sign1' */
    if (rtb_Product_n < 0.0) {
      rtb_Product_d = -1.0;
    } else if (rtb_Product_n > 0.0) {
      rtb_Product_d = 1.0;
    } else if (rtb_Product_n == 0.0) {
      rtb_Product_d = 0.0;
    } else {
      rtb_Product_d = rtb_Product_n;
    }

    Wahadlo_B.Switch3 = Wahadlo_P.Gain8_Gain * rtb_Product_d + rtb_Product_n;
  } else if (Wahadlo_P.Jr * rt_powd_snf(Wahadlo_B.Pend_vel, 2.0) *
             Wahadlo_P.Gain9_Gain + Wahadlo_P.E * cos(Wahadlo_B.PendPosOut) >
             1.05 * Wahadlo_P.E) {
    /* Switch: '<Root>/Switch2' incorporates:
     *  Constant: '<Root>/Constant3'
     */
    Wahadlo_B.Switch3 = Wahadlo_P.Constant3_Value;
  } else {
    /* Switch: '<Root>/Switch2' */
    Wahadlo_B.Switch3 = Wahadlo_B.Gain6;
  }

  /* End of Switch: '<Root>/Switch3' */

  /* Switch: '<Root>/Switch' incorporates:
   *  ManualSwitch: '<Root>/Manual Switch1'
   */
  if (Wahadlo_B.Abs > Wahadlo_P.Switch_Threshold) {
    rtb_Product_n = Wahadlo_B.Add1;
  } else if (Wahadlo_P.ManualSwitch1_CurrentSetting == 1) {
    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  ManualSwitch: '<Root>/Manual Switch1'
     */
    if (Wahadlo_P.ManualSwitch_CurrentSetting == 1) {
      rtb_Product_n = Wahadlo_B.SliderGain;
    } else {
      rtb_Product_n = rtb_FromWs;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch' */
  } else {
    rtb_Product_n = Wahadlo_B.Switch3;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Saturate: '<S3>/Saturation' */
  if (0.0 > Wahadlo_P.Saturation_UpperSat) {
    Wahadlo_B.Saturation[0] = Wahadlo_P.Saturation_UpperSat;
  } else if (0.0 < Wahadlo_P.Saturation_LowerSat) {
    Wahadlo_B.Saturation[0] = Wahadlo_P.Saturation_LowerSat;
  } else {
    Wahadlo_B.Saturation[0] = 0.0;
  }

  if (rtb_Product_n > Wahadlo_P.Saturation_UpperSat) {
    Wahadlo_B.Saturation[1] = Wahadlo_P.Saturation_UpperSat;
  } else if (rtb_Product_n < Wahadlo_P.Saturation_LowerSat) {
    Wahadlo_B.Saturation[1] = Wahadlo_P.Saturation_LowerSat;
  } else {
    Wahadlo_B.Saturation[1] = rtb_Product_n;
  }

  if (0.0 > Wahadlo_P.Saturation_UpperSat) {
    Wahadlo_B.Saturation[2] = Wahadlo_P.Saturation_UpperSat;
  } else if (0.0 < Wahadlo_P.Saturation_LowerSat) {
    Wahadlo_B.Saturation[2] = Wahadlo_P.Saturation_LowerSat;
  } else {
    Wahadlo_B.Saturation[2] = 0.0;
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* Level2 S-Function Block: '<S3>/ResetEncoder' (P1_ResetEncoder) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[2];
    sfcnOutputs(rts, 1);
  }

  /* Constant: '<S3>/ResetSource' */
  Wahadlo_B.ResetSource[0] = Wahadlo_P.ResetSource_Value[0];
  Wahadlo_B.ResetSource[1] = Wahadlo_P.ResetSource_Value[1];
  Wahadlo_B.ResetSource[2] = Wahadlo_P.ResetSource_Value[2];

  /* Level2 S-Function Block: '<S3>/LimitFlag' (P1_LimitFlag) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[3];
    sfcnOutputs(rts, 1);
  }

  /* Constant: '<S3>/LimitFlagSource' */
  Wahadlo_B.LimitFlagSource[0] = Wahadlo_P.LimitFlagSource_Value[0];
  Wahadlo_B.LimitFlagSource[1] = Wahadlo_P.LimitFlagSource_Value[1];
  Wahadlo_B.LimitFlagSource[2] = Wahadlo_P.LimitFlagSource_Value[2];

  /* Constant: '<S3>/LimitSource' */
  Wahadlo_B.LimitSource[0] = Wahadlo_P.LimitSource_Value[0];
  Wahadlo_B.LimitSource[1] = Wahadlo_P.LimitSource_Value[1];
  Wahadlo_B.LimitSource[2] = Wahadlo_P.LimitSource_Value[2];

  /* Level2 S-Function Block: '<S3>/SetLimit' (P1_SetLimit) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[4];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S3>/LimitSwitch' (P1_Switch) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[5];
    sfcnOutputs(rts, 1);
  }

  /* Level2 S-Function Block: '<S3>/PWMPrescaler' (P1_PWMPrescaler) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[6];
    sfcnOutputs(rts, 1);
  }

  /* Constant: '<S3>/PWMPrescalerSource' */
  Wahadlo_B.PWMPrescalerSource = Wahadlo_P.PWMPrescalerSource_Value;

  /* Level2 S-Function Block: '<S3>/ResetSwitchFlag ' (P1_ResetSwitchFlag) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[7];
    sfcnOutputs(rts, 1);
  }

  /* Constant: '<S3>/ResetSwitchFlagSource' */
  Wahadlo_B.ResetSwitchFlagSource[0] = Wahadlo_P.ResetSwitchFlagSource_Value[0];
  Wahadlo_B.ResetSwitchFlagSource[1] = Wahadlo_P.ResetSwitchFlagSource_Value[1];
  Wahadlo_B.ResetSwitchFlagSource[2] = Wahadlo_P.ResetSwitchFlagSource_Value[2];

  /* Level2 S-Function Block: '<S3>/ThermFlag ' (P1_ThermFlag) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[8];
    sfcnOutputs(rts, 1);
  }

  /* Constant: '<S3>/ThermFlagSource' */
  Wahadlo_B.ThermFlagSource[0] = Wahadlo_P.ThermFlagSource_Value[0];
  Wahadlo_B.ThermFlagSource[1] = Wahadlo_P.ThermFlagSource_Value[1];
  Wahadlo_B.ThermFlagSource[2] = Wahadlo_P.ThermFlagSource_Value[2];

  /* ManualSwitch: '<Root>/Reset Encoders' incorporates:
   *  Constant: '<Root>/Normal'
   *  Constant: '<Root>/Reset'
   */
  if (Wahadlo_P.ResetEncoders_CurrentSetting == 1) {
    Wahadlo_B.ResetEncoders = Wahadlo_P.Reset_Value;
  } else {
    Wahadlo_B.ResetEncoders = Wahadlo_P.Normal_Value;
  }

  /* End of ManualSwitch: '<Root>/Reset Encoders' */
}

/* Model update function */
void Wahadlo_update(void)
{
  /* Update for Memory: '<Root>/TmpLatchAtSample and HoldInport1' */
  Wahadlo_DW.TmpLatchAtSampleandHoldInport1_ = Wahadlo_B.Cart_pos;

  /* Update for Memory: '<S7>/Memory' */
  Wahadlo_DW.Memory_PreviousInput_b = Wahadlo_B.Logic[0];

  /* Update for Memory: '<S9>/Memory' */
  Wahadlo_DW.Memory_PreviousInput = Wahadlo_B.AngleScale;

  /* Update for Memory: '<S9>/Memory1' */
  Wahadlo_DW.Memory1_PreviousInput = Wahadlo_B.Sum;

  /* Update for Memory: '<S1>/Memory1' */
  Wahadlo_DW.Memory1_PreviousInput_m = Wahadlo_B.Cart_vel;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Wahadlo_M->Timing.clockTick0)) {
    ++Wahadlo_M->Timing.clockTickH0;
  }

  Wahadlo_M->Timing.t[0] = Wahadlo_M->Timing.clockTick0 *
    Wahadlo_M->Timing.stepSize0 + Wahadlo_M->Timing.clockTickH0 *
    Wahadlo_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Wahadlo_M->Timing.clockTick1)) {
      ++Wahadlo_M->Timing.clockTickH1;
    }

    Wahadlo_M->Timing.t[1] = Wahadlo_M->Timing.clockTick1 *
      Wahadlo_M->Timing.stepSize1 + Wahadlo_M->Timing.clockTickH1 *
      Wahadlo_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void Wahadlo_initialize(void)
{
  /* Start for Triggered SubSystem: '<Root>/Sample and Hold' */
  /* VirtualOutportStart for Outport: '<S8>/ ' */
  Wahadlo_B.In = Wahadlo_P._Y0;

  /* End of Start for SubSystem: '<Root>/Sample and Hold' */
  /* Start for FromWorkspace: '<S10>/FromWs' */
  {
    static real_T pTimeValues0[] = { 0.0, 1.0, 1.0, 2.0, 2.0, 4.0, 4.0, 5.0, 5.0,
      6.0, 6.0, 8.0, 8.0, 9.0, 9.0, 10.0, 10.0, 12.0, 12.0, 12.5, 12.5, 13.0,
      13.0, 16.0, 16.0, 16.5, 16.5, 17.0, 17.0, 20.0, 20.0, 20.25, 20.25, 20.5,
      20.5, 30.0 } ;

    static real_T pDataValues0[] = { 0.1, 0.1, -0.1, -0.1, 0.0, 0.0, 0.2, 0.2,
      -0.2, -0.2, 0.0, 0.0, 0.25, 0.25, -0.25, -0.25, 0.0, 0.0, 0.3, 0.3, -0.3,
      -0.3, 0.0, 0.0, 0.4, 0.4, -0.4, -0.4, 0.0, 0.0, 0.5, 0.5, -0.5, -0.5, 0.0,
      0.0 } ;

    Wahadlo_DW.FromWs_PWORK.TimePtr = (void *) pTimeValues0;
    Wahadlo_DW.FromWs_PWORK.DataPtr = (void *) pDataValues0;
    Wahadlo_DW.FromWs_IWORK.PrevIndex = 0;
  }

  /* Start for Constant: '<S3>/LimitFlagSource' */
  Wahadlo_B.LimitFlagSource[0] = Wahadlo_P.LimitFlagSource_Value[0];
  Wahadlo_B.LimitFlagSource[1] = Wahadlo_P.LimitFlagSource_Value[1];
  Wahadlo_B.LimitFlagSource[2] = Wahadlo_P.LimitFlagSource_Value[2];

  /* Start for Constant: '<S3>/LimitSource' */
  Wahadlo_B.LimitSource[0] = Wahadlo_P.LimitSource_Value[0];
  Wahadlo_B.LimitSource[1] = Wahadlo_P.LimitSource_Value[1];
  Wahadlo_B.LimitSource[2] = Wahadlo_P.LimitSource_Value[2];

  /* Start for Constant: '<S3>/PWMPrescalerSource' */
  Wahadlo_B.PWMPrescalerSource = Wahadlo_P.PWMPrescalerSource_Value;

  /* Start for Constant: '<S3>/ResetSwitchFlagSource' */
  Wahadlo_B.ResetSwitchFlagSource[0] = Wahadlo_P.ResetSwitchFlagSource_Value[0];
  Wahadlo_B.ResetSwitchFlagSource[1] = Wahadlo_P.ResetSwitchFlagSource_Value[1];
  Wahadlo_B.ResetSwitchFlagSource[2] = Wahadlo_P.ResetSwitchFlagSource_Value[2];

  /* Start for Constant: '<S3>/ThermFlagSource' */
  Wahadlo_B.ThermFlagSource[0] = Wahadlo_P.ThermFlagSource_Value[0];
  Wahadlo_B.ThermFlagSource[1] = Wahadlo_P.ThermFlagSource_Value[1];
  Wahadlo_B.ThermFlagSource[2] = Wahadlo_P.ThermFlagSource_Value[2];
  Wahadlo_PrevZCX.SampleandHold_Trig_ZCE = POS_ZCSIG;

  /* InitializeConditions for Memory: '<Root>/TmpLatchAtSample and HoldInport1' */
  Wahadlo_DW.TmpLatchAtSampleandHoldInport1_ =
    Wahadlo_P.TmpLatchAtSampleandHoldInport1_;

  /* InitializeConditions for Memory: '<S7>/Memory' */
  Wahadlo_DW.Memory_PreviousInput_b = Wahadlo_P.SRFlipFlop_initial_condition;

  /* InitializeConditions for Memory: '<S9>/Memory' */
  Wahadlo_DW.Memory_PreviousInput = Wahadlo_P.Memory_X0;

  /* InitializeConditions for Memory: '<S9>/Memory1' */
  Wahadlo_DW.Memory1_PreviousInput = Wahadlo_P.Memory1_X0;

  /* InitializeConditions for Memory: '<S1>/Memory1' */
  Wahadlo_DW.Memory1_PreviousInput_m = Wahadlo_P.Memory1_X0_b;
}

/* Model terminate function */
void Wahadlo_terminate(void)
{
  /* Level2 S-Function Block: '<S3>/Encoder' (P1_Encoder) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/PWM' (P1_PWM) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/ResetEncoder' (P1_ResetEncoder) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/LimitFlag' (P1_LimitFlag) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/SetLimit' (P1_SetLimit) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/LimitSwitch' (P1_Switch) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/PWMPrescaler' (P1_PWMPrescaler) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/ResetSwitchFlag ' (P1_ResetSwitchFlag) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/ThermFlag ' (P1_ThermFlag) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[8];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Wahadlo_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Wahadlo_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Wahadlo_initialize();
}

void MdlTerminate(void)
{
  Wahadlo_terminate();
}

/* Registration function */
RT_MODEL_Wahadlo_T *Wahadlo(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Wahadlo_M, 0,
                sizeof(RT_MODEL_Wahadlo_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Wahadlo_M->solverInfo, &Wahadlo_M->Timing.simTimeStep);
    rtsiSetTPtr(&Wahadlo_M->solverInfo, &rtmGetTPtr(Wahadlo_M));
    rtsiSetStepSizePtr(&Wahadlo_M->solverInfo, &Wahadlo_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Wahadlo_M->solverInfo, (&rtmGetErrorStatus(Wahadlo_M)));
    rtsiSetRTModelPtr(&Wahadlo_M->solverInfo, Wahadlo_M);
  }

  rtsiSetSimTimeStep(&Wahadlo_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Wahadlo_M->solverInfo,"FixedStepDiscrete");
  Wahadlo_M->solverInfoPtr = (&Wahadlo_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Wahadlo_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Wahadlo_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Wahadlo_M->Timing.sampleTimes = (&Wahadlo_M->Timing.sampleTimesArray[0]);
    Wahadlo_M->Timing.offsetTimes = (&Wahadlo_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Wahadlo_M->Timing.sampleTimes[0] = (0.0);
    Wahadlo_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    Wahadlo_M->Timing.offsetTimes[0] = (0.0);
    Wahadlo_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Wahadlo_M, &Wahadlo_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Wahadlo_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Wahadlo_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Wahadlo_M, 1000.0);
  Wahadlo_M->Timing.stepSize0 = 0.01;
  Wahadlo_M->Timing.stepSize1 = 0.01;

  /* External mode info */
  Wahadlo_M->Sizes.checksums[0] = (2389427435U);
  Wahadlo_M->Sizes.checksums[1] = (4100144922U);
  Wahadlo_M->Sizes.checksums[2] = (77127371U);
  Wahadlo_M->Sizes.checksums[3] = (1825649549U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    Wahadlo_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = (sysRanDType *)&Wahadlo_DW.SampleandHold_SubsysRanBC;
    rteiSetModelMappingInfoPtr(Wahadlo_M->extModeInfo,
      &Wahadlo_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Wahadlo_M->extModeInfo, Wahadlo_M->Sizes.checksums);
    rteiSetTPtr(Wahadlo_M->extModeInfo, rtmGetTPtr(Wahadlo_M));
  }

  Wahadlo_M->solverInfoPtr = (&Wahadlo_M->solverInfo);
  Wahadlo_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&Wahadlo_M->solverInfo, 0.01);
  rtsiSetSolverMode(&Wahadlo_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Wahadlo_M->ModelData.blockIO = ((void *) &Wahadlo_B);
  (void) memset(((void *) &Wahadlo_B), 0,
                sizeof(B_Wahadlo_T));

  {
    int32_T i;
    for (i = 0; i < 5; i++) {
      Wahadlo_B.Encoder[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      Wahadlo_B.ResetEncoder[i] = 0.0;
    }

    Wahadlo_B.Sum = 0.0;
    Wahadlo_B.Cart_pos = 0.0;
    Wahadlo_B.AngleScale = 0.0;
    Wahadlo_B.PendPosOut = 0.0;
    Wahadlo_B.Pend_vel = 0.0;
    Wahadlo_B.Cart_vel = 0.0;
    Wahadlo_B.Cart_acc = 0.0;
    Wahadlo_B.Gain2 = 0.0;
    Wahadlo_B.Gain3 = 0.0;
    Wahadlo_B.Gain4 = 0.0;
    Wahadlo_B.Gain5 = 0.0;
    Wahadlo_B.Subtract = 0.0;
    Wahadlo_B.Gain6 = 0.0;
    Wahadlo_B.Abs = 0.0;
    Wahadlo_B.Add1 = 0.0;
    Wahadlo_B.PWM[0] = 0.0;
    Wahadlo_B.PWM[1] = 0.0;
    Wahadlo_B.PWM[2] = 0.0;
    Wahadlo_B.SliderGain = 0.0;
    Wahadlo_B.Switch3 = 0.0;
    Wahadlo_B.Saturation[0] = 0.0;
    Wahadlo_B.Saturation[1] = 0.0;
    Wahadlo_B.Saturation[2] = 0.0;
    Wahadlo_B.ResetSource[0] = 0.0;
    Wahadlo_B.ResetSource[1] = 0.0;
    Wahadlo_B.ResetSource[2] = 0.0;
    Wahadlo_B.LimitFlag[0] = 0.0;
    Wahadlo_B.LimitFlag[1] = 0.0;
    Wahadlo_B.LimitFlag[2] = 0.0;
    Wahadlo_B.LimitFlagSource[0] = 0.0;
    Wahadlo_B.LimitFlagSource[1] = 0.0;
    Wahadlo_B.LimitFlagSource[2] = 0.0;
    Wahadlo_B.LimitSource[0] = 0.0;
    Wahadlo_B.LimitSource[1] = 0.0;
    Wahadlo_B.LimitSource[2] = 0.0;
    Wahadlo_B.SetLimit[0] = 0.0;
    Wahadlo_B.SetLimit[1] = 0.0;
    Wahadlo_B.SetLimit[2] = 0.0;
    Wahadlo_B.LimitSwitch[0] = 0.0;
    Wahadlo_B.LimitSwitch[1] = 0.0;
    Wahadlo_B.LimitSwitch[2] = 0.0;
    Wahadlo_B.PWMPrescaler = 0.0;
    Wahadlo_B.PWMPrescalerSource = 0.0;
    Wahadlo_B.ResetSwitchFlag[0] = 0.0;
    Wahadlo_B.ResetSwitchFlag[1] = 0.0;
    Wahadlo_B.ResetSwitchFlag[2] = 0.0;
    Wahadlo_B.ResetSwitchFlagSource[0] = 0.0;
    Wahadlo_B.ResetSwitchFlagSource[1] = 0.0;
    Wahadlo_B.ResetSwitchFlagSource[2] = 0.0;
    Wahadlo_B.ThermFlag[0] = 0.0;
    Wahadlo_B.ThermFlag[1] = 0.0;
    Wahadlo_B.ThermFlag[2] = 0.0;
    Wahadlo_B.ThermFlagSource[0] = 0.0;
    Wahadlo_B.ThermFlagSource[1] = 0.0;
    Wahadlo_B.ThermFlagSource[2] = 0.0;
    Wahadlo_B.ResetEncoders = 0.0;
    Wahadlo_B.In = 0.0;
  }

  /* parameters */
  Wahadlo_M->ModelData.defaultParam = ((real_T *)&Wahadlo_P);

  /* states (dwork) */
  Wahadlo_M->ModelData.dwork = ((void *) &Wahadlo_DW);
  (void) memset((void *)&Wahadlo_DW, 0,
                sizeof(DW_Wahadlo_T));
  Wahadlo_DW.TmpLatchAtSampleandHoldInport1_ = 0.0;
  Wahadlo_DW.Memory_PreviousInput = 0.0;
  Wahadlo_DW.Memory1_PreviousInput = 0.0;
  Wahadlo_DW.Memory1_PreviousInput_m = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Wahadlo_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &Wahadlo_M->NonInlinedSFcns.sfcnInfo;
    Wahadlo_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(Wahadlo_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &Wahadlo_M->Sizes.numSampTimes);
    Wahadlo_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(Wahadlo_M)[0]);
    Wahadlo_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(Wahadlo_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,Wahadlo_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(Wahadlo_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(Wahadlo_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(Wahadlo_M));
    rtssSetStepSizePtr(sfcnInfo, &Wahadlo_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(Wahadlo_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &Wahadlo_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &Wahadlo_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &Wahadlo_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &Wahadlo_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &Wahadlo_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &Wahadlo_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &Wahadlo_M->solverInfoPtr);
  }

  Wahadlo_M->Sizes.numSFcns = (9);

  /* register each child */
  {
    (void) memset((void *)&Wahadlo_M->NonInlinedSFcns.childSFunctions[0], 0,
                  9*sizeof(SimStruct));
    Wahadlo_M->childSfunctions = (&Wahadlo_M->
      NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 9; i++) {
        Wahadlo_M->childSfunctions[i] =
          (&Wahadlo_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: Wahadlo/<S3>/Encoder (P1_Encoder) */
    {
      SimStruct *rts = Wahadlo_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = Wahadlo_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = Wahadlo_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = Wahadlo_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Wahadlo_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, Wahadlo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Wahadlo_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Wahadlo_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Wahadlo_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Wahadlo_B.Encoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "Encoder");
      ssSetPath(rts, "Wahadlo/Cart-Pendulum System/Encoder");
      ssSetRTModel(rts,Wahadlo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Wahadlo_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Wahadlo_P.Encoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Wahadlo_P.Encoder_P2_Size);
      }

      /* registration */
      P1_Encoder(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Wahadlo/<S3>/PWM (P1_PWM) */
    {
      SimStruct *rts = Wahadlo_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = Wahadlo_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = Wahadlo_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = Wahadlo_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Wahadlo_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, Wahadlo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Wahadlo_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Wahadlo_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Wahadlo_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Wahadlo_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = Wahadlo_B.Saturation;
          sfcnUPtrs[1] = &Wahadlo_B.Saturation[1];
          sfcnUPtrs[2] = &Wahadlo_B.Saturation[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Wahadlo_B.PWM));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWM");
      ssSetPath(rts, "Wahadlo/Cart-Pendulum System/PWM");
      ssSetRTModel(rts,Wahadlo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Wahadlo_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Wahadlo_P.PWM_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Wahadlo_P.PWM_P2_Size);
      }

      /* registration */
      P1_PWM(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Wahadlo/<S3>/ResetEncoder (P1_ResetEncoder) */
    {
      SimStruct *rts = Wahadlo_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = Wahadlo_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = Wahadlo_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = Wahadlo_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Wahadlo_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, Wahadlo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Wahadlo_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Wahadlo_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Wahadlo_M->NonInlinedSFcns.statesInfo2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Wahadlo_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &Wahadlo_B.ResetSource[0];
          sfcnUPtrs[1] = &Wahadlo_B.ResetSource[1];
          sfcnUPtrs[2] = &Wahadlo_B.ResetSource[2];
          sfcnUPtrs[3] = &Wahadlo_B.ResetEncoders;
          sfcnUPtrs[4] = &Wahadlo_B.ResetEncoders;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 5);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Wahadlo_B.ResetEncoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetEncoder");
      ssSetPath(rts, "Wahadlo/Cart-Pendulum System/ResetEncoder");
      ssSetRTModel(rts,Wahadlo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Wahadlo_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Wahadlo_P.ResetEncoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Wahadlo_P.ResetEncoder_P2_Size);
      }

      /* registration */
      P1_ResetEncoder(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Wahadlo/<S3>/LimitFlag (P1_LimitFlag) */
    {
      SimStruct *rts = Wahadlo_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = Wahadlo_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = Wahadlo_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = Wahadlo_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Wahadlo_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, Wahadlo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Wahadlo_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Wahadlo_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Wahadlo_M->NonInlinedSFcns.statesInfo2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Wahadlo_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = Wahadlo_B.LimitFlagSource;
          sfcnUPtrs[1] = &Wahadlo_B.LimitFlagSource[1];
          sfcnUPtrs[2] = &Wahadlo_B.LimitFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Wahadlo_B.LimitFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "LimitFlag");
      ssSetPath(rts, "Wahadlo/Cart-Pendulum System/LimitFlag");
      ssSetRTModel(rts,Wahadlo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Wahadlo_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Wahadlo_P.LimitFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Wahadlo_P.LimitFlag_P2_Size);
      }

      /* registration */
      P1_LimitFlag(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Wahadlo/<S3>/SetLimit (P1_SetLimit) */
    {
      SimStruct *rts = Wahadlo_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = Wahadlo_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = Wahadlo_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = Wahadlo_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Wahadlo_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, Wahadlo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Wahadlo_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Wahadlo_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Wahadlo_M->NonInlinedSFcns.statesInfo2[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Wahadlo_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = Wahadlo_B.LimitSource;
          sfcnUPtrs[1] = &Wahadlo_B.LimitSource[1];
          sfcnUPtrs[2] = &Wahadlo_B.LimitSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Wahadlo_B.SetLimit));
        }
      }

      /* path info */
      ssSetModelName(rts, "SetLimit");
      ssSetPath(rts, "Wahadlo/Cart-Pendulum System/SetLimit");
      ssSetRTModel(rts,Wahadlo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Wahadlo_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Wahadlo_P.SetLimit_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Wahadlo_P.SetLimit_P2_Size);
      }

      /* registration */
      P1_SetLimit(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Wahadlo/<S3>/LimitSwitch (P1_Switch) */
    {
      SimStruct *rts = Wahadlo_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = Wahadlo_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = Wahadlo_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = Wahadlo_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Wahadlo_M->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, Wahadlo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Wahadlo_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Wahadlo_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Wahadlo_M->NonInlinedSFcns.statesInfo2[5]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Wahadlo_B.LimitSwitch));
        }
      }

      /* path info */
      ssSetModelName(rts, "LimitSwitch");
      ssSetPath(rts, "Wahadlo/Cart-Pendulum System/LimitSwitch");
      ssSetRTModel(rts,Wahadlo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Wahadlo_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Wahadlo_P.LimitSwitch_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Wahadlo_P.LimitSwitch_P2_Size);
      }

      /* registration */
      P1_Switch(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Wahadlo/<S3>/PWMPrescaler (P1_PWMPrescaler) */
    {
      SimStruct *rts = Wahadlo_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = Wahadlo_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = Wahadlo_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = Wahadlo_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Wahadlo_M->NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, Wahadlo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Wahadlo_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Wahadlo_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Wahadlo_M->NonInlinedSFcns.statesInfo2[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Wahadlo_M->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = &Wahadlo_B.PWMPrescalerSource;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Wahadlo_B.PWMPrescaler));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWMPrescaler");
      ssSetPath(rts, "Wahadlo/Cart-Pendulum System/PWMPrescaler");
      ssSetRTModel(rts,Wahadlo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Wahadlo_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Wahadlo_P.PWMPrescaler_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Wahadlo_P.PWMPrescaler_P2_Size);
      }

      /* registration */
      P1_PWMPrescaler(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Wahadlo/<S3>/ResetSwitchFlag  (P1_ResetSwitchFlag) */
    {
      SimStruct *rts = Wahadlo_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = Wahadlo_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = Wahadlo_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = Wahadlo_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Wahadlo_M->NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, Wahadlo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Wahadlo_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Wahadlo_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Wahadlo_M->NonInlinedSFcns.statesInfo2[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Wahadlo_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = Wahadlo_B.ResetSwitchFlagSource;
          sfcnUPtrs[1] = &Wahadlo_B.ResetSwitchFlagSource[1];
          sfcnUPtrs[2] = &Wahadlo_B.ResetSwitchFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Wahadlo_B.ResetSwitchFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetSwitchFlag ");
      ssSetPath(rts, "Wahadlo/Cart-Pendulum System/ResetSwitchFlag ");
      ssSetRTModel(rts,Wahadlo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Wahadlo_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Wahadlo_P.ResetSwitchFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Wahadlo_P.ResetSwitchFlag_P2_Size);
      }

      /* registration */
      P1_ResetSwitchFlag(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Wahadlo/<S3>/ThermFlag  (P1_ThermFlag) */
    {
      SimStruct *rts = Wahadlo_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = Wahadlo_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = Wahadlo_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = Wahadlo_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Wahadlo_M->NonInlinedSFcns.blkInfo2[8]);
      }

      ssSetRTWSfcnInfo(rts, Wahadlo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Wahadlo_M->NonInlinedSFcns.methods2[8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Wahadlo_M->NonInlinedSFcns.methods3[8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Wahadlo_M->NonInlinedSFcns.statesInfo2[8]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn8.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Wahadlo_M->NonInlinedSFcns.Sfcn8.UPtrs0;
          sfcnUPtrs[0] = Wahadlo_B.ThermFlagSource;
          sfcnUPtrs[1] = &Wahadlo_B.ThermFlagSource[1];
          sfcnUPtrs[2] = &Wahadlo_B.ThermFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Wahadlo_B.ThermFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ThermFlag ");
      ssSetPath(rts, "Wahadlo/Cart-Pendulum System/ThermFlag ");
      ssSetRTModel(rts,Wahadlo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Wahadlo_M->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Wahadlo_P.ThermFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Wahadlo_P.ThermFlag_P2_Size);
      }

      /* registration */
      P1_ThermFlag(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Initialize Sizes */
  Wahadlo_M->Sizes.numContStates = (0);/* Number of continuous states */
  Wahadlo_M->Sizes.numY = (0);         /* Number of model outputs */
  Wahadlo_M->Sizes.numU = (0);         /* Number of model inputs */
  Wahadlo_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Wahadlo_M->Sizes.numSampTimes = (2); /* Number of sample times */
  Wahadlo_M->Sizes.numBlocks = (98);   /* Number of blocks */
  Wahadlo_M->Sizes.numBlockIO = (36);  /* Number of block outputs */
  Wahadlo_M->Sizes.numBlockPrms = (126);/* Sum of parameter "widths" */
  return Wahadlo_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
