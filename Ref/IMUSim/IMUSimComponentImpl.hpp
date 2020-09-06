// ======================================================================
// \title  IMUSimComponentImpl.hpp
// \author bdmolyne
// \brief  hpp file for IMUSim component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef IMUSim_HPP
#define IMUSim_HPP

#include "Ref/IMUSim/IMUSimComponentAc.hpp"

namespace Ref {

  class IMUSimComponentImpl :
    public IMUSimComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object IMUSim
      //!
      IMUSimComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object IMUSim
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object IMUSim
      //!
      ~IMUSimComponentImpl(void);
      
  private:
      F32 curr_x_axis = 0.2;
      F32 curr_y_axis = 0.2;
      F32 curr_z_axis = 0.2;

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for driverReqIn
      //!
      void driverReqIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 request_x, 
          F32 request_y, 
          F32 request_z 
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for IMU_SET_ROTATION command handler
      //! 
      void IMU_SET_ROTATION_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          F32 x_axis, 
          F32 y_axis, 
          F32 z_axis 
      );


    };

} // end namespace Ref

#endif
