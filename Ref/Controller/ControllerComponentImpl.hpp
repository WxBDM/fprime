// ======================================================================
// \title  ControllerComponentImpl.hpp
// \author jzl0213
// \brief  hpp file for Controller component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef Controller_HPP
#define Controller_HPP

#include "Ref/Controller/ControllerComponentAc.hpp"

namespace Ref {

  class ControllerComponentImpl :
    public ControllerComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object Controller
      //!
      ControllerComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object Controller
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object Controller
      //!
      ~ControllerComponentImpl(void);

      private:
        U32 currPhase;
        U32 currBattery;

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for healthAlertIn
      //!
      void healthAlertIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U32 enterSafeMode, 
          U32 sourceComponent 
      );

      //! Handler implementation for MonitorAlertIn
      //!
      void MonitorAlertIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U32 sourceComponent 
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for CONTROLLER_CHANGE_PHASE command handler
      //! 
      void CONTROLLER_CHANGE_PHASE_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          U32 phase 
      );

      //! Implementation for CONTROLLER_CHANGE_TEMP_THRESHOLD command handler
      //! 
      void CONTROLLER_CHANGE_TEMP_THRESHOLD_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          U32 phase, 
          F32 minTemp, 
          F32 maxTemp 
      );

      //! Implementation for CONTROLLER_CHANGE_BATTERY command handler
      //! 
      void CONTROLLER_CHANGE_BATTERY_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          U32 battery 
      );

      //! Implementation for CONTROLLER_CHANGE_DOD_THRESHOLD command handler
      //! 
      void CONTROLLER_CHANGE_DOD_THRESHOLD_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          U32 battery, 
          F32 minDOD, 
          F32 maxDOD 
      );


    };

} // end namespace Ref

#endif
