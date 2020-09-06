// ======================================================================
// \title  IMUManagerComponentImpl.hpp
// \author bdmolyne
// \brief  hpp file for IMUManager component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef IMUManager_HPP
#define IMUManager_HPP

#include "Ref/IMUManager/IMUManagerComponentAc.hpp"

namespace Ref {

  class IMUManagerComponentImpl :
    public IMUManagerComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object IMUManager
      //!
      IMUManagerComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object IMUManager
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object IMUManager
      //!
      ~IMUManagerComponentImpl(void);
      private:
      F32 last_x_axis = 0.2;
      F32 last_y_axis = 0.2;
      F32 last_z_axis = 0.2;

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for angvelIn
      //!
      void angvelIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 x_axis, 
          F32 y_axis, 
          F32 z_axis 
      );

      //! Handler implementation for SchedIn
      //!
      void SchedIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< The call order*/
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for IMU_MANAGER_ENABLE_AUTO_CHECK command handler
      //! 
      void IMU_MANAGER_ENABLE_AUTO_CHECK_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq /*!< The command sequence number*/
      );

      //! Implementation for IMU_MANAGER_DISABLE_AUTO_CHECK command handler
      //! 
      void IMU_MANAGER_DISABLE_AUTO_CHECK_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq /*!< The command sequence number*/
      );


    };

} // end namespace Ref

#endif
