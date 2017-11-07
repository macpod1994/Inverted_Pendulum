/*
 * Wahadlo_data.c
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

/* Block parameters (auto storage) */
P_Wahadlo_T Wahadlo_P = {
  0.15327144,                          /* Variable: E
                                        * Referenced by:
                                        *   '<Root>/Gain10'
                                        *   '<S4>/Constant'
                                        */
  0.0056120814327229717,               /* Variable: Jr
                                        * Referenced by: '<Root>/Constant4'
                                        */

  /*  Variable: K
   * Referenced by:
   *   '<Root>/Gain2'
   *   '<Root>/Gain3'
   *   '<Root>/Gain4'
   *   '<Root>/Gain5'
   */
  { 3.8697805511456389, 0.72229242608864253, 1.0000000000000044,
    1.2069041623810548 },
  0.01,                                /* Mask Parameter: Sensors_T0
                                        * Referenced by:
                                        *   '<S9>/Gain2'
                                        *   '<S9>/Gain4'
                                        */
  0.01,                                /* Mask Parameter: Acceleration_T0
                                        * Referenced by: '<S1>/Gain4'
                                        */
  0.01,                                /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S5>/Constant'
                                        */
  0.0,                                 /* Mask Parameter: SliderGain_gain
                                        * Referenced by: '<S11>/Slider Gain'
                                        */
  1.0,                                 /* Mask Parameter: AlfaNormalization_pos
                                        * Referenced by: '<S2>/pos'
                                        */
  0,                                   /* Mask Parameter: SRFlipFlop_initial_condition
                                        * Referenced by: '<S7>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<Root>/Gain9'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<Root>/Gain8'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Normal'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Reset'
                                        */
  0.0,                                 /* Expression: initCond
                                        * Referenced by: '<S8>/ '
                                        */

  /*  Computed Parameter: Encoder_P1_Size
   * Referenced by: '<S3>/Encoder'
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S3>/Encoder'
                                        */

  /*  Computed Parameter: Encoder_P2_Size
   * Referenced by: '<S3>/Encoder'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S3>/Encoder'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/Encoder 1024 PPR'
                                        */
  5.7053E-5,                           /* Expression: 5.7053e-005
                                        * Referenced by: '<S3>/PosCart Scale'
                                        */
  -0.93,                               /* Expression: -1.86/2
                                        * Referenced by: '<S3>/Cart Offset'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S9>/Gain3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: synthesized block
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S2>/pi'
                                        */
  0.0015339807878856412,               /* Expression: 2*pi/4096
                                        * Referenced by: '<S3>/Angle Scale'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S9>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Memory1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory1'
                                        */
  1.5707963267948966,                  /* Expression: pi/2
                                        * Referenced by: '<Root>/Constant1'
                                        */
  -0.35,                               /* Expression: -0.35
                                        * Referenced by: '<Root>/Gain6'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<Root>/Gain'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<Root>/Gain7'
                                        */

  /*  Computed Parameter: PWM_P1_Size
   * Referenced by: '<S3>/PWM'
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S3>/PWM'
                                        */

  /*  Computed Parameter: PWM_P2_Size
   * Referenced by: '<S3>/PWM'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S3>/PWM'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  0.7,                                 /* Expression: 0.7
                                        * Referenced by: '<Root>/Switch'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S3>/Saturation'
                                        */
  -0.5,                                /* Expression: -0.5
                                        * Referenced by: '<S3>/Saturation'
                                        */

  /*  Computed Parameter: ResetEncoder_P1_Size
   * Referenced by: '<S3>/ResetEncoder'
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S3>/ResetEncoder'
                                        */

  /*  Computed Parameter: ResetEncoder_P2_Size
   * Referenced by: '<S3>/ResetEncoder'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S3>/ResetEncoder'
                                        */

  /*  Expression: [1 1 1 ]
   * Referenced by: '<S3>/ResetSource'
   */
  { 1.0, 1.0, 1.0 },

  /*  Computed Parameter: LimitFlag_P1_Size
   * Referenced by: '<S3>/LimitFlag'
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S3>/LimitFlag'
                                        */

  /*  Computed Parameter: LimitFlag_P2_Size
   * Referenced by: '<S3>/LimitFlag'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S3>/LimitFlag'
                                        */

  /*  Expression: [0 0 0]
   * Referenced by: '<S3>/LimitFlagSource'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [129 116 300]
   * Referenced by: '<S3>/LimitSource'
   */
  { 129.0, 116.0, 300.0 },

  /*  Computed Parameter: SetLimit_P1_Size
   * Referenced by: '<S3>/SetLimit'
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S3>/SetLimit'
                                        */

  /*  Computed Parameter: SetLimit_P2_Size
   * Referenced by: '<S3>/SetLimit'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S3>/SetLimit'
                                        */

  /*  Computed Parameter: LimitSwitch_P1_Size
   * Referenced by: '<S3>/LimitSwitch'
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S3>/LimitSwitch'
                                        */

  /*  Computed Parameter: LimitSwitch_P2_Size
   * Referenced by: '<S3>/LimitSwitch'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S3>/LimitSwitch'
                                        */

  /*  Computed Parameter: PWMPrescaler_P1_Size
   * Referenced by: '<S3>/PWMPrescaler'
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S3>/PWMPrescaler'
                                        */

  /*  Computed Parameter: PWMPrescaler_P2_Size
   * Referenced by: '<S3>/PWMPrescaler'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S3>/PWMPrescaler'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/PWMPrescalerSource'
                                        */

  /*  Computed Parameter: ResetSwitchFlag_P1_Size
   * Referenced by: '<S3>/ResetSwitchFlag '
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S3>/ResetSwitchFlag '
                                        */

  /*  Computed Parameter: ResetSwitchFlag_P2_Size
   * Referenced by: '<S3>/ResetSwitchFlag '
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S3>/ResetSwitchFlag '
                                        */

  /*  Expression: [ 0 0 0 ]
   * Referenced by: '<S3>/ResetSwitchFlagSource'
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: ThermFlag_P1_Size
   * Referenced by: '<S3>/ThermFlag '
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S3>/ThermFlag '
                                        */

  /*  Computed Parameter: ThermFlag_P2_Size
   * Referenced by: '<S3>/ThermFlag '
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S3>/ThermFlag '
                                        */

  /*  Expression: [1 1 1]
   * Referenced by: '<S3>/ThermFlagSource'
   */
  { 1.0, 1.0, 1.0 },
  1U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  0U,                                  /* Computed Parameter: ManualSwitch1_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch1'
                                        */
  0U,                                  /* Computed Parameter: ResetEncoders_CurrentSetting
                                        * Referenced by: '<Root>/Reset Encoders'
                                        */

  /*  Computed Parameter: Logic_table
   * Referenced by: '<S7>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0 }
};
