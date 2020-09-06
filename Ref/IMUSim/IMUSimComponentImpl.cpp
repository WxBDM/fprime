// ======================================================================
// \title  IMUSimComponentImpl.cpp
// \author bdmolyne
// \brief  cpp file for IMUSim component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/IMUSim/IMUSimComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  IMUSimComponentImpl ::
#if FW_OBJECT_NAMES == 1
    IMUSimComponentImpl(
        const char *const compName
    ) :
      IMUSimComponentBase(compName)
#else
    IMUSimComponentImpl(void)
#endif
  {

  }

  void IMUSimComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    IMUSimComponentBase::init(queueDepth, instance);
  }

  IMUSimComponentImpl ::
    ~IMUSimComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void IMUSimComponentImpl ::
    driverReqIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 request_x,
        F32 request_y,
        F32 request_z
    )
  {
    // TODO
      this->tempOut_out(0, this->curr_x_axis, this->curr_y_axis, this->curr_z_axis);
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void IMUSimComponentImpl ::
    IMU_SET_ROTATION_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        F32 x_axis,
        F32 y_axis,
        F32 z_axis
    )
  {
    // TODO
      // set vales
      this->curr_x_axis = x_axis;
      this->curr_y_axis = y_axis;
      this->curr_z_axis = z_axis;
      
      // telementary
      this->tlmWrite_IMUSIM_X_VAL(this->curr_x_axis);
      this->tlmWrite_IMUSIM_Y_VAL(this->curr_y_axis);
      this->tlmWrite_IMUSIM_Z_VAL(this->curr_z_axis);
      
      // log that the velocity changed.
      this->log_ACTIVITY_HI_IMUSIM_ANG_VEL_CHANGED(x_axis, y_axis, z_axis);
      
      // this came with it.
      this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace Ref
