  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Wahadlo_P)
    ;%
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% Wahadlo_P.E
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Wahadlo_P.Jr
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Wahadlo_P.K
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Wahadlo_P.Sensors_T0
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 6;
	
	  ;% Wahadlo_P.Acceleration_T0
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 7;
	
	  ;% Wahadlo_P.CompareToConstant1_const
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 8;
	
	  ;% Wahadlo_P.SliderGain_gain
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 9;
	
	  ;% Wahadlo_P.AlfaNormalization_pos
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Wahadlo_P.SRFlipFlop_initial_condition
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 67;
      section.data(67)  = dumData; %prealloc
      
	  ;% Wahadlo_P.Constant3_Value
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Wahadlo_P.Gain9_Gain
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Wahadlo_P.Gain8_Gain
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Wahadlo_P.Normal_Value
	  section.data(4).logicalSrcIdx = 12;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Wahadlo_P.Reset_Value
	  section.data(5).logicalSrcIdx = 13;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Wahadlo_P._Y0
	  section.data(6).logicalSrcIdx = 14;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Wahadlo_P.Encoder_P1_Size
	  section.data(7).logicalSrcIdx = 15;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Wahadlo_P.Encoder_P1
	  section.data(8).logicalSrcIdx = 16;
	  section.data(8).dtTransOffset = 8;
	
	  ;% Wahadlo_P.Encoder_P2_Size
	  section.data(9).logicalSrcIdx = 17;
	  section.data(9).dtTransOffset = 9;
	
	  ;% Wahadlo_P.Encoder_P2
	  section.data(10).logicalSrcIdx = 18;
	  section.data(10).dtTransOffset = 11;
	
	  ;% Wahadlo_P.Encoder1024PPR_Gain
	  section.data(11).logicalSrcIdx = 19;
	  section.data(11).dtTransOffset = 12;
	
	  ;% Wahadlo_P.PosCartScale_Gain
	  section.data(12).logicalSrcIdx = 20;
	  section.data(12).dtTransOffset = 13;
	
	  ;% Wahadlo_P.CartOffset_Value
	  section.data(13).logicalSrcIdx = 21;
	  section.data(13).dtTransOffset = 14;
	
	  ;% Wahadlo_P.Gain3_Gain
	  section.data(14).logicalSrcIdx = 22;
	  section.data(14).dtTransOffset = 15;
	
	  ;% Wahadlo_P.TmpLatchAtSampleandHoldInport1_
	  section.data(15).logicalSrcIdx = 23;
	  section.data(15).dtTransOffset = 16;
	
	  ;% Wahadlo_P.pi_Value
	  section.data(16).logicalSrcIdx = 24;
	  section.data(16).dtTransOffset = 17;
	
	  ;% Wahadlo_P.AngleScale_Gain
	  section.data(17).logicalSrcIdx = 25;
	  section.data(17).dtTransOffset = 18;
	
	  ;% Wahadlo_P.Gain1_Gain
	  section.data(18).logicalSrcIdx = 26;
	  section.data(18).dtTransOffset = 19;
	
	  ;% Wahadlo_P.Memory_X0
	  section.data(19).logicalSrcIdx = 27;
	  section.data(19).dtTransOffset = 20;
	
	  ;% Wahadlo_P.Memory1_X0
	  section.data(20).logicalSrcIdx = 28;
	  section.data(20).dtTransOffset = 21;
	
	  ;% Wahadlo_P.Memory1_X0_b
	  section.data(21).logicalSrcIdx = 29;
	  section.data(21).dtTransOffset = 22;
	
	  ;% Wahadlo_P.Constant1_Value
	  section.data(22).logicalSrcIdx = 30;
	  section.data(22).dtTransOffset = 23;
	
	  ;% Wahadlo_P.Gain6_Gain
	  section.data(23).logicalSrcIdx = 31;
	  section.data(23).dtTransOffset = 24;
	
	  ;% Wahadlo_P.Gain_Gain
	  section.data(24).logicalSrcIdx = 32;
	  section.data(24).dtTransOffset = 25;
	
	  ;% Wahadlo_P.Gain7_Gain
	  section.data(25).logicalSrcIdx = 33;
	  section.data(25).dtTransOffset = 26;
	
	  ;% Wahadlo_P.PWM_P1_Size
	  section.data(26).logicalSrcIdx = 34;
	  section.data(26).dtTransOffset = 27;
	
	  ;% Wahadlo_P.PWM_P1
	  section.data(27).logicalSrcIdx = 35;
	  section.data(27).dtTransOffset = 29;
	
	  ;% Wahadlo_P.PWM_P2_Size
	  section.data(28).logicalSrcIdx = 36;
	  section.data(28).dtTransOffset = 30;
	
	  ;% Wahadlo_P.PWM_P2
	  section.data(29).logicalSrcIdx = 37;
	  section.data(29).dtTransOffset = 32;
	
	  ;% Wahadlo_P.Constant_Value
	  section.data(30).logicalSrcIdx = 38;
	  section.data(30).dtTransOffset = 33;
	
	  ;% Wahadlo_P.Switch_Threshold
	  section.data(31).logicalSrcIdx = 39;
	  section.data(31).dtTransOffset = 34;
	
	  ;% Wahadlo_P.Saturation_UpperSat
	  section.data(32).logicalSrcIdx = 40;
	  section.data(32).dtTransOffset = 35;
	
	  ;% Wahadlo_P.Saturation_LowerSat
	  section.data(33).logicalSrcIdx = 41;
	  section.data(33).dtTransOffset = 36;
	
	  ;% Wahadlo_P.ResetEncoder_P1_Size
	  section.data(34).logicalSrcIdx = 42;
	  section.data(34).dtTransOffset = 37;
	
	  ;% Wahadlo_P.ResetEncoder_P1
	  section.data(35).logicalSrcIdx = 43;
	  section.data(35).dtTransOffset = 39;
	
	  ;% Wahadlo_P.ResetEncoder_P2_Size
	  section.data(36).logicalSrcIdx = 44;
	  section.data(36).dtTransOffset = 40;
	
	  ;% Wahadlo_P.ResetEncoder_P2
	  section.data(37).logicalSrcIdx = 45;
	  section.data(37).dtTransOffset = 42;
	
	  ;% Wahadlo_P.ResetSource_Value
	  section.data(38).logicalSrcIdx = 46;
	  section.data(38).dtTransOffset = 43;
	
	  ;% Wahadlo_P.LimitFlag_P1_Size
	  section.data(39).logicalSrcIdx = 47;
	  section.data(39).dtTransOffset = 46;
	
	  ;% Wahadlo_P.LimitFlag_P1
	  section.data(40).logicalSrcIdx = 48;
	  section.data(40).dtTransOffset = 48;
	
	  ;% Wahadlo_P.LimitFlag_P2_Size
	  section.data(41).logicalSrcIdx = 49;
	  section.data(41).dtTransOffset = 49;
	
	  ;% Wahadlo_P.LimitFlag_P2
	  section.data(42).logicalSrcIdx = 50;
	  section.data(42).dtTransOffset = 51;
	
	  ;% Wahadlo_P.LimitFlagSource_Value
	  section.data(43).logicalSrcIdx = 51;
	  section.data(43).dtTransOffset = 52;
	
	  ;% Wahadlo_P.LimitSource_Value
	  section.data(44).logicalSrcIdx = 52;
	  section.data(44).dtTransOffset = 55;
	
	  ;% Wahadlo_P.SetLimit_P1_Size
	  section.data(45).logicalSrcIdx = 53;
	  section.data(45).dtTransOffset = 58;
	
	  ;% Wahadlo_P.SetLimit_P1
	  section.data(46).logicalSrcIdx = 54;
	  section.data(46).dtTransOffset = 60;
	
	  ;% Wahadlo_P.SetLimit_P2_Size
	  section.data(47).logicalSrcIdx = 55;
	  section.data(47).dtTransOffset = 61;
	
	  ;% Wahadlo_P.SetLimit_P2
	  section.data(48).logicalSrcIdx = 56;
	  section.data(48).dtTransOffset = 63;
	
	  ;% Wahadlo_P.LimitSwitch_P1_Size
	  section.data(49).logicalSrcIdx = 57;
	  section.data(49).dtTransOffset = 64;
	
	  ;% Wahadlo_P.LimitSwitch_P1
	  section.data(50).logicalSrcIdx = 58;
	  section.data(50).dtTransOffset = 66;
	
	  ;% Wahadlo_P.LimitSwitch_P2_Size
	  section.data(51).logicalSrcIdx = 59;
	  section.data(51).dtTransOffset = 67;
	
	  ;% Wahadlo_P.LimitSwitch_P2
	  section.data(52).logicalSrcIdx = 60;
	  section.data(52).dtTransOffset = 69;
	
	  ;% Wahadlo_P.PWMPrescaler_P1_Size
	  section.data(53).logicalSrcIdx = 61;
	  section.data(53).dtTransOffset = 70;
	
	  ;% Wahadlo_P.PWMPrescaler_P1
	  section.data(54).logicalSrcIdx = 62;
	  section.data(54).dtTransOffset = 72;
	
	  ;% Wahadlo_P.PWMPrescaler_P2_Size
	  section.data(55).logicalSrcIdx = 63;
	  section.data(55).dtTransOffset = 73;
	
	  ;% Wahadlo_P.PWMPrescaler_P2
	  section.data(56).logicalSrcIdx = 64;
	  section.data(56).dtTransOffset = 75;
	
	  ;% Wahadlo_P.PWMPrescalerSource_Value
	  section.data(57).logicalSrcIdx = 65;
	  section.data(57).dtTransOffset = 76;
	
	  ;% Wahadlo_P.ResetSwitchFlag_P1_Size
	  section.data(58).logicalSrcIdx = 66;
	  section.data(58).dtTransOffset = 77;
	
	  ;% Wahadlo_P.ResetSwitchFlag_P1
	  section.data(59).logicalSrcIdx = 67;
	  section.data(59).dtTransOffset = 79;
	
	  ;% Wahadlo_P.ResetSwitchFlag_P2_Size
	  section.data(60).logicalSrcIdx = 68;
	  section.data(60).dtTransOffset = 80;
	
	  ;% Wahadlo_P.ResetSwitchFlag_P2
	  section.data(61).logicalSrcIdx = 69;
	  section.data(61).dtTransOffset = 82;
	
	  ;% Wahadlo_P.ResetSwitchFlagSource_Value
	  section.data(62).logicalSrcIdx = 70;
	  section.data(62).dtTransOffset = 83;
	
	  ;% Wahadlo_P.ThermFlag_P1_Size
	  section.data(63).logicalSrcIdx = 71;
	  section.data(63).dtTransOffset = 86;
	
	  ;% Wahadlo_P.ThermFlag_P1
	  section.data(64).logicalSrcIdx = 72;
	  section.data(64).dtTransOffset = 88;
	
	  ;% Wahadlo_P.ThermFlag_P2_Size
	  section.data(65).logicalSrcIdx = 73;
	  section.data(65).dtTransOffset = 89;
	
	  ;% Wahadlo_P.ThermFlag_P2
	  section.data(66).logicalSrcIdx = 74;
	  section.data(66).dtTransOffset = 91;
	
	  ;% Wahadlo_P.ThermFlagSource_Value
	  section.data(67).logicalSrcIdx = 75;
	  section.data(67).dtTransOffset = 92;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Wahadlo_P.ManualSwitch_CurrentSetting
	  section.data(1).logicalSrcIdx = 76;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Wahadlo_P.ManualSwitch1_CurrentSetting
	  section.data(2).logicalSrcIdx = 77;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Wahadlo_P.ResetEncoders_CurrentSetting
	  section.data(3).logicalSrcIdx = 78;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Wahadlo_P.Logic_table
	  section.data(1).logicalSrcIdx = 79;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Wahadlo_B)
    ;%
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% Wahadlo_B.Encoder
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Wahadlo_B.Sum
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 5;
	
	  ;% Wahadlo_B.Cart_pos
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Wahadlo_B.AngleScale
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 7;
	
	  ;% Wahadlo_B.PendPosOut
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% Wahadlo_B.Pend_vel
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 9;
	
	  ;% Wahadlo_B.Cart_vel
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 10;
	
	  ;% Wahadlo_B.Cart_acc
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 11;
	
	  ;% Wahadlo_B.Gain2
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 12;
	
	  ;% Wahadlo_B.Gain3
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 13;
	
	  ;% Wahadlo_B.Gain4
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 14;
	
	  ;% Wahadlo_B.Gain5
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 15;
	
	  ;% Wahadlo_B.Subtract
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 16;
	
	  ;% Wahadlo_B.Gain6
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 17;
	
	  ;% Wahadlo_B.Abs
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 18;
	
	  ;% Wahadlo_B.Add1
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 19;
	
	  ;% Wahadlo_B.PWM
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 20;
	
	  ;% Wahadlo_B.SliderGain
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 23;
	
	  ;% Wahadlo_B.Switch3
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 24;
	
	  ;% Wahadlo_B.Saturation
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 25;
	
	  ;% Wahadlo_B.ResetEncoder
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 28;
	
	  ;% Wahadlo_B.ResetSource
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 33;
	
	  ;% Wahadlo_B.LimitFlag
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 36;
	
	  ;% Wahadlo_B.LimitFlagSource
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 39;
	
	  ;% Wahadlo_B.LimitSource
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 42;
	
	  ;% Wahadlo_B.SetLimit
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 45;
	
	  ;% Wahadlo_B.LimitSwitch
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 48;
	
	  ;% Wahadlo_B.PWMPrescaler
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 51;
	
	  ;% Wahadlo_B.PWMPrescalerSource
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 52;
	
	  ;% Wahadlo_B.ResetSwitchFlag
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 53;
	
	  ;% Wahadlo_B.ResetSwitchFlagSource
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 56;
	
	  ;% Wahadlo_B.ThermFlag
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 59;
	
	  ;% Wahadlo_B.ThermFlagSource
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 62;
	
	  ;% Wahadlo_B.ResetEncoders
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 65;
	
	  ;% Wahadlo_B.In
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 66;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Wahadlo_B.Logic
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
    sectIdxOffset = 2;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Wahadlo_DW)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Wahadlo_DW.TmpLatchAtSampleandHoldInport1_
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Wahadlo_DW.Memory_PreviousInput
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Wahadlo_DW.Memory1_PreviousInput
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Wahadlo_DW.Memory1_PreviousInput_m
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Wahadlo_DW.PendulumControlandStatesExperim.LoggedData
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Wahadlo_DW.Scope_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Wahadlo_DW.Scope1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Wahadlo_DW.FromWs_PWORK.TimePtr
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Wahadlo_DW.FromWs_IWORK.PrevIndex
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Wahadlo_DW.SampleandHold_SubsysRanBC
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Wahadlo_DW.Memory_PreviousInput_b
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2389427435;
  targMap.checksum1 = 4100144922;
  targMap.checksum2 = 77127371;
  targMap.checksum3 = 1825649549;

