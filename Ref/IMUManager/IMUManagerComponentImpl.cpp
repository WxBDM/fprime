// ======================================================================
// \title  IMUManagerComponentImpl.cpp
// \author bdmolyne
// \brief  cpp file for IMUManager component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/IMUManager/IMUManagerComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  IMUManagerComponentImpl ::
#if FW_OBJECT_NAMES == 1
    IMUManagerComponentImpl(
        const char *const compName
    ) :
      IMUManagerComponentBase(compName)
#else
    IMUManagerComponentImpl(void)
#endif
  {
      this -> last_x_axis = 0.2;
      this -> last_y_axis = 0.2;
      this -> last_z_axis = 0.2;
      
      this -> tlmWrite_IMU_MANAGER_LAST_TEMP(0.2);
  }

  void IMUManagerComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    IMUManagerComponentBase::init(queueDepth, instance);
  }

  IMUManagerComponentImpl ::
    ~IMUManagerComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void IMUManagerComponentImpl ::
    angvelIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 x_axis,
        F32 y_axis,
        F32 z_axis
    )
  {
    // TODO
      this -> last_x_axis = x_axis;
      this -> last_y_axis = y_axis;
      this->last_z_axis = z_axis;
      
      this->tlmWrite_IMU_MANAGER_LAST_TEMP(x_axis);
  }

  void IMUManagerComponentImpl ::
    SchedIn_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    // TODO
      this-> angvelOut_out(0, 0, 0, 0);
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void IMUManagerComponentImpl ::
    IMU_MANAGER_ENABLE_AUTO_CHECK_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq
    )
  {
    // TODO
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  void IMUManagerComponentImpl ::
    IMU_MANAGER_DISABLE_AUTO_CHECK_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq
    )
  {
    // TODO
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace Ref
